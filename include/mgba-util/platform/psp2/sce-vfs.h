#ifndef SCE_VFS_H
#define SCE_VFS_H

#ifdef PSP2
#include <psp2/types.h>
#include <psp2/io/fcntl.h>
#else
#include <pspiofilemgr.h>
#endif

struct VFile* VFileOpenSce(const char* path, int flags, SceMode mode);

#endif
