#pragma once

#include "Override.h"

#include <mgba/gba/interface.h>

namespace QGBA {

class GBAOverride : public Override {
public:
	void identify(const struct mCore*) override;
	void save(struct Configuration*) const override;
	const void* raw() const override;

	struct GBACartridgeOverride override;
	bool vbaBugCompatSet;
};

}
