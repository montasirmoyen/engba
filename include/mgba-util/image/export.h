#ifndef M_IMAGE_EXPORT_H
#define M_IMAGE_EXPORT_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct VFile;

bool mPaletteExportRIFF(struct VFile* vf, size_t entries, const uint16_t* colors);
bool mPaletteExportACT(struct VFile* vf, size_t entries, const uint16_t* colors);

CXX_GUARD_END

#endif
