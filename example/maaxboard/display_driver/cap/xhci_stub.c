/* This work is Crown Copyright NCSC, 2023. */
#include <microkit.h>
#include <printf.h>

#include <machine/bus_funcs.h>

#include <dev/usb/xhcivar.h>

#include <wrapper.h>
#include <tinyalloc.h>
#include <dma.h>
#include <sys/bus.h>
#include <sys/device.h>
#include <sys/device_impl.h>
#include <sys/intr.h>
#include <sys/kernel.h>
#include <sys/kmem.h>

#include <timer.h>
#include <shared_ringbuffer.h>
#include <dev/usb/usb.h>
#include <dev/usb/usbdi.h>
#include <dev/usb/usbdivar.h>
#include <dev/usb/usbhist.h>
#include <dev/usb/usb_mem.h>
#include <dev/usb/xhcireg.h>
#include <dev/usb/xhcivar.h>
#include <sys/device.h>
#include <machine/types.h>
#include <sel4_bus_funcs.h>
#include <imx8m_dcss.h>

#include <lib/libkern/libkern.h>
#include <dev/fdt/fdtvar.h>
#define BUS_DEBUG 0
#define __AARCH64__

//extern variables
bool int_once = false;
struct xhci_softc *glob_xhci_sc	= NULL;
struct usb_softc *glob_usb_sc 	= NULL;
struct usbd_bus_methods *xhci_bus_methods_ptr;
uintptr_t xhci_root_intr_pointer;
uintptr_t xhci_root_intr_pointer_other;
uintptr_t device_ctrl_pointer;
uintptr_t device_ctrl_pointer_other;
uintptr_t device_intr_pointer;
uintptr_t device_intr_pointer_other;
uintptr_t rx_free;
uintptr_t rx_used;
uintptr_t tx_free;
uintptr_t tx_used;

struct intr_ptrs_holder *intr_ptrs;
bool pipe_thread;
int cold = 1;

struct imx8mq_usbphy_softc {
	device_t		sc_dev;
	bus_space_tag_t		sc_bst;
	bus_space_handle_t	sc_bsh;
	int			sc_phandle;
};

// definitions from .system file
uintptr_t xhci_base;
uintptr_t xhci_phy_base;
uintptr_t heap_base;
uint64_t heap_size = 0x2000000;
int ta_blocks = 256;
int ta_thresh = 16;
int ta_align = 64;
uintptr_t pipe_heap_base;
uintptr_t dma_base;
uintptr_t dma_cp_paddr;
uintptr_t dma_cp_vaddr = 0x54000000;
uintptr_t ta_limit;
uintptr_t timer_base;
uintptr_t software_heap;

/* Pointers to shared_ringbuffers */
ring_handle_t *kbd_buffer_ring;

int phy_setup() {
    struct imx8mq_usbphy_softc *sc_usbphy;
	sc_usbphy = kmem_alloc(sizeof(*sc_usbphy), 0);
    device_t parent_usbphy = NULL;
    device_t self_usbphy = kmem_alloc(sizeof(device_t), 0);
    void *aux_usbphy = kmem_alloc(sizeof(struct fdt_attach_args), 0);
	sc_usbphy->sc_bsh = 0x382f0040;
	sc_usbphy->sc_bst = kmem_alloc(sizeof(bus_space_tag_t), 0);
	self_usbphy->dv_private = sc_usbphy;
	imx8mq_usbphy_attach(parent_usbphy, self_usbphy,aux_usbphy);


    imx8mq_usbphy_enable(self_usbphy, NULL, true); //imx8 doesn't need priv 
    return 0;
}

