#ifndef FFMPEG_DECODER
#define FFMPEG_DECODER

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/core/interface.h>

#include "feature/ffmpeg/ffmpeg-common.h"

#define FFMPEG_DECODER_BUFSIZE 4096

struct FFmpegDecoder {
	struct mAVStream* out;
	struct AVFormatContext* context;

	int audioStream;
	AVFrame* audioFrame;
	struct AVCodecContext* audio;

	int videoStream;
	AVFrame* videoFrame;
	struct AVCodecContext* video;
	struct SwsContext* scaleContext;

	int width;
	int height;
	uint8_t* pixels;
};

void FFmpegDecoderInit(struct FFmpegDecoder*);
bool FFmpegDecoderOpen(struct FFmpegDecoder*, const char* infile);
void FFmpegDecoderClose(struct FFmpegDecoder*);
bool FFmpegDecoderIsOpen(struct FFmpegDecoder*);
bool FFmpegDecoderRead(struct FFmpegDecoder*);

CXX_GUARD_END

#endif
