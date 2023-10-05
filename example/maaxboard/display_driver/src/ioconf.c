#include "ioconf.h"
/*
 * MACHINE GENERATED: DO NOT EDIT
 *
 * ioconf.c, from "XHCI_DEBUG"
 */

#include <sys/param.h>
#include <sys/conf.h>
#include <sys/device.h>
#ifndef SEL4
#include <sys/mount.h>
#endif

static const struct cfiattrdata tps65217pmiccf_iattrdata = {
	"tps65217pmic", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata simplebuscf_iattrdata = {
	"simplebus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata wskbddevcf_iattrdata = {
	"wskbddev", 2, {
		{ "console", "-1", -1 },
		{ "mux", "1", 1 },
	}
};
static const struct cfiattrdata pckbportcf_iattrdata = {
	"pckbport", 1, {
		{ "slot", "-1", -1 },
	}
};
static const struct cfiattrdata wsmousedevcf_iattrdata = {
	"wsmousedev", 1, {
		{ "mux", "0", 0 },
	}
};
static const struct cfiattrdata midibuscf_iattrdata = {
	"midibus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata tegra210xpadcf_iattrdata = {
	"tegra210xpad", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata vchiqbuscf_iattrdata = {
	"vchiqbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata sysconcf_iattrdata = {
	"syscon", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata nvmecf_iattrdata = {
	"nvme", 1, {
		{ "nsid", "-1", -1 },
	}
};
static const struct cfiattrdata drmcf_iattrdata = {
	"drm", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata irbuscf_iattrdata = {
	"irbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata usbuscf_iattrdata = {
	"usbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata miicf_iattrdata = {
	"mii", 1, {
		{ "phy", "-1", -1 },
	}
};
static const struct cfiattrdata spicf_iattrdata = {
	"spi", 1, {
		{ "slave", "NULL", 0 },
	}
};
static const struct cfiattrdata i2cbuscf_iattrdata = {
	"i2cbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata atapicf_iattrdata = {
	"atapi", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata scsicf_iattrdata = {
	"scsi", 1, {
		{ "channel", "-1", -1 },
	}
};
static const struct cfiattrdata usbififcf_iattrdata = {
	"usbifif", 6, {
		{ "port", "-1", -1 },
		{ "configuration", "-1", -1 },
		{ "interface", "-1", -1 },
		{ "vendor", "-1", -1 },
		{ "product", "-1", -1 },
		{ "release", "-1", -1 },
	}
};
static const struct cfiattrdata hdaudiobuscf_iattrdata = {
	"hdaudiobus", 1, {
		{ "nid", "-1", -1 },
	}
};
static const struct cfiattrdata gpiobuscf_iattrdata = {
	"gpiobus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata scsibuscf_iattrdata = {
	"scsibus", 2, {
		{ "target", "-1", -1 },
		{ "lun", "-1", -1 },
	}
};
static const struct cfiattrdata tilcdcfbbuscf_iattrdata = {
	"tilcdcfbbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata atacf_iattrdata = {
	"ata", 1, {
		{ "channel", "-1", -1 },
	}
};
static const struct cfiattrdata usbdevifcf_iattrdata = {
	"usbdevif", 6, {
		{ "port", "-1", -1 },
		{ "configuration", "-1", -1 },
		{ "interface", "-1", -1 },
		{ "vendor", "-1", -1 },
		{ "product", "-1", -1 },
		{ "release", "-1", -1 },
	}
};
static const struct cfiattrdata armfdtcf_iattrdata = {
	"armfdt", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata audiocf_iattrdata = {
	"audio", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata nandbuscf_iattrdata = {
	"nandbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata tisysccf_iattrdata = {
	"tisysc", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata gpiocf_iattrdata = {
	"gpio", 3, {
		{ "offset", "-1", -1 },
		{ "mask", "0", 0 },
		{ "flag", "0", 0 },
	}
};
static const struct cfiattrdata axppmiccf_iattrdata = {
	"axppmic", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata uhidbuscf_iattrdata = {
	"uhidbus", 1, {
		{ "reportid", "-1", -1 },
	}
};
static const struct cfiattrdata omap3cmcf_iattrdata = {
	"omap3cm", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata spibuscf_iattrdata = {
	"spibus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata radiodevcf_iattrdata = {
	"radiodev", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata ucombuscf_iattrdata = {
	"ucombus", 1, {
		{ "portno", "-1", -1 },
	}
};
static const struct cfiattrdata tiusbcf_iattrdata = {
	"tiusb", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata tigpmccf_iattrdata = {
	"tigpmc", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata sdmmccf_iattrdata = {
	"sdmmc", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata plcomcf_iattrdata = {
	"plcom", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata flashbuscf_iattrdata = {
	"flashbus", 4, {
		{ "offset", "0", 0 },
		{ "size", "0", 0 },
		{ "readonly", "0", 0 },
		{ "dynamic", "0", 0 },
	}
};
static const struct cfiattrdata cpuscf_iattrdata = {
	"cpus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata cpucf_iattrdata = {
	"cpu", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata pcicf_iattrdata = {
	"pci", 2, {
		{ "dev", "-1", -1 },
		{ "function", "-1", -1 },
	}
};
static const struct cfiattrdata wsbelldevcf_iattrdata = {
	"wsbelldev", 2, {
		{ "console", "-1", -1 },
		{ "mux", "1", 1 },
	}
};
static const struct cfiattrdata pcibuscf_iattrdata = {
	"pcibus", 1, {
		{ "bus", "-1", -1 },
	}
};
static const struct cfiattrdata as3722pmiccf_iattrdata = {
	"as3722pmic", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata virtiocf_iattrdata = {
	"virtio", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata dtvbuscf_iattrdata = {
	"dtvbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata atapibuscf_iattrdata = {
	"atapibus", 1, {
		{ "drive", "-1", -1 },
	}
};
static const struct cfiattrdata sdmmcbuscf_iattrdata = {
	"sdmmcbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata bcmmboxbuscf_iattrdata = {
	"bcmmboxbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata btbuscf_iattrdata = {
	"btbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata bthubcf_iattrdata = {
	"bthub", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata sunxicancf_iattrdata = {
	"sunxican", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata omap3prmcf_iattrdata = {
	"omap3prm", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata wsemuldisplaydevcf_iattrdata = {
	"wsemuldisplaydev", 2, {
		{ "console", "-1", -1 },
		{ "kbdmux", "1", 1 },
	}
};
static const struct cfiattrdata am3prcmcf_iattrdata = {
	"am3prcm", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata mpcorebuscf_iattrdata = {
	"mpcorebus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata tiotgcf_iattrdata = {
	"tiotg", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata hdmicecbuscf_iattrdata = {
	"hdmicecbus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata fdtcf_iattrdata = {
	"fdt", 1, {
		{ "pass", "10", 10 },
	}
};
static const struct cfiattrdata sunxidebecf_iattrdata = {
	"sunxidebe", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata iiccf_iattrdata = {
	"iic", 1, {
		{ "addr", "-1", -1 },
	}
};
static const struct cfiattrdata audiobuscf_iattrdata = {
	"audiobus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata videobuscf_iattrdata = {
	"videobus", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata ata_hlcf_iattrdata = {
	"ata_hl", 1, {
		{ "drive", "-1", -1 },
	}
};
static const struct cfiattrdata axp20xcf_iattrdata = {
	"axp20x", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata comcf_iattrdata = {
	"com", 0, {
		{ NULL, NULL, 0 },
	}
};
static const struct cfiattrdata usbroothubifcf_iattrdata = {
	"usbroothubif", 0, {
		{ NULL, NULL, 0 },
	}
};

static const struct cfiattrdata * const spkr_attrs[] = { &wsbelldevcf_iattrdata, NULL };
CFDRIVER_DECL(spkr, DV_DULL, spkr_attrs);

static const struct cfiattrdata * const audio_attrs[] = { &audiocf_iattrdata, NULL };
CFDRIVER_DECL(audio, DV_AUDIODEV, audio_attrs);

static const struct cfiattrdata * const midi_attrs[] = { &audiocf_iattrdata, NULL };
CFDRIVER_DECL(midi, DV_DULL, midi_attrs);

static const struct cfiattrdata * const hdaudio_attrs[] = { &hdaudiobuscf_iattrdata, NULL };
CFDRIVER_DECL(hdaudio, DV_DULL, hdaudio_attrs);

static const struct cfiattrdata * const hdafg_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(hdafg, DV_DULL, hdafg_attrs);

CFDRIVER_DECL(video, DV_DULL, NULL);

CFDRIVER_DECL(dtv, DV_DULL, NULL);

CFDRIVER_DECL(hdmicec, DV_DULL, NULL);

static const struct cfiattrdata * const iic_attrs[] = { &iiccf_iattrdata, NULL };
CFDRIVER_DECL(iic, DV_DULL, iic_attrs);

CFDRIVER_DECL(pcf8563rtc, DV_DULL, NULL);

CFDRIVER_DECL(seeprom, DV_DULL, NULL);

static const struct cfiattrdata * const tps65217pmic_attrs[] = { &tps65217pmiccf_iattrdata, NULL };
CFDRIVER_DECL(tps65217pmic, DV_DULL, tps65217pmic_attrs);

static const struct cfiattrdata * const tps65217reg_attrs[] = { &tps65217pmiccf_iattrdata, NULL };
CFDRIVER_DECL(tps65217reg, DV_DULL, tps65217reg_attrs);

static const struct cfiattrdata * const axp20x_attrs[] = { &axp20xcf_iattrdata, NULL };
CFDRIVER_DECL(axp20x, DV_DULL, axp20x_attrs);

static const struct cfiattrdata * const axp20xreg_attrs[] = { &axp20xcf_iattrdata, NULL };
CFDRIVER_DECL(axp20xreg, DV_DULL, axp20xreg_attrs);

CFDRIVER_DECL(axp22x, DV_DULL, NULL);

static const struct cfiattrdata * const axppmic_attrs[] = { &axppmiccf_iattrdata, NULL };
CFDRIVER_DECL(axppmic, DV_DULL, axppmic_attrs);

static const struct cfiattrdata * const axpreg_attrs[] = { &axppmiccf_iattrdata, NULL };
CFDRIVER_DECL(axpreg, DV_DULL, axpreg_attrs);

CFDRIVER_DECL(ac100ic, DV_DULL, NULL);

CFDRIVER_DECL(titemp, DV_DULL, NULL);

static const struct cfiattrdata * const as3722pmic_attrs[] = { &as3722pmiccf_iattrdata, NULL };
CFDRIVER_DECL(as3722pmic, DV_DULL, as3722pmic_attrs);

static const struct cfiattrdata * const as3722reg_attrs[] = { &as3722pmiccf_iattrdata, NULL };
CFDRIVER_DECL(as3722reg, DV_DULL, as3722reg_attrs);

static const struct cfiattrdata * const tcakp_attrs[] = { &wskbddevcf_iattrdata, NULL };
CFDRIVER_DECL(tcakp, DV_DULL, tcakp_attrs);

CFDRIVER_DECL(max77620pmic, DV_DULL, NULL);

CFDRIVER_DECL(tcagpio, DV_DULL, NULL);

CFDRIVER_DECL(sy8106a, DV_DULL, NULL);

CFDRIVER_DECL(twl, DV_DULL, NULL);

CFDRIVER_DECL(tdahdmi, DV_DULL, NULL);

static const struct cfiattrdata * const spi_attrs[] = { &spicf_iattrdata, NULL };
CFDRIVER_DECL(spi, DV_DULL, spi_attrs);

CFDRIVER_DECL(irframe, DV_DULL, NULL);

CFDRIVER_DECL(cir, DV_DULL, NULL);

CFDRIVER_DECL(ld, DV_DISK, NULL);

CFDRIVER_DECL(tlphy, DV_DULL, NULL);

CFDRIVER_DECL(nsphy, DV_DULL, NULL);

CFDRIVER_DECL(nsphyter, DV_DULL, NULL);

CFDRIVER_DECL(gentbi, DV_DULL, NULL);

CFDRIVER_DECL(glxtphy, DV_DULL, NULL);

CFDRIVER_DECL(gphyter, DV_DULL, NULL);

CFDRIVER_DECL(qsphy, DV_DULL, NULL);

CFDRIVER_DECL(inphy, DV_DULL, NULL);

CFDRIVER_DECL(iophy, DV_DULL, NULL);

CFDRIVER_DECL(exphy, DV_DULL, NULL);

CFDRIVER_DECL(lxtphy, DV_DULL, NULL);

CFDRIVER_DECL(makphy, DV_DULL, NULL);

CFDRIVER_DECL(icsphy, DV_DULL, NULL);

CFDRIVER_DECL(igphy, DV_DULL, NULL);

CFDRIVER_DECL(ikphy, DV_DULL, NULL);

CFDRIVER_DECL(sqphy, DV_DULL, NULL);

CFDRIVER_DECL(tqphy, DV_DULL, NULL);

CFDRIVER_DECL(pnaphy, DV_DULL, NULL);

CFDRIVER_DECL(rgephy, DV_DULL, NULL);

CFDRIVER_DECL(urlphy, DV_DULL, NULL);

CFDRIVER_DECL(ukphy, DV_DULL, NULL);

CFDRIVER_DECL(rlphy, DV_DULL, NULL);

CFDRIVER_DECL(ihphy, DV_DULL, NULL);

CFDRIVER_DECL(rdcphy, DV_DULL, NULL);

static const struct cfiattrdata * const awge_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(awge, DV_IFNET, awge_attrs);

static const struct cfiattrdata * const com_attrs[] = { &comcf_iattrdata, NULL };
CFDRIVER_DECL(com, DV_TTY, com_attrs);

static const struct cfiattrdata * const re_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(re, DV_IFNET, re_attrs);

static const struct cfiattrdata * const virtio_attrs[] = { &virtiocf_iattrdata, NULL };
CFDRIVER_DECL(virtio, DV_DULL, virtio_attrs);

CFDRIVER_DECL(vioif, DV_IFNET, NULL);

CFDRIVER_DECL(viornd, DV_DULL, NULL);

static const struct cfiattrdata * const vioscsi_attrs[] = { &scsicf_iattrdata, NULL };
CFDRIVER_DECL(vioscsi, DV_DULL, vioscsi_attrs);

static const struct cfiattrdata * const atabus_attrs[] = { &ata_hlcf_iattrdata, &atapicf_iattrdata, NULL };
CFDRIVER_DECL(atabus, DV_DULL, atabus_attrs);

static const struct cfiattrdata * const ahcisata_attrs[] = { &atacf_iattrdata, NULL };
CFDRIVER_DECL(ahcisata, DV_DULL, ahcisata_attrs);

static const struct cfiattrdata * const smsh_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(smsh, DV_IFNET, smsh_attrs);

CFDRIVER_DECL(wsdisplay, DV_DULL, NULL);

CFDRIVER_DECL(wskbd, DV_DULL, NULL);

CFDRIVER_DECL(wsmouse, DV_DULL, NULL);

static const struct cfiattrdata * const genfb_attrs[] = { &drmcf_iattrdata, &wsemuldisplaydevcf_iattrdata, NULL };
CFDRIVER_DECL(genfb, DV_DULL, genfb_attrs);

static const struct cfiattrdata * const ohci_attrs[] = { &usbuscf_iattrdata, NULL };
CFDRIVER_DECL(ohci, DV_DULL, ohci_attrs);

static const struct cfiattrdata * const ehci_attrs[] = { &usbuscf_iattrdata, NULL };
CFDRIVER_DECL(ehci, DV_DULL, ehci_attrs);

static const struct cfiattrdata * const xhci_attrs[] = { &usbuscf_iattrdata, NULL };
CFDRIVER_DECL(xhci, DV_DULL, xhci_attrs);

static const struct cfiattrdata * const motg_attrs[] = { &usbuscf_iattrdata, NULL };
CFDRIVER_DECL(motg, DV_DULL, motg_attrs);

static const struct cfiattrdata * const dwctwo_attrs[] = { &usbuscf_iattrdata, NULL };
CFDRIVER_DECL(dwctwo, DV_DULL, dwctwo_attrs);

static const struct cfiattrdata * const sdhc_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(sdhc, DV_DULL, sdhc_attrs);

static const struct cfiattrdata * const dwcmmc_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(dwcmmc, DV_DULL, dwcmmc_attrs);

CFDRIVER_DECL(plrtc, DV_DULL, NULL);

static const struct cfiattrdata * const aaci_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(aaci, DV_DULL, aaci_attrs);

static const struct cfiattrdata * const plkmi_attrs[] = { &pckbportcf_iattrdata, NULL };
CFDRIVER_DECL(plkmi, DV_DULL, plkmi_attrs);

static const struct cfiattrdata * const plgpio_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(plgpio, DV_DULL, plgpio_attrs);

static const struct cfiattrdata * const plmmc_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(plmmc, DV_DULL, plmmc_attrs);

CFDRIVER_DECL(radio, DV_DULL, NULL);

static const struct cfiattrdata * const nvme_attrs[] = { &nvmecf_iattrdata, NULL };
CFDRIVER_DECL(nvme, DV_DULL, nvme_attrs);

CFDRIVER_DECL(bwfm, DV_IFNET, NULL);

CFDRIVER_DECL(qemufwcfg, DV_DULL, NULL);

CFDRIVER_DECL(vnd, DV_DISK, NULL);

CFDRIVER_DECL(cgd, DV_DISK, NULL);

CFDRIVER_DECL(tap, DV_IFNET, NULL);

static const struct cfiattrdata * const gpio_attrs[] = { &gpiocf_iattrdata, NULL };
CFDRIVER_DECL(gpio, DV_DULL, gpio_attrs);

CFDRIVER_DECL(flash, DV_DISK, NULL);

static const struct cfiattrdata * const nand_attrs[] = { &flashbuscf_iattrdata, NULL };
CFDRIVER_DECL(nand, DV_DULL, nand_attrs);

CFDRIVER_DECL(athn, DV_IFNET, NULL);

static const struct cfiattrdata * const simplebus_attrs[] = { &simplebuscf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(simplebus, DV_DULL, simplebus_attrs);

CFDRIVER_DECL(fregulator, DV_DULL, NULL);

CFDRIVER_DECL(gregulator, DV_DULL, NULL);

CFDRIVER_DECL(fclock, DV_DULL, NULL);

CFDRIVER_DECL(ffclock, DV_DULL, NULL);

static const struct cfiattrdata * const gpiokeys_attrs[] = { &wskbddevcf_iattrdata, NULL };
CFDRIVER_DECL(gpiokeys, DV_DULL, gpiokeys_attrs);

CFDRIVER_DECL(gpioleds, DV_DULL, NULL);

CFDRIVER_DECL(connector, DV_DULL, NULL);

CFDRIVER_DECL(panel, DV_DULL, NULL);

static const struct cfiattrdata * const cpus_attrs[] = { &cpuscf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(cpus, DV_DULL, cpus_attrs);

CFDRIVER_DECL(mmcpwrseq, DV_DULL, NULL);

static const struct cfiattrdata * const syscon_attrs[] = { &sysconcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(syscon, DV_DULL, syscon_attrs);

CFDRIVER_DECL(pinctrl, DV_DULL, NULL);

CFDRIVER_DECL(pwmbacklight, DV_DULL, NULL);

CFDRIVER_DECL(pwmfan, DV_DULL, NULL);

static const struct cfiattrdata * const ausoc_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(ausoc, DV_DULL, ausoc_attrs);

CFDRIVER_DECL(dwcwdt, DV_DULL, NULL);

CFDRIVER_DECL(usbnopphy, DV_DULL, NULL);

CFDRIVER_DECL(psci, DV_DULL, NULL);

static const struct cfiattrdata * const cpu_attrs[] = { &cpucf_iattrdata, NULL };
CFDRIVER_DECL(cpu, DV_DULL, cpu_attrs);

CFDRIVER_DECL(wd, DV_DISK, NULL);

static const struct cfiattrdata * const bthub_attrs[] = { &bthubcf_iattrdata, NULL };
CFDRIVER_DECL(bthub, DV_DULL, bthub_attrs);

static const struct cfiattrdata * const pci_attrs[] = { &pcicf_iattrdata, NULL };
CFDRIVER_DECL(pci, DV_DULL, pci_attrs);

static const struct cfiattrdata * const ppb_attrs[] = { &pcibuscf_iattrdata, NULL };
CFDRIVER_DECL(ppb, DV_DULL, ppb_attrs);

static const struct cfiattrdata * const sdmmc_attrs[] = { &sdmmccf_iattrdata, NULL };
CFDRIVER_DECL(sdmmc, DV_DULL, sdmmc_attrs);

static const struct cfiattrdata * const scsibus_attrs[] = { &scsibuscf_iattrdata, NULL };
CFDRIVER_DECL(scsibus, DV_DULL, scsibus_attrs);

static const struct cfiattrdata * const atapibus_attrs[] = { &atapibuscf_iattrdata, NULL };
CFDRIVER_DECL(atapibus, DV_DULL, atapibus_attrs);

CFDRIVER_DECL(cd, DV_DISK, NULL);

CFDRIVER_DECL(ch, DV_DULL, NULL);

CFDRIVER_DECL(sd, DV_DISK, NULL);

CFDRIVER_DECL(st, DV_TAPE, NULL);

CFDRIVER_DECL(ses, DV_DULL, NULL);

CFDRIVER_DECL(ss, DV_DULL, NULL);

CFDRIVER_DECL(uk, DV_DULL, NULL);

static const struct cfiattrdata * const usb_attrs[] = { &usbroothubifcf_iattrdata, NULL };
CFDRIVER_DECL(usb, DV_DULL, usb_attrs);

static const struct cfiattrdata * const uhub_attrs[] = { &usbififcf_iattrdata, &usbdevifcf_iattrdata, NULL };
CFDRIVER_DECL(uhub, DV_DULL, uhub_attrs);

static const struct cfiattrdata * const uaudio_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(uaudio, DV_DULL, uaudio_attrs);

static const struct cfiattrdata * const umidi_attrs[] = { &midibuscf_iattrdata, NULL };
CFDRIVER_DECL(umidi, DV_DULL, umidi_attrs);

CFDRIVER_DECL(ucom, DV_DULL, NULL);

CFDRIVER_DECL(ugen, DV_DULL, NULL);

CFDRIVER_DECL(ugenif, DV_DULL, NULL);

static const struct cfiattrdata * const uhidev_attrs[] = { &uhidbuscf_iattrdata, NULL };
CFDRIVER_DECL(uhidev, DV_DULL, uhidev_attrs);

CFDRIVER_DECL(uhid, DV_DULL, NULL);

static const struct cfiattrdata * const ukbd_attrs[] = { &wskbddevcf_iattrdata, NULL };
CFDRIVER_DECL(ukbd, DV_DULL, ukbd_attrs);

static const struct cfiattrdata * const ums_attrs[] = { &wsmousedevcf_iattrdata, NULL };
CFDRIVER_DECL(ums, DV_DULL, ums_attrs);

static const struct cfiattrdata * const uts_attrs[] = { &wsmousedevcf_iattrdata, NULL };
CFDRIVER_DECL(uts, DV_DULL, uts_attrs);

static const struct cfiattrdata * const uep_attrs[] = { &wsmousedevcf_iattrdata, NULL };
CFDRIVER_DECL(uep, DV_DULL, uep_attrs);

CFDRIVER_DECL(ucycom, DV_DULL, NULL);

CFDRIVER_DECL(ulpt, DV_DULL, NULL);

static const struct cfiattrdata * const umass_attrs[] = { &ata_hlcf_iattrdata, &atapicf_iattrdata, &scsicf_iattrdata, NULL };
CFDRIVER_DECL(umass, DV_DULL, umass_attrs);

static const struct cfiattrdata * const uirda_attrs[] = { &irbuscf_iattrdata, NULL };
CFDRIVER_DECL(uirda, DV_DULL, uirda_attrs);

static const struct cfiattrdata * const stuirda_attrs[] = { &irbuscf_iattrdata, NULL };
CFDRIVER_DECL(stuirda, DV_DULL, stuirda_attrs);

static const struct cfiattrdata * const ustir_attrs[] = { &irbuscf_iattrdata, NULL };
CFDRIVER_DECL(ustir, DV_DULL, ustir_attrs);

static const struct cfiattrdata * const irmce_attrs[] = { &irbuscf_iattrdata, NULL };
CFDRIVER_DECL(irmce, DV_DULL, irmce_attrs);

static const struct cfiattrdata * const ubt_attrs[] = { &btbuscf_iattrdata, NULL };
CFDRIVER_DECL(ubt, DV_DULL, ubt_attrs);

CFDRIVER_DECL(aubtfwl, DV_DULL, NULL);

static const struct cfiattrdata * const pseye_attrs[] = { &videobuscf_iattrdata, NULL };
CFDRIVER_DECL(pseye, DV_DULL, pseye_attrs);

static const struct cfiattrdata * const uvideo_attrs[] = { &videobuscf_iattrdata, NULL };
CFDRIVER_DECL(uvideo, DV_DULL, uvideo_attrs);

static const struct cfiattrdata * const auvitek_attrs[] = { &usbififcf_iattrdata, &i2cbuscf_iattrdata, &dtvbuscf_iattrdata, &videobuscf_iattrdata, NULL };
CFDRIVER_DECL(auvitek, DV_DULL, auvitek_attrs);

static const struct cfiattrdata * const emdtv_attrs[] = { &irbuscf_iattrdata, &dtvbuscf_iattrdata, NULL };
CFDRIVER_DECL(emdtv, DV_DULL, emdtv_attrs);

CFDRIVER_DECL(umodeswitch, DV_DULL, NULL);

CFDRIVER_DECL(urio, DV_DULL, NULL);

CFDRIVER_DECL(uipad, DV_DULL, NULL);

CFDRIVER_DECL(uberry, DV_DULL, NULL);

static const struct cfiattrdata * const uvisor_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uvisor, DV_DULL, uvisor_attrs);

static const struct cfiattrdata * const ugensa_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(ugensa, DV_DULL, ugensa_attrs);

static const struct cfiattrdata * const u3g_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(u3g, DV_DULL, u3g_attrs);

CFDRIVER_DECL(uyap, DV_DULL, NULL);

static const struct cfiattrdata * const udsbr_attrs[] = { &radiodevcf_iattrdata, NULL };
CFDRIVER_DECL(udsbr, DV_DULL, udsbr_attrs);

static const struct cfiattrdata * const slurm_attrs[] = { &radiodevcf_iattrdata, NULL };
CFDRIVER_DECL(slurm, DV_DULL, slurm_attrs);

CFDRIVER_DECL(uthum, DV_DULL, NULL);

static const struct cfiattrdata * const aue_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(aue, DV_IFNET, aue_attrs);

CFDRIVER_DECL(cdce, DV_IFNET, NULL);

CFDRIVER_DECL(cue, DV_IFNET, NULL);

CFDRIVER_DECL(kue, DV_IFNET, NULL);

CFDRIVER_DECL(upl, DV_IFNET, NULL);

static const struct cfiattrdata * const url_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(url, DV_IFNET, url_attrs);

static const struct cfiattrdata * const axe_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(axe, DV_IFNET, axe_attrs);

static const struct cfiattrdata * const axen_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(axen, DV_IFNET, axen_attrs);

static const struct cfiattrdata * const mue_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(mue, DV_IFNET, mue_attrs);

static const struct cfiattrdata * const udav_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(udav, DV_IFNET, udav_attrs);

CFDRIVER_DECL(otus, DV_IFNET, NULL);

static const struct cfiattrdata * const ure_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(ure, DV_IFNET, ure_attrs);

static const struct cfiattrdata * const umodem_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(umodem, DV_DULL, umodem_attrs);

static const struct cfiattrdata * const uftdi_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uftdi, DV_DULL, uftdi_attrs);

static const struct cfiattrdata * const uplcom_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uplcom, DV_DULL, uplcom_attrs);

static const struct cfiattrdata * const umct_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(umct, DV_DULL, umct_attrs);

static const struct cfiattrdata * const umcs_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(umcs, DV_DULL, umcs_attrs);

static const struct cfiattrdata * const uvscom_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uvscom, DV_DULL, uvscom_attrs);

static const struct cfiattrdata * const uxrcom_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uxrcom, DV_DULL, uxrcom_attrs);

static const struct cfiattrdata * const ubsa_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(ubsa, DV_DULL, ubsa_attrs);

static const struct cfiattrdata * const uipaq_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uipaq, DV_DULL, uipaq_attrs);

static const struct cfiattrdata * const ukyopon_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(ukyopon, DV_DULL, ukyopon_attrs);

static const struct cfiattrdata * const uark_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uark, DV_DULL, uark_attrs);

static const struct cfiattrdata * const uslsa_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uslsa, DV_DULL, uslsa_attrs);

static const struct cfiattrdata * const uchcom_attrs[] = { &ucombuscf_iattrdata, NULL };
CFDRIVER_DECL(uchcom, DV_DULL, uchcom_attrs);

static const struct cfiattrdata * const usscanner_attrs[] = { &scsicf_iattrdata, NULL };
CFDRIVER_DECL(usscanner, DV_DULL, usscanner_attrs);

CFDRIVER_DECL(atu, DV_IFNET, NULL);

CFDRIVER_DECL(upgt, DV_IFNET, NULL);

static const struct cfiattrdata * const usmsc_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(usmsc, DV_IFNET, usmsc_attrs);

CFDRIVER_DECL(ural, DV_IFNET, NULL);

CFDRIVER_DECL(rum, DV_IFNET, NULL);

CFDRIVER_DECL(utoppy, DV_DULL, NULL);

CFDRIVER_DECL(zyd, DV_IFNET, NULL);

static const struct cfiattrdata * const udl_attrs[] = { &wsemuldisplaydevcf_iattrdata, NULL };
CFDRIVER_DECL(udl, DV_DULL, udl_attrs);

CFDRIVER_DECL(uhso, DV_IFNET, NULL);

CFDRIVER_DECL(urndis, DV_IFNET, NULL);

CFDRIVER_DECL(urtwn, DV_IFNET, NULL);

CFDRIVER_DECL(urtw, DV_IFNET, NULL);

CFDRIVER_DECL(run, DV_IFNET, NULL);

static const struct cfiattrdata * const udsir_attrs[] = { &irbuscf_iattrdata, NULL };
CFDRIVER_DECL(udsir, DV_DULL, udsir_attrs);

static const struct cfiattrdata * const plcom_attrs[] = { &plcomcf_iattrdata, NULL };
CFDRIVER_DECL(plcom, DV_TTY, plcom_attrs);

CFDRIVER_DECL(armgic, DV_DULL, NULL);

CFDRIVER_DECL(arml2cc, DV_DULL, NULL);

CFDRIVER_DECL(armgtmr, DV_DULL, NULL);

CFDRIVER_DECL(arma9tmr, DV_DULL, NULL);

CFDRIVER_DECL(arma9ptmr, DV_DULL, NULL);

static const struct cfiattrdata * const pckbd_attrs[] = { &wskbddevcf_iattrdata, NULL };
CFDRIVER_DECL(pckbd, DV_DULL, pckbd_attrs);

static const struct cfiattrdata * const pms_attrs[] = { &wsmousedevcf_iattrdata, NULL };
CFDRIVER_DECL(pms, DV_DULL, pms_attrs);

static const struct cfiattrdata * const armfdt_attrs[] = { &armfdtcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(armfdt, DV_DULL, armfdt_attrs);

CFDRIVER_DECL(cpufreqdt, DV_DULL, NULL);

static const struct cfiattrdata * const a9tmr_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(a9tmr, DV_DULL, a9tmr_attrs);

static const struct cfiattrdata * const a9ptmr_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(a9ptmr, DV_DULL, a9ptmr_attrs);

static const struct cfiattrdata * const gtmr_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(gtmr, DV_DULL, gtmr_attrs);

static const struct cfiattrdata * const gic_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(gic, DV_DULL, gic_attrs);

static const struct cfiattrdata * const l2cc_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(l2cc, DV_DULL, l2cc_attrs);

static const struct cfiattrdata * const pcihost_attrs[] = { &pcibuscf_iattrdata, NULL };
CFDRIVER_DECL(pcihost, DV_DULL, pcihost_attrs);

CFDRIVER_DECL(armpmu, DV_DULL, NULL);

CFDRIVER_DECL(cycvclkmgr, DV_DULL, NULL);

CFDRIVER_DECL(cycvrstmgr, DV_DULL, NULL);

CFDRIVER_DECL(meson8bclkc, DV_DULL, NULL);

CFDRIVER_DECL(mesonresets, DV_DULL, NULL);

CFDRIVER_DECL(mesonuart, DV_DULL, NULL);

static const struct cfiattrdata * const mesonfb_attrs[] = { &wsemuldisplaydevcf_iattrdata, NULL };
CFDRIVER_DECL(mesonfb, DV_DULL, mesonfb_attrs);

static const struct cfiattrdata * const mesonpinctrl_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(mesonpinctrl, DV_DULL, mesonpinctrl_attrs);

static const struct cfiattrdata * const mesonsdhc_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(mesonsdhc, DV_DULL, mesonsdhc_attrs);

static const struct cfiattrdata * const mesonsdio_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(mesonsdio, DV_DULL, mesonsdio_attrs);

CFDRIVER_DECL(mesonusbphy, DV_DULL, NULL);

CFDRIVER_DECL(mesonrtc, DV_DULL, NULL);

CFDRIVER_DECL(mesonrng, DV_DULL, NULL);

CFDRIVER_DECL(mesonwdt, DV_DULL, NULL);

CFDRIVER_DECL(bcmicu, DV_DULL, NULL);

static const struct cfiattrdata * const bcmmbox_attrs[] = { &bcmmboxbuscf_iattrdata, NULL };
CFDRIVER_DECL(bcmmbox, DV_DULL, bcmmbox_attrs);

CFDRIVER_DECL(bcmpmwdog, DV_DULL, NULL);

CFDRIVER_DECL(bcmrng, DV_DULL, NULL);

CFDRIVER_DECL(bcmaux, DV_DULL, NULL);

static const struct cfiattrdata * const bcmsdhost_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(bcmsdhost, DV_DULL, bcmsdhost_attrs);

CFDRIVER_DECL(bcmdmac, DV_DULL, NULL);

static const struct cfiattrdata * const bcmspi_attrs[] = { &spibuscf_iattrdata, NULL };
CFDRIVER_DECL(bcmspi, DV_DULL, bcmspi_attrs);

static const struct cfiattrdata * const bsciic_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(bsciic, DV_DULL, bsciic_attrs);

static const struct cfiattrdata * const vchiq_attrs[] = { &vchiqbuscf_iattrdata, NULL };
CFDRIVER_DECL(vchiq, DV_DULL, vchiq_attrs);

static const struct cfiattrdata * const vcaudio_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(vcaudio, DV_DULL, vcaudio_attrs);

static const struct cfiattrdata * const bcmgpio_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(bcmgpio, DV_DULL, bcmgpio_attrs);

CFDRIVER_DECL(bcmcprman, DV_DULL, NULL);

CFDRIVER_DECL(vcmbox, DV_DULL, NULL);

CFDRIVER_DECL(tegra124cpu, DV_DULL, NULL);

CFDRIVER_DECL(tegralic, DV_DULL, NULL);

CFDRIVER_DECL(tegramc, DV_DULL, NULL);

CFDRIVER_DECL(tegrapmc, DV_DULL, NULL);

CFDRIVER_DECL(tegrafuse, DV_DULL, NULL);

CFDRIVER_DECL(tegra124car, DV_DULL, NULL);

CFDRIVER_DECL(tegra210car, DV_DULL, NULL);

static const struct cfiattrdata * const tegragpio_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(tegragpio, DV_DULL, tegragpio_attrs);

CFDRIVER_DECL(tegratimer, DV_DULL, NULL);

CFDRIVER_DECL(tegrapinmux, DV_DULL, NULL);

CFDRIVER_DECL(tegraapbdma, DV_DULL, NULL);

CFDRIVER_DECL(tegra124xpad, DV_DULL, NULL);

static const struct cfiattrdata * const tegra210xpad_attrs[] = { &tegra210xpadcf_iattrdata, NULL };
CFDRIVER_DECL(tegra210xpad, DV_DULL, tegra210xpad_attrs);

static const struct cfiattrdata * const tegra210xphy_attrs[] = { &tegra210xpadcf_iattrdata, NULL };
CFDRIVER_DECL(tegra210xphy, DV_DULL, tegra210xphy_attrs);

static const struct cfiattrdata * const tegrai2c_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(tegrai2c, DV_DULL, tegrai2c_attrs);

CFDRIVER_DECL(tegrartc, DV_DULL, NULL);

CFDRIVER_DECL(tegrausbphy, DV_DULL, NULL);

CFDRIVER_DECL(tegrasoctherm, DV_DULL, NULL);

static const struct cfiattrdata * const tegrapcie_attrs[] = { &pcibuscf_iattrdata, NULL };
CFDRIVER_DECL(tegrapcie, DV_DULL, tegrapcie_attrs);

static const struct cfiattrdata * const tegracec_attrs[] = { &hdmicecbuscf_iattrdata, NULL };
CFDRIVER_DECL(tegracec, DV_DULL, tegracec_attrs);

CFDRIVER_DECL(exyointr, DV_DULL, NULL);

static const struct cfiattrdata * const mct_attrs[] = { &mpcorebuscf_iattrdata, NULL };
CFDRIVER_DECL(mct, DV_DULL, mct_attrs);

CFDRIVER_DECL(exuart, DV_DULL, NULL);

static const struct cfiattrdata * const exyopctl_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(exyopctl, DV_DULL, exyopctl_attrs);

CFDRIVER_DECL(exusbphy, DV_DULL, NULL);

CFDRIVER_DECL(exusbdrdphy, DV_DULL, NULL);

static const struct cfiattrdata * const exyoi2c_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(exyoi2c, DV_DULL, exyoi2c_attrs);

CFDRIVER_DECL(expwm, DV_DULL, NULL);

CFDRIVER_DECL(exy5422clk, DV_DULL, NULL);

CFDRIVER_DECL(exy5410clk, DV_DULL, NULL);

CFDRIVER_DECL(sun4ia10ccu, DV_DULL, NULL);

CFDRIVER_DECL(sun5ia13ccu, DV_DULL, NULL);

CFDRIVER_DECL(sun6ia31ccu, DV_DULL, NULL);

CFDRIVER_DECL(sun8ia83tccu, DV_DULL, NULL);

CFDRIVER_DECL(sun8ih3ccu, DV_DULL, NULL);

CFDRIVER_DECL(sun8ih3rccu, DV_DULL, NULL);

CFDRIVER_DECL(sun9ia80ccu, DV_DULL, NULL);

CFDRIVER_DECL(sunxiresets, DV_DULL, NULL);

CFDRIVER_DECL(sunxigates, DV_DULL, NULL);

CFDRIVER_DECL(sunxigmacclk, DV_DULL, NULL);

CFDRIVER_DECL(sun9immcclk, DV_DULL, NULL);

CFDRIVER_DECL(sun9iusbclk, DV_DULL, NULL);

CFDRIVER_DECL(sun9icpusclk, DV_DULL, NULL);

CFDRIVER_DECL(sun8iapbclk, DV_DULL, NULL);

CFDRIVER_DECL(sunxiintc, DV_DULL, NULL);

CFDRIVER_DECL(sunxinmi, DV_DULL, NULL);

static const struct cfiattrdata * const sunxigpio_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(sunxigpio, DV_DULL, sunxigpio_attrs);

CFDRIVER_DECL(sunxipwm, DV_DULL, NULL);

static const struct cfiattrdata * const sunximmc_attrs[] = { &sdmmcbuscf_iattrdata, NULL };
CFDRIVER_DECL(sunximmc, DV_DULL, sunximmc_attrs);

CFDRIVER_DECL(sunxiusbphy, DV_DULL, NULL);

CFDRIVER_DECL(sunxiusb3phy, DV_DULL, NULL);

CFDRIVER_DECL(sun9iusbphy, DV_DULL, NULL);

static const struct cfiattrdata * const sunxitwi_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(sunxitwi, DV_DULL, sunxitwi_attrs);

static const struct cfiattrdata * const sunxirsb_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(sunxirsb, DV_DULL, sunxirsb_attrs);

CFDRIVER_DECL(sunxirtc, DV_DULL, NULL);

static const struct cfiattrdata * const emac_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(emac, DV_IFNET, emac_attrs);

CFDRIVER_DECL(sunxitimer, DV_DULL, NULL);

CFDRIVER_DECL(sunxihstimer, DV_DULL, NULL);

CFDRIVER_DECL(sunxiwdt, DV_DULL, NULL);

CFDRIVER_DECL(sun4idma, DV_DULL, NULL);

CFDRIVER_DECL(sun6idma, DV_DULL, NULL);

static const struct cfiattrdata * const sunxicodec_attrs[] = { &audiobuscf_iattrdata, NULL };
CFDRIVER_DECL(sunxicodec, DV_DULL, sunxicodec_attrs);

CFDRIVER_DECL(sun8icodec, DV_DULL, NULL);

CFDRIVER_DECL(h3codec, DV_DULL, NULL);

CFDRIVER_DECL(a64acodec, DV_DULL, NULL);

CFDRIVER_DECL(sunxii2s, DV_DULL, NULL);

CFDRIVER_DECL(sunxitcon, DV_DULL, NULL);

static const struct cfiattrdata * const sunxidebe_attrs[] = { &sunxidebecf_iattrdata, NULL };
CFDRIVER_DECL(sunxidebe, DV_DULL, sunxidebe_attrs);

CFDRIVER_DECL(sunxihdmi, DV_DULL, NULL);

CFDRIVER_DECL(sunxidep, DV_DULL, NULL);

static const struct cfiattrdata * const sunxits_attrs[] = { &wsmousedevcf_iattrdata, NULL };
CFDRIVER_DECL(sunxits, DV_DULL, sunxits_attrs);

CFDRIVER_DECL(sunxisid, DV_DULL, NULL);

CFDRIVER_DECL(sunxithermal, DV_DULL, NULL);

CFDRIVER_DECL(sunxisramc, DV_DULL, NULL);

static const struct cfiattrdata * const sunxinand_attrs[] = { &nandbuscf_iattrdata, NULL };
CFDRIVER_DECL(sunxinand, DV_DULL, sunxinand_attrs);

static const struct cfiattrdata * const sun6ispi_attrs[] = { &spibuscf_iattrdata, NULL };
CFDRIVER_DECL(sun6ispi, DV_DULL, sun6ispi_attrs);

static const struct cfiattrdata * const sunxican_attrs[] = { &sunxicancf_iattrdata, NULL };
CFDRIVER_DECL(sunxican, DV_IFNET, sunxican_attrs);

CFDRIVER_DECL(sunxilradc, DV_DULL, NULL);

CFDRIVER_DECL(omapintc, DV_DULL, NULL);

static const struct cfiattrdata * const tisysc_attrs[] = { &tisysccf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(tisysc, DV_DULL, tisysc_attrs);

static const struct cfiattrdata * const am3prcm_attrs[] = { &am3prcmcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(am3prcm, DV_DULL, am3prcm_attrs);

static const struct cfiattrdata * const omap3cm_attrs[] = { &omap3cmcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(omap3cm, DV_DULL, omap3cm_attrs);

static const struct cfiattrdata * const omap3prm_attrs[] = { &omap3prmcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(omap3prm, DV_DULL, omap3prm_attrs);

CFDRIVER_DECL(timuxclk, DV_DULL, NULL);

CFDRIVER_DECL(tidivclk, DV_DULL, NULL);

CFDRIVER_DECL(tidpllclk, DV_DULL, NULL);

CFDRIVER_DECL(omaptimer, DV_DULL, NULL);

static const struct cfiattrdata * const tigpio_attrs[] = { &gpiobuscf_iattrdata, NULL };
CFDRIVER_DECL(tigpio, DV_DULL, tigpio_attrs);

static const struct cfiattrdata * const tiiic_attrs[] = { &i2cbuscf_iattrdata, NULL };
CFDRIVER_DECL(tiiic, DV_DULL, tiiic_attrs);

static const struct cfiattrdata * const cpsw_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(cpsw, DV_IFNET, cpsw_attrs);

CFDRIVER_DECL(tiedma, DV_DULL, NULL);

CFDRIVER_DECL(titptc, DV_DULL, NULL);

static const struct cfiattrdata * const tiotg_attrs[] = { &tiotgcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(tiotg, DV_DULL, tiotg_attrs);

static const struct cfiattrdata * const tiusb_attrs[] = { &tiusbcf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(tiusb, DV_DULL, tiusb_attrs);

CFDRIVER_DECL(tiusbtll, DV_DULL, NULL);

CFDRIVER_DECL(tirng, DV_DULL, NULL);

static const struct cfiattrdata * const omapfb_attrs[] = { &wsemuldisplaydevcf_iattrdata, NULL };
CFDRIVER_DECL(omapfb, DV_DULL, omapfb_attrs);

static const struct cfiattrdata * const tilcdc_attrs[] = { &tilcdcfbbuscf_iattrdata, NULL };
CFDRIVER_DECL(tilcdc, DV_DULL, tilcdc_attrs);

static const struct cfiattrdata * const tifb_attrs[] = { &wsemuldisplaydevcf_iattrdata, &tilcdcfbbuscf_iattrdata, NULL };
CFDRIVER_DECL(tifb, DV_DULL, tifb_attrs);

static const struct cfiattrdata * const tigpmc_attrs[] = { &tigpmccf_iattrdata, &fdtcf_iattrdata, NULL };
CFDRIVER_DECL(tigpmc, DV_DULL, tigpmc_attrs);

static const struct cfiattrdata * const omapnand_attrs[] = { &nandbuscf_iattrdata, NULL };
CFDRIVER_DECL(omapnand, DV_DULL, omapnand_attrs);

CFDRIVER_DECL(tiwdt, DV_DULL, NULL);

CFDRIVER_DECL(vxsysreg, DV_DULL, NULL);

CFDRIVER_DECL(zynquart, DV_DULL, NULL);

static const struct cfiattrdata * const cemac_attrs[] = { &miicf_iattrdata, NULL };
CFDRIVER_DECL(cemac, DV_IFNET, cemac_attrs);


struct cfdriver * const cfdriver_list_initial[] = {
	&spkr_cd,
	&audio_cd,
	&midi_cd,
	&hdaudio_cd,
	&hdafg_cd,
	&video_cd,
	&dtv_cd,
	&hdmicec_cd,
	&iic_cd,
	&pcf8563rtc_cd,
	&seeprom_cd,
	&tps65217pmic_cd,
	&tps65217reg_cd,
	&axp20x_cd,
	&axp20xreg_cd,
	&axp22x_cd,
	&axppmic_cd,
	&axpreg_cd,
	&ac100ic_cd,
	&titemp_cd,
	&as3722pmic_cd,
	&as3722reg_cd,
	&tcakp_cd,
	&max77620pmic_cd,
	&tcagpio_cd,
	&sy8106a_cd,
	&twl_cd,
	&tdahdmi_cd,
	&spi_cd,
	&irframe_cd,
	&cir_cd,
	&ld_cd,
	&tlphy_cd,
	&nsphy_cd,
	&nsphyter_cd,
	&gentbi_cd,
	&glxtphy_cd,
	&gphyter_cd,
	&qsphy_cd,
	&inphy_cd,
	&iophy_cd,
	&exphy_cd,
	&lxtphy_cd,
	&makphy_cd,
	&icsphy_cd,
	&igphy_cd,
	&ikphy_cd,
	&sqphy_cd,
	&tqphy_cd,
	&pnaphy_cd,
	&rgephy_cd,
	&urlphy_cd,
	&ukphy_cd,
	&rlphy_cd,
	&ihphy_cd,
	&rdcphy_cd,
	&awge_cd,
	&com_cd,
	&re_cd,
	&virtio_cd,
	&vioif_cd,
	&viornd_cd,
	&vioscsi_cd,
	&atabus_cd,
	&ahcisata_cd,
	&smsh_cd,
	&wsdisplay_cd,
	&wskbd_cd,
	&wsmouse_cd,
	&genfb_cd,
	&ohci_cd,
	&ehci_cd,
	&xhci_cd,
	&motg_cd,
	&dwctwo_cd,
	&sdhc_cd,
	&dwcmmc_cd,
	&plrtc_cd,
	&aaci_cd,
	&plkmi_cd,
	&plgpio_cd,
	&plmmc_cd,
	&radio_cd,
	&nvme_cd,
	&bwfm_cd,
	&qemufwcfg_cd,
	&vnd_cd,
	&cgd_cd,
	&tap_cd,
	&gpio_cd,
	&flash_cd,
	&nand_cd,
	&athn_cd,
	&simplebus_cd,
	&fregulator_cd,
	&gregulator_cd,
	&fclock_cd,
	&ffclock_cd,
	&gpiokeys_cd,
	&gpioleds_cd,
	&connector_cd,
	&panel_cd,
	&cpus_cd,
	&mmcpwrseq_cd,
	&syscon_cd,
	&pinctrl_cd,
	&pwmbacklight_cd,
	&pwmfan_cd,
	&ausoc_cd,
	&dwcwdt_cd,
	&usbnopphy_cd,
	&psci_cd,
	&cpu_cd,
	&wd_cd,
	&bthub_cd,
	&pci_cd,
	&ppb_cd,
	&sdmmc_cd,
	&scsibus_cd,
	&atapibus_cd,
	&cd_cd,
	&ch_cd,
	&sd_cd,
	&st_cd,
	&ses_cd,
	&ss_cd,
	&uk_cd,
	&usb_cd,
	&uhub_cd,
	&uaudio_cd,
	&umidi_cd,
	&ucom_cd,
	&ugen_cd,
	&ugenif_cd,
	&uhidev_cd,
	&uhid_cd,
	&ukbd_cd,
	&ums_cd,
	&uts_cd,
	&uep_cd,
	&ucycom_cd,
	&ulpt_cd,
	&umass_cd,
	&uirda_cd,
	&stuirda_cd,
	&ustir_cd,
	&irmce_cd,
	&ubt_cd,
	&aubtfwl_cd,
	&pseye_cd,
	&uvideo_cd,
	&auvitek_cd,
	&emdtv_cd,
	&umodeswitch_cd,
	&urio_cd,
	&uipad_cd,
	&uberry_cd,
	&uvisor_cd,
	&ugensa_cd,
	&u3g_cd,
	&uyap_cd,
	&udsbr_cd,
	&slurm_cd,
	&uthum_cd,
	&aue_cd,
	&cdce_cd,
	&cue_cd,
	&kue_cd,
	&upl_cd,
	&url_cd,
	&axe_cd,
	&axen_cd,
	&mue_cd,
	&udav_cd,
	&otus_cd,
	&ure_cd,
	&umodem_cd,
	&uftdi_cd,
	&uplcom_cd,
	&umct_cd,
	&umcs_cd,
	&uvscom_cd,
	&uxrcom_cd,
	&ubsa_cd,
	&uipaq_cd,
	&ukyopon_cd,
	&uark_cd,
	&uslsa_cd,
	&uchcom_cd,
	&usscanner_cd,
	&atu_cd,
	&upgt_cd,
	&usmsc_cd,
	&ural_cd,
	&rum_cd,
	&utoppy_cd,
	&zyd_cd,
	&udl_cd,
	&uhso_cd,
	&urndis_cd,
	&urtwn_cd,
	&urtw_cd,
	&run_cd,
	&udsir_cd,
	&plcom_cd,
	&armgic_cd,
	&arml2cc_cd,
	&armgtmr_cd,
	&arma9tmr_cd,
	&arma9ptmr_cd,
	&pckbd_cd,
	&pms_cd,
	&armfdt_cd,
	&cpufreqdt_cd,
	&a9tmr_cd,
	&a9ptmr_cd,
	&gtmr_cd,
	&gic_cd,
	&l2cc_cd,
	&pcihost_cd,
	&armpmu_cd,
	&cycvclkmgr_cd,
	&cycvrstmgr_cd,
	&meson8bclkc_cd,
	&mesonresets_cd,
	&mesonuart_cd,
	&mesonfb_cd,
	&mesonpinctrl_cd,
	&mesonsdhc_cd,
	&mesonsdio_cd,
	&mesonusbphy_cd,
	&mesonrtc_cd,
	&mesonrng_cd,
	&mesonwdt_cd,
	&bcmicu_cd,
	&bcmmbox_cd,
	&bcmpmwdog_cd,
	&bcmrng_cd,
	&bcmaux_cd,
	&bcmsdhost_cd,
	&bcmdmac_cd,
	&bcmspi_cd,
	&bsciic_cd,
	&vchiq_cd,
	&vcaudio_cd,
	&bcmgpio_cd,
	&bcmcprman_cd,
	&vcmbox_cd,
	&tegra124cpu_cd,
	&tegralic_cd,
	&tegramc_cd,
	&tegrapmc_cd,
	&tegrafuse_cd,
	&tegra124car_cd,
	&tegra210car_cd,
	&tegragpio_cd,
	&tegratimer_cd,
	&tegrapinmux_cd,
	&tegraapbdma_cd,
	&tegra124xpad_cd,
	&tegra210xpad_cd,
	&tegra210xphy_cd,
	&tegrai2c_cd,
	&tegrartc_cd,
	&tegrausbphy_cd,
	&tegrasoctherm_cd,
	&tegrapcie_cd,
	&tegracec_cd,
	&exyointr_cd,
	&mct_cd,
	&exuart_cd,
	&exyopctl_cd,
	&exusbphy_cd,
	&exusbdrdphy_cd,
	&exyoi2c_cd,
	&expwm_cd,
	&exy5422clk_cd,
	&exy5410clk_cd,
	&sun4ia10ccu_cd,
	&sun5ia13ccu_cd,
	&sun6ia31ccu_cd,
	&sun8ia83tccu_cd,
	&sun8ih3ccu_cd,
	&sun8ih3rccu_cd,
	&sun9ia80ccu_cd,
	&sunxiresets_cd,
	&sunxigates_cd,
	&sunxigmacclk_cd,
	&sun9immcclk_cd,
	&sun9iusbclk_cd,
	&sun9icpusclk_cd,
	&sun8iapbclk_cd,
	&sunxiintc_cd,
	&sunxinmi_cd,
	&sunxigpio_cd,
	&sunxipwm_cd,
	&sunximmc_cd,
	&sunxiusbphy_cd,
	&sunxiusb3phy_cd,
	&sun9iusbphy_cd,
	&sunxitwi_cd,
	&sunxirsb_cd,
	&sunxirtc_cd,
	&emac_cd,
	&sunxitimer_cd,
	&sunxihstimer_cd,
	&sunxiwdt_cd,
	&sun4idma_cd,
	&sun6idma_cd,
	&sunxicodec_cd,
	&sun8icodec_cd,
	&h3codec_cd,
	&a64acodec_cd,
	&sunxii2s_cd,
	&sunxitcon_cd,
	&sunxidebe_cd,
	&sunxihdmi_cd,
	&sunxidep_cd,
	&sunxits_cd,
	&sunxisid_cd,
	&sunxithermal_cd,
	&sunxisramc_cd,
	&sunxinand_cd,
	&sun6ispi_cd,
	&sunxican_cd,
	&sunxilradc_cd,
	&omapintc_cd,
	&tisysc_cd,
	&am3prcm_cd,
	&omap3cm_cd,
	&omap3prm_cd,
	&timuxclk_cd,
	&tidivclk_cd,
	&tidpllclk_cd,
	&omaptimer_cd,
	&tigpio_cd,
	&tiiic_cd,
	&cpsw_cd,
	&tiedma_cd,
	&titptc_cd,
	&tiotg_cd,
	&tiusb_cd,
	&tiusbtll_cd,
	&tirng_cd,
	&omapfb_cd,
	&tilcdc_cd,
	&tifb_cd,
	&tigpmc_cd,
	&omapnand_cd,
	&tiwdt_cd,
	&vxsysreg_cd,
	&zynquart_cd,
	&cemac_cd,
	NULL
};

extern struct cfattach audio_ca;
extern struct cfattach midi_ca;
extern struct cfattach spkr_audio_ca;
extern struct cfattach hdafg_ca;
extern struct cfattach video_ca;
extern struct cfattach dtv_ca;
extern struct cfattach hdmicec_ca;
extern struct cfattach iic_ca;
extern struct cfattach pcf8563rtc_ca;
extern struct cfattach seeprom_ca;
extern struct cfattach tps65217pmic_ca;
extern struct cfattach tps65217reg_ca;
extern struct cfattach axp20x_ca;
extern struct cfattach axp20xreg_ca;
extern struct cfattach axp22x_ca;
extern struct cfattach axppmic_ca;
extern struct cfattach axpreg_ca;
extern struct cfattach ac100ic_ca;
extern struct cfattach titemp_ca;
extern struct cfattach as3722pmic_ca;
extern struct cfattach as3722reg_ca;
extern struct cfattach tcakp_ca;
extern struct cfattach max77620pmic_ca;
extern struct cfattach tcagpio_ca;
extern struct cfattach sy8106a_ca;
extern struct cfattach twl_ca;
extern struct cfattach tdahdmi_ca;
extern struct cfattach spi_ca;
extern struct cfattach irframe_ca;
extern struct cfattach cir_ca;
extern struct cfattach tlphy_ca;
extern struct cfattach nsphy_ca;
extern struct cfattach nsphyter_ca;
extern struct cfattach gentbi_ca;
extern struct cfattach glxtphy_ca;
extern struct cfattach gphyter_ca;
extern struct cfattach qsphy_ca;
extern struct cfattach inphy_ca;
extern struct cfattach iophy_ca;
extern struct cfattach exphy_ca;
extern struct cfattach lxtphy_ca;
extern struct cfattach makphy_ca;
extern struct cfattach icsphy_ca;
extern struct cfattach igphy_ca;
extern struct cfattach ikphy_ca;
extern struct cfattach sqphy_ca;
extern struct cfattach tqphy_ca;
extern struct cfattach pnaphy_ca;
extern struct cfattach rgephy_ca;
extern struct cfattach urlphy_ca;
extern struct cfattach ukphy_ca;
extern struct cfattach rlphy_ca;
extern struct cfattach ihphy_ca;
extern struct cfattach rdcphy_ca;
extern struct cfattach ld_virtio_ca;
extern struct cfattach vioif_ca;
extern struct cfattach viornd_ca;
extern struct cfattach vioscsi_ca;
extern struct cfattach atabus_ca;
extern struct cfattach wsdisplay_emul_ca;
extern struct cfattach wskbd_ca;
extern struct cfattach wsmouse_ca;
extern struct cfattach radio_ca;
extern struct cfattach ld_nvme_ca;
extern struct cfattach gpio_ca;
extern struct cfattach flash_ca;
extern struct cfattach nand_ca;
extern struct cfattach simplebus_ca;
extern struct cfattach fregulator_ca;
extern struct cfattach gregulator_ca;
extern struct cfattach fclock_ca;
extern struct cfattach ffclock_ca;
extern struct cfattach gpiokeys_ca;
extern struct cfattach gpioleds_ca;
extern struct cfattach fdt_connector_ca;
extern struct cfattach fdt_panel_ca;
extern struct cfattach panel_fdt_ca;
extern struct cfattach cpus_ca;
extern struct cfattach mmcpwrseq_simple_ca;
extern struct cfattach mmcpwrseq_emmc_ca;
extern struct cfattach syscon_ca;
extern struct cfattach pinctrl_single_ca;
extern struct cfattach pwmbacklight_ca;
extern struct cfattach pwmfan_ca;
extern struct cfattach ausoc_ca;
extern struct cfattach simplefb_ca;
extern struct cfattach dw_apb_uart_ca;
extern struct cfattach dwc2_fdt_ca;
extern struct cfattach dwc3_fdt_ca;
extern struct cfattach dwcmmc_fdt_ca;
extern struct cfattach dwcwdt_fdt_ca;
extern struct cfattach virtio_mmio_fdt_ca;
extern struct cfattach qemufwcfg_fdt_ca;
extern struct cfattach plgpio_fdt_ca;
extern struct cfattach ahcisata_fdt_ca;
extern struct cfattach arasan_sdhc_fdt_ca;
extern struct cfattach usbnopphy_ca;
extern struct cfattach wd_ca;
extern struct cfattach bthub_ca;
extern struct cfattach pci_ca;
extern struct cfattach ahcisata_pci_ca;
extern struct cfattach ppb_ca;
extern struct cfattach re_pci_ca;
extern struct cfattach virtio_pci_ca;
extern struct cfattach nvme_pci_ca;
extern struct cfattach sdmmc_ca;
extern struct cfattach ld_sdmmc_ca;
extern struct cfattach scsibus_ca;
extern struct cfattach atapibus_ca;
extern struct cfattach cd_ca;
extern struct cfattach ch_ca;
extern struct cfattach sd_ca;
extern struct cfattach st_scsibus_ca;
extern struct cfattach st_atapibus_ca;
extern struct cfattach ses_ca;
extern struct cfattach ss_ca;
extern struct cfattach uk_ca;
extern struct cfattach usb_ca;
extern struct cfattach uroothub_ca;
extern struct cfattach uhub_ca;
extern struct cfattach uaudio_ca;
extern struct cfattach umidi_ca;
extern struct cfattach ucom_ca;
extern struct cfattach ugen_ca;
extern struct cfattach ugenif_ca;
extern struct cfattach uhidev_ca;
extern struct cfattach uhid_ca;
extern struct cfattach ukbd_ca;
extern struct cfattach ums_ca;
extern struct cfattach uts_ca;
extern struct cfattach uep_ca;
extern struct cfattach ucycom_ca;
extern struct cfattach ulpt_ca;
extern struct cfattach umass_ca;
extern struct cfattach uirda_ca;
extern struct cfattach stuirda_ca;
extern struct cfattach ustir_ca;
extern struct cfattach irmce_ca;
extern struct cfattach ubt_ca;
extern struct cfattach aubtfwl_ca;
extern struct cfattach pseye_ca;
extern struct cfattach uvideo_ca;
extern struct cfattach auvitek_ca;
extern struct cfattach emdtv_ca;
extern struct cfattach umodeswitch_ca;
extern struct cfattach urio_ca;
extern struct cfattach uipad_ca;
extern struct cfattach uberry_ca;
extern struct cfattach uvisor_ca;
extern struct cfattach ugensa_ca;
extern struct cfattach u3g_ca;
extern struct cfattach uyap_ca;
extern struct cfattach udsbr_ca;
extern struct cfattach slurm_ca;
extern struct cfattach uthum_ca;
extern struct cfattach aue_ca;
extern struct cfattach cdce_ca;
extern struct cfattach cue_ca;
extern struct cfattach kue_ca;
extern struct cfattach upl_ca;
extern struct cfattach url_ca;
extern struct cfattach axe_ca;
extern struct cfattach axen_ca;
extern struct cfattach mue_ca;
extern struct cfattach udav_ca;
extern struct cfattach otus_ca;
extern struct cfattach ure_ca;
extern struct cfattach umodem_ca;
extern struct cfattach uftdi_ca;
extern struct cfattach uplcom_ca;
extern struct cfattach umct_ca;
extern struct cfattach umcs_ca;
extern struct cfattach uvscom_ca;
extern struct cfattach uxrcom_ca;
extern struct cfattach ubsa_ca;
extern struct cfattach uipaq_ca;
extern struct cfattach ukyopon_ca;
extern struct cfattach uark_ca;
extern struct cfattach uslsa_ca;
extern struct cfattach uchcom_ca;
extern struct cfattach usscanner_ca;
extern struct cfattach atu_ca;
extern struct cfattach upgt_ca;
extern struct cfattach usmsc_ca;
extern struct cfattach ural_ca;
extern struct cfattach rum_ca;
extern struct cfattach utoppy_ca;
extern struct cfattach zyd_ca;
extern struct cfattach udl_ca;
extern struct cfattach uhso_ca;
extern struct cfattach urndis_ca;
extern struct cfattach urtwn_ca;
extern struct cfattach urtw_ca;
extern struct cfattach run_ca;
extern struct cfattach athn_usb_ca;
extern struct cfattach udsir_ca;
extern struct cfattach bwfm_usb_ca;
extern struct cfattach armgic_ca;
extern struct cfattach arml2cc_ca;
extern struct cfattach armgtmr_ca;
extern struct cfattach arma9tmr_ca;
extern struct cfattach arma9ptmr_ca;
extern struct cfattach pckbd_ca;
extern struct cfattach pms_ca;
extern struct cfattach arm_fdt_ca;
extern struct cfattach cpu_fdt_ca;
extern struct cfattach cpufreq_dt_ca;
extern struct cfattach a9tmr_fdt_ca;
extern struct cfattach a9ptmr_fdt_ca;
extern struct cfattach gtmr_fdt_ca;
extern struct cfattach gic_fdt_ca;
extern struct cfattach l2cc_fdt_ca;
extern struct cfattach plcom_fdt_ca;
extern struct cfattach plkmi_fdt_ca;
extern struct cfattach plmmc_fdt_ca;
extern struct cfattach smsh_fdt_ca;
extern struct cfattach aaci_fdt_ca;
extern struct cfattach plrtc_fdt_ca;
extern struct cfattach psci_fdt_ca;
extern struct cfattach pcihost_fdt_ca;
extern struct cfattach pmu_fdt_ca;
extern struct cfattach plfb_fdt_ca;
extern struct cfattach cycvclkmgr_ca;
extern struct cfattach cycvrstmgr_ca;
extern struct cfattach cycv_gmac_ca;
extern struct cfattach cycv_dwcmmc_ca;
extern struct cfattach meson8b_clkc_ca;
extern struct cfattach meson_resets_ca;
extern struct cfattach meson_uart_ca;
extern struct cfattach meson_genfb_ca;
extern struct cfattach meson_pinctrl_ca;
extern struct cfattach meson_sdhc_ca;
extern struct cfattach meson_sdio_ca;
extern struct cfattach meson_usbphy_ca;
extern struct cfattach meson_rtc_ca;
extern struct cfattach meson_rng_ca;
extern struct cfattach meson_dwmac_ca;
extern struct cfattach meson_wdt_ca;
extern struct cfattach bcmicu_ca;
extern struct cfattach bcmmbox_ca;
extern struct cfattach bcmpmwdog_fdt_ca;
extern struct cfattach bcmrng_fdt_ca;
extern struct cfattach bcmaux_fdt_ca;
extern struct cfattach bcmcom_ca;
extern struct cfattach bcmemmc_ca;
extern struct cfattach bcmsdhost_ca;
extern struct cfattach bcmdmac_fdt_ca;
extern struct cfattach bcmdwctwo_ca;
extern struct cfattach bcmspi_ca;
extern struct cfattach bsciic_ca;
extern struct cfattach bcmgenfb_ca;
extern struct cfattach vchiq_ca;
extern struct cfattach vcaudio_ca;
extern struct cfattach bcmgpio_ca;
extern struct cfattach bcmcprman_fdt_ca;
extern struct cfattach vcmbox_ca;
extern struct cfattach tegra124_cpu_ca;
extern struct cfattach tegra_lic_ca;
extern struct cfattach tegra_mc_ca;
extern struct cfattach tegra_pmc_ca;
extern struct cfattach tegra_fuse_ca;
extern struct cfattach tegra124_car_ca;
extern struct cfattach tegra210_car_ca;
extern struct cfattach tegra_gpio_ca;
extern struct cfattach tegra_timer_ca;
extern struct cfattach tegra_pinmux_ca;
extern struct cfattach tegra_apbdma_ca;
extern struct cfattach tegra124_xusbpad_ca;
extern struct cfattach tegra210_xusbpad_ca;
extern struct cfattach tegra210xphy_ca;
extern struct cfattach tegra_com_ca;
extern struct cfattach tegra_i2c_ca;
extern struct cfattach tegra_rtc_ca;
extern struct cfattach tegra_usbphy_ca;
extern struct cfattach tegra_ehci_ca;
extern struct cfattach tegra_xusb_ca;
extern struct cfattach tegra_sdhc_ca;
extern struct cfattach tegra_soctherm_ca;
extern struct cfattach tegra_pcie_ca;
extern struct cfattach tegra_ahcisata_ca;
extern struct cfattach tegra_hdaudio_ca;
extern struct cfattach tegra_cec_ca;
extern struct cfattach exynos_intr_ca;
extern struct cfattach exyo_mct_ca;
extern struct cfattach exynos_uart_ca;
extern struct cfattach exynos_pinctrl_ca;
extern struct cfattach exynos_usbphy_ca;
extern struct cfattach exynos_usbdrdphy_ca;
extern struct cfattach exynos_ohci_ca;
extern struct cfattach exynos_ehci_ca;
extern struct cfattach exynos_dwcmmc_ca;
extern struct cfattach exynos_i2c_ca;
extern struct cfattach exynos_pwm_ca;
extern struct cfattach exynos5422_clock_ca;
extern struct cfattach exynos5410_clock_ca;
extern struct cfattach sunxi_a10_ccu_ca;
extern struct cfattach sunxi_a13_ccu_ca;
extern struct cfattach sunxi_a31_ccu_ca;
extern struct cfattach sunxi_a83t_ccu_ca;
extern struct cfattach sunxi_h3_ccu_ca;
extern struct cfattach sunxi_h3_r_ccu_ca;
extern struct cfattach sunxi_a80_ccu_ca;
extern struct cfattach sunxi_resets_ca;
extern struct cfattach sunxi_gates_ca;
extern struct cfattach sunxi_gmacclk_ca;
extern struct cfattach sunxi_a80_mmcclk_ca;
extern struct cfattach sunxi_a80_usbclk_ca;
extern struct cfattach sunxi_a80_cpusclk_ca;
extern struct cfattach sunxi_a23_apbclk_ca;
extern struct cfattach sunxi_intc_ca;
extern struct cfattach sunxi_nmi_ca;
extern struct cfattach sunxi_gpio_ca;
extern struct cfattach sunxi_pwm_ca;
extern struct cfattach sunxi_mmc_ca;
extern struct cfattach sunxi_usbphy_ca;
extern struct cfattach sunxi_usb3phy_ca;
extern struct cfattach sunxi_a80_usbphy_ca;
extern struct cfattach ehci_fdt_ca;
extern struct cfattach ohci_fdt_ca;
extern struct cfattach sunxi_twi_ca;
extern struct cfattach sunxi_rsb_ca;
extern struct cfattach sunxi_rtc_ca;
extern struct cfattach sun4i_emac_ca;
extern struct cfattach sunxi_emac_ca;
extern struct cfattach sunxi_gmac_ca;
extern struct cfattach sunxi_timer_ca;
extern struct cfattach sunxi_hstimer_ca;
extern struct cfattach sunxi_wdt_ca;
extern struct cfattach sun4i_dma_ca;
extern struct cfattach sun6i_dma_ca;
extern struct cfattach sunxi_codec_ca;
extern struct cfattach sun8i_codec_ca;
extern struct cfattach h3_codec_ca;
extern struct cfattach a64_acodec_ca;
extern struct cfattach sunxi_i2s_ca;
extern struct cfattach sunxi_tcon_ca;
extern struct cfattach sunxi_debe_ca;
extern struct cfattach sunxi_befb_ca;
extern struct cfattach sunxi_hdmi_ca;
extern struct cfattach sunxi_dep_ca;
extern struct cfattach sunxi_ts_ca;
extern struct cfattach sunxi_musb_ca;
extern struct cfattach sunxi_sid_ca;
extern struct cfattach sunxi_thermal_ca;
extern struct cfattach sunxi_sata_ca;
extern struct cfattach sunxi_sramc_ca;
extern struct cfattach sunxi_nand_ca;
extern struct cfattach sun6i_spi_ca;
extern struct cfattach sunxi_can_ca;
extern struct cfattach sunxi_lradc_ca;
extern struct cfattach omapintc_ca;
extern struct cfattach ti_sysc_ca;
extern struct cfattach am3_prcm_ca;
extern struct cfattach omap3_cm_ca;
extern struct cfattach omap3_prm_ca;
extern struct cfattach ti_mux_clock_ca;
extern struct cfattach ti_div_clock_ca;
extern struct cfattach ti_dpll_clock_ca;
extern struct cfattach ti_com_ca;
extern struct cfattach omaptimer_ca;
extern struct cfattach ti_gpio_ca;
extern struct cfattach ti_iic_ca;
extern struct cfattach cpsw_ca;
extern struct cfattach ti_edma_ca;
extern struct cfattach ti_tptc_ca;
extern struct cfattach ti_sdhc_ca;
extern struct cfattach ti_otg_ca;
extern struct cfattach ti_usb_ca;
extern struct cfattach ti_usbtll_ca;
extern struct cfattach ti_ehci_ca;
extern struct cfattach ti_motg_ca;
extern struct cfattach ti_rng_ca;
extern struct cfattach omap3_dss_ca;
extern struct cfattach ti_lcdc_ca;
extern struct cfattach ti_fb_ca;
extern struct cfattach ti_gpmc_ca;
extern struct cfattach omapnand_ca;
extern struct cfattach ti_wdt_ca;
extern struct cfattach vexpress_sysreg_ca;
extern struct cfattach zynquart_ca;
extern struct cfattach cemac_ca;
extern struct cfattach zynqusb_ca;
extern struct cfattach sdhc_fdt_ca;

/* locators */
static int loc[788] = {
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, 1, 1, 0x1050,
	0x114, -1, -1, 1, 1, 0x1050, 0x115, -1,
	-1, 1, 2, 0x1050, 0x116, -1, -1, 1,
	1, 0x1050, 0x405, -1, -1, 1, 1, 0x1050,
	0x406, -1, -1, 1, 2, 0x1050, 0x407, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, 0, 0,
	0, 1, -1, -1, -1, -1, -1, -1,
	-1, 1, -1, -1, -1, 1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, 1,
	-1, -1, -1, -1, -1, 1, -1, 1,
	-1, 1, -1, -1, -1, -1, 5, 4,
	1, 1, 10, 10, 4, 4, 4, 0,
	10, 10, 1, 2, 10, 10, 10, 10,
	9, 10, 0, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, 10, 10, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, 10, 10,
	10, 4, 4, 4, 4, 10, -1, 10,
	10, 10, 10, 0, 0, 0, 0, 0,
	10, 10, 10, 10, 10, 10, 10, 10,
	10, 10, 10, 10, 10, 10, 10, 10,
	10, 10, 10, 10, 10, 10, 10, 10,
	10, 10, 10, 10, 10, 10, 10, 10,
	10, 10, 0, 10, 4, 10, 10, 10,
	10, 10, 10, 4, 4, 10, 10, 10,
	10, 10, 4, 4, 4, 5, 10, 4,
	10, 4, 10, 10, 10, 10, 2, 2,
	1, 1, 1, 1, 1, 2, 10, 2,
	4, 10, 4, 3, 10, 9, 8, 10,
	10, 10, 4, 10, 10, 10, 4, 4,
	-1, -1, 2, 2, 1, 1, 2, 10,
	10, 1, 0, 2, 2, 4, 10, 2,
	10, 10, 9, 10, 10, 10, 1, 10,
	10, 10, 1, 10, 10, 10, 10, 10,
	10, 1, 1, 4, 4, 4, 3, 3,
	2, 10, 10, 4, 10, 10, 4, 10,
	10, 10, 10, 10, 1, 2, 4, 2,
	9, 9, 10, 4, 3, 3, 2, 2,
	2, 2, 2, 2, 2, 1, 1, 2,
	2, 2, 2, 2, 1, 2, 3, 3,
	10, 9, 9, 9,
};

static const struct cfparent pspec0 = {
	"fdt", NULL, 0
};
static const struct cfparent pspec1 = {
	"cpu", "cpu", DVUNIT_ANY
};
static const struct cfparent pspec2 = {
	"wskbddev", "gpiokeys", DVUNIT_ANY
};
static const struct cfparent pspec3 = {
	"mpcorebus", "a9ptmr", DVUNIT_ANY
};
static const struct cfparent pspec4 = {
	"mpcorebus", "a9tmr", DVUNIT_ANY
};
static const struct cfparent pspec5 = {
	"mpcorebus", "gtmr", DVUNIT_ANY
};
static const struct cfparent pspec6 = {
	"mpcorebus", "mct", DVUNIT_ANY
};
static const struct cfparent pspec7 = {
	"mpcorebus", "gic", DVUNIT_ANY
};
static const struct cfparent pspec8 = {
	"mpcorebus", "l2cc", DVUNIT_ANY
};
static const struct cfparent pspec9 = {
	"bcmmboxbus", "bcmmbox", DVUNIT_ANY
};
static const struct cfparent pspec10 = {
	"gpiobus", NULL, 0
};
static const struct cfparent pspec11 = {
	"tegra210xpad", "tegra210xpad", DVUNIT_ANY
};
static const struct cfparent pspec12 = {
	"pcibus", NULL, 0
};
static const struct cfparent pspec13 = {
	"pci", "pci", DVUNIT_ANY
};
static const struct cfparent pspec14 = {
	"pcibus", "ppb", DVUNIT_ANY
};
static const struct cfparent pspec15 = {
	"mii", NULL, 0
};
static const struct cfparent pspec16 = {
	"i2cbus", NULL, 0
};
static const struct cfparent pspec17 = {
	"iic", "iic", DVUNIT_ANY
};
static const struct cfparent pspec18 = {
	"as3722pmic", "as3722pmic", DVUNIT_ANY
};
static const struct cfparent pspec19 = {
	"axp20x", "axp20x", DVUNIT_ANY
};
static const struct cfparent pspec20 = {
	"axppmic", "axppmic", DVUNIT_ANY
};
static const struct cfparent pspec21 = {
	"tps65217pmic", "tps65217pmic", DVUNIT_ANY
};
static const struct cfparent pspec22 = {
	"wskbddev", "tcakp", DVUNIT_ANY
};
static const struct cfparent pspec23 = {
	"spibus", NULL, 0
};
static const struct cfparent pspec24 = {
	"vchiqbus", "vchiq", 0
};
static const struct cfparent pspec25 = {
	"hdaudiobus", NULL, 0
};
static const struct cfparent pspec26 = {
	"audiobus", NULL, 0
};
static const struct cfparent pspec27 = {
	"audio", "audio", DVUNIT_ANY
};
static const struct cfparent pspec28 = {
	"sdmmcbus", NULL, 0
};
static const struct cfparent pspec29 = {
	"sdmmc", "sdmmc", 0
};
static const struct cfparent pspec30 = {
	"sdmmc", "sdmmc", 1
};
static const struct cfparent pspec31 = {
	"sdmmc", "sdmmc", 2
};
static const struct cfparent pspec32 = {
	"sdmmc", "sdmmc", 3
};
static const struct cfparent pspec33 = {
	"sdmmc", "sdmmc", DVUNIT_ANY
};
static const struct cfparent pspec34 = {
	"nandbus", NULL, 0
};
static const struct cfparent pspec35 = {
	"flashbus", "nand", DVUNIT_ANY
};
static const struct cfparent pspec36 = {
	"ata", NULL, 0
};
static const struct cfparent pspec37 = {
	"atapi", NULL, 0
};
static const struct cfparent pspec38 = {
	"ata_hl", "atabus", DVUNIT_ANY
};
static const struct cfparent pspec39 = {
	"atapibus", "atapibus", DVUNIT_ANY
};
static const struct cfparent pspec40 = {
	"nvme", "nvme", DVUNIT_ANY
};
static const struct cfparent pspec41 = {
	"hdmicecbus", NULL, 0
};
static const struct cfparent pspec42 = {
	"wsemuldisplaydev", NULL, 0
};
static const struct cfparent pspec43 = {
	"sunxidebe", "sunxidebe", DVUNIT_ANY
};
static const struct cfparent pspec44 = {
	"tilcdcfbbus", "tilcdc", DVUNIT_ANY
};
static const struct cfparent pspec45 = {
	"pckbport", NULL, 0
};
static const struct cfparent pspec46 = {
	"wskbddev", "pckbd", DVUNIT_ANY
};
static const struct cfparent pspec47 = {
	"wsmousedev", "pms", DVUNIT_ANY
};
static const struct cfparent pspec48 = {
	"wsmousedev", "sunxits", DVUNIT_ANY
};
static const struct cfparent pspec49 = {
	"usbus", NULL, 0
};
static const struct cfparent pspec50 = {
	"virtio", "virtio", DVUNIT_ANY
};
static const struct cfparent pspec51 = {
	"scsi", NULL, 0
};
static const struct cfparent pspec52 = {
	"scsibus", "scsibus", DVUNIT_ANY
};
static const struct cfparent pspec53 = {
	"usbroothubif", "usb", DVUNIT_ANY
};
static const struct cfparent pspec54 = {
	"usbdevif", "uhub", DVUNIT_ANY
};
static const struct cfparent pspec55 = {
	"usbifif", "uhub", DVUNIT_ANY
};
static const struct cfparent pspec56 = {
	"uhidbus", "uhidev", DVUNIT_ANY
};
static const struct cfparent pspec57 = {
	"wsmousedev", "ums", DVUNIT_ANY
};
static const struct cfparent pspec58 = {
	"wsmousedev", "uts", DVUNIT_ANY
};
static const struct cfparent pspec59 = {
	"wskbddev", "ukbd", DVUNIT_ANY
};
static const struct cfparent pspec60 = {
	"wsmousedev", "uep", DVUNIT_ANY
};
static const struct cfparent pspec61 = {
	"wsemuldisplaydev", "udl", DVUNIT_ANY
};
static const struct cfparent pspec62 = {
	"ucombus", "umodem", DVUNIT_ANY
};
static const struct cfparent pspec63 = {
	"scsi", "umass", DVUNIT_ANY
};
static const struct cfparent pspec64 = {
	"atapi", "umass", DVUNIT_ANY
};
static const struct cfparent pspec65 = {
	"usbifif", NULL, 0
};
static const struct cfparent pspec66 = {
	"audiobus", "uaudio", DVUNIT_ANY
};
static const struct cfparent pspec67 = {
	"irbus", "uirda", DVUNIT_ANY
};
static const struct cfparent pspec68 = {
	"irbus", "stuirda", DVUNIT_ANY
};
static const struct cfparent pspec69 = {
	"irbus", "ustir", DVUNIT_ANY
};
static const struct cfparent pspec70 = {
	"irbus", "udsir", DVUNIT_ANY
};
static const struct cfparent pspec71 = {
	"irbus", "irmce", DVUNIT_ANY
};
static const struct cfparent pspec72 = {
	"ucombus", "uark", DVUNIT_ANY
};
static const struct cfparent pspec73 = {
	"ucombus", "ubsa", DVUNIT_ANY
};
static const struct cfparent pspec74 = {
	"ucombus", "uchcom", DVUNIT_ANY
};
static const struct cfparent pspec75 = {
	"ucombus", "uftdi", DVUNIT_ANY
};
static const struct cfparent pspec76 = {
	"ucombus", "uipaq", DVUNIT_ANY
};
static const struct cfparent pspec77 = {
	"ucombus", "umct", DVUNIT_ANY
};
static const struct cfparent pspec78 = {
	"ucombus", "uplcom", DVUNIT_ANY
};
static const struct cfparent pspec79 = {
	"ucombus", "uslsa", DVUNIT_ANY
};
static const struct cfparent pspec80 = {
	"ucombus", "uvscom", DVUNIT_ANY
};
static const struct cfparent pspec81 = {
	"ucombus", "umcs", DVUNIT_ANY
};
static const struct cfparent pspec82 = {
	"ucombus", "uxrcom", DVUNIT_ANY
};
static const struct cfparent pspec83 = {
	"ucombus", "uvisor", DVUNIT_ANY
};
static const struct cfparent pspec84 = {
	"ucombus", "ukyopon", DVUNIT_ANY
};
static const struct cfparent pspec85 = {
	"scsi", "usscanner", DVUNIT_ANY
};
static const struct cfparent pspec86 = {
	"radiodev", "udsbr", DVUNIT_ANY
};
static const struct cfparent pspec87 = {
	"radiodev", "slurm", DVUNIT_ANY
};
static const struct cfparent pspec88 = {
	"ucombus", "u3g", DVUNIT_ANY
};
static const struct cfparent pspec89 = {
	"ucombus", "ugensa", DVUNIT_ANY
};
static const struct cfparent pspec90 = {
	"irbus", "emdtv", DVUNIT_ANY
};
static const struct cfparent pspec91 = {
	"videobus", NULL, 0
};
static const struct cfparent pspec92 = {
	"dtvbus", NULL, 0
};
static const struct cfparent pspec93 = {
	"btbus", "ubt", DVUNIT_ANY
};
static const struct cfparent pspec94 = {
	"midibus", NULL, 0
};

#define NORM FSTATE_NOTFOUND
#define STAR FSTATE_STAR

struct cfdata cfdata[] = {
    /* driver           attachment    unit state      loc   flags  pspec */
// /*184: usb* at usbus? */
    { "usb",		"usb",		 0, STAR,    NULL,      0, &pspec49 },
/*185: uhub* at usb? */
    { "uhub",		"uroothub",	 0, STAR,    NULL,      0, &pspec53 },
/*186: uhub* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    { "uhub",		"uhub",		 0, STAR, loc+246,      0, &pspec54 },
/*213: uhidev* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    { "uhidev",		"uhidev",	 0, STAR, loc+384,      0, &pspec55 },
/*214: uhid* at uhidev? reportid -1 */
    { "uhid",		"uhid",		 0, STAR, loc+549,      0, &pspec56 },
/*215: ukbd* at uhidev? reportid -1 */
    { "ukbd",		"ukbd",		 0, STAR, loc+550,      0, &pspec56 },
/*216: ums* at uhidev? reportid -1 */
    { "ums",		"ums",		 0, STAR, loc+551,      0, &pspec56 },
/*217: uts* at uhidev? reportid -1 */
     { "uts",		"uts",		 0, STAR, loc+552,      0, &pspec56 }, 
    { NULL,		NULL,		 0,    0,    NULL,      0, NULL }
};

static struct cfattach * const usb_cfattachinit[] = {
	&usb_ca, NULL
};
static struct cfattach * const uhub_cfattachinit[] = {
	&uroothub_ca, &uhub_ca, NULL
};
static struct cfattach * const uhidev_cfattachinit[] = {
	&uhidev_ca, NULL
};
static struct cfattach * const uhid_cfattachinit[] = {
	&uhid_ca, NULL
};
static struct cfattach * const ukbd_cfattachinit[] = {
	&ukbd_ca, NULL
};
static struct cfattach * const ums_cfattachinit[] = {
	&ums_ca, NULL
};
static struct cfattach * const uts_cfattachinit[] = {
	&uts_ca, NULL
}; 

const struct cfattachinit cfattachinit[] = {
	{ "usb", usb_cfattachinit },
	{ "uhub", uhub_cfattachinit },
	{ "uhidev", uhidev_cfattachinit },
	{ "uhid", uhid_cfattachinit },
	{ "ukbd", ukbd_cfattachinit },
	{ "ums", ums_cfattachinit },
	{ "uts", uts_cfattachinit },
	{ NULL, NULL }
};

const short cfroots[] = {
	292 /* armfdt0 */,
	-1
};
