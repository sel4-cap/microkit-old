#include "ioconf.h"
/*
 * MACHINE GENERATED: DO NOT EDIT
 *
 * ioconf.c, from "XHCI_DEBUG"
 */

#include <sys/param.h>
#include <sys/conf.h>
#include <sys/device.h>
// #include <sys/mount.h>

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
// /*  0: spkr* at audio? */
//     { "spkr",		"spkr_audio",	 0, STAR,    NULL,      0, &pspec27 },
// /*  1: audio* at audiobus? */
//     { "audio",		"audio",	 0, STAR,    NULL,      0, &pspec26 },
// /*  2: audio* at uaudio? */
//     { "audio",		"audio",	 0, STAR,    NULL,      0, &pspec66 },
// /*  3: midi* at midibus? */
//     { "midi",		"midi",		 0, STAR,    NULL,      0, &pspec94 },
// /*  4: hdaudio* at fdt? pass 10 */
//     { "hdaudio",	"tegra_hdaudio",	 0, STAR, loc+556,      0, &pspec0 },
// /*  5: hdafg* at hdaudiobus? nid -1 */
//     { "hdafg",		"hdafg",	 0, STAR, loc+557,      0, &pspec25 },
// /*  6: video* at videobus? */
//     { "video",		"video",	 0, STAR,    NULL,      0, &pspec91 },
// /*  7: dtv* at dtvbus? */
//     { "dtv",		"dtv",		 0, STAR,    NULL,      0, &pspec92 },
// /*  8: hdmicec* at hdmicecbus? */
//     { "hdmicec",	"hdmicec",	 0, STAR,    NULL,      0, &pspec41 },
// /*  9: iic* at i2cbus? */
//     { "iic",		"iic",		 0, STAR,    NULL,      0, &pspec16 },
// /* 10: pcf8563rtc* at iic? addr -1 */
//     { "pcf8563rtc",	"pcf8563rtc",	 0, STAR, loc+558,      0, &pspec17 },
// /* 11: seeprom* at iic? addr -1 */
//     { "seeprom",	"seeprom",	 0, STAR, loc+559,      0, &pspec17 },
// /* 12: tps65217pmic* at iic? addr -1 */
//     { "tps65217pmic",	"tps65217pmic",	 0, STAR, loc+560,      0, &pspec17 },
// /* 13: tps65217reg* at tps65217pmic? */
//     { "tps65217reg",	"tps65217reg",	 0, STAR,    NULL,      0, &pspec21 },
// /* 14: axp20x* at iic? addr -1 */
//     { "axp20x",		"axp20x",	 0, STAR, loc+561,      0, &pspec17 },
// /* 15: axp20xreg* at axp20x? */
//     { "axp20xreg",	"axp20xreg",	 0, STAR,    NULL,      0, &pspec19 },
// /* 16: axp22x* at iic? addr -1 */
//     { "axp22x",		"axp22x",	 0, STAR, loc+562,      0, &pspec17 },
// /* 17: axppmic* at iic? addr -1 */
//     { "axppmic",	"axppmic",	 0, STAR, loc+563,      0, &pspec17 },
// /* 18: axpreg* at axppmic? */
//     { "axpreg",		"axpreg",	 0, STAR,    NULL,      0, &pspec20 },
// /* 19: ac100ic* at iic? addr -1 */
//     { "ac100ic",	"ac100ic",	 0, STAR, loc+564,      0, &pspec17 },
// /* 20: titemp* at iic? addr -1 */
//     { "titemp",		"titemp",	 0, STAR, loc+565,      0, &pspec17 },
// /* 21: as3722pmic* at iic? addr -1 */
//     { "as3722pmic",	"as3722pmic",	 0, STAR, loc+566,      0, &pspec17 },
// /* 22: as3722reg* at as3722pmic? */
//     { "as3722reg",	"as3722reg",	 0, STAR,    NULL,      0, &pspec18 },
// /* 23: tcakp* at iic? addr -1 */
//     { "tcakp",		"tcakp",	 0, STAR, loc+567,      0, &pspec17 },
// /* 24: max77620pmic* at iic? addr -1 */
//     { "max77620pmic",	"max77620pmic",	 0, STAR, loc+568,      0, &pspec17 },
// /* 25: tcagpio* at iic? addr -1 */
//     { "tcagpio",	"tcagpio",	 0, STAR, loc+569,      0, &pspec17 },
// /* 26: sy8106a* at iic? addr -1 */
//     { "sy8106a",	"sy8106a",	 0, STAR, loc+570,      0, &pspec17 },
// /* 27: twl* at iic? addr -1 */
//     { "twl",		"twl",		 0, STAR, loc+571,      0, &pspec17 },
// /* 28: tdahdmi* at iic? addr -1 */
//     { "tdahdmi",	"tdahdmi",	 0, STAR, loc+572,      0, &pspec17 },
// /* 29: spi* at spibus? */
//     { "spi",		"spi",		 0, STAR,    NULL,      0, &pspec23 },
// /* 30: irframe* at uirda? */
//     { "irframe",	"irframe",	 0, STAR,    NULL,      0, &pspec67 },
// /* 31: irframe* at stuirda? */
//     { "irframe",	"irframe",	 0, STAR,    NULL,      0, &pspec68 },
// /* 32: irframe* at ustir? */
//     { "irframe",	"irframe",	 0, STAR,    NULL,      0, &pspec69 },
// /* 33: irframe* at udsir? */
//     { "irframe",	"irframe",	 0, STAR,    NULL,      0, &pspec70 },
// /* 34: cir* at irmce? */
//     { "cir",		"cir",		 0, STAR,    NULL,      0, &pspec71 },
// /* 35: cir* at emdtv? */
//     { "cir",		"cir",		 0, STAR,    NULL,      0, &pspec90 },
// /* 36: ld0 at sdmmc0 */
//     { "ld",		"ld_sdmmc",	 0, NORM,    NULL,      0, &pspec29 },
// /* 37: ld1 at sdmmc1 */
//     { "ld",		"ld_sdmmc",	 1, NORM,    NULL,      0, &pspec30 },
// /* 38: ld2 at sdmmc2 */
//     { "ld",		"ld_sdmmc",	 2, NORM,    NULL,      0, &pspec31 },
// /* 39: ld3 at sdmmc3 */
//     { "ld",		"ld_sdmmc",	 3, NORM,    NULL,      0, &pspec32 },
// /* 40: ld* at sdmmc? */
//     { "ld",		"ld_sdmmc",	 4, STAR,    NULL,      0, &pspec33 },
// /* 41: ld* at nvme? nsid -1 */
//     { "ld",		"ld_nvme",	 4, STAR, loc+573,      0, &pspec40 },
// /* 42: ld* at virtio? */
//     { "ld",		"ld_virtio",	 4, STAR,    NULL,      0, &pspec50 },
// /* 43: tlphy* at mii? phy -1 */
//     { "tlphy",		"tlphy",	 0, STAR, loc+574,      0, &pspec15 },
// /* 44: nsphy* at mii? phy -1 */
//     { "nsphy",		"nsphy",	 0, STAR, loc+575,      0, &pspec15 },
// /* 45: nsphyter* at mii? phy -1 */
//     { "nsphyter",	"nsphyter",	 0, STAR, loc+576,      0, &pspec15 },
// /* 46: gentbi* at mii? phy -1 */
//     { "gentbi",		"gentbi",	 0, STAR, loc+577,      0, &pspec15 },
// /* 47: glxtphy* at mii? phy -1 */
//     { "glxtphy",	"glxtphy",	 0, STAR, loc+578,      0, &pspec15 },
// /* 48: gphyter* at mii? phy -1 */
//     { "gphyter",	"gphyter",	 0, STAR, loc+579,      0, &pspec15 },
// /* 49: qsphy* at mii? phy -1 */
//     { "qsphy",		"qsphy",	 0, STAR, loc+580,      0, &pspec15 },
// /* 50: inphy* at mii? phy -1 */
//     { "inphy",		"inphy",	 0, STAR, loc+581,      0, &pspec15 },
// /* 51: iophy* at mii? phy -1 */
//     { "iophy",		"iophy",	 0, STAR, loc+582,      0, &pspec15 },
// /* 52: exphy* at mii? phy -1 */
//     { "exphy",		"exphy",	 0, STAR, loc+583,      0, &pspec15 },
// /* 53: lxtphy* at mii? phy -1 */
//     { "lxtphy",		"lxtphy",	 0, STAR, loc+584,      0, &pspec15 },
// /* 54: makphy* at mii? phy -1 */
//     { "makphy",		"makphy",	 0, STAR, loc+585,      0, &pspec15 },
// /* 55: icsphy* at mii? phy -1 */
//     { "icsphy",		"icsphy",	 0, STAR, loc+586,      0, &pspec15 },
// /* 56: igphy* at mii? phy -1 */
//     { "igphy",		"igphy",	 0, STAR, loc+587,      0, &pspec15 },
// /* 57: ikphy* at mii? phy -1 */
//     { "ikphy",		"ikphy",	 0, STAR, loc+588,      0, &pspec15 },
// /* 58: sqphy* at mii? phy -1 */
//     { "sqphy",		"sqphy",	 0, STAR, loc+589,      0, &pspec15 },
// /* 59: tqphy* at mii? phy -1 */
//     { "tqphy",		"tqphy",	 0, STAR, loc+590,      0, &pspec15 },
// /* 60: pnaphy* at mii? phy -1 */
//     { "pnaphy",		"pnaphy",	 0, STAR, loc+591,      0, &pspec15 },
// /* 61: rgephy* at mii? phy -1 */
//     { "rgephy",		"rgephy",	 0, STAR, loc+592,      0, &pspec15 },
// /* 62: urlphy* at mii? phy -1 */
//     { "urlphy",		"urlphy",	 0, STAR, loc+593,      0, &pspec15 },
// /* 63: ukphy* at mii? phy -1 */
//     { "ukphy",		"ukphy",	 0, STAR, loc+594,      0, &pspec15 },
// /* 64: rlphy* at mii? phy -1 */
//     { "rlphy",		"rlphy",	 0, STAR, loc+595,      0, &pspec15 },
// /* 65: ihphy* at mii? phy -1 */
//     { "ihphy",		"ihphy",	 0, STAR, loc+596,      0, &pspec15 },
// /* 66: rdcphy* at mii? phy -1 */
//     { "rdcphy",		"rdcphy",	 0, STAR, loc+597,      0, &pspec15 },
// /* 67: awge* at fdt? pass 10 */
//     { "awge",		"cycv_gmac",	 0, STAR, loc+598,      0, &pspec0 },
// /* 68: awge* at fdt? pass 10 */
//     { "awge",		"meson_dwmac",	 0, STAR, loc+599,      0, &pspec0 },
// /* 69: awge* at fdt? pass 10 */
//     { "awge",		"sunxi_gmac",	 0, STAR, loc+600,      0, &pspec0 },
// /* 70: com* at fdt? pass 4 */
//     { "com",		"dw_apb_uart",	 0, STAR, loc+601,      0, &pspec0 },
// /* 71: com* at fdt? pass 4 */
//     { "com",		"bcmcom",	 0, STAR, loc+602,      0, &pspec0 },
// /* 72: com* at fdt? pass 4 */
//     { "com",		"tegra_com",	 0, STAR, loc+603,      0, &pspec0 },
// /* 73: com* at fdt? pass 4 */
//     { "com",		"ti_com",	 0, STAR, loc+604,      0, &pspec0 },
// /* 74: re* at pci? dev -1 function -1 */
//     { "re",		"re_pci",	 0, STAR, loc+498,      0, &pspec13 },
// /* 75: virtio* at fdt? pass 10 */
//     { "virtio",		"virtio_mmio_fdt",	 0, STAR, loc+605,      0, &pspec0 },
// /* 76: virtio* at pci? dev -1 function -1 */
//     { "virtio",		"virtio_pci",	 0, STAR, loc+468,      0, &pspec13 },
// /* 77: vioif* at virtio? */
//     { "vioif",		"vioif",	 0, STAR,    NULL,      0, &pspec50 },
// /* 78: viornd* at virtio? */
//     { "viornd",		"viornd",	 0, STAR,    NULL,      0, &pspec50 },
// /* 79: vioscsi* at virtio? */
//     { "vioscsi",	"vioscsi",	 0, STAR,    NULL,      0, &pspec50 },
// /* 80: atabus* at ata? channel -1 */
//     { "atabus",		"atabus",	 0, STAR, loc+606,      0, &pspec36 },
// /* 81: ahcisata* at fdt? pass 10 */
//     { "ahcisata",	"ahcisata_fdt",	 0, STAR, loc+607,      0, &pspec0 },
// /* 82: ahcisata* at fdt? pass 10 */
//     { "ahcisata",	"tegra_ahcisata",	 0, STAR, loc+608,      0, &pspec0 },
// /* 83: ahcisata* at fdt? pass 10 */
//     { "ahcisata",	"sunxi_sata",	 0, STAR, loc+609,      0, &pspec0 },
// /* 84: ahcisata* at pci? dev -1 function -1 */
//     { "ahcisata",	"ahcisata_pci",	 0, STAR, loc+490,      0, &pspec13 },
// /* 85: smsh* at fdt? pass 10 */
//     { "smsh",		"smsh_fdt",	 0, STAR, loc+610,      0, &pspec0 },
// /* 86: wsdisplay* at wsemuldisplaydev? console -1 kbdmux 1 */
//     { "wsdisplay",	"wsdisplay_emul",	 0, STAR, loc+496,      0, &pspec42 },
// /* 87: wsdisplay* at udl? console -1 kbdmux 1 */
//     { "wsdisplay",	"wsdisplay_emul",	 0, STAR, loc+472,      0, &pspec61 },
// /* 88: wskbd* at gpiokeys? console -1 mux 1 */
//     { "wskbd",		"wskbd",	 0, STAR, loc+476,      0, &pspec2 },
// /* 89: wskbd* at tcakp? console -1 mux 1 */
//     { "wskbd",		"wskbd",	 0, STAR, loc+486,      0, &pspec22 },
// /* 90: wskbd* at pckbd? console -1 mux 1 */
//     { "wskbd",		"wskbd",	 0, STAR, loc+492,      0, &pspec46 },
// /* 91: wskbd* at ukbd? console -1 mux 1 */
//     { "wskbd",		"wskbd",	 0, STAR, loc+494,      0, &pspec59 },
// /* 92: wsmouse* at pms? mux 0 */
//     { "wsmouse",	"wsmouse",	 0, STAR, loc+611,      0, &pspec47 },
// /* 93: wsmouse* at sunxits? mux 0 */
//     { "wsmouse",	"wsmouse",	 0, STAR, loc+612,      0, &pspec48 },
// /* 94: wsmouse* at ums? mux 0 */
//     { "wsmouse",	"wsmouse",	 0, STAR, loc+613,      0, &pspec57 },
// /* 95: wsmouse* at uts? mux 0 */
//     { "wsmouse",	"wsmouse",	 0, STAR, loc+614,      0, &pspec58 },
// /* 96: wsmouse* at uep? mux 0 */
//     { "wsmouse",	"wsmouse",	 0, STAR, loc+615,      0, &pspec60 },
// /* 97: genfb* at fdt? pass 10 */
//     { "genfb",		"simplefb",	 0, STAR, loc+616,      0, &pspec0 },
// /* 98: genfb* at fdt? pass 10 */
//     { "genfb",		"plfb_fdt",	 0, STAR, loc+617,      0, &pspec0 },
// /* 99: genfb* at fdt? pass 10 */
//     { "genfb",		"bcmgenfb",	 0, STAR, loc+618,      0, &pspec0 },
// /*100: genfb* at sunxidebe? */
//     { "genfb",		"sunxi_befb",	 0, STAR,    NULL,      0, &pspec43 },
// /*101: ohci* at fdt? pass 10 */
//     { "ohci",		"exynos_ohci",	 0, STAR, loc+619,      0, &pspec0 },
// /*102: ohci* at fdt? pass 10 */
//     { "ohci",		"ohci_fdt",	 0, STAR, loc+620,      0, &pspec0 },
// /*103: ehci* at fdt? pass 10 */
//     { "ehci",		"tegra_ehci",	 0, STAR, loc+621,      0, &pspec0 },
// /*104: ehci* at fdt? pass 10 */
//     { "ehci",		"exynos_ehci",	 0, STAR, loc+622,      0, &pspec0 },
// /*105: ehci* at fdt? pass 10 */
//     { "ehci",		"ehci_fdt",	 0, STAR, loc+623,      0, &pspec0 },
// /*106: ehci* at fdt? pass 10 */
//     { "ehci",		"ti_ehci",	 0, STAR, loc+624,      0, &pspec0 },
// /*107: ehci* at fdt? pass 10 */
//     { "ehci",		"zynqusb",	 0, STAR, loc+625,      0, &pspec0 },
// /*108: ehci* at fdt? pass 10 */
//     { "ehci",		"exynos_ehci",	 0, STAR, loc+626,      0, &pspec0 },
// /*109: ehci* at fdt? pass 10 */
//     { "ehci",		"ehci_fdt",	 0, STAR, loc+627,      0, &pspec0 },
// /*110: ehci* at fdt? pass 10 */
//     { "ehci",		"ti_ehci",	 0, STAR, loc+628,      0, &pspec0 },
// /*111: ehci* at fdt? pass 10 */
//     { "ehci",		"zynqusb",	 0, STAR, loc+629,      0, &pspec0 },
// /*112: xhci* at fdt? pass 10 */
//     { "xhci",		"dwc3_fdt",	 0, STAR, loc+630,      0, &pspec0 },
// /*113: xhci* at fdt? pass 10 */
//     { "xhci",		"tegra_xusb",	 0, STAR, loc+631,      0, &pspec0 },
// /*114: motg* at fdt? pass 10 */
//     { "motg",		"sunxi_musb",	 0, STAR, loc+632,      0, &pspec0 },
// /*115: motg* at fdt? pass 10 */
//     { "motg",		"ti_motg",	 0, STAR, loc+633,      0, &pspec0 },
// /*116: dwctwo* at fdt? pass 10 */
//     { "dwctwo",		"dwc2_fdt",	 0, STAR, loc+634,      0, &pspec0 },
// /*117: dwctwo* at fdt? pass 10 */
//     { "dwctwo",		"bcmdwctwo",	 0, STAR, loc+635,      0, &pspec0 },
// /*118: sdhc* at fdt? pass 10 */
//     { "sdhc",		"arasan_sdhc_fdt",	 0, STAR, loc+636,      0, &pspec0 },
// /*119: sdhc* at fdt? pass 10 */
//     { "sdhc",		"bcmemmc",	 0, STAR, loc+637,      0, &pspec0 },
// /*120: sdhc* at fdt? pass 10 */
//     { "sdhc",		"tegra_sdhc",	 0, STAR, loc+638,      0, &pspec0 },
// /*121: sdhc* at fdt? pass 10 */
//     { "sdhc",		"ti_sdhc",	 0, STAR, loc+639,      0, &pspec0 },
// /*122: sdhc* at fdt? pass 10 */
//     { "sdhc",		"sdhc_fdt",	 0, STAR, loc+640,      0, &pspec0 },
// /*123: dwcmmc* at fdt? pass 10 */
//     { "dwcmmc",		"dwcmmc_fdt",	 0, STAR, loc+641,      0, &pspec0 },
// /*124: dwcmmc* at fdt? pass 10 */
//     { "dwcmmc",		"cycv_dwcmmc",	 0, STAR, loc+642,      0, &pspec0 },
// /*125: dwcmmc* at fdt? pass 10 */
//     { "dwcmmc",		"exynos_dwcmmc",	 0, STAR, loc+643,      0, &pspec0 },
// /*126: plrtc* at fdt? pass 10 */
//     { "plrtc",		"plrtc_fdt",	 0, STAR, loc+644,      0, &pspec0 },
// /*127: aaci* at fdt? pass 10 */
//     { "aaci",		"aaci_fdt",	 0, STAR, loc+645,      0, &pspec0 },
// /*128: plkmi* at fdt? pass 10 */
//     { "plkmi",		"plkmi_fdt",	 0, STAR, loc+646,      0, &pspec0 },
// /*129: plgpio* at fdt? pass 10 */
//     { "plgpio",		"plgpio_fdt",	 0, STAR, loc+647,      0, &pspec0 },
// /*130: plmmc* at fdt? pass 10 */
//     { "plmmc",		"plmmc_fdt",	 0, STAR, loc+648,      0, &pspec0 },
// /*131: radio* at udsbr? */
//     { "radio",		"radio",	 0, STAR,    NULL,      0, &pspec86 },
// /*132: radio* at slurm? */
//     { "radio",		"radio",	 0, STAR,    NULL,      0, &pspec87 },
// /*133: nvme* at pci? dev -1 function -1 */
//     { "nvme",		"nvme_pci",	 0, STAR, loc+488,      0, &pspec13 },
// /*134: bwfm* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "bwfm",		"bwfm_usb",	 0, STAR, loc+294,      0, &pspec54 },
// /*135: qemufwcfg* at fdt? pass 10 */
//     { "qemufwcfg",	"qemufwcfg_fdt",	 0, STAR, loc+649,      0, &pspec0 },
// /*136: gpio* at gpiobus? */
//     { "gpio",		"gpio",		 0, STAR,    NULL,      0, &pspec10 },
// /*137: flash* at nand? offset 0 size 0 readonly 0 dynamic 1 */
//     { "flash",		"flash",	 0, STAR, loc+462,      0, &pspec35 },
// /*138: nand* at nandbus? */
//     { "nand",		"nand",		 0, STAR,    NULL,      0, &pspec34 },
// /*139: athn* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "athn",		"athn_usb",	 0, STAR, loc+318,      0, &pspec54 },
// /*140: simplebus* at fdt? pass 0 */
//     { "simplebus",	"simplebus",	 0, STAR, loc+650,      0, &pspec0 },
// /*141: fregulator* at fdt? pass 5 */
//     { "fregulator",	"fregulator",	 0, STAR, loc+502,      0, &pspec0 },
// /*142: gregulator* at fdt? pass 4 */
//     { "gregulator",	"gregulator",	 0, STAR, loc+503,      0, &pspec0 },
// /*143: fclock* at fdt? pass 1 */
//     { "fclock",		"fclock",	 0, STAR, loc+504,      0, &pspec0 },
// /*144: ffclock* at fdt? pass 1 */
//     { "ffclock",	"ffclock",	 0, STAR, loc+505,      0, &pspec0 },
// /*145: gpiokeys* at fdt? pass 10 */
//     { "gpiokeys",	"gpiokeys",	 0, STAR, loc+506,      0, &pspec0 },
// /*146: gpioleds* at fdt? pass 10 */
//     { "gpioleds",	"gpioleds",	 0, STAR, loc+507,      0, &pspec0 },
// /*147: connector* at fdt? pass 4 */
//     { "connector",	"fdt_connector",	 0, STAR, loc+508,      0, &pspec0 },
// /*148: panel* at fdt? pass 4 */
//     { "panel",		"fdt_panel",	 0, STAR, loc+509,      0, &pspec0 },
// /*149: panel* at fdt? pass 4 */
//     { "panel",		"panel_fdt",	 0, STAR, loc+510,      0, &pspec0 },
// /*150: cpus* at fdt? pass 0 */
//     { "cpus",		"cpus",		 0, STAR, loc+511,      0, &pspec0 },
// /*151: mmcpwrseq* at fdt? pass 10 */
//     { "mmcpwrseq",	"mmcpwrseq_simple",	 0, STAR, loc+512,      0, &pspec0 },
// /*152: mmcpwrseq* at fdt? pass 10 */
//     { "mmcpwrseq",	"mmcpwrseq_emmc",	 0, STAR, loc+513,      0, &pspec0 },
// /*153: syscon* at fdt? pass 1 */
//     { "syscon",		"syscon",	 0, STAR, loc+514,      0, &pspec0 },
// /*154: pinctrl* at fdt? pass 2 */
//     { "pinctrl",	"pinctrl_single",	 0, STAR, loc+515,      0, &pspec0 },
// /*155: pwmbacklight* at fdt? pass 10 */
//     { "pwmbacklight",	"pwmbacklight",	 0, STAR, loc+516,      0, &pspec0 },
// /*156: pwmfan* at fdt? pass 10 */
//     { "pwmfan",		"pwmfan",	 0, STAR, loc+517,      0, &pspec0 },
// /*157: ausoc* at fdt? pass 10 */
//     { "ausoc",		"ausoc",	 0, STAR, loc+518,      0, &pspec0 },
// /*158: dwcwdt* at fdt? pass 10 */
//     { "dwcwdt",		"dwcwdt_fdt",	 0, STAR, loc+519,      0, &pspec0 },
// /*159: usbnopphy* at fdt? pass 9 */
//     { "usbnopphy",	"usbnopphy",	 0, STAR, loc+520,      0, &pspec0 },
// /*160: psci* at fdt? pass 10 */
//     { "psci",		"psci_fdt",	 0, STAR, loc+521,      0, &pspec0 },
// /*161: cpu* at fdt? pass 0 */
//     { "cpu",		"cpu_fdt",	 0, STAR, loc+522,      0, &pspec0 },
// /*162: wd* at atabus? drive -1 */
//     { "wd",		"wd",		 0, STAR, loc+523,      0, &pspec38 },
// /*163: bthub* at ubt? */
//     { "bthub",		"bthub",	 0, STAR,    NULL,      0, &pspec93 },
// /*164: pci* at pcibus? bus -1 */
//     { "pci",		"pci",		 0, STAR, loc+524,      0, &pspec12 },
// /*165: pci* at ppb? bus -1 */
//     { "pci",		"pci",		 0, STAR, loc+525,      0, &pspec14 },
// /*166: ppb* at pci? dev -1 function -1 */
//     { "ppb",		"ppb",		 0, STAR, loc+484,      0, &pspec13 },
// /*167: sdmmc* at sdmmcbus? */
//     { "sdmmc",		"sdmmc",	 0, STAR,    NULL,      0, &pspec28 },
// /*168: scsibus* at scsi? channel -1 */
//     { "scsibus",	"scsibus",	 0, STAR, loc+526,      0, &pspec51 },
// /*169: scsibus* at umass? channel -1 */
//     { "scsibus",	"scsibus",	 0, STAR, loc+527,      0, &pspec63 },
// /*170: scsibus* at usscanner? channel -1 */
//     { "scsibus",	"scsibus",	 0, STAR, loc+528,      0, &pspec85 },
// /*171: atapibus* at atapi? */
//     { "atapibus",	"atapibus",	 0, STAR,    NULL,      0, &pspec37 },
// /*172: atapibus* at umass? */
//     { "atapibus",	"atapibus",	 0, STAR,    NULL,      0, &pspec64 },
// /*173: cd* at atapibus? drive -1 */
//     { "cd",		"cd",		 0, STAR, loc+529,      0, &pspec39 },
// /*174: cd* at scsibus? target -1 lun -1 */
//     { "cd",		"cd",		 0, STAR, loc+500,      0, &pspec52 },
// /*175: ch* at scsibus? target -1 lun -1 */
//     { "ch",		"ch",		 0, STAR, loc+466,      0, &pspec52 },
// /*176: sd* at scsibus? target -1 lun -1 */
//     { "sd",		"sd",		 0, STAR, loc+470,      0, &pspec52 },
// /*177: sd* at atapibus? drive -1 */
//     { "sd",		"sd",		 0, STAR, loc+530,      0, &pspec39 },
// /*178: st* at scsibus? target -1 lun -1 */
//     { "st",		"st_scsibus",	 0, STAR, loc+474,      0, &pspec52 },
// /*179: st* at atapibus? drive -1 */
//     { "st",		"st_atapibus",	 0, STAR, loc+531,      0, &pspec39 },
// /*180: ses* at scsibus? target -1 lun -1 */
//     { "ses",		"ses",		 0, STAR, loc+478,      0, &pspec52 },
// /*181: ss* at scsibus? target -1 lun -1 */
//     { "ss",		"ss",		 0, STAR, loc+480,      0, &pspec52 },
// /*182: uk* at scsibus? target -1 lun -1 */
//     { "uk",		"uk",		 0, STAR, loc+482,      0, &pspec52 },
// /*183: uk* at atapibus? drive -1 */
//     { "uk",		"uk",		 0, STAR, loc+532,      0, &pspec39 },
// /*184: usb* at usbus? */
    { "usb",		"usb",		 0, STAR,    NULL,      0, &pspec49 },
