#include <stdbool.h>
#include <stddef.h>

bool init(const void *base, const void *limit, const size_t heap_blocks, const size_t split_thresh, const size_t alignment);
void *malloc(size_t num);
void free(void *ptr);
