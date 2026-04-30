#include <mgba/internal/gba/input.h>

#include <mgba/gba/interface.h>

MGBA_EXPORT const struct mInputPlatformInfo GBAInputInfo = {
	.platformName = "gba",
	.keyId = (const char*[]) {
		"A",
		"B",
		"Select",
		"Start",
		"Right",
		"Left",
		"Up",
		"Down",
		"R",
		"L"
	},
	.nKeys = GBA_KEY_MAX,
	.hat = {
		.up = GBA_KEY_UP,
		.right = GBA_KEY_RIGHT,
		.down = GBA_KEY_DOWN,
		.left = GBA_KEY_LEFT
	}
};