void imx8m_dcss_init() {

    // priv->addr replaced with vaddr of display_controller1
    // Other vlues replaced with debug output
    // priv->timings.hactive.typ replace with 1280
    // priv->timings.vactive.typ replaced with 720
    // priv->timings.pixelclock.typ replaced with 74250000
    // plat->base replaced with 0xbf800000

    /* DTRC-CHAN2/3 */
    reg32_write(0x32e00000 + 0x160c8, 0x00000002);
	reg32_write(0x32e00000 + 0x170c8, 0x00000002);

	/* CHAN1_DPR */
    
	reg32_write(0x32e00000 + 0x18090, 0x00000002);
	reg32_write(0x32e00000 + 0x180a0, 1280);
	reg32_write(0x32e00000 + 0x180b0, 720);
	reg32_write(0x32e00000 + 0x18110,
		    0xbf800000 + 1280 * 720);
	reg32_write(0x32e00000 + 0x180f0, 0x00000280);
	reg32_write(0x32e00000 + 0x18100, 0x000000f0);
	reg32_write(0x32e00000 + 0x180c0, 0xbf800000);
	reg32_write(0x32e00000 + 0x18070, ((1280 * 4) << 16));
	reg32_write(0x32e00000 + 0x18050, 0x000e4203);
	reg32_write(0x32e00000 + 0x18050, 0x000e4203);
	reg32_write(0x32e00000 + 0x18200, 0x00000038);
	reg32_write(0x32e00000 + 0x18000, 0x00000004);
	reg32_write(0x32e00000 + 0x18000, 0x00000005);

	/* SCALER */
	reg32_write(0x32e00000 + 0x1c008, 0x00000000);
	reg32_write(0x32e00000 + 0x1c00c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c010, 0x00000002);
	reg32_write(0x32e00000 + 0x1c014, 0x00000002);
	reg32_write(0x32e00000 + 0x1c018,
		    ((720 - 1) << 16 | (1280 - 1)));
	reg32_write(0x32e00000 + 0x1c01c,
		    ((720 - 1) << 16 | (1280 - 1)));
	reg32_write(0x32e00000 + 0x1c020,
		    ((720 - 1) << 16 | (1280 - 1)));
	reg32_write(0x32e00000 + 0x1c024,
		    ((720 - 1) << 16 | (1280 - 1)));
	reg32_write(0x32e00000 + 0x1c028, 0x00000000);
	reg32_write(0x32e00000 + 0x1c02c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c030, 0x00000000);
	reg32_write(0x32e00000 + 0x1c034, 0x00000000);
	reg32_write(0x32e00000 + 0x1c038, 0x00000000);
	reg32_write(0x32e00000 + 0x1c03c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c040, 0x00000000);
	reg32_write(0x32e00000 + 0x1c044, 0x00000000);
	reg32_write(0x32e00000 + 0x1c048, 0x00000000);
	reg32_write(0x32e00000 + 0x1c04c, 0x00002000);
	reg32_write(0x32e00000 + 0x1c050, 0x00000000);
	reg32_write(0x32e00000 + 0x1c054, 0x00002000);
	reg32_write(0x32e00000 + 0x1c058, 0x00000000);
	reg32_write(0x32e00000 + 0x1c05c, 0x00002000);
	reg32_write(0x32e00000 + 0x1c060, 0x00000000);
	reg32_write(0x32e00000 + 0x1c064, 0x00002000);
	reg32_write(0x32e00000 + 0x1c080, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0c0, 0x00040000);
	reg32_write(0x32e00000 + 0x1c100, 0x00000000);
	reg32_write(0x32e00000 + 0x1c084, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0c4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c104, 0x00000000);
	reg32_write(0x32e00000 + 0x1c088, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0c8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c108, 0x00000000);
	reg32_write(0x32e00000 + 0x1c08c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0cc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c10c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c090, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0d0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c110, 0x00000000);
	reg32_write(0x32e00000 + 0x1c094, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0d4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c114, 0x00000000);
	reg32_write(0x32e00000 + 0x1c098, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0d8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c118, 0x00000000);
	reg32_write(0x32e00000 + 0x1c09c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0dc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c11c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0a0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0e0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c120, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0a4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0e4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c124, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0a8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0e8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c128, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0ac, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0ec, 0x00000000);
	reg32_write(0x32e00000 + 0x1c12c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0b0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0f0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c130, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0b4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0f4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c134, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0b8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0f8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c138, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0bc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c0fc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c13c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c140, 0x00000000);
	reg32_write(0x32e00000 + 0x1c180, 0x00040000);
	reg32_write(0x32e00000 + 0x1c1c0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c144, 0x00000000);
	reg32_write(0x32e00000 + 0x1c184, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1c4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c148, 0x00000000);
	reg32_write(0x32e00000 + 0x1c188, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1c8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c14c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c18c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1cc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c150, 0x00000000);
	reg32_write(0x32e00000 + 0x1c190, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1d0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c154, 0x00000000);
	reg32_write(0x32e00000 + 0x1c194, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1d4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c158, 0x00000000);
	reg32_write(0x32e00000 + 0x1c198, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1d8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c15c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c19c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1dc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c160, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1a0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1e0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c164, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1a4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1e4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c168, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1a8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1e8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c16c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1ac, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1ec, 0x00000000);
	reg32_write(0x32e00000 + 0x1c170, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1b0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1f0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c174, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1b4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1f4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c178, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1b8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1f8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c17c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1bc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c1fc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c300, 0x00000000);
	reg32_write(0x32e00000 + 0x1c340, 0x00000000);
	reg32_write(0x32e00000 + 0x1c380, 0x00000000);
	reg32_write(0x32e00000 + 0x1c304, 0x00000000);
	reg32_write(0x32e00000 + 0x1c344, 0x00000000);
	reg32_write(0x32e00000 + 0x1c384, 0x00000000);
	reg32_write(0x32e00000 + 0x1c308, 0x00000000);
	reg32_write(0x32e00000 + 0x1c348, 0x00000000);
	reg32_write(0x32e00000 + 0x1c388, 0x00000000);
	reg32_write(0x32e00000 + 0x1c30c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c34c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c38c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c310, 0x00000000);
	reg32_write(0x32e00000 + 0x1c350, 0x00000000);
	reg32_write(0x32e00000 + 0x1c390, 0x00000000);
	reg32_write(0x32e00000 + 0x1c314, 0x00000000);
	reg32_write(0x32e00000 + 0x1c354, 0x00000000);
	reg32_write(0x32e00000 + 0x1c394, 0x00000000);
	reg32_write(0x32e00000 + 0x1c318, 0x00000000);
	reg32_write(0x32e00000 + 0x1c358, 0x00000000);
	reg32_write(0x32e00000 + 0x1c398, 0x00000000);
	reg32_write(0x32e00000 + 0x1c31c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c35c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c39c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c320, 0x00000000);
	reg32_write(0x32e00000 + 0x1c360, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3a0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c324, 0x00000000);
	reg32_write(0x32e00000 + 0x1c364, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3a4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c328, 0x00000000);
	reg32_write(0x32e00000 + 0x1c368, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3a8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c32c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c36c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3ac, 0x00000000);
	reg32_write(0x32e00000 + 0x1c330, 0x00000000);
	reg32_write(0x32e00000 + 0x1c370, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3b0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c334, 0x00000000);
	reg32_write(0x32e00000 + 0x1c374, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3b4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c338, 0x00000000);
	reg32_write(0x32e00000 + 0x1c378, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3b8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c33c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c37c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c3bc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c200, 0x00000000);
	reg32_write(0x32e00000 + 0x1c240, 0x00000000);
	reg32_write(0x32e00000 + 0x1c280, 0x00000000);
	reg32_write(0x32e00000 + 0x1c204, 0x00000000);
	reg32_write(0x32e00000 + 0x1c244, 0x00000000);
	reg32_write(0x32e00000 + 0x1c284, 0x00000000);
	reg32_write(0x32e00000 + 0x1c208, 0x00000000);
	reg32_write(0x32e00000 + 0x1c248, 0x00000000);
	reg32_write(0x32e00000 + 0x1c288, 0x00000000);
	reg32_write(0x32e00000 + 0x1c20c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c24c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c28c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c210, 0x00000000);
	reg32_write(0x32e00000 + 0x1c250, 0x00000000);
	reg32_write(0x32e00000 + 0x1c290, 0x00000000);
	reg32_write(0x32e00000 + 0x1c214, 0x00000000);
	reg32_write(0x32e00000 + 0x1c254, 0x00000000);
	reg32_write(0x32e00000 + 0x1c294, 0x00000000);
	reg32_write(0x32e00000 + 0x1c218, 0x00000000);
	reg32_write(0x32e00000 + 0x1c258, 0x00000000);
	reg32_write(0x32e00000 + 0x1c298, 0x00000000);
	reg32_write(0x32e00000 + 0x1c21c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c25c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c29c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c220, 0x00000000);
	reg32_write(0x32e00000 + 0x1c260, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2a0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c224, 0x00000000);
	reg32_write(0x32e00000 + 0x1c264, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2a4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c228, 0x00000000);
	reg32_write(0x32e00000 + 0x1c268, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2a8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c22c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c26c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2ac, 0x00000000);
	reg32_write(0x32e00000 + 0x1c230, 0x00000000);
	reg32_write(0x32e00000 + 0x1c270, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2b0, 0x00000000);
	reg32_write(0x32e00000 + 0x1c234, 0x00000000);
	reg32_write(0x32e00000 + 0x1c274, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2b4, 0x00000000);
	reg32_write(0x32e00000 + 0x1c238, 0x00000000);
	reg32_write(0x32e00000 + 0x1c278, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2b8, 0x00000000);
	reg32_write(0x32e00000 + 0x1c23c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c27c, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2bc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c2bc, 0x00000000);
	reg32_write(0x32e00000 + 0x1c000, 0x00000011);

	/* SUBSAM */
	reg32_write(0x32e00000 + 0x1b070, 0x21612161);
	reg32_write(0x32e00000 + 0x1b080, 0x03ff0000);
	reg32_write(0x32e00000 + 0x1b090, 0x03ff0000);

    // priv->timings.vfront_porch.typ = 20
    // priv->timings.vback_porch.typ = 5
    // priv->timings.vsync_len.typ = 5
    // priv->timings.vactive.typ = 720
    // priv->timings.hfront_porch.typ = 220
    // priv->timings.hback_porch.typ = 110
    // priv->timings.hsync_len.typ = 40
    // priv->timings.hactive.typ = 1280
    // priv->hpol = 0
    // priv->vpol = 0

    reg32_write(0x32e00000 + 0x1b010,
		    (((20 + 5 + 5 +
			720 -1) << 16) |
		       (220 + 110 + 40 +
			1280 - 1)));
	reg32_write(0x32e00000 + 0x1b020,
		    (((40 - 1) << 16) | 0 << 31 | (220 +
			110 + 40 + 1280 -1)));
	reg32_write(0x32e00000 + 0x1b030,
		    (((20 + 5 - 1) << 16) | 0 << 31 | (20 - 1)));
	reg32_write(0x32e00000 + 0x1b040,
		    ((1 << 31) | ((5 +20 + 5) << 16) |
		    (40 + 110 - 1)));
	reg32_write(0x32e00000 + 0x1b050,
		    (((5 + 20 + 5 + 720 -1) << 16) |
		    (40 + 110 + 1280 - 1)));

	/* subsample mode 0 bypass 444, 1 422, 2 420 */
	reg32_write(0x32e00000 + 0x1b060, 0x0000000);

	reg32_write(0x32e00000 + 0x1b000, 0x00000001);

	/* DTG */
	/*reg32_write(priv->addr + 0x20000, 0xff000484); */
	/* disable local alpha */
	reg32_write(0x32e00000 + 0x20000, 0xff005084);
	reg32_write(0x32e00000 + 0x20004,
		    (((20 + 5 + 5 + 720 -
		       1) << 16) | (220 + 110 + 40 +
			1280 - 1)));
	reg32_write(0x32e00000 + 0x20008,
		    (((5 + 20 + 5 -
		       1) << 16) | (40 + 110 - 1)));
	reg32_write(0x32e00000 + 0x2000c,
		    (((5 + 20 + 5 + 720 -
		       1) << 16) | (40 + 110 + 1280 - 1)));
	reg32_write(0x32e00000 + 0x20010,
		    (((5 + 20 + 5 -
		       1) << 16) | (40 + 110 - 1)));
	reg32_write(0x32e00000 + 0x20014,
		    (((5 + 20 + 5 + 720 -
		       1) << 16) | (40 + 110 + 1280 - 1)));
	reg32_write(0x32e00000 + 0x20028, 0x000b000a);

	/* disable local alpha */
	reg32_write(0x32e00000 + 0x20000, 0xff005184);
}

