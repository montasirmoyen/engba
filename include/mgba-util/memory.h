#ifndef MEMORY_H
#define MEMORY_H

#include <mgba-util/common.h>

CXX_GUARD_START

void* anonymousMemoryMap(size_t size);
void mappedMemoryFree(void* memory, size_t size);

CXX_GUARD_END

#endif