/*185: uhub* at usb? */
    { "uhub",		"uroothub",	 0, STAR,    NULL,      0, &pspec53 },
/*186: uhub* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    { "uhub",		"uhub",		 0, STAR, loc+246,      0, &pspec54 },
// /*187: uaudio* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uaudio",		"uaudio",	 0, STAR, loc+252,      0, &pspec55 },
// /*188: uaudio* at usbifif? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uaudio",		"uaudio",	 0, STAR, loc+258,      0, &pspec65 },
// /*189: umidi* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umidi",		"umidi",	 0, STAR, loc+264,      0, &pspec55 },
// /*190: ucom* at umodem? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+533,      0, &pspec62 },
// /*191: ucom* at uark? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+534,      0, &pspec72 },
// /*192: ucom* at ubsa? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+535,      0, &pspec73 },
// /*193: ucom* at uchcom? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+536,      0, &pspec74 },
// /*194: ucom* at uftdi? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+537,      0, &pspec75 },
// /*195: ucom* at uipaq? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+538,      0, &pspec76 },
// /*196: ucom* at umct? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+539,      0, &pspec77 },
// /*197: ucom* at uplcom? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+540,      0, &pspec78 },
// /*198: ucom* at uslsa? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+541,      0, &pspec79 },
// /*199: ucom* at uvscom? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+542,      0, &pspec80 },
// /*200: ucom* at umcs? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+543,      0, &pspec81 },
// /*201: ucom* at uxrcom? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+544,      0, &pspec82 },
// /*202: ucom* at uvisor? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+545,      0, &pspec83 },
// /*203: ucom* at ukyopon? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+546,      0, &pspec84 },
// /*204: ucom* at u3g? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+547,      0, &pspec88 },
// /*205: ucom* at ugensa? portno -1 */
//     { "ucom",		"ucom",		 0, STAR, loc+548,      0, &pspec89 },
// /*206: ugen* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ugen",		"ugen",		 0, STAR, loc+342,      0, &pspec54 },
// /*207: ugenif* at uhub? port -1 configuration 1 interface 1 vendor 0x1050 product 0x114 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+348,      0, &pspec55 },
// /*208: ugenif* at uhub? port -1 configuration 1 interface 1 vendor 0x1050 product 0x115 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+354,      0, &pspec55 },
// /*209: ugenif* at uhub? port -1 configuration 1 interface 2 vendor 0x1050 product 0x116 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+360,      0, &pspec55 },
// /*210: ugenif* at uhub? port -1 configuration 1 interface 1 vendor 0x1050 product 0x405 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+366,      0, &pspec55 },
// /*211: ugenif* at uhub? port -1 configuration 1 interface 1 vendor 0x1050 product 0x406 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+372,      0, &pspec55 },
// /*212: ugenif* at uhub? port -1 configuration 1 interface 2 vendor 0x1050 product 0x407 release -1 */
//     { "ugenif",		"ugenif",	 0, STAR, loc+378,      0, &pspec55 },
/*213: uhidev* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    { "uhidev",		"uhidev",	 0, STAR, loc+384,      0, &pspec55 },
// /*214: uhid* at uhidev? reportid -1 */
    { "uhid",		"uhid",		 0, STAR, loc+549,      0, &pspec56 },
