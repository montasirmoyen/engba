#pragma once

#include "Override.h"

#include <mgba/gb/interface.h>

namespace QGBA {

class GBOverride : public Override {
public:
	void identify(const struct mCore*) override;
	void save(struct Configuration*) const override;
	const void* raw() const override;

	struct GBCartridgeOverride override;
};

}
