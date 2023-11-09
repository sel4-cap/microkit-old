#include <stdbool.h>
#include <stddef.h>

bool ta_init(const void *base, const void *limit, const size_t heap_blocks, const size_t split_thresh, const size_t alignment);
void *malloc(size_t num);
void free(void *ptr);
void *ta_calloc(size_t num, size_t size);