/*215: ukbd* at uhidev? reportid -1 */
    { "ukbd",		"ukbd",		 0, STAR, loc+550,      0, &pspec56 },
/*216: ums* at uhidev? reportid -1 */
    { "ums",		"ums",		 0, STAR, loc+551,      0, &pspec56 },
// /*217: uts* at uhidev? reportid -1 */
//     { "uts",		"uts",		 0, STAR, loc+552,      0, &pspec56 },
// /*218: uep* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uep",		"uep",		 0, STAR, loc+414,      0, &pspec54 },
// /*219: ucycom* at uhidev? reportid -1 */
//     { "ucycom",		"ucycom",	 0, STAR, loc+553,      0, &pspec56 },
// /*220: ulpt* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ulpt",		"ulpt",		 0, STAR, loc+426,      0, &pspec55 },
// /*221: umass* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umass",		"umass",	 0, STAR, loc+432,      0, &pspec55 },
// /*222: uirda* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uirda",		"uirda",	 0, STAR, loc+438,      0, &pspec55 },
// /*223: stuirda* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "stuirda",	"stuirda",	 0, STAR, loc+444,      0, &pspec55 },
// /*224: ustir* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ustir",		"ustir",	 0, STAR, loc+450,      0, &pspec54 },
// /*225: irmce* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "irmce",		"irmce",	 0, STAR, loc+456,      0, &pspec55 },
// /*226: ubt* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ubt",		"ubt",		 0, STAR, loc+ 42,      0, &pspec54 },
// /*227: aubtfwl* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "aubtfwl",	"aubtfwl",	 0, STAR, loc+ 48,      0, &pspec54 },
// /*228: pseye* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "pseye",		"pseye",	 0, STAR, loc+ 54,      0, &pspec55 },
// /*229: uvideo* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uvideo",		"uvideo",	 0, STAR, loc+ 60,      0, &pspec55 },
// /*230: auvitek* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "auvitek",	"auvitek",	 0, STAR, loc+ 66,      0, &pspec54 },
// /*231: emdtv* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "emdtv",		"emdtv",	 0, STAR, loc+ 72,      0, &pspec54 },
// /*232: umodeswitch* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umodeswitch",	"umodeswitch",	 0, STAR, loc+ 78,      0, &pspec54 },
// /*233: urio* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "urio",		"urio",		 0, STAR, loc+ 84,      0, &pspec54 },
// /*234: uipad* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uipad",		"uipad",	 0, STAR, loc+ 90,      0, &pspec54 },
// /*235: uberry* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uberry",		"uberry",	 0, STAR, loc+ 96,      0, &pspec54 },
// /*236: uvisor* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uvisor",		"uvisor",	 0, STAR, loc+102,      0, &pspec54 },
// /*237: ugensa* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ugensa",		"ugensa",	 0, STAR, loc+108,      0, &pspec54 },
// /*238: u3g* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "u3g",		"u3g",		 0, STAR, loc+114,      0, &pspec55 },
// /*239: uyap* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uyap",		"uyap",		 0, STAR, loc+120,      0, &pspec54 },
// /*240: udsbr* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "udsbr",		"udsbr",	 0, STAR, loc+126,      0, &pspec54 },
// /*241: slurm* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "slurm",		"slurm",	 0, STAR, loc+132,      0, &pspec55 },
// /*242: uthum* at uhidev? reportid -1 */
//     { "uthum",		"uthum",	 0, STAR, loc+554,      0, &pspec56 },
// /*243: aue* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "aue",		"aue",		 0, STAR, loc+144,      0, &pspec54 },
// /*244: cdce* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "cdce",		"cdce",		 0, STAR, loc+  0,      0, &pspec55 },
// /*245: cue* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "cue",		"cue",		 0, STAR, loc+240,      0, &pspec54 },
// /*246: kue* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "kue",		"kue",		 0, STAR, loc+234,      0, &pspec54 },
// /*247: upl* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "upl",		"upl",		 0, STAR, loc+228,      0, &pspec54 },
// /*248: url* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "url",		"url",		 0, STAR, loc+222,      0, &pspec54 },
// /*249: axe* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "axe",		"axe",		 0, STAR, loc+204,      0, &pspec54 },
// /*250: axen* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "axen",		"axen",		 0, STAR, loc+186,      0, &pspec54 },
// /*251: mue* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "mue",		"mue",		 0, STAR, loc+312,      0, &pspec54 },
// /*252: udav* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "udav",		"udav",		 0, STAR, loc+306,      0, &pspec54 },
// /*253: otus* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "otus",		"otus",		 0, STAR, loc+288,      0, &pspec54 },
// /*254: ure* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ure",		"ure",		 0, STAR, loc+282,      0, &pspec54 },
// /*255: umodem* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umodem",		"umodem",	 0, STAR, loc+402,      0, &pspec55 },
// /*256: uftdi* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uftdi",		"uftdi",	 0, STAR, loc+174,      0, &pspec55 },
// /*257: uplcom* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uplcom",		"uplcom",	 0, STAR, loc+168,      0, &pspec54 },
// /*258: umct* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umct",		"umct",		 0, STAR, loc+162,      0, &pspec54 },
// /*259: umcs* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "umcs",		"umcs",		 0, STAR, loc+138,      0, &pspec54 },
// /*260: uvscom* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uvscom",		"uvscom",	 0, STAR, loc+408,      0, &pspec54 },
// /*261: uxrcom* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uxrcom",		"uxrcom",	 0, STAR, loc+396,      0, &pspec55 },
// /*262: ubsa* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ubsa",		"ubsa",		 0, STAR, loc+390,      0, &pspec54 },
// /*263: uipaq* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uipaq",		"uipaq",	 0, STAR, loc+336,      0, &pspec54 },
// /*264: ukyopon* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ukyopon",	"ukyopon",	 0, STAR, loc+330,      0, &pspec55 },
// /*265: uark* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uark",		"uark",		 0, STAR, loc+324,      0, &pspec54 },
// /*266: uslsa* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uslsa",		"uslsa",	 0, STAR, loc+300,      0, &pspec55 },
// /*267: uchcom* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uchcom",		"uchcom",	 0, STAR, loc+276,      0, &pspec54 },
// /*268: usscanner* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "usscanner",	"usscanner",	 0, STAR, loc+270,      0, &pspec54 },
// /*269: atu* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "atu",		"atu",		 0, STAR, loc+216,      0, &pspec54 },
// /*270: upgt* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "upgt",		"upgt",		 0, STAR, loc+210,      0, &pspec54 },
// /*271: usmsc* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "usmsc",		"usmsc",	 0, STAR, loc+198,      0, &pspec54 },
// /*272: ural* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "ural",		"ural",		 0, STAR, loc+ 18,      0, &pspec54 },
// /*273: rum* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "rum",		"rum",		 0, STAR, loc+420,      0, &pspec54 },
// /*274: utoppy* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "utoppy",		"utoppy",	 0, STAR, loc+156,      0, &pspec54 },
// /*275: zyd* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "zyd",		"zyd",		 0, STAR, loc+ 30,      0, &pspec54 },
// /*276: udl* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "udl",		"udl",		 0, STAR, loc+150,      0, &pspec54 },
// /*277: uhso* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "uhso",		"uhso",		 0, STAR, loc+192,      0, &pspec54 },
// /*278: urndis* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "urndis",		"urndis",	 0, STAR, loc+180,      0, &pspec55 },
// /*279: urtwn* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "urtwn",		"urtwn",	 0, STAR, loc+ 36,      0, &pspec54 },
// /*280: urtw* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "urtw",		"urtw",		 0, STAR, loc+  6,      0, &pspec54 },
// /*281: run* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "run",		"run",		 0, STAR, loc+ 24,      0, &pspec54 },
// /*282: udsir* at uhub? port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
//     { "udsir",		"udsir",	 0, STAR, loc+ 12,      0, &pspec55 },
// /*283: plcom* at fdt? pass 4 */
//     { "plcom",		"plcom_fdt",	 0, STAR, loc+703,      0, &pspec0 },
// /*284: armgic0 at gic? */
//     { "armgic",		"armgic",	 0, NORM,    NULL,      0, &pspec7 },
// /*285: arml2cc* at l2cc? */
//     { "arml2cc",	"arml2cc",	 0, STAR,    NULL,      0, &pspec8 },
// /*286: armgtmr0 at gtmr? */
//     { "armgtmr",	"armgtmr",	 0, NORM,    NULL,      0, &pspec5 },
// /*287: armgtmr* at mct? */
//     { "armgtmr",	"armgtmr",	 1, STAR,    NULL,      0, &pspec6 },
// /*288: arma9tmr* at a9tmr? */
//     { "arma9tmr",	"arma9tmr",	 0, STAR,    NULL,      0, &pspec4 },
// /*289: arma9ptmr* at a9ptmr? */
//     { "arma9ptmr",	"arma9ptmr",	 0, STAR,    NULL,      0, &pspec3 },
// /*290: pckbd* at pckbport? slot -1 */
//     { "pckbd",		"pckbd",	 0, STAR, loc+704,      0, &pspec45 },
// /*291: pms* at pckbport? slot -1 */
//     { "pms",		"pms",		 0, STAR, loc+705,      0, &pspec45 },
// /*292: armfdt0 at root */
//     { "armfdt",		"arm_fdt",	 0, NORM,    NULL,      0, NULL },
// /*293: cpufreqdt* at cpu? */
//     { "cpufreqdt",	"cpufreq_dt",	 0, STAR,    NULL,      0, &pspec1 },
// /*294: a9tmr* at fdt? pass 2 */
//     { "a9tmr",		"a9tmr_fdt",	 0, STAR, loc+706,      0, &pspec0 },
// /*295: a9ptmr* at fdt? pass 2 */
//     { "a9ptmr",		"a9ptmr_fdt",	 0, STAR, loc+707,      0, &pspec0 },
// /*296: gtmr* at fdt? pass 1 */
//     { "gtmr",		"gtmr_fdt",	 0, STAR, loc+708,      0, &pspec0 },
// /*297: gic* at fdt? pass 1 */
//     { "gic",		"gic_fdt",	 0, STAR, loc+709,      0, &pspec0 },
// /*298: l2cc* at fdt? pass 2 */
//     { "l2cc",		"l2cc_fdt",	 0, STAR, loc+710,      0, &pspec0 },
// /*299: pcihost* at fdt? pass 10 */
//     { "pcihost",	"pcihost_fdt",	 0, STAR, loc+711,      0, &pspec0 },
// /*300: armpmu* at fdt? pass 10 */
//     { "armpmu",		"pmu_fdt",	 0, STAR, loc+712,      0, &pspec0 },
// /*301: cycvclkmgr* at fdt? pass 1 */
//     { "cycvclkmgr",	"cycvclkmgr",	 0, STAR, loc+713,      0, &pspec0 },
// /*302: cycvrstmgr* at fdt? pass 0 */
//     { "cycvrstmgr",	"cycvrstmgr",	 0, STAR, loc+714,      0, &pspec0 },
// /*303: meson8bclkc* at fdt? pass 2 */
//     { "meson8bclkc",	"meson8b_clkc",	 0, STAR, loc+715,      0, &pspec0 },
// /*304: mesonresets* at fdt? pass 2 */
//     { "mesonresets",	"meson_resets",	 0, STAR, loc+716,      0, &pspec0 },
// /*305: mesonuart* at fdt? pass 4 */
//     { "mesonuart",	"meson_uart",	 0, STAR, loc+717,      0, &pspec0 },
// /*306: mesonfb* at fdt? pass 10 */
//     { "mesonfb",	"meson_genfb",	 0, STAR, loc+718,      0, &pspec0 },
// /*307: mesonpinctrl* at fdt? pass 2 */
//     { "mesonpinctrl",	"meson_pinctrl",	 0, STAR, loc+719,      0, &pspec0 },
// /*308: mesonsdhc* at fdt? pass 10 */
//     { "mesonsdhc",	"meson_sdhc",	 0, STAR, loc+720,      0, &pspec0 },
// /*309: mesonsdio* at fdt? pass 10 */
//     { "mesonsdio",	"meson_sdio",	 0, STAR, loc+721,      0, &pspec0 },
// /*310: mesonusbphy* at fdt? pass 9 */
//     { "mesonusbphy",	"meson_usbphy",	 0, STAR, loc+722,      0, &pspec0 },
// /*311: mesonrtc* at fdt? pass 10 */
//     { "mesonrtc",	"meson_rtc",	 0, STAR, loc+723,      0, &pspec0 },
// /*312: mesonrng* at fdt? pass 10 */
//     { "mesonrng",	"meson_rng",	 0, STAR, loc+724,      0, &pspec0 },
// /*313: mesonwdt* at fdt? pass 10 */
//     { "mesonwdt",	"meson_wdt",	 0, STAR, loc+725,      0, &pspec0 },
// /*314: bcmicu* at fdt? pass 1 */
//     { "bcmicu",		"bcmicu",	 0, STAR, loc+726,      0, &pspec0 },
// /*315: bcmmbox* at fdt? pass 10 */
//     { "bcmmbox",	"bcmmbox",	 0, STAR, loc+727,      0, &pspec0 },
// /*316: bcmpmwdog* at fdt? pass 10 */
//     { "bcmpmwdog",	"bcmpmwdog_fdt",	 0, STAR, loc+728,      0, &pspec0 },
// /*317: bcmrng* at fdt? pass 10 */
//     { "bcmrng",		"bcmrng_fdt",	 0, STAR, loc+729,      0, &pspec0 },
// /*318: bcmaux* at fdt? pass 1 */
//     { "bcmaux",		"bcmaux_fdt",	 0, STAR, loc+730,      0, &pspec0 },
// /*319: bcmsdhost* at fdt? pass 10 */
//     { "bcmsdhost",	"bcmsdhost",	 0, STAR, loc+731,      0, &pspec0 },
// /*320: bcmdmac* at fdt? pass 10 */
//     { "bcmdmac",	"bcmdmac_fdt",	 0, STAR, loc+732,      0, &pspec0 },
// /*321: bcmspi* at fdt? pass 10 */
//     { "bcmspi",		"bcmspi",	 0, STAR, loc+733,      0, &pspec0 },
// /*322: bsciic* at fdt? pass 10 */
//     { "bsciic",		"bsciic",	 0, STAR, loc+734,      0, &pspec0 },
// /*323: vchiq0 at fdt? pass 10 */
//     { "vchiq",		"vchiq",	 0, NORM, loc+735,      0, &pspec0 },
// /*324: vcaudio0 at vchiq0 */
//     { "vcaudio",	"vcaudio",	 0, NORM,    NULL,      0, &pspec24 },
// /*325: bcmgpio* at fdt? pass 10 */
//     { "bcmgpio",	"bcmgpio",	 0, STAR, loc+736,      0, &pspec0 },
// /*326: bcmcprman* at fdt? pass 1 */
//     { "bcmcprman",	"bcmcprman_fdt",	 0, STAR, loc+737,      0, &pspec0 },
// /*327: vcmbox* at bcmmbox? */
//     { "vcmbox",		"vcmbox",	 0, STAR,    NULL,      0, &pspec9 },
// /*328: tegra124cpu* at cpu? */
//     { "tegra124cpu",	"tegra124_cpu",	 0, STAR,    NULL,      0, &pspec1 },
// /*329: tegralic* at fdt? pass 1 */
//     { "tegralic",	"tegra_lic",	 0, STAR, loc+738,      0, &pspec0 },
// /*330: tegramc* at fdt? pass 4 */
//     { "tegramc",	"tegra_mc",	 0, STAR, loc+739,      0, &pspec0 },
// /*331: tegrapmc* at fdt? pass 4 */
//     { "tegrapmc",	"tegra_pmc",	 0, STAR, loc+740,      0, &pspec0 },
// /*332: tegrafuse* at fdt? pass 4 */
//     { "tegrafuse",	"tegra_fuse",	 0, STAR, loc+741,      0, &pspec0 },
// /*333: tegra124car* at fdt? pass 3 */
//     { "tegra124car",	"tegra124_car",	 0, STAR, loc+742,      0, &pspec0 },
// /*334: tegra210car* at fdt? pass 3 */
//     { "tegra210car",	"tegra210_car",	 0, STAR, loc+743,      0, &pspec0 },
// /*335: tegragpio* at fdt? pass 2 */
//     { "tegragpio",	"tegra_gpio",	 0, STAR, loc+744,      0, &pspec0 },
// /*336: tegratimer* at fdt? pass 10 */
//     { "tegratimer",	"tegra_timer",	 0, STAR, loc+745,      0, &pspec0 },
// /*337: tegrapinmux* at fdt? pass 10 */
//     { "tegrapinmux",	"tegra_pinmux",	 0, STAR, loc+746,      0, &pspec0 },
// /*338: tegraapbdma* at fdt? pass 4 */
//     { "tegraapbdma",	"tegra_apbdma",	 0, STAR, loc+747,      0, &pspec0 },
// /*339: tegra124xpad* at fdt? pass 10 */
//     { "tegra124xpad",	"tegra124_xusbpad",	 0, STAR, loc+748,      0, &pspec0 },
// /*340: tegra210xpad* at fdt? pass 10 */
//     { "tegra210xpad",	"tegra210_xusbpad",	 0, STAR, loc+749,      0, &pspec0 },
// /*341: tegra210xphy* at tegra210xpad? */
//     { "tegra210xphy",	"tegra210xphy",	 0, STAR,    NULL,      0, &pspec11 },
// /*342: tegrai2c* at fdt? pass 4 */
//     { "tegrai2c",	"tegra_i2c",	 0, STAR, loc+750,      0, &pspec0 },
// /*343: tegrartc* at fdt? pass 10 */
//     { "tegrartc",	"tegra_rtc",	 0, STAR, loc+751,      0, &pspec0 },
// /*344: tegrausbphy* at fdt? pass 10 */
//     { "tegrausbphy",	"tegra_usbphy",	 0, STAR, loc+752,      0, &pspec0 },
// /*345: tegrasoctherm* at fdt? pass 10 */
//     { "tegrasoctherm",	"tegra_soctherm",	 0, STAR, loc+753,      0, &pspec0 },
// /*346: tegrapcie0 at fdt? pass 10 */
//     { "tegrapcie",	"tegra_pcie",	 0, NORM, loc+754,      0, &pspec0 },
// /*347: tegracec0 at fdt? pass 10 */
//     { "tegracec",	"tegra_cec",	 0, NORM, loc+755,      0, &pspec0 },
// /*348: exyointr* at fdt? pass 1 */
//     { "exyointr",	"exynos_intr",	 0, STAR, loc+756,      0, &pspec0 },
// /*349: mct* at fdt? pass 2 */
//     { "mct",		"exyo_mct",	 0, STAR, loc+757,      0, &pspec0 },
// /*350: exuart* at fdt? pass 4 */
//     { "exuart",		"exynos_uart",	 0, STAR, loc+758,      0, &pspec0 },
// /*351: exyopctl* at fdt? pass 2 */
//     { "exyopctl",	"exynos_pinctrl",	 0, STAR, loc+759,      0, &pspec0 },
// /*352: exusbphy* at fdt? pass 9 */
//     { "exusbphy",	"exynos_usbphy",	 0, STAR, loc+760,      0, &pspec0 },
// /*353: exusbdrdphy* at fdt? pass 9 */
//     { "exusbdrdphy",	"exynos_usbdrdphy",	 0, STAR, loc+761,      0, &pspec0 },
// /*354: exyoi2c* at fdt? pass 10 */
//     { "exyoi2c",	"exynos_i2c",	 0, STAR, loc+762,      0, &pspec0 },
// /*355: expwm* at fdt? pass 4 */
//     { "expwm",		"exynos_pwm",	 0, STAR, loc+763,      0, &pspec0 },
// /*356: exy5422clk* at fdt? pass 3 */
//     { "exy5422clk",	"exynos5422_clock",	 0, STAR, loc+764,      0, &pspec0 },
// /*357: exy5410clk* at fdt? pass 3 */
//     { "exy5410clk",	"exynos5410_clock",	 0, STAR, loc+765,      0, &pspec0 },
// /*358: sun4ia10ccu* at fdt? pass 2 */
//     { "sun4ia10ccu",	"sunxi_a10_ccu",	 0, STAR, loc+766,      0, &pspec0 },
// /*359: sun5ia13ccu* at fdt? pass 2 */
//     { "sun5ia13ccu",	"sunxi_a13_ccu",	 0, STAR, loc+767,      0, &pspec0 },
// /*360: sun6ia31ccu* at fdt? pass 2 */
//     { "sun6ia31ccu",	"sunxi_a31_ccu",	 0, STAR, loc+768,      0, &pspec0 },
// /*361: sun8ia83tccu* at fdt? pass 2 */
//     { "sun8ia83tccu",	"sunxi_a83t_ccu",	 0, STAR, loc+769,      0, &pspec0 },
// /*362: sun8ih3ccu* at fdt? pass 2 */
//     { "sun8ih3ccu",	"sunxi_h3_ccu",	 0, STAR, loc+770,      0, &pspec0 },
// /*363: sun8ih3rccu* at fdt? pass 2 */
//     { "sun8ih3rccu",	"sunxi_h3_r_ccu",	 0, STAR, loc+771,      0, &pspec0 },
// /*364: sun9ia80ccu* at fdt? pass 2 */
//     { "sun9ia80ccu",	"sunxi_a80_ccu",	 0, STAR, loc+772,      0, &pspec0 },
// /*365: sunxiresets* at fdt? pass 1 */
//     { "sunxiresets",	"sunxi_resets",	 0, STAR, loc+773,      0, &pspec0 },
// /*366: sunxigates* at fdt? pass 1 */
//     { "sunxigates",	"sunxi_gates",	 0, STAR, loc+774,      0, &pspec0 },
// /*367: sunxigmacclk* at fdt? pass 2 */
//     { "sunxigmacclk",	"sunxi_gmacclk",	 0, STAR, loc+775,      0, &pspec0 },
// /*368: sun9immcclk* at fdt? pass 2 */
//     { "sun9immcclk",	"sunxi_a80_mmcclk",	 0, STAR, loc+776,      0, &pspec0 },
// /*369: sun9iusbclk* at fdt? pass 2 */
//     { "sun9iusbclk",	"sunxi_a80_usbclk",	 0, STAR, loc+777,      0, &pspec0 },
// /*370: sun9icpusclk* at fdt? pass 2 */
//     { "sun9icpusclk",	"sunxi_a80_cpusclk",	 0, STAR, loc+778,      0, &pspec0 },
// /*371: sun8iapbclk* at fdt? pass 2 */
//     { "sun8iapbclk",	"sunxi_a23_apbclk",	 0, STAR, loc+779,      0, &pspec0 },
// /*372: sunxiintc* at fdt? pass 1 */
//     { "sunxiintc",	"sunxi_intc",	 0, STAR, loc+780,      0, &pspec0 },
// /*373: sunxinmi* at fdt? pass 2 */
//     { "sunxinmi",	"sunxi_nmi",	 0, STAR, loc+781,      0, &pspec0 },
// /*374: sunxigpio* at fdt? pass 3 */
//     { "sunxigpio",	"sunxi_gpio",	 0, STAR, loc+782,      0, &pspec0 },
// /*375: sunxipwm* at fdt? pass 3 */
//     { "sunxipwm",	"sunxi_pwm",	 0, STAR, loc+783,      0, &pspec0 },
// /*376: sunximmc* at fdt? pass 10 */
//     { "sunximmc",	"sunxi_mmc",	 0, STAR, loc+784,      0, &pspec0 },
// /*377: sunxiusbphy* at fdt? pass 9 */
//     { "sunxiusbphy",	"sunxi_usbphy",	 0, STAR, loc+785,      0, &pspec0 },
// /*378: sunxiusb3phy* at fdt? pass 9 */
//     { "sunxiusb3phy",	"sunxi_usb3phy",	 0, STAR, loc+786,      0, &pspec0 },
// /*379: sun9iusbphy* at fdt? pass 9 */
//     { "sun9iusbphy",	"sunxi_a80_usbphy",	 0, STAR, loc+787,      0, &pspec0 },
// /*380: sunxitwi* at fdt? pass 10 */
//     { "sunxitwi",	"sunxi_twi",	 0, STAR, loc+651,      0, &pspec0 },
// /*381: sunxirsb* at fdt? pass 4 */
//     { "sunxirsb",	"sunxi_rsb",	 0, STAR, loc+652,      0, &pspec0 },
// /*382: sunxirtc* at fdt? pass 10 */
//     { "sunxirtc",	"sunxi_rtc",	 0, STAR, loc+653,      0, &pspec0 },
// /*383: emac* at fdt? pass 10 */
//     { "emac",		"sun4i_emac",	 0, STAR, loc+654,      0, &pspec0 },
// /*384: emac* at fdt? pass 10 */
//     { "emac",		"sunxi_emac",	 0, STAR, loc+655,      0, &pspec0 },
// /*385: sunxitimer* at fdt? pass 10 */
//     { "sunxitimer",	"sunxi_timer",	 0, STAR, loc+656,      0, &pspec0 },
// /*386: sunxihstimer* at fdt? pass 10 */
//     { "sunxihstimer",	"sunxi_hstimer",	 0, STAR, loc+657,      0, &pspec0 },
// /*387: sunxiwdt* at fdt? pass 10 */
//     { "sunxiwdt",	"sunxi_wdt",	 0, STAR, loc+658,      0, &pspec0 },
// /*388: sun4idma* at fdt? pass 4 */
//     { "sun4idma",	"sun4i_dma",	 0, STAR, loc+659,      0, &pspec0 },
// /*389: sun6idma* at fdt? pass 4 */
//     { "sun6idma",	"sun6i_dma",	 0, STAR, loc+660,      0, &pspec0 },
// /*390: sunxicodec* at fdt? pass 10 */
//     { "sunxicodec",	"sunxi_codec",	 0, STAR, loc+661,      0, &pspec0 },
// /*391: sun8icodec* at fdt? pass 10 */
//     { "sun8icodec",	"sun8i_codec",	 0, STAR, loc+662,      0, &pspec0 },
// /*392: h3codec* at fdt? pass 10 */
//     { "h3codec",	"h3_codec",	 0, STAR, loc+663,      0, &pspec0 },
// /*393: a64acodec* at fdt? pass 10 */
//     { "a64acodec",	"a64_acodec",	 0, STAR, loc+664,      0, &pspec0 },
// /*394: sunxii2s* at fdt? pass 10 */
//     { "sunxii2s",	"sunxi_i2s",	 0, STAR, loc+665,      0, &pspec0 },
// /*395: sunxitcon* at fdt? pass 4 */
//     { "sunxitcon",	"sunxi_tcon",	 0, STAR, loc+666,      0, &pspec0 },
// /*396: sunxidebe* at fdt? pass 4 */
//     { "sunxidebe",	"sunxi_debe",	 0, STAR, loc+667,      0, &pspec0 },
// /*397: sunxihdmi* at fdt? pass 4 */
//     { "sunxihdmi",	"sunxi_hdmi",	 0, STAR, loc+668,      0, &pspec0 },
// /*398: sunxidep* at fdt? pass 5 */
//     { "sunxidep",	"sunxi_dep",	 0, STAR, loc+669,      0, &pspec0 },
// /*399: sunxits* at fdt? pass 10 */
//     { "sunxits",	"sunxi_ts",	 0, STAR, loc+670,      0, &pspec0 },
// /*400: sunxisid* at fdt? pass 4 */
//     { "sunxisid",	"sunxi_sid",	 0, STAR, loc+671,      0, &pspec0 },
// /*401: sunxithermal* at fdt? pass 10 */
//     { "sunxithermal",	"sunxi_thermal",	 0, STAR, loc+672,      0, &pspec0 },
// /*402: sunxisramc* at fdt? pass 4 */
//     { "sunxisramc",	"sunxi_sramc",	 0, STAR, loc+673,      0, &pspec0 },
// /*403: sunxinand* at fdt? pass 10 */
//     { "sunxinand",	"sunxi_nand",	 0, STAR, loc+674,      0, &pspec0 },
// /*404: sun6ispi* at fdt? pass 10 */
//     { "sun6ispi",	"sun6i_spi",	 0, STAR, loc+675,      0, &pspec0 },
// /*405: sunxican* at fdt? pass 10 */
//     { "sunxican",	"sunxi_can",	 0, STAR, loc+676,      0, &pspec0 },
// /*406: sunxilradc* at fdt? pass 10 */
//     { "sunxilradc",	"sunxi_lradc",	 0, STAR, loc+677,      0, &pspec0 },
// /*407: omapintc* at fdt? pass 2 */
//     { "omapintc",	"omapintc",	 0, STAR, loc+678,      0, &pspec0 },
// /*408: tisysc* at fdt? pass 2 */
//     { "tisysc",		"ti_sysc",	 0, STAR, loc+679,      0, &pspec0 },
// /*409: am3prcm* at fdt? pass 1 */
//     { "am3prcm",	"am3_prcm",	 0, STAR, loc+680,      0, &pspec0 },
// /*410: omap3cm* at fdt? pass 1 */
//     { "omap3cm",	"omap3_cm",	 0, STAR, loc+681,      0, &pspec0 },
// /*411: omap3prm* at fdt? pass 1 */
//     { "omap3prm",	"omap3_prm",	 0, STAR, loc+682,      0, &pspec0 },
// /*412: timuxclk* at fdt? pass 1 */
//     { "timuxclk",	"ti_mux_clock",	 0, STAR, loc+683,      0, &pspec0 },
// /*413: tidivclk* at fdt? pass 1 */
//     { "tidivclk",	"ti_div_clock",	 0, STAR, loc+684,      0, &pspec0 },
// /*414: tidpllclk* at fdt? pass 2 */
//     { "tidpllclk",	"ti_dpll_clock",	 0, STAR, loc+685,      0, &pspec0 },
// /*415: omaptimer* at fdt? pass 10 */
//     { "omaptimer",	"omaptimer",	 0, STAR, loc+686,      0, &pspec0 },
// /*416: tigpio* at fdt? pass 2 */
//     { "tigpio",		"ti_gpio",	 0, STAR, loc+687,      0, &pspec0 },
// /*417: tiiic* at fdt? pass 4 */
//     { "tiiic",		"ti_iic",	 0, STAR, loc+688,      0, &pspec0 },
// /*418: cpsw* at fdt? pass 10 */
//     { "cpsw",		"cpsw",		 0, STAR, loc+689,      0, &pspec0 },
// /*419: tiedma* at fdt? pass 4 */
//     { "tiedma",		"ti_edma",	 0, STAR, loc+690,      0, &pspec0 },
// /*420: titptc* at fdt? pass 3 */
//     { "titptc",		"ti_tptc",	 0, STAR, loc+691,      0, &pspec0 },
// /*421: tiotg* at fdt? pass 10 */
//     { "tiotg",		"ti_otg",	 0, STAR, loc+692,      0, &pspec0 },
// /*422: tiusb* at fdt? pass 9 */
//     { "tiusb",		"ti_usb",	 0, STAR, loc+693,      0, &pspec0 },
// /*423: tiusbtll* at fdt? pass 8 */
//     { "tiusbtll",	"ti_usbtll",	 0, STAR, loc+694,      0, &pspec0 },
// /*424: tirng* at fdt? pass 10 */
//     { "tirng",		"ti_rng",	 0, STAR, loc+695,      0, &pspec0 },
// /*425: omapfb* at fdt? pass 10 */
//     { "omapfb",		"omap3_dss",	 0, STAR, loc+696,      0, &pspec0 },
// /*426: tilcdc* at fdt? pass 10 */
//     { "tilcdc",		"ti_lcdc",	 0, STAR, loc+697,      0, &pspec0 },
// /*427: tifb* at tilcdc? */
//     { "tifb",		"ti_fb",	 0, STAR,    NULL,      0, &pspec44 },
// /*428: tigpmc* at fdt? pass 4 */
//     { "tigpmc",		"ti_gpmc",	 0, STAR, loc+698,      0, &pspec0 },
// /*429: omapnand* at fdt? pass 10 */
//     { "omapnand",	"omapnand",	 0, STAR, loc+699,      0, &pspec0 },
// /*430: tiwdt* at fdt? pass 10 */
//     { "tiwdt",		"ti_wdt",	 0, STAR, loc+700,      0, &pspec0 },
// /*431: vxsysreg* at fdt? pass 10 */
//     { "vxsysreg",	"vexpress_sysreg",	 0, STAR, loc+701,      0, &pspec0 },
// /*432: zynquart* at fdt? pass 4 */
//     { "zynquart",	"zynquart",	 0, STAR, loc+702,      0, &pspec0 },
// /*433: cemac* at fdt? pass 10 */
//     { "cemac",		"cemac",	 0, STAR, loc+555,      0, &pspec0 },
    { NULL,		NULL,		 0,    0,    NULL,      0, NULL }
};

