#ifndef PATCH_H
#define PATCH_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct VFile;

struct Patch {
	struct VFile* vf;

	size_t (*outputSize)(struct Patch* patch, size_t inSize);
	bool (*applyPatch)(struct Patch* patch, const void* restrict in, size_t inSize, void* restrict out, size_t outSize);
};

bool loadPatch(struct VFile* vf, struct Patch* patch);

CXX_GUARD_END

#endif
