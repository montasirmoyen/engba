#ifndef FFMPEG_SCALE
#define FFMPEG_SCALE

#include <mgba-util/common.h>

CXX_GUARD_START

#include "feature/ffmpeg/ffmpeg-common.h"

void FFmpegScale(const void* input, int iwidth, int iheight, unsigned istride,
                 void* output, int owidth, int oheight, unsigned ostride,
                 enum mColorFormat format, int quality);

CXX_GUARD_END

#endif
