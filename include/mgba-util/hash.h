#ifndef HASH_H
#define HASH_H

#include <mgba-util/common.h>

CXX_GUARD_START

uint32_t hash32(const void* key, size_t len, uint32_t seed);

CXX_GUARD_END

#endif
