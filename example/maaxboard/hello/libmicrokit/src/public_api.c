#include <tinyalloc.h>
#include <stdint.h>
#include <printf.h>
#include <microkit.h>


bool init(const void *base, const void *limit, const size_t heap_blocks, const size_t split_thresh, const size_t alignment){
    return ta_init(base, limit, heap_blocks, split_thresh, alignment);
}
void *malloc(size_t num){
    return ta_alloc(num);
}
void free(void *ptr){
    ta_free(ptr);
}

int printf(const char* format, ...)
{
  va_list va;
  va_start(va, format);
  char buffer[1];
  const int ret = _vsnprintf(_out_char, buffer, (size_t)-1, format, va);
  va_end(va);
  return ret;
}
