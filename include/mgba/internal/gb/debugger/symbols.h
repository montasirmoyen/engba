#ifndef GB_SYMBOLS_H
#define GB_SYMBOLS_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mDebuggerSymbols;
struct VFile;
void GBLoadSymbols(struct mDebuggerSymbols*, struct VFile* vf);

CXX_GUARD_END

#endif