// static struct cfattach * const spkr_cfattachinit[] = {
// 	&spkr_audio_ca, NULL
// };
// static struct cfattach * const audio_cfattachinit[] = {
// 	&audio_ca, NULL
// };
// static struct cfattach * const midi_cfattachinit[] = {
// 	&midi_ca, NULL
// };
// static struct cfattach * const hdaudio_cfattachinit[] = {
// 	&tegra_hdaudio_ca, NULL
// };
// static struct cfattach * const hdafg_cfattachinit[] = {
// 	&hdafg_ca, NULL
// };
// static struct cfattach * const video_cfattachinit[] = {
// 	&video_ca, NULL
// };
// static struct cfattach * const dtv_cfattachinit[] = {
// 	&dtv_ca, NULL
// };
// static struct cfattach * const hdmicec_cfattachinit[] = {
// 	&hdmicec_ca, NULL
// };
// static struct cfattach * const iic_cfattachinit[] = {
// 	&iic_ca, NULL
// };
// static struct cfattach * const pcf8563rtc_cfattachinit[] = {
// 	&pcf8563rtc_ca, NULL
// };
// static struct cfattach * const seeprom_cfattachinit[] = {
// 	&seeprom_ca, NULL
// };
// static struct cfattach * const tps65217pmic_cfattachinit[] = {
// 	&tps65217pmic_ca, NULL
// };
// static struct cfattach * const tps65217reg_cfattachinit[] = {
// 	&tps65217reg_ca, NULL
// };
// static struct cfattach * const axp20x_cfattachinit[] = {
// 	&axp20x_ca, NULL
// };
// static struct cfattach * const axp20xreg_cfattachinit[] = {
// 	&axp20xreg_ca, NULL
// };
// static struct cfattach * const axp22x_cfattachinit[] = {
// 	&axp22x_ca, NULL
// };
// static struct cfattach * const axppmic_cfattachinit[] = {
// 	&axppmic_ca, NULL
// };
// static struct cfattach * const axpreg_cfattachinit[] = {
// 	&axpreg_ca, NULL
// };
// static struct cfattach * const ac100ic_cfattachinit[] = {
// 	&ac100ic_ca, NULL
// };
// static struct cfattach * const titemp_cfattachinit[] = {
// 	&titemp_ca, NULL
// };
// static struct cfattach * const as3722pmic_cfattachinit[] = {
// 	&as3722pmic_ca, NULL
// };
// static struct cfattach * const as3722reg_cfattachinit[] = {
// 	&as3722reg_ca, NULL
// };
// static struct cfattach * const tcakp_cfattachinit[] = {
// 	&tcakp_ca, NULL
// };
// static struct cfattach * const max77620pmic_cfattachinit[] = {
// 	&max77620pmic_ca, NULL
// };
// static struct cfattach * const tcagpio_cfattachinit[] = {
// 	&tcagpio_ca, NULL
// };
// static struct cfattach * const sy8106a_cfattachinit[] = {
// 	&sy8106a_ca, NULL
// };
// static struct cfattach * const twl_cfattachinit[] = {
// 	&twl_ca, NULL
// };
// static struct cfattach * const tdahdmi_cfattachinit[] = {
// 	&tdahdmi_ca, NULL
// };
// static struct cfattach * const spi_cfattachinit[] = {
// 	&spi_ca, NULL
// };
// static struct cfattach * const irframe_cfattachinit[] = {
// 	&irframe_ca, NULL
// };
// static struct cfattach * const cir_cfattachinit[] = {
// 	&cir_ca, NULL
// };
// static struct cfattach * const ld_cfattachinit[] = {
// 	&ld_virtio_ca, &ld_nvme_ca, &ld_sdmmc_ca, NULL
// };
// static struct cfattach * const tlphy_cfattachinit[] = {
// 	&tlphy_ca, NULL
// };
// static struct cfattach * const nsphy_cfattachinit[] = {
// 	&nsphy_ca, NULL
// };
// static struct cfattach * const nsphyter_cfattachinit[] = {
// 	&nsphyter_ca, NULL
// };
// static struct cfattach * const gentbi_cfattachinit[] = {
// 	&gentbi_ca, NULL
// };
// static struct cfattach * const glxtphy_cfattachinit[] = {
// 	&glxtphy_ca, NULL
// };
// static struct cfattach * const gphyter_cfattachinit[] = {
// 	&gphyter_ca, NULL
// };
// static struct cfattach * const qsphy_cfattachinit[] = {
// 	&qsphy_ca, NULL
// };
// static struct cfattach * const inphy_cfattachinit[] = {
// 	&inphy_ca, NULL
// };
// static struct cfattach * const iophy_cfattachinit[] = {
// 	&iophy_ca, NULL
// };
// static struct cfattach * const exphy_cfattachinit[] = {
// 	&exphy_ca, NULL
// };
// static struct cfattach * const lxtphy_cfattachinit[] = {
// 	&lxtphy_ca, NULL
// };
// static struct cfattach * const makphy_cfattachinit[] = {
// 	&makphy_ca, NULL
// };
// static struct cfattach * const icsphy_cfattachinit[] = {
// 	&icsphy_ca, NULL
// };
// static struct cfattach * const igphy_cfattachinit[] = {
// 	&igphy_ca, NULL
// };
// static struct cfattach * const ikphy_cfattachinit[] = {
// 	&ikphy_ca, NULL
// };
// static struct cfattach * const sqphy_cfattachinit[] = {
// 	&sqphy_ca, NULL
// };
// static struct cfattach * const tqphy_cfattachinit[] = {
// 	&tqphy_ca, NULL
// };
// static struct cfattach * const pnaphy_cfattachinit[] = {
// 	&pnaphy_ca, NULL
// };
// static struct cfattach * const rgephy_cfattachinit[] = {
// 	&rgephy_ca, NULL
// };
// static struct cfattach * const urlphy_cfattachinit[] = {
// 	&urlphy_ca, NULL
// };
// static struct cfattach * const ukphy_cfattachinit[] = {
// 	&ukphy_ca, NULL
// };
// static struct cfattach * const rlphy_cfattachinit[] = {
// 	&rlphy_ca, NULL
// };
// static struct cfattach * const ihphy_cfattachinit[] = {
// 	&ihphy_ca, NULL
// };
// static struct cfattach * const rdcphy_cfattachinit[] = {
// 	&rdcphy_ca, NULL
// };
// static struct cfattach * const awge_cfattachinit[] = {
// 	&cycv_gmac_ca, &meson_dwmac_ca, &sunxi_gmac_ca, NULL
// };
// static struct cfattach * const com_cfattachinit[] = {
// 	&dw_apb_uart_ca, &bcmcom_ca, &tegra_com_ca, &ti_com_ca, NULL
// };
// static struct cfattach * const re_cfattachinit[] = {
// 	&re_pci_ca, NULL
// };
// static struct cfattach * const virtio_cfattachinit[] = {
// 	&virtio_mmio_fdt_ca, &virtio_pci_ca, NULL
// };
// static struct cfattach * const vioif_cfattachinit[] = {
// 	&vioif_ca, NULL
// };
// static struct cfattach * const viornd_cfattachinit[] = {
// 	&viornd_ca, NULL
// };
// static struct cfattach * const vioscsi_cfattachinit[] = {
// 	&vioscsi_ca, NULL
// };
// static struct cfattach * const atabus_cfattachinit[] = {
// 	&atabus_ca, NULL
// };
// static struct cfattach * const ahcisata_cfattachinit[] = {
// 	&ahcisata_fdt_ca, &ahcisata_pci_ca, &tegra_ahcisata_ca, &sunxi_sata_ca, NULL
// };
// static struct cfattach * const smsh_cfattachinit[] = {
// 	&smsh_fdt_ca, NULL
// };
// static struct cfattach * const wsdisplay_cfattachinit[] = {
// 	&wsdisplay_emul_ca, NULL
// };
// static struct cfattach * const wskbd_cfattachinit[] = {
// 	&wskbd_ca, NULL
// };
// static struct cfattach * const wsmouse_cfattachinit[] = {
// 	&wsmouse_ca, NULL
// };
// static struct cfattach * const genfb_cfattachinit[] = {
// 	&simplefb_ca, &plfb_fdt_ca, &bcmgenfb_ca, &sunxi_befb_ca, NULL
// };
// static struct cfattach * const ohci_cfattachinit[] = {
// 	&exynos_ohci_ca, &ohci_fdt_ca, NULL
// };
// static struct cfattach * const ehci_cfattachinit[] = {
// 	&tegra_ehci_ca, &exynos_ehci_ca, &ehci_fdt_ca, &ti_ehci_ca, &zynqusb_ca, NULL
// };
// static struct cfattach * const xhci_cfattachinit[] = {
// 	&dwc3_fdt_ca, &tegra_xusb_ca, NULL
// };
// static struct cfattach * const motg_cfattachinit[] = {
// 	&sunxi_musb_ca, &ti_motg_ca, NULL
// };
// static struct cfattach * const dwctwo_cfattachinit[] = {
// 	&dwc2_fdt_ca, &bcmdwctwo_ca, NULL
// };
// static struct cfattach * const sdhc_cfattachinit[] = {
// 	&arasan_sdhc_fdt_ca, &bcmemmc_ca, &tegra_sdhc_ca, &ti_sdhc_ca, &sdhc_fdt_ca, NULL
// };
// static struct cfattach * const dwcmmc_cfattachinit[] = {
// 	&dwcmmc_fdt_ca, &cycv_dwcmmc_ca, &exynos_dwcmmc_ca, NULL
// };
// static struct cfattach * const plrtc_cfattachinit[] = {
// 	&plrtc_fdt_ca, NULL
// };
// static struct cfattach * const aaci_cfattachinit[] = {
// 	&aaci_fdt_ca, NULL
// };
// static struct cfattach * const plkmi_cfattachinit[] = {
// 	&plkmi_fdt_ca, NULL
// };
// static struct cfattach * const plgpio_cfattachinit[] = {
// 	&plgpio_fdt_ca, NULL
// };
// static struct cfattach * const plmmc_cfattachinit[] = {
// 	&plmmc_fdt_ca, NULL
// };
// static struct cfattach * const radio_cfattachinit[] = {
// 	&radio_ca, NULL
// };
// static struct cfattach * const nvme_cfattachinit[] = {
// 	&nvme_pci_ca, NULL
// };
// static struct cfattach * const bwfm_cfattachinit[] = {
// 	&bwfm_usb_ca, NULL
// };
// static struct cfattach * const qemufwcfg_cfattachinit[] = {
// 	&qemufwcfg_fdt_ca, NULL
// };
// static struct cfattach * const gpio_cfattachinit[] = {
// 	&gpio_ca, NULL
// };
// static struct cfattach * const flash_cfattachinit[] = {
// 	&flash_ca, NULL
// };
// static struct cfattach * const nand_cfattachinit[] = {
// 	&nand_ca, NULL
// };
// static struct cfattach * const athn_cfattachinit[] = {
// 	&athn_usb_ca, NULL
// };
// static struct cfattach * const simplebus_cfattachinit[] = {
// 	&simplebus_ca, NULL
// };
// static struct cfattach * const fregulator_cfattachinit[] = {
// 	&fregulator_ca, NULL
// };
// static struct cfattach * const gregulator_cfattachinit[] = {
// 	&gregulator_ca, NULL
// };
// static struct cfattach * const fclock_cfattachinit[] = {
// 	&fclock_ca, NULL
// };
// static struct cfattach * const ffclock_cfattachinit[] = {
// 	&ffclock_ca, NULL
// };
// static struct cfattach * const gpiokeys_cfattachinit[] = {
// 	&gpiokeys_ca, NULL
// };
// static struct cfattach * const gpioleds_cfattachinit[] = {
// 	&gpioleds_ca, NULL
// };
// static struct cfattach * const connector_cfattachinit[] = {
// 	&fdt_connector_ca, NULL
// };
// static struct cfattach * const panel_cfattachinit[] = {
// 	&fdt_panel_ca, &panel_fdt_ca, NULL
// };
// static struct cfattach * const cpus_cfattachinit[] = {
// 	&cpus_ca, NULL
// };
// static struct cfattach * const mmcpwrseq_cfattachinit[] = {
// 	&mmcpwrseq_simple_ca, &mmcpwrseq_emmc_ca, NULL
// };
// static struct cfattach * const syscon_cfattachinit[] = {
// 	&syscon_ca, NULL
// };
// static struct cfattach * const pinctrl_cfattachinit[] = {
// 	&pinctrl_single_ca, NULL
// };
// static struct cfattach * const pwmbacklight_cfattachinit[] = {
// 	&pwmbacklight_ca, NULL
// };
// static struct cfattach * const pwmfan_cfattachinit[] = {
// 	&pwmfan_ca, NULL
// };
// static struct cfattach * const ausoc_cfattachinit[] = {
// 	&ausoc_ca, NULL
// };
// static struct cfattach * const dwcwdt_cfattachinit[] = {
// 	&dwcwdt_fdt_ca, NULL
// };
// static struct cfattach * const usbnopphy_cfattachinit[] = {
// 	&usbnopphy_ca, NULL
// };
// static struct cfattach * const psci_cfattachinit[] = {
// 	&psci_fdt_ca, NULL
// };
// static struct cfattach * const cpu_cfattachinit[] = {
// 	&cpu_fdt_ca, NULL
// };
// static struct cfattach * const wd_cfattachinit[] = {
// 	&wd_ca, NULL
// };
// static struct cfattach * const bthub_cfattachinit[] = {
// 	&bthub_ca, NULL
// };
// static struct cfattach * const pci_cfattachinit[] = {
// 	&pci_ca, NULL
// };
// static struct cfattach * const ppb_cfattachinit[] = {
// 	&ppb_ca, NULL
// };
// static struct cfattach * const sdmmc_cfattachinit[] = {
// 	&sdmmc_ca, NULL
// };
// static struct cfattach * const scsibus_cfattachinit[] = {
// 	&scsibus_ca, NULL
// };
// static struct cfattach * const atapibus_cfattachinit[] = {
// 	&atapibus_ca, NULL
// };
// static struct cfattach * const cd_cfattachinit[] = {
// 	&cd_ca, NULL
// };
// static struct cfattach * const ch_cfattachinit[] = {
// 	&ch_ca, NULL
// };
// static struct cfattach * const sd_cfattachinit[] = {
// 	&sd_ca, NULL
// };
// static struct cfattach * const st_cfattachinit[] = {
// 	&st_scsibus_ca, &st_atapibus_ca, NULL
// };
// static struct cfattach * const ses_cfattachinit[] = {
// 	&ses_ca, NULL
// };
// static struct cfattach * const ss_cfattachinit[] = {
// 	&ss_ca, NULL
// };
// static struct cfattach * const uk_cfattachinit[] = {
// 	&uk_ca, NULL
// };
static struct cfattach * const usb_cfattachinit[] = {
	&usb_ca, NULL
};
static struct cfattach * const uhub_cfattachinit[] = {
	&uroothub_ca, &uhub_ca, NULL
};
// static struct cfattach * const uaudio_cfattachinit[] = {
// 	&uaudio_ca, NULL
// };
// static struct cfattach * const umidi_cfattachinit[] = {
// 	&umidi_ca, NULL
// };
// static struct cfattach * const ucom_cfattachinit[] = {
// 	&ucom_ca, NULL
// };
// static struct cfattach * const ugen_cfattachinit[] = {
// 	&ugen_ca, NULL
// };
// static struct cfattach * const ugenif_cfattachinit[] = {
// 	&ugenif_ca, NULL
// };
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
// static struct cfattach * const uts_cfattachinit[] = {
// 	&uts_ca, NULL
// };
// static struct cfattach * const uep_cfattachinit[] = {
// 	&uep_ca, NULL
// };
// static struct cfattach * const ucycom_cfattachinit[] = {
// 	&ucycom_ca, NULL
// };
// static struct cfattach * const ulpt_cfattachinit[] = {
// 	&ulpt_ca, NULL
// };
// static struct cfattach * const umass_cfattachinit[] = {
// 	&umass_ca, NULL
// };
// static struct cfattach * const uirda_cfattachinit[] = {
// 	&uirda_ca, NULL
// };
// static struct cfattach * const stuirda_cfattachinit[] = {
// 	&stuirda_ca, NULL
// };
// static struct cfattach * const ustir_cfattachinit[] = {
// 	&ustir_ca, NULL
// };
// static struct cfattach * const irmce_cfattachinit[] = {
// 	&irmce_ca, NULL
// };
// static struct cfattach * const ubt_cfattachinit[] = {
// 	&ubt_ca, NULL
// };
// static struct cfattach * const aubtfwl_cfattachinit[] = {
// 	&aubtfwl_ca, NULL
// };
// static struct cfattach * const pseye_cfattachinit[] = {
// 	&pseye_ca, NULL
// };
// static struct cfattach * const uvideo_cfattachinit[] = {
// 	&uvideo_ca, NULL
// };
// static struct cfattach * const auvitek_cfattachinit[] = {
// 	&auvitek_ca, NULL
// };
// static struct cfattach * const emdtv_cfattachinit[] = {
// 	&emdtv_ca, NULL
// };
// static struct cfattach * const umodeswitch_cfattachinit[] = {
// 	&umodeswitch_ca, NULL
// };
// static struct cfattach * const urio_cfattachinit[] = {
// 	&urio_ca, NULL
// };
// static struct cfattach * const uipad_cfattachinit[] = {
// 	&uipad_ca, NULL
// };
// static struct cfattach * const uberry_cfattachinit[] = {
// 	&uberry_ca, NULL
// };
// static struct cfattach * const uvisor_cfattachinit[] = {
// 	&uvisor_ca, NULL
// };
// static struct cfattach * const ugensa_cfattachinit[] = {
// 	&ugensa_ca, NULL
// };
// static struct cfattach * const u3g_cfattachinit[] = {
// 	&u3g_ca, NULL
// };
// static struct cfattach * const uyap_cfattachinit[] = {
// 	&uyap_ca, NULL
// };
// static struct cfattach * const udsbr_cfattachinit[] = {
// 	&udsbr_ca, NULL
// };
// static struct cfattach * const slurm_cfattachinit[] = {
// 	&slurm_ca, NULL
// };
// static struct cfattach * const uthum_cfattachinit[] = {
// 	&uthum_ca, NULL
// };
// static struct cfattach * const aue_cfattachinit[] = {
// 	&aue_ca, NULL
// };
// static struct cfattach * const cdce_cfattachinit[] = {
// 	&cdce_ca, NULL
// };
// static struct cfattach * const cue_cfattachinit[] = {
// 	&cue_ca, NULL
// };
// static struct cfattach * const kue_cfattachinit[] = {
// 	&kue_ca, NULL
// };
// static struct cfattach * const upl_cfattachinit[] = {
// 	&upl_ca, NULL
// };
// static struct cfattach * const url_cfattachinit[] = {
// 	&url_ca, NULL
// };
// static struct cfattach * const axe_cfattachinit[] = {
// 	&axe_ca, NULL
// };
// static struct cfattach * const axen_cfattachinit[] = {
// 	&axen_ca, NULL
// };
// static struct cfattach * const mue_cfattachinit[] = {
// 	&mue_ca, NULL
// };
// static struct cfattach * const udav_cfattachinit[] = {
// 	&udav_ca, NULL
// };
// static struct cfattach * const otus_cfattachinit[] = {
// 	&otus_ca, NULL
// };
// static struct cfattach * const ure_cfattachinit[] = {
// 	&ure_ca, NULL
// };
// static struct cfattach * const umodem_cfattachinit[] = {
// 	&umodem_ca, NULL
// };
// static struct cfattach * const uftdi_cfattachinit[] = {
// 	&uftdi_ca, NULL
// };
// static struct cfattach * const uplcom_cfattachinit[] = {
// 	&uplcom_ca, NULL
// };
// static struct cfattach * const umct_cfattachinit[] = {
// 	&umct_ca, NULL
// };
// static struct cfattach * const umcs_cfattachinit[] = {
// 	&umcs_ca, NULL
// };
// static struct cfattach * const uvscom_cfattachinit[] = {
// 	&uvscom_ca, NULL
// };
// static struct cfattach * const uxrcom_cfattachinit[] = {
// 	&uxrcom_ca, NULL
// };
// static struct cfattach * const ubsa_cfattachinit[] = {
// 	&ubsa_ca, NULL
// };
// static struct cfattach * const uipaq_cfattachinit[] = {
// 	&uipaq_ca, NULL
// };
// static struct cfattach * const ukyopon_cfattachinit[] = {
// 	&ukyopon_ca, NULL
// };
// static struct cfattach * const uark_cfattachinit[] = {
// 	&uark_ca, NULL
// };
// static struct cfattach * const uslsa_cfattachinit[] = {
// 	&uslsa_ca, NULL
// };
// static struct cfattach * const uchcom_cfattachinit[] = {
// 	&uchcom_ca, NULL
// };
// static struct cfattach * const usscanner_cfattachinit[] = {
// 	&usscanner_ca, NULL
// };
// static struct cfattach * const atu_cfattachinit[] = {
// 	&atu_ca, NULL
// };
// static struct cfattach * const upgt_cfattachinit[] = {
// 	&upgt_ca, NULL
// };
// static struct cfattach * const usmsc_cfattachinit[] = {
// 	&usmsc_ca, NULL
// };
// static struct cfattach * const ural_cfattachinit[] = {
// 	&ural_ca, NULL
// };
// static struct cfattach * const rum_cfattachinit[] = {
// 	&rum_ca, NULL
// };
// static struct cfattach * const utoppy_cfattachinit[] = {
// 	&utoppy_ca, NULL
// };
// static struct cfattach * const zyd_cfattachinit[] = {
// 	&zyd_ca, NULL
// };
// static struct cfattach * const udl_cfattachinit[] = {
// 	&udl_ca, NULL
// };
// static struct cfattach * const uhso_cfattachinit[] = {
// 	&uhso_ca, NULL
// };
// static struct cfattach * const urndis_cfattachinit[] = {
// 	&urndis_ca, NULL
// };
// static struct cfattach * const urtwn_cfattachinit[] = {
// 	&urtwn_ca, NULL
// };
// static struct cfattach * const urtw_cfattachinit[] = {
// 	&urtw_ca, NULL
// };
// static struct cfattach * const run_cfattachinit[] = {
// 	&run_ca, NULL
// };
// static struct cfattach * const udsir_cfattachinit[] = {
// 	&udsir_ca, NULL
// };
// static struct cfattach * const plcom_cfattachinit[] = {
// 	&plcom_fdt_ca, NULL
// };
// static struct cfattach * const armgic_cfattachinit[] = {
// 	&armgic_ca, NULL
// };
// static struct cfattach * const arml2cc_cfattachinit[] = {
// 	&arml2cc_ca, NULL
// };
// static struct cfattach * const armgtmr_cfattachinit[] = {
// 	&armgtmr_ca, NULL
// };
// static struct cfattach * const arma9tmr_cfattachinit[] = {
// 	&arma9tmr_ca, NULL
// };
// static struct cfattach * const arma9ptmr_cfattachinit[] = {
// 	&arma9ptmr_ca, NULL
// };
// static struct cfattach * const pckbd_cfattachinit[] = {
// 	&pckbd_ca, NULL
// };
// static struct cfattach * const pms_cfattachinit[] = {
// 	&pms_ca, NULL
// };
// static struct cfattach * const armfdt_cfattachinit[] = {
// 	&arm_fdt_ca, NULL
// };
// static struct cfattach * const cpufreqdt_cfattachinit[] = {
// 	&cpufreq_dt_ca, NULL
// };
// static struct cfattach * const a9tmr_cfattachinit[] = {
// 	&a9tmr_fdt_ca, NULL
// };
// static struct cfattach * const a9ptmr_cfattachinit[] = {
// 	&a9ptmr_fdt_ca, NULL
// };
// static struct cfattach * const gtmr_cfattachinit[] = {
// 	&gtmr_fdt_ca, NULL
// };
// static struct cfattach * const gic_cfattachinit[] = {
// 	&gic_fdt_ca, NULL
// };
// static struct cfattach * const l2cc_cfattachinit[] = {
// 	&l2cc_fdt_ca, NULL
// };
// static struct cfattach * const pcihost_cfattachinit[] = {
// 	&pcihost_fdt_ca, NULL
// };
// static struct cfattach * const armpmu_cfattachinit[] = {
// 	&pmu_fdt_ca, NULL
// };
// static struct cfattach * const cycvclkmgr_cfattachinit[] = {
// 	&cycvclkmgr_ca, NULL
// };
// static struct cfattach * const cycvrstmgr_cfattachinit[] = {
// 	&cycvrstmgr_ca, NULL
// };
// static struct cfattach * const meson8bclkc_cfattachinit[] = {
// 	&meson8b_clkc_ca, NULL
// };
// static struct cfattach * const mesonresets_cfattachinit[] = {
// 	&meson_resets_ca, NULL
// };
// static struct cfattach * const mesonuart_cfattachinit[] = {
// 	&meson_uart_ca, NULL
// };
// static struct cfattach * const mesonfb_cfattachinit[] = {
// 	&meson_genfb_ca, NULL
// };
// static struct cfattach * const mesonpinctrl_cfattachinit[] = {
// 	&meson_pinctrl_ca, NULL
// };
// static struct cfattach * const mesonsdhc_cfattachinit[] = {
// 	&meson_sdhc_ca, NULL
// };
// static struct cfattach * const mesonsdio_cfattachinit[] = {
// 	&meson_sdio_ca, NULL
// };
// static struct cfattach * const mesonusbphy_cfattachinit[] = {
// 	&meson_usbphy_ca, NULL
// };
// static struct cfattach * const mesonrtc_cfattachinit[] = {
// 	&meson_rtc_ca, NULL
// };
// static struct cfattach * const mesonrng_cfattachinit[] = {
// 	&meson_rng_ca, NULL
// };
// static struct cfattach * const mesonwdt_cfattachinit[] = {
// 	&meson_wdt_ca, NULL
// };
// static struct cfattach * const bcmicu_cfattachinit[] = {
// 	&bcmicu_ca, NULL
// };
// static struct cfattach * const bcmmbox_cfattachinit[] = {
// 	&bcmmbox_ca, NULL
// };
// static struct cfattach * const bcmpmwdog_cfattachinit[] = {
// 	&bcmpmwdog_fdt_ca, NULL
// };
// static struct cfattach * const bcmrng_cfattachinit[] = {
// 	&bcmrng_fdt_ca, NULL
// };
// static struct cfattach * const bcmaux_cfattachinit[] = {
// 	&bcmaux_fdt_ca, NULL
// };
// static struct cfattach * const bcmsdhost_cfattachinit[] = {
// 	&bcmsdhost_ca, NULL
// };
// static struct cfattach * const bcmdmac_cfattachinit[] = {
// 	&bcmdmac_fdt_ca, NULL
// };
// static struct cfattach * const bcmspi_cfattachinit[] = {
// 	&bcmspi_ca, NULL
// };
// static struct cfattach * const bsciic_cfattachinit[] = {
// 	&bsciic_ca, NULL
// };
// static struct cfattach * const vchiq_cfattachinit[] = {
// 	&vchiq_ca, NULL
// };
// static struct cfattach * const vcaudio_cfattachinit[] = {
// 	&vcaudio_ca, NULL
// };
// static struct cfattach * const bcmgpio_cfattachinit[] = {
// 	&bcmgpio_ca, NULL
// };
// static struct cfattach * const bcmcprman_cfattachinit[] = {
// 	&bcmcprman_fdt_ca, NULL
// };
// static struct cfattach * const vcmbox_cfattachinit[] = {
// 	&vcmbox_ca, NULL
// };
// static struct cfattach * const tegra124cpu_cfattachinit[] = {
// 	&tegra124_cpu_ca, NULL
// };
// static struct cfattach * const tegralic_cfattachinit[] = {
// 	&tegra_lic_ca, NULL
// };
// static struct cfattach * const tegramc_cfattachinit[] = {
// 	&tegra_mc_ca, NULL
// };
// static struct cfattach * const tegrapmc_cfattachinit[] = {
// 	&tegra_pmc_ca, NULL
// };
// static struct cfattach * const tegrafuse_cfattachinit[] = {
// 	&tegra_fuse_ca, NULL
// };
// static struct cfattach * const tegra124car_cfattachinit[] = {
// 	&tegra124_car_ca, NULL
// };
// static struct cfattach * const tegra210car_cfattachinit[] = {
// 	&tegra210_car_ca, NULL
// };
// static struct cfattach * const tegragpio_cfattachinit[] = {
// 	&tegra_gpio_ca, NULL
// };
// static struct cfattach * const tegratimer_cfattachinit[] = {
// 	&tegra_timer_ca, NULL
// };
// static struct cfattach * const tegrapinmux_cfattachinit[] = {
// 	&tegra_pinmux_ca, NULL
// };
// static struct cfattach * const tegraapbdma_cfattachinit[] = {
// 	&tegra_apbdma_ca, NULL
// };
// static struct cfattach * const tegra124xpad_cfattachinit[] = {
// 	&tegra124_xusbpad_ca, NULL
// };
// static struct cfattach * const tegra210xpad_cfattachinit[] = {
// 	&tegra210_xusbpad_ca, NULL
// };
// static struct cfattach * const tegra210xphy_cfattachinit[] = {
// 	&tegra210xphy_ca, NULL
// };
// static struct cfattach * const tegrai2c_cfattachinit[] = {
// 	&tegra_i2c_ca, NULL
// };
// static struct cfattach * const tegrartc_cfattachinit[] = {
// 	&tegra_rtc_ca, NULL
// };
// static struct cfattach * const tegrausbphy_cfattachinit[] = {
// 	&tegra_usbphy_ca, NULL
// };
// static struct cfattach * const tegrasoctherm_cfattachinit[] = {
// 	&tegra_soctherm_ca, NULL
// };
// static struct cfattach * const tegrapcie_cfattachinit[] = {
// 	&tegra_pcie_ca, NULL
// };
// static struct cfattach * const tegracec_cfattachinit[] = {
// 	&tegra_cec_ca, NULL
// };
// static struct cfattach * const exyointr_cfattachinit[] = {
// 	&exynos_intr_ca, NULL
// };
// static struct cfattach * const mct_cfattachinit[] = {
// 	&exyo_mct_ca, NULL
// };
// static struct cfattach * const exuart_cfattachinit[] = {
// 	&exynos_uart_ca, NULL
// };
// static struct cfattach * const exyopctl_cfattachinit[] = {
// 	&exynos_pinctrl_ca, NULL
// };
// static struct cfattach * const exusbphy_cfattachinit[] = {
// 	&exynos_usbphy_ca, NULL
// };
// static struct cfattach * const exusbdrdphy_cfattachinit[] = {
// 	&exynos_usbdrdphy_ca, NULL
// };
// static struct cfattach * const exyoi2c_cfattachinit[] = {
// 	&exynos_i2c_ca, NULL
// };
// static struct cfattach * const expwm_cfattachinit[] = {
// 	&exynos_pwm_ca, NULL
// };
// static struct cfattach * const exy5422clk_cfattachinit[] = {
// 	&exynos5422_clock_ca, NULL
// };
// static struct cfattach * const exy5410clk_cfattachinit[] = {
// 	&exynos5410_clock_ca, NULL
// };
// static struct cfattach * const sun4ia10ccu_cfattachinit[] = {
// 	&sunxi_a10_ccu_ca, NULL
// };
// static struct cfattach * const sun5ia13ccu_cfattachinit[] = {
// 	&sunxi_a13_ccu_ca, NULL
// };
// static struct cfattach * const sun6ia31ccu_cfattachinit[] = {
// 	&sunxi_a31_ccu_ca, NULL
// };
// static struct cfattach * const sun8ia83tccu_cfattachinit[] = {
// 	&sunxi_a83t_ccu_ca, NULL
// };
// static struct cfattach * const sun8ih3ccu_cfattachinit[] = {
// 	&sunxi_h3_ccu_ca, NULL
// };
// static struct cfattach * const sun8ih3rccu_cfattachinit[] = {
// 	&sunxi_h3_r_ccu_ca, NULL
// };
// static struct cfattach * const sun9ia80ccu_cfattachinit[] = {
// 	&sunxi_a80_ccu_ca, NULL
// };
// static struct cfattach * const sunxiresets_cfattachinit[] = {
// 	&sunxi_resets_ca, NULL
// };
// static struct cfattach * const sunxigates_cfattachinit[] = {
// 	&sunxi_gates_ca, NULL
// };
// static struct cfattach * const sunxigmacclk_cfattachinit[] = {
// 	&sunxi_gmacclk_ca, NULL
// };
// static struct cfattach * const sun9immcclk_cfattachinit[] = {
// 	&sunxi_a80_mmcclk_ca, NULL
// };
// static struct cfattach * const sun9iusbclk_cfattachinit[] = {
// 	&sunxi_a80_usbclk_ca, NULL
// };
// static struct cfattach * const sun9icpusclk_cfattachinit[] = {
// 	&sunxi_a80_cpusclk_ca, NULL
// };
// static struct cfattach * const sun8iapbclk_cfattachinit[] = {
// 	&sunxi_a23_apbclk_ca, NULL
// };
// static struct cfattach * const sunxiintc_cfattachinit[] = {
// 	&sunxi_intc_ca, NULL
// };
// static struct cfattach * const sunxinmi_cfattachinit[] = {
// 	&sunxi_nmi_ca, NULL
// };
// static struct cfattach * const sunxigpio_cfattachinit[] = {
// 	&sunxi_gpio_ca, NULL
// };
// static struct cfattach * const sunxipwm_cfattachinit[] = {
// 	&sunxi_pwm_ca, NULL
// };
// static struct cfattach * const sunximmc_cfattachinit[] = {
// 	&sunxi_mmc_ca, NULL
// };
// static struct cfattach * const sunxiusbphy_cfattachinit[] = {
// 	&sunxi_usbphy_ca, NULL
// };
// static struct cfattach * const sunxiusb3phy_cfattachinit[] = {
// 	&sunxi_usb3phy_ca, NULL
// };
// static struct cfattach * const sun9iusbphy_cfattachinit[] = {
// 	&sunxi_a80_usbphy_ca, NULL
// };
// static struct cfattach * const sunxitwi_cfattachinit[] = {
// 	&sunxi_twi_ca, NULL
// };
// static struct cfattach * const sunxirsb_cfattachinit[] = {
// 	&sunxi_rsb_ca, NULL
// };
// static struct cfattach * const sunxirtc_cfattachinit[] = {
// 	&sunxi_rtc_ca, NULL
// };
// static struct cfattach * const emac_cfattachinit[] = {
// 	&sun4i_emac_ca, &sunxi_emac_ca, NULL
// };
// static struct cfattach * const sunxitimer_cfattachinit[] = {
// 	&sunxi_timer_ca, NULL
// };
// static struct cfattach * const sunxihstimer_cfattachinit[] = {
// 	&sunxi_hstimer_ca, NULL
// };
// static struct cfattach * const sunxiwdt_cfattachinit[] = {
// 	&sunxi_wdt_ca, NULL
// };
// static struct cfattach * const sun4idma_cfattachinit[] = {
// 	&sun4i_dma_ca, NULL
// };
// static struct cfattach * const sun6idma_cfattachinit[] = {
// 	&sun6i_dma_ca, NULL
// };
// static struct cfattach * const sunxicodec_cfattachinit[] = {
// 	&sunxi_codec_ca, NULL
// };
// static struct cfattach * const sun8icodec_cfattachinit[] = {
// 	&sun8i_codec_ca, NULL
// };
// static struct cfattach * const h3codec_cfattachinit[] = {
// 	&h3_codec_ca, NULL
// };
// static struct cfattach * const a64acodec_cfattachinit[] = {
// 	&a64_acodec_ca, NULL
// };
// static struct cfattach * const sunxii2s_cfattachinit[] = {
// 	&sunxi_i2s_ca, NULL
// };
// static struct cfattach * const sunxitcon_cfattachinit[] = {
// 	&sunxi_tcon_ca, NULL
// };
// static struct cfattach * const sunxidebe_cfattachinit[] = {
// 	&sunxi_debe_ca, NULL
// };
// static struct cfattach * const sunxihdmi_cfattachinit[] = {
// 	&sunxi_hdmi_ca, NULL
// };
// static struct cfattach * const sunxidep_cfattachinit[] = {
// 	&sunxi_dep_ca, NULL
// };
// static struct cfattach * const sunxits_cfattachinit[] = {
// 	&sunxi_ts_ca, NULL
// };
// static struct cfattach * const sunxisid_cfattachinit[] = {
// 	&sunxi_sid_ca, NULL
// };
// static struct cfattach * const sunxithermal_cfattachinit[] = {
// 	&sunxi_thermal_ca, NULL
// };
// static struct cfattach * const sunxisramc_cfattachinit[] = {
// 	&sunxi_sramc_ca, NULL
// };
// static struct cfattach * const sunxinand_cfattachinit[] = {
// 	&sunxi_nand_ca, NULL
// };
// static struct cfattach * const sun6ispi_cfattachinit[] = {
// 	&sun6i_spi_ca, NULL
// };
// static struct cfattach * const sunxican_cfattachinit[] = {
// 	&sunxi_can_ca, NULL
// };
// static struct cfattach * const sunxilradc_cfattachinit[] = {
// 	&sunxi_lradc_ca, NULL
// };
// static struct cfattach * const omapintc_cfattachinit[] = {
// 	&omapintc_ca, NULL
// };
// static struct cfattach * const tisysc_cfattachinit[] = {
// 	&ti_sysc_ca, NULL
// };
// static struct cfattach * const am3prcm_cfattachinit[] = {
// 	&am3_prcm_ca, NULL
// };
// static struct cfattach * const omap3cm_cfattachinit[] = {
// 	&omap3_cm_ca, NULL
// };
// static struct cfattach * const omap3prm_cfattachinit[] = {
// 	&omap3_prm_ca, NULL
// };
// static struct cfattach * const timuxclk_cfattachinit[] = {
// 	&ti_mux_clock_ca, NULL
// };
// static struct cfattach * const tidivclk_cfattachinit[] = {
// 	&ti_div_clock_ca, NULL
// };
// static struct cfattach * const tidpllclk_cfattachinit[] = {
// 	&ti_dpll_clock_ca, NULL
// };
// static struct cfattach * const omaptimer_cfattachinit[] = {
// 	&omaptimer_ca, NULL
// };
// static struct cfattach * const tigpio_cfattachinit[] = {
// 	&ti_gpio_ca, NULL
// };
// static struct cfattach * const tiiic_cfattachinit[] = {
// 	&ti_iic_ca, NULL
// };
// static struct cfattach * const cpsw_cfattachinit[] = {
// 	&cpsw_ca, NULL
// };
// static struct cfattach * const tiedma_cfattachinit[] = {
// 	&ti_edma_ca, NULL
// };
// static struct cfattach * const titptc_cfattachinit[] = {
// 	&ti_tptc_ca, NULL
// };
// static struct cfattach * const tiotg_cfattachinit[] = {
// 	&ti_otg_ca, NULL
// };
// static struct cfattach * const tiusb_cfattachinit[] = {
// 	&ti_usb_ca, NULL
// };
// static struct cfattach * const tiusbtll_cfattachinit[] = {
// 	&ti_usbtll_ca, NULL
// };
// static struct cfattach * const tirng_cfattachinit[] = {
// 	&ti_rng_ca, NULL
// };
// static struct cfattach * const omapfb_cfattachinit[] = {
// 	&omap3_dss_ca, NULL
// };
// static struct cfattach * const tilcdc_cfattachinit[] = {
// 	&ti_lcdc_ca, NULL
// };
// static struct cfattach * const tifb_cfattachinit[] = {
// 	&ti_fb_ca, NULL
// };
// static struct cfattach * const tigpmc_cfattachinit[] = {
// 	&ti_gpmc_ca, NULL
// };
// static struct cfattach * const omapnand_cfattachinit[] = {
// 	&omapnand_ca, NULL
// };
// static struct cfattach * const tiwdt_cfattachinit[] = {
// 	&ti_wdt_ca, NULL
// };
// static struct cfattach * const vxsysreg_cfattachinit[] = {
// 	&vexpress_sysreg_ca, NULL
// };
// static struct cfattach * const zynquart_cfattachinit[] = {
// 	&zynquart_ca, NULL
// };
// static struct cfattach * const cemac_cfattachinit[] = {
// 	&cemac_ca, NULL
// };