void imx8m_dcss_reset () {
    /* DCSS reset */
	reg32_write(0x32e00000 + 0x2f000, 0xffffffff);

	/* DCSS clock selection */
	reg32_write(0x32e00000 + 0x2f010, 0x1);
}

void
init(void) {

    config_init();
    pipe_thread = false;
    cold = 0;

    // init
    printf("XHCI_STUB: dmapaddr = %p\n", dma_cp_paddr);
    xhci_bus_methods_ptr = (struct usbd_bus_methods *) get_bus_methods();
    xhci_root_intr_pointer = (uintptr_t) get_root_intr_methods();
    device_ctrl_pointer = (uintptr_t) get_device_methods();
    microkit_msginfo addr = microkit_ppcall(1, seL4_MessageInfo_new((uint64_t) xhci_root_intr_pointer,1,0,0));
    xhci_root_intr_pointer_other = microkit_msginfo_get_label(addr);
    device_ctrl_pointer = (uintptr_t) get_device_methods();
    addr = microkit_ppcall(3, seL4_MessageInfo_new((uint64_t) device_ctrl_pointer,1,0,0));
    device_ctrl_pointer_other = (uintptr_t) microkit_msginfo_get_label(addr);
    device_intr_pointer = (uintptr_t) get_device_intr_methods();
    addr = microkit_ppcall(4, seL4_MessageInfo_new((uint64_t) device_intr_pointer,1,0,0));
    device_intr_pointer_other = (uintptr_t) microkit_msginfo_get_label(addr);
    addr = microkit_ppcall(8, seL4_MessageInfo_new(0,0,0,0));
    intr_ptrs = (struct intr_ptrs_holder *) microkit_msginfo_get_label(addr);

    initialise_and_start_timer(timer_base);

    sel4_dma_init(dma_cp_paddr, dma_cp_vaddr, dma_cp_vaddr + 0x200000);

    // device_t parent_xhci = NULL;
    // kbd_buffer_ring = kmem_alloc(sizeof(*kbd_buffer_ring), 0);

    // phy_setup();
    // device_t self_xhci = kmem_alloc(sizeof(device_t), 0);
    // void *aux_xhci = kmem_alloc(sizeof(struct fdt_attach_args), 0);

    // struct xhci_softc *sc_xhci = kmem_alloc(sizeof(struct xhci_softc), 0);
    // glob_xhci_sc = sc_xhci;
    // sc_xhci->sc_ioh=0x38200000;
    // microkit_ppcall(0, seL4_MessageInfo_new((uint64_t) sc_xhci,1,0,0));
    // microkit_ppcall(2, seL4_MessageInfo_new((uint64_t) sc_xhci,1,0,0));
	// bus_space_tag_t iot = kmem_alloc(sizeof(bus_space_tag_t), 0);
    // sc_xhci->sc_iot=iot;

    // self_xhci->dv_private = sc_xhci;

    // dwc3_fdt_attach(parent_xhci,self_xhci,aux_xhci);

    // struct usb_softc *usb_sc = kmem_alloc(sizeof(struct usb_softc),0);
    // struct usbd_bus *sc_bus = kmem_alloc(sizeof(struct usbd_bus),0);
    // device_t self = kmem_alloc(sizeof(device_t), 0);
    // *sc_bus = glob_xhci_sc->sc_bus;
    // sc_bus->ub_methods = glob_xhci_sc->sc_bus.ub_methods;
    // self->dv_unit = 1;
    // self->dv_private = usb_sc;
    // device_t parent = NULL;
    // usb_attach(parent, self, sc_bus);
	// usb_sc->sc_bus->ub_needsexplore = 1;

    // usb_discover(usb_sc);
    // printf("\nxHCI driver ready\n");

    imx8m_dcss_init();
}


void
notified(microkit_channel ch)
{
}

microkit_msginfo
protected(microkit_channel ch, microkit_msginfo msginfo) {
    switch (ch) {
        case 1:
            // return addr of root_intr_methods
            xhci_root_intr_pointer = (uintptr_t) microkit_msginfo_get_label(msginfo);
            break;
        default:
            printf("xhci_stub received protected unexpected channel\n");
    }
    return seL4_MessageInfo_new(0,0,0,0);
}
