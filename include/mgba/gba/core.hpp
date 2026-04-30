#ifndef GBA_CORE_H
#define GBA_CORE_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mCore;
struct mCore* GBACoreCreate(void);
#ifndef MINIMAL_CORE
struct mCore* GBAVideoLogPlayerCreate(void);
#endif

CXX_GUARD_END

#endif