const struct cfattachinit cfattachinit[] = {
	// { "spkr", spkr_cfattachinit },
	// { "audio", audio_cfattachinit },
	// { "midi", midi_cfattachinit },
	// { "hdaudio", hdaudio_cfattachinit },
	// { "hdafg", hdafg_cfattachinit },
	// { "video", video_cfattachinit },
	// { "dtv", dtv_cfattachinit },
	// { "hdmicec", hdmicec_cfattachinit },
	// { "iic", iic_cfattachinit },
	// { "pcf8563rtc", pcf8563rtc_cfattachinit },
	// { "seeprom", seeprom_cfattachinit },
	// { "tps65217pmic", tps65217pmic_cfattachinit },
	// { "tps65217reg", tps65217reg_cfattachinit },
	// { "axp20x", axp20x_cfattachinit },
	// { "axp20xreg", axp20xreg_cfattachinit },
	// { "axp22x", axp22x_cfattachinit },
	// { "axppmic", axppmic_cfattachinit },
	// { "axpreg", axpreg_cfattachinit },
	// { "ac100ic", ac100ic_cfattachinit },
	// { "titemp", titemp_cfattachinit },
	// { "as3722pmic", as3722pmic_cfattachinit },
	// { "as3722reg", as3722reg_cfattachinit },
	// { "tcakp", tcakp_cfattachinit },
	// { "max77620pmic", max77620pmic_cfattachinit },
	// { "tcagpio", tcagpio_cfattachinit },
	// { "sy8106a", sy8106a_cfattachinit },
	// { "twl", twl_cfattachinit },
	// { "tdahdmi", tdahdmi_cfattachinit },
	// { "spi", spi_cfattachinit },
	// { "irframe", irframe_cfattachinit },
	// { "cir", cir_cfattachinit },
	// { "ld", ld_cfattachinit },
	// { "tlphy", tlphy_cfattachinit },
	// { "nsphy", nsphy_cfattachinit },
	// { "nsphyter", nsphyter_cfattachinit },
	// { "gentbi", gentbi_cfattachinit },
	// { "glxtphy", glxtphy_cfattachinit },
	// { "gphyter", gphyter_cfattachinit },
	// { "qsphy", qsphy_cfattachinit },
	// { "inphy", inphy_cfattachinit },
	// { "iophy", iophy_cfattachinit },
	// { "exphy", exphy_cfattachinit },
	// { "lxtphy", lxtphy_cfattachinit },
	// { "makphy", makphy_cfattachinit },
	// { "icsphy", icsphy_cfattachinit },
	// { "igphy", igphy_cfattachinit },
	// { "ikphy", ikphy_cfattachinit },
	// { "sqphy", sqphy_cfattachinit },
	// { "tqphy", tqphy_cfattachinit },
	// { "pnaphy", pnaphy_cfattachinit },
	// { "rgephy", rgephy_cfattachinit },
	// { "urlphy", urlphy_cfattachinit },
	// { "ukphy", ukphy_cfattachinit },
	// { "rlphy", rlphy_cfattachinit },
	// { "ihphy", ihphy_cfattachinit },
	// { "rdcphy", rdcphy_cfattachinit },
	// { "awge", awge_cfattachinit },
	// { "com", com_cfattachinit },
	// { "re", re_cfattachinit },
	// { "virtio", virtio_cfattachinit },
	// { "vioif", vioif_cfattachinit },
	// { "viornd", viornd_cfattachinit },
	// { "vioscsi", vioscsi_cfattachinit },
	// { "atabus", atabus_cfattachinit },
	// { "ahcisata", ahcisata_cfattachinit },
	// { "smsh", smsh_cfattachinit },
	// { "wsdisplay", wsdisplay_cfattachinit },
	// { "wskbd", wskbd_cfattachinit },
	// { "wsmouse", wsmouse_cfattachinit },
	// { "genfb", genfb_cfattachinit },
	// { "ohci", ohci_cfattachinit },
	// { "ehci", ehci_cfattachinit },
	// { "xhci", xhci_cfattachinit },
	// { "motg", motg_cfattachinit },
	// { "dwctwo", dwctwo_cfattachinit },
	// { "sdhc", sdhc_cfattachinit },
	// { "dwcmmc", dwcmmc_cfattachinit },
	// { "plrtc", plrtc_cfattachinit },
	// { "aaci", aaci_cfattachinit },
	// { "plkmi", plkmi_cfattachinit },
	// { "plgpio", plgpio_cfattachinit },
	// { "plmmc", plmmc_cfattachinit },
	// { "radio", radio_cfattachinit },
	// { "nvme", nvme_cfattachinit },
	// { "bwfm", bwfm_cfattachinit },
	// { "qemufwcfg", qemufwcfg_cfattachinit },
	// { "gpio", gpio_cfattachinit },
	// { "flash", flash_cfattachinit },
	// { "nand", nand_cfattachinit },
	// { "athn", athn_cfattachinit },
	// { "simplebus", simplebus_cfattachinit },
	// { "fregulator", fregulator_cfattachinit },
	// { "gregulator", gregulator_cfattachinit },
	// { "fclock", fclock_cfattachinit },
	// { "ffclock", ffclock_cfattachinit },
	// { "gpiokeys", gpiokeys_cfattachinit },
	// { "gpioleds", gpioleds_cfattachinit },
	// { "connector", connector_cfattachinit },
	// { "panel", panel_cfattachinit },
	// { "cpus", cpus_cfattachinit },
	// { "mmcpwrseq", mmcpwrseq_cfattachinit },
	// { "syscon", syscon_cfattachinit },
	// { "pinctrl", pinctrl_cfattachinit },
	// { "pwmbacklight", pwmbacklight_cfattachinit },
	// { "pwmfan", pwmfan_cfattachinit },
	// { "ausoc", ausoc_cfattachinit },
	// { "dwcwdt", dwcwdt_cfattachinit },
	// { "usbnopphy", usbnopphy_cfattachinit },
	// { "psci", psci_cfattachinit },
	// { "cpu", cpu_cfattachinit },
	// { "wd", wd_cfattachinit },
	// { "bthub", bthub_cfattachinit },
	// { "pci", pci_cfattachinit },
	// { "ppb", ppb_cfattachinit },
	// { "sdmmc", sdmmc_cfattachinit },
	// { "scsibus", scsibus_cfattachinit },
	// { "atapibus", atapibus_cfattachinit },
	// { "cd", cd_cfattachinit },
	// { "ch", ch_cfattachinit },
	// { "sd", sd_cfattachinit },
	// { "st", st_cfattachinit },
	// { "ses", ses_cfattachinit },
	// { "ss", ss_cfattachinit },
	// { "uk", uk_cfattachinit },
	{ "usb", usb_cfattachinit },
	{ "uhub", uhub_cfattachinit },
	// { "uaudio", uaudio_cfattachinit },
	// { "umidi", umidi_cfattachinit },
	// { "ucom", ucom_cfattachinit },
	// { "ugen", ugen_cfattachinit },
	// { "ugenif", ugenif_cfattachinit },
	{ "uhidev", uhidev_cfattachinit },
	{ "uhid", uhid_cfattachinit },
	{ "ukbd", ukbd_cfattachinit },
	// { "ums", ums_cfattachinit },
	// { "uts", uts_cfattachinit },
	// { "uep", uep_cfattachinit },
	// { "ucycom", ucycom_cfattachinit },
	// { "ulpt", ulpt_cfattachinit },
	// { "umass", umass_cfattachinit },
	// { "uirda", uirda_cfattachinit },
	// { "stuirda", stuirda_cfattachinit },
	// { "ustir", ustir_cfattachinit },
	// { "irmce", irmce_cfattachinit },
	// { "ubt", ubt_cfattachinit },
	// { "aubtfwl", aubtfwl_cfattachinit },
	// { "pseye", pseye_cfattachinit },
	// { "uvideo", uvideo_cfattachinit },
	// { "auvitek", auvitek_cfattachinit },
	// { "emdtv", emdtv_cfattachinit },
	// { "umodeswitch", umodeswitch_cfattachinit },
	// { "urio", urio_cfattachinit },
	// { "uipad", uipad_cfattachinit },
	// { "uberry", uberry_cfattachinit },
	// { "uvisor", uvisor_cfattachinit },
	// { "ugensa", ugensa_cfattachinit },
	// { "u3g", u3g_cfattachinit },
	// { "uyap", uyap_cfattachinit },
	// { "udsbr", udsbr_cfattachinit },
	// { "slurm", slurm_cfattachinit },
	// { "uthum", uthum_cfattachinit },
	// { "aue", aue_cfattachinit },
	// { "cdce", cdce_cfattachinit },
	// { "cue", cue_cfattachinit },
	// { "kue", kue_cfattachinit },
	// { "upl", upl_cfattachinit },
	// { "url", url_cfattachinit },
	// { "axe", axe_cfattachinit },
	// { "axen", axen_cfattachinit },
	// { "mue", mue_cfattachinit },
	// { "udav", udav_cfattachinit },
	// { "otus", otus_cfattachinit },
	// { "ure", ure_cfattachinit },
	// { "umodem", umodem_cfattachinit },
	// { "uftdi", uftdi_cfattachinit },
	// { "uplcom", uplcom_cfattachinit },
	// { "umct", umct_cfattachinit },
	// { "umcs", umcs_cfattachinit },
	// { "uvscom", uvscom_cfattachinit },
	// { "uxrcom", uxrcom_cfattachinit },
	// { "ubsa", ubsa_cfattachinit },
	// { "uipaq", uipaq_cfattachinit },
	// { "ukyopon", ukyopon_cfattachinit },
	// { "uark", uark_cfattachinit },
	// { "uslsa", uslsa_cfattachinit },
	// { "uchcom", uchcom_cfattachinit },
	// { "usscanner", usscanner_cfattachinit },
	// { "atu", atu_cfattachinit },
	// { "upgt", upgt_cfattachinit },
	// { "usmsc", usmsc_cfattachinit },
	// { "ural", ural_cfattachinit },
	// { "rum", rum_cfattachinit },
	// { "utoppy", utoppy_cfattachinit },
	// { "zyd", zyd_cfattachinit },
	// { "udl", udl_cfattachinit },
	// { "uhso", uhso_cfattachinit },
	// { "urndis", urndis_cfattachinit },
	// { "urtwn", urtwn_cfattachinit },
	// { "urtw", urtw_cfattachinit },
	// { "run", run_cfattachinit },
	// { "udsir", udsir_cfattachinit },
	// { "plcom", plcom_cfattachinit },
	// { "armgic", armgic_cfattachinit },
	// { "arml2cc", arml2cc_cfattachinit },
	// { "armgtmr", armgtmr_cfattachinit },
	// { "arma9tmr", arma9tmr_cfattachinit },
	// { "arma9ptmr", arma9ptmr_cfattachinit },
	// { "pckbd", pckbd_cfattachinit },
	// { "pms", pms_cfattachinit },
	// { "armfdt", armfdt_cfattachinit },
	// { "cpufreqdt", cpufreqdt_cfattachinit },
	// { "a9tmr", a9tmr_cfattachinit },
	// { "a9ptmr", a9ptmr_cfattachinit },
	// { "gtmr", gtmr_cfattachinit },
	// { "gic", gic_cfattachinit },
	// { "l2cc", l2cc_cfattachinit },
	// { "pcihost", pcihost_cfattachinit },
	// { "armpmu", armpmu_cfattachinit },
	// { "cycvclkmgr", cycvclkmgr_cfattachinit },
	// { "cycvrstmgr", cycvrstmgr_cfattachinit },
	// { "meson8bclkc", meson8bclkc_cfattachinit },
	// { "mesonresets", mesonresets_cfattachinit },
	// { "mesonuart", mesonuart_cfattachinit },
	// { "mesonfb", mesonfb_cfattachinit },
	// { "mesonpinctrl", mesonpinctrl_cfattachinit },
	// { "mesonsdhc", mesonsdhc_cfattachinit },
	// { "mesonsdio", mesonsdio_cfattachinit },
	// { "mesonusbphy", mesonusbphy_cfattachinit },
	// { "mesonrtc", mesonrtc_cfattachinit },
	// { "mesonrng", mesonrng_cfattachinit },
	// { "mesonwdt", mesonwdt_cfattachinit },
	// { "bcmicu", bcmicu_cfattachinit },
	// { "bcmmbox", bcmmbox_cfattachinit },
	// { "bcmpmwdog", bcmpmwdog_cfattachinit },
	// { "bcmrng", bcmrng_cfattachinit },
	// { "bcmaux", bcmaux_cfattachinit },
	// { "bcmsdhost", bcmsdhost_cfattachinit },
	// { "bcmdmac", bcmdmac_cfattachinit },
	// { "bcmspi", bcmspi_cfattachinit },
	// { "bsciic", bsciic_cfattachinit },
	// { "vchiq", vchiq_cfattachinit },
	// { "vcaudio", vcaudio_cfattachinit },
	// { "bcmgpio", bcmgpio_cfattachinit },
	// { "bcmcprman", bcmcprman_cfattachinit },
	// { "vcmbox", vcmbox_cfattachinit },
	// { "tegra124cpu", tegra124cpu_cfattachinit },
	// { "tegralic", tegralic_cfattachinit },
	// { "tegramc", tegramc_cfattachinit },
	// { "tegrapmc", tegrapmc_cfattachinit },
	// { "tegrafuse", tegrafuse_cfattachinit },
	// { "tegra124car", tegra124car_cfattachinit },
	// { "tegra210car", tegra210car_cfattachinit },
	// { "tegragpio", tegragpio_cfattachinit },
	// { "tegratimer", tegratimer_cfattachinit },
	// { "tegrapinmux", tegrapinmux_cfattachinit },
	// { "tegraapbdma", tegraapbdma_cfattachinit },
	// { "tegra124xpad", tegra124xpad_cfattachinit },
	// { "tegra210xpad", tegra210xpad_cfattachinit },
	// { "tegra210xphy", tegra210xphy_cfattachinit },
	// { "tegrai2c", tegrai2c_cfattachinit },
	// { "tegrartc", tegrartc_cfattachinit },
	// { "tegrausbphy", tegrausbphy_cfattachinit },
	// { "tegrasoctherm", tegrasoctherm_cfattachinit },
	// { "tegrapcie", tegrapcie_cfattachinit },
	// { "tegracec", tegracec_cfattachinit },
	// { "exyointr", exyointr_cfattachinit },
	// { "mct", mct_cfattachinit },
	// { "exuart", exuart_cfattachinit },
	// { "exyopctl", exyopctl_cfattachinit },
	// { "exusbphy", exusbphy_cfattachinit },
	// { "exusbdrdphy", exusbdrdphy_cfattachinit },
	// { "exyoi2c", exyoi2c_cfattachinit },
	// { "expwm", expwm_cfattachinit },
	// { "exy5422clk", exy5422clk_cfattachinit },
	// { "exy5410clk", exy5410clk_cfattachinit },
	// { "sun4ia10ccu", sun4ia10ccu_cfattachinit },
	// { "sun5ia13ccu", sun5ia13ccu_cfattachinit },
	// { "sun6ia31ccu", sun6ia31ccu_cfattachinit },
	// { "sun8ia83tccu", sun8ia83tccu_cfattachinit },
	// { "sun8ih3ccu", sun8ih3ccu_cfattachinit },
	// { "sun8ih3rccu", sun8ih3rccu_cfattachinit },
	// { "sun9ia80ccu", sun9ia80ccu_cfattachinit },
	// { "sunxiresets", sunxiresets_cfattachinit },
	// { "sunxigates", sunxigates_cfattachinit },
	// { "sunxigmacclk", sunxigmacclk_cfattachinit },
	// { "sun9immcclk", sun9immcclk_cfattachinit },
	// { "sun9iusbclk", sun9iusbclk_cfattachinit },
	// { "sun9icpusclk", sun9icpusclk_cfattachinit },
	// { "sun8iapbclk", sun8iapbclk_cfattachinit },
	// { "sunxiintc", sunxiintc_cfattachinit },
	// { "sunxinmi", sunxinmi_cfattachinit },
	// { "sunxigpio", sunxigpio_cfattachinit },
	// { "sunxipwm", sunxipwm_cfattachinit },
	// { "sunximmc", sunximmc_cfattachinit },
	// { "sunxiusbphy", sunxiusbphy_cfattachinit },
	// { "sunxiusb3phy", sunxiusb3phy_cfattachinit },
	// { "sun9iusbphy", sun9iusbphy_cfattachinit },
	// { "sunxitwi", sunxitwi_cfattachinit },
	// { "sunxirsb", sunxirsb_cfattachinit },
	// { "sunxirtc", sunxirtc_cfattachinit },
	// { "emac", emac_cfattachinit },
	// { "sunxitimer", sunxitimer_cfattachinit },
	// { "sunxihstimer", sunxihstimer_cfattachinit },
	// { "sunxiwdt", sunxiwdt_cfattachinit },
	// { "sun4idma", sun4idma_cfattachinit },
	// { "sun6idma", sun6idma_cfattachinit },
	// { "sunxicodec", sunxicodec_cfattachinit },
	// { "sun8icodec", sun8icodec_cfattachinit },
	// { "h3codec", h3codec_cfattachinit },
	// { "a64acodec", a64acodec_cfattachinit },
	// { "sunxii2s", sunxii2s_cfattachinit },
	// { "sunxitcon", sunxitcon_cfattachinit },
	// { "sunxidebe", sunxidebe_cfattachinit },
	// { "sunxihdmi", sunxihdmi_cfattachinit },
	// { "sunxidep", sunxidep_cfattachinit },
	// { "sunxits", sunxits_cfattachinit },
	// { "sunxisid", sunxisid_cfattachinit },
	// { "sunxithermal", sunxithermal_cfattachinit },
	// { "sunxisramc", sunxisramc_cfattachinit },
	// { "sunxinand", sunxinand_cfattachinit },
	// { "sun6ispi", sun6ispi_cfattachinit },
	// { "sunxican", sunxican_cfattachinit },
	// { "sunxilradc", sunxilradc_cfattachinit },
	// { "omapintc", omapintc_cfattachinit },
	// { "tisysc", tisysc_cfattachinit },
	// { "am3prcm", am3prcm_cfattachinit },
	// { "omap3cm", omap3cm_cfattachinit },
	// { "omap3prm", omap3prm_cfattachinit },
	// { "timuxclk", timuxclk_cfattachinit },
	// { "tidivclk", tidivclk_cfattachinit },
	// { "tidpllclk", tidpllclk_cfattachinit },
	// { "omaptimer", omaptimer_cfattachinit },
	// { "tigpio", tigpio_cfattachinit },
	// { "tiiic", tiiic_cfattachinit },
	// { "cpsw", cpsw_cfattachinit },
	// { "tiedma", tiedma_cfattachinit },
	// { "titptc", titptc_cfattachinit },
	// { "tiotg", tiotg_cfattachinit },
	// { "tiusb", tiusb_cfattachinit },
	// { "tiusbtll", tiusbtll_cfattachinit },
	// { "tirng", tirng_cfattachinit },
	// { "omapfb", omapfb_cfattachinit },
	// { "tilcdc", tilcdc_cfattachinit },
	// { "tifb", tifb_cfattachinit },
	// { "tigpmc", tigpmc_cfattachinit },
	// { "omapnand", omapnand_cfattachinit },
	// { "tiwdt", tiwdt_cfattachinit },
	// { "vxsysreg", vxsysreg_cfattachinit },
	// { "zynquart", zynquart_cfattachinit },
	// { "cemac", cemac_cfattachinit },
	{ NULL, NULL }
};

