#ifndef GBA_RENDERER_COMMON_H
#define GBA_RENDERER_COMMON_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/internal/gba/video.h>

struct GBAVideoRendererSprite {
	struct GBAObj obj;
	int16_t y;
	int16_t endY;
	int16_t cycles;
	int8_t index;
};

int GBAVideoRendererCleanOAM(struct GBAObj* oam, struct GBAVideoRendererSprite* sprites, int offsetY);

CXX_GUARD_END

#endif