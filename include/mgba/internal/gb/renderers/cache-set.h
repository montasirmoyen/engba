#ifndef GB_TILE_CACHE_H
#define GB_TILE_CACHE_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct GBVideo;
struct mCacheSet;

void GBVideoCacheInit(struct mCacheSet* cache);
void GBVideoCacheAssociate(struct mCacheSet* cache, struct GBVideo* video);

void GBVideoCacheWriteVideoRegister(struct mCacheSet* cache, uint16_t address, uint8_t value);

CXX_GUARD_END

#endif
