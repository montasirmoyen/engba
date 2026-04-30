#ifndef GBA_OVERRIDES_H
#define GBA_OVERRIDES_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/gba/interface.h>

struct GBA;
void GBAOverrideApply(struct GBA*, const struct GBACartridgeOverride*);
void GBAOverrideApplyDefaults(struct GBA*, const struct Configuration*);

CXX_GUARD_END

#endif
