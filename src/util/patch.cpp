#include <mgba-util/patch.h>

#include <mgba-util/patch/ips.h>
#include <mgba-util/patch/ups.h>

bool loadPatch(struct VFile* vf, struct Patch* patch) {
	patch->vf = vf;

	if (loadPatchIPS(patch)) {
		return true;
	}

	if (loadPatchUPS(patch)) {
		return true;
	}

	patch->outputSize = NULL;
	patch->applyPatch = NULL;
	return false;
}
