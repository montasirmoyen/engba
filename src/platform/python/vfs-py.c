#include "vfs-py.h"

struct VFile* VFileFromPython(void* fileobj) {
	if (!fileobj) {
		return 0;
	}

	struct VFilePy* vfp = malloc(sizeof(struct VFilePy));
	if (!vfp) {
		return 0;
	}

	vfp->fileobj = fileobj;
	vfp->d.close = _vfpClose;
	vfp->d.seek = _vfpSeek;
	vfp->d.read = _vfpRead;
	vfp->d.readline = VFileReadline;
	vfp->d.write = _vfpWrite;
	vfp->d.map = _vfpMap;
	vfp->d.unmap = _vfpUnmap;
	vfp->d.truncate = _vfpTruncate;
	vfp->d.size = _vfpSize;
	vfp->d.sync = _vfpSync;

	return &vfp->d;
}
