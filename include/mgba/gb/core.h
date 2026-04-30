#ifndef GB_CORE_H
#define GB_CORE_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mCore;
struct mCore* GBCoreCreate(void);
#ifndef MINIMAL_CORE
struct mCore* GBVideoLogPlayerCreate(void);
#endif

CXX_GUARD_END

#endif
