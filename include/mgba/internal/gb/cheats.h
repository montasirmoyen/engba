#ifndef GB_CHEATS_H
#define GB_CHEATS_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/core/cheats.h>

enum GBCheatType {
	GB_CHEAT_AUTODETECT,
	GB_CHEAT_GAMESHARK,
	GB_CHEAT_GAME_GENIE,
	GB_CHEAT_VBA
};

struct mCheatDevice* GBCheatDeviceCreate(void);

CXX_GUARD_END

#endif