const short cfroots[] = {
	292 /* armfdt0 */,
	-1
};

/* pseudo-devices */

// const struct pdevinit pdevinit[] = {
// 	{ cpuctlattach, 1 },
// 	{ rndattach, 1 },
// 	{ putterattach, 1 },
// 	{ nsmbattach, 1 },
// 	{ cryptoattach, 1 },
// 	{ swcryptoattach, 1 },
// 	{ vndattach, 1 },
// 	{ drvctlattach, 1 },
// 	{ cgdattach, 1 },
// 	{ bpfilterattach, 1 },
// 	{ carpattach, 1 },
// 	{ loopattach, 1 },
// 	{ bridgeattach, 1 },
// 	{ vlanattach, 1 },
// 	{ pppattach, 1 },
// 	{ pppoeattach, 1 },
// 	{ tunattach, 1 },
// 	{ tapattach, 1 },
// 	{ gifattach, 1 },
// 	{ ipsecifattach, 1 },
// 	{ greattach, 1 },
// 	{ npfattach, 1 },
// 	{ ptyattach, 1 },
// 	{ clockctlattach, 1 },
// 	{ ksymsattach, 1 },
// 	{ lockstatattach, 1 },
// 	{ veriexecattach, 1 },
// 	{ openfirmattach, 1 },
// 	{ tprofattach, 1 },
// 	{ canloopattach, 1 },
// 	{ wsmuxattach, 1 },
// 	{ wsfontattach, 1 },
// 	{ sequencerattach, 1 },
// 	{ 0, 0 }
// };
