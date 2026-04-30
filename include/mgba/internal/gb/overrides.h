#ifndef GB_OVERRIDES_H
#define GB_OVERRIDES_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/gb/interface.h>

struct GB;
void GBOverrideApply(struct GB*, const struct GBCartridgeOverride*);
void GBOverrideApplyDefaults(struct GB*);

CXX_GUARD_END

#endif
