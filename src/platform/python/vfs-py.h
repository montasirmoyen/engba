#include <mgba-util/vfs.h>

#include "pycommon.h"

struct VFilePy {
	struct VFile d;
	void* fileobj;
};

struct VFile* VFileFromPython(void* fileobj);

PYEXPORT bool _vfpClose(struct VFile* vf);
PYEXPORT off_t _vfpSeek(struct VFile* vf, off_t offset, int whence);
PYEXPORT ssize_t _vfpRead(struct VFile* vf, void* buffer, size_t size);
PYEXPORT ssize_t _vfpWrite(struct VFile* vf, const void* buffer, size_t size);
PYEXPORT void* _vfpMap(struct VFile* vf, size_t size, int flags);
PYEXPORT void _vfpUnmap(struct VFile* vf, void* memory, size_t size);
PYEXPORT void _vfpTruncate(struct VFile* vf, size_t size);
PYEXPORT ssize_t _vfpSize(struct VFile* vf);
PYEXPORT bool _vfpSync(struct VFile* vf, void* buffer, size_t size);
