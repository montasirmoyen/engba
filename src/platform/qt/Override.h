#pragma once

struct Configuration;
struct mCore;

namespace QGBA {

class Override {
public:
	virtual ~Override() {}

	virtual void identify(const struct mCore*) = 0;
	virtual void save(struct Configuration*) const = 0;
	virtual const void* raw() const = 0;
};

}
