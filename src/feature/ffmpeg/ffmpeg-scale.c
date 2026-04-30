#include "ffmpeg-scale.h"

#include <libswscale/swscale.h>

static const int _qualityToFlags[] = {
	SWS_POINT,
	SWS_FAST_BILINEAR,
	SWS_BILINEAR,
	SWS_BICUBIC,
	SWS_LANCZOS,
	SWS_SINC,
};

void FFmpegScale(const void* input, int iwidth, int iheight, unsigned istride,
                 void* output, int owidth, int oheight, unsigned ostride,
                 enum mColorFormat format, int quality) {
	enum AVPixelFormat pixFormat = mColorFormatToFFmpegPixFmt(format);
	int flags;
	if (quality < 0) {
		quality = 0;
	} else if ((unsigned) quality >= sizeof(_qualityToFlags) / sizeof(_qualityToFlags[0])) {
		quality = sizeof(_qualityToFlags) / sizeof(_qualityToFlags[0]) - 1;
	}
	flags = _qualityToFlags[quality];

	struct SwsContext* scaleContext = sws_getContext(iwidth, iheight, pixFormat,
	    owidth, oheight, pixFormat,
	    flags, 0, 0, 0);
	sws_scale(scaleContext, (const uint8_t* const*) &input, (const int*) &istride, 0, iheight, (uint8_t* const*) &output, (const int*) &ostride);
	sws_freeContext(scaleContext);
}
