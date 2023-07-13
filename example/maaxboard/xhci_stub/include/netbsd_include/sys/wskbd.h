/*	$NetBSD: wskbd.h,v 1.1 2015/08/24 23:01:59 pooka Exp $	*/
#include <stdint.h>
#include <printf.h>
#include <sys/bus.h>
#include <dev/usb/usbdi.h>
#include  <sys/callout.h>
#include  "types.h"
#include <dev/wscons/wseventvar.h>
#include <dev/wscons/wsmuxvar.h>
#include <dev/wscons/wsconsio.h>
#include <dev/wscons/wskbdvar.h>
#include <dev/wscons/wsksymdef.h>
#include <dev/wscons/wsksymvar.h>

#define NWSKBD 1

//int wskbd_cngetc(dev_t);

void wskbd_attach(device_t, device_t, void *);

struct wskbd_internal {
	const struct wskbd_mapdata *t_keymap;

	const struct wskbd_consops *t_consops;
	void	*t_consaccesscookie;

	int	t_modifiers;
	int	t_composelen;		/* remaining entries in t_composebuf */
	keysym_t t_composebuf[2];

	int t_flags;
#define WSKFL_METAESC 1

#define MAXKEYSYMSPERKEY 2 /* ESC <key> at max */
	keysym_t t_symbols[MAXKEYSYMSPERKEY];

	struct wskbd_softc *t_sc;	/* back pointer */
};

struct wskbd_softc {
	struct wsevsrc sc_base;

	struct wskbd_internal *id;

	const struct wskbd_accessops *sc_accessops;
	void *sc_accesscookie;

	int	sc_ledstate;

	int	sc_isconsole;

	struct wskbd_bell_data sc_bell_data;
	struct wskbd_keyrepeat_data sc_keyrepeat_data;
#ifdef WSDISPLAY_SCROLLSUPPORT
	struct wskbd_scroll_data sc_scroll_data;
#endif

	int	sc_repeating;		/* we've called timeout() */
	callout_t sc_repeat_ch;
	u_int	sc_repeat_type;
	int	sc_repeat_value;

	int	sc_translating;		/* xlate to chars for emulation */

	int	sc_maplen;		/* number of entries in sc_map */
	struct wscons_keymap *sc_map;	/* current translation map */
	kbd_t sc_layout; /* current layout */

	int		sc_refcnt;
	u_char		sc_dying;	/* device is being detached */

	wskbd_hotkey_plugin *sc_hotkey;
	void *sc_hotkeycookie;

	/* optional table to translate scancodes in event mode */
	int		sc_evtrans_len;
	keysym_t	*sc_evtrans;
};

void update_leds(struct wskbd_internal *);