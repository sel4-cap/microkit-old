#include <sel4_bus_funcs.h>
#include <evbarm/bus_defs.h>

int sel4_sub_region(bus_addr_t h, bus_addr_t o, bus_space_handle_t *hp) {
    *hp = h + o;
	return 0;
}