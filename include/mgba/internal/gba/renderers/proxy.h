#ifndef GBA_VIDEO_PROXY_H
#define GBA_VIDEO_PROXY_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/internal/gba/video.h>
#include <mgba/feature/video-logger.h>

struct GBAVideoProxyRenderer {
	struct GBAVideoRenderer d;
	struct GBAVideoRenderer* backend;
	struct mVideoLogger* logger;
	int flushScanline;
};

void GBAVideoProxyRendererCreate(struct GBAVideoProxyRenderer* renderer, struct GBAVideoRenderer* backend, struct mVideoLogger* logger);
void GBAVideoProxyRendererShim(struct GBAVideo* video, struct GBAVideoProxyRenderer* renderer);
void GBAVideoProxyRendererUnshim(struct GBAVideo* video, struct GBAVideoProxyRenderer* renderer);

CXX_GUARD_END

#endif
