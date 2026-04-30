#include "GBAOverride.h"

#include <mgba/core/core.h>
#include <mgba/internal/gba/gba.h>

using namespace QGBA;

void GBAOverride::identify(const struct mCore* core) {
	if (core->platform(core) != mPLATFORM_GBA) {
		return;
	}
	mGameInfo info;
	core->getGameInfo(core, &info);
	memcpy(override.id, info.code, 4);
}

void GBAOverride::save(struct Configuration* config) const {
	GBAOverrideSave(config, &override);
}

const void* GBAOverride::raw() const {
	return &override;
}
