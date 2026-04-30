#ifndef GB_DEBUGGER_H
#define GB_DEBUGGER_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct GB;
struct mDebuggerPlatform;

struct mDebuggerPlatform* GBDebuggerCreate(struct GB* gb);

CXX_GUARD_END

#endif