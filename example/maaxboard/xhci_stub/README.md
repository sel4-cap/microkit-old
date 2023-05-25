# XHCI_STUB

## DONE:
- Added maaxboard to the build_sdk.py
- Created a (very average) build system
- Pulled in initial bus reads/writes
- Pulled in all netbsd headers required
- Can perform dwc3 bring up
- "Implemented" printf and malloc
    - malloc receives heap base allocated in `xhci_stub.system`
    - printf receives `sel4cp_debug_putc()`
- Pulled in other C files
- DMA done (tentatively... need to look at implementing "cached=true")
    - Doesn't work when I enable caching, probably to do with the cache flush stuff.
    - Incredibly basic algorithm that just has a base pointer for virt and phys addresses and then increments
    - No freeing or reallocation possible yet
- Interrupts enabled
- Back to where we were with CAmkES

## TODO:
- Neaten up code sooner rather than later
    - Look at CMake now
    - Platform headers for future proofing
    - Headers for things like heap size and heap base
- NOTE: with the new "cached" option for memory, could be possible to implement xfer_pool and give it some of the cached memory. Food for thought

## External sources
- Tiny alloc: https://github.com/thi-ng/tinyalloc/tree/master
    - License: apache
- printf: https://github.com/mpaland/printf/tree/master
    - License: MIT
- memset/memcpy/strlen etc etc: pulled from linux source, stored in util.c
    - License: whatever linux has (I think BSD)