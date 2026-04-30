#include <mgba/internal/gba/overrides.h>

#include <mgba/internal/gba/gba.h>
#include <mgba/internal/gba/cart/ereader.h>
#include <mgba/internal/gba/cart/gpio.h>

#include <mgba-util/configuration.h>

static const struct GBACartridgeOverride _overrides[] = {
	// Advance Wars
	{ {'A', 'W', 'R', 'E'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x8038810 },
	{ {'A', 'W', 'R', 'P'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x8038810 },

	// Advance Wars 2: Black Hole Rising
	{ {'A', 'W', '2', 'E'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x8036E08 },
	{ {'A', 'W', '2', 'P'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x803719C },

	// Boktai: The Sun is in Your Hand
	{ {'U', '3', 'I', 'J'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },
	{ {'U', '3', 'I', 'E'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },
	{ {'U', '3', 'I', 'P'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },

	// Boktai 2: Solar Boy Django
	{ {'U', '3', '2', 'J'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },
	{ {'U', '3', '2', 'E'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },
	{ {'U', '3', '2', 'P'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },

	// Crash Bandicoot 2 - N-Tranced
	{ {'A', 'C', '8', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'C', '8', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'C', '8', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// DigiCommunication Nyo - Datou! Black Gemagema Dan
	{ {'B', 'D', 'K', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Dragon Ball Z - The Legacy of Goku
	{ {'A', 'L', 'G', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Dragon Ball Z - The Legacy of Goku II
	{ {'A', 'L', 'F', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'L', 'F', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'L', 'F', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Dragon Ball Z - Taiketsu
	{ {'B', 'D', 'B', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'D', 'B', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Drill Dozer
	{ {'V', '4', '9', 'J'},  GBA_SAVEDATA_SRAM, HW_RUMBLE, GBA_IDLE_LOOP_NONE },
	{ {'V', '4', '9', 'E'},  GBA_SAVEDATA_SRAM, HW_RUMBLE, GBA_IDLE_LOOP_NONE },
	{ {'V', '4', '9', 'P'},  GBA_SAVEDATA_SRAM, HW_RUMBLE, GBA_IDLE_LOOP_NONE },

	// e-Reader
	{ {'P', 'E', 'A', 'J'},  GBA_SAVEDATA_FLASH1M, HW_EREADER, GBA_IDLE_LOOP_NONE },
	{ {'P', 'S', 'A', 'J'},  GBA_SAVEDATA_FLASH1M, HW_EREADER, GBA_IDLE_LOOP_NONE },
	{ {'P', 'S', 'A', 'E'},  GBA_SAVEDATA_FLASH1M, HW_EREADER, GBA_IDLE_LOOP_NONE },

	// Final Fantasy Tactics Advance
	{ {'A', 'F', 'X', 'E'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x8000428 },

	// F-Zero - Climax
	{ {'B', 'F', 'T', 'J'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Goodboy Galaxy
	{ {'2', 'G', 'B', 'P'},  GBA_SAVEDATA_SRAM, HW_RUMBLE, GBA_IDLE_LOOP_NONE },

	// Iridion II
	{ {'A', 'I', '2', 'E'},  GBA_SAVEDATA_FORCE_NONE, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'I', '2', 'P'},  GBA_SAVEDATA_FORCE_NONE, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Game Boy Wars Advance 1+2
	{ {'B', 'G', 'W', 'J'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Golden Sun: The Lost Age
	{ {'A', 'G', 'F', 'E'},  GBA_SAVEDATA_FLASH512, HW_NONE, 0x801353A },

	// Koro Koro Puzzle - Happy Panechu!
	{ {'K', 'H', 'P', 'J'},  GBA_SAVEDATA_EEPROM, HW_TILT, GBA_IDLE_LOOP_NONE },

	// Legendz - Yomigaeru Shiren no Shima
	{ {'B', 'L', 'J', 'J'},  GBA_SAVEDATA_FLASH512, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'B', 'L', 'J', 'K'},  GBA_SAVEDATA_FLASH512, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Legendz - Sign of Nekuromu
	{ {'B', 'L', 'V', 'J'},  GBA_SAVEDATA_FLASH512, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Mega Man Battle Network
	{ {'A', 'R', 'E', 'E'},  GBA_SAVEDATA_SRAM, HW_NONE, 0x800032E },

	// Mega Man Zero
	{ {'A', 'Z', 'C', 'E'},  GBA_SAVEDATA_SRAM, HW_NONE, 0x80004E8 },

	// Metal Slug Advance
	{ {'B', 'S', 'M', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x8000290 },

	// Pokemon Ruby
	{ {'A', 'X', 'V', 'J'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'E'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'P'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'I'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'S'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'D'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'V', 'F'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Pokemon Sapphire
	{ {'A', 'X', 'P', 'J'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'E'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'P'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'I'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'S'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'D'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },
	{ {'A', 'X', 'P', 'F'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Pokemon Emerald
	{ {'B', 'P', 'E', 'J'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'E'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'P'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'I'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'S'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'D'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },
	{ {'B', 'P', 'E', 'F'},  GBA_SAVEDATA_FLASH1M, HW_RTC, 0x80008C6 },

	// Pokemon Mystery Dungeon
	{ {'B', '2', '4', 'E'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', '2', '4', 'P'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Pokemon FireRed
	{ {'B', 'P', 'R', 'J'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'E'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'P'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'I'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'S'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'D'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'R', 'F'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Pokemon LeafGreen
	{ {'B', 'P', 'G', 'J'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'E'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'P'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'I'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'S'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'D'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'B', 'P', 'G', 'F'},  GBA_SAVEDATA_FLASH1M, HW_NONE, GBA_IDLE_LOOP_NONE },

	// RockMan EXE 4.5 - Real Operation
	{ {'B', 'R', '4', 'J'},  GBA_SAVEDATA_FLASH512, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Rocky
	{ {'A', 'R', '8', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'R', 'O', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Sennen Kazoku
	{ {'B', 'K', 'A', 'J'},  GBA_SAVEDATA_FLASH1M, HW_RTC, GBA_IDLE_LOOP_NONE },

	// Shin Bokura no Taiyou: Gyakushuu no Sabata
	{ {'U', '3', '3', 'J'},  GBA_SAVEDATA_EEPROM, HW_RTC | HW_LIGHT_SENSOR, GBA_IDLE_LOOP_NONE },

	// Stuart Little 2
	{ {'A', 'S', 'L', 'E'},  GBA_SAVEDATA_FORCE_NONE, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'S', 'L', 'F'},  GBA_SAVEDATA_FORCE_NONE, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Super Mario Advance 2
	{ {'A', 'A', '2', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x800052E },
	{ {'A', 'A', '2', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x800052E },
	{ {'A', 'A', '2', 'P'},  GBA_SAVEDATA_AUTODETECT, HW_NONE, 0x800052E },

	// Super Mario Advance 3
	{ {'A', '3', 'A', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x8002B9C },
	{ {'A', '3', 'A', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x8002B9C },
	{ {'A', '3', 'A', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, 0x8002B9C },

	// Super Mario Advance 4
	{ {'A', 'X', '4', 'J'},  GBA_SAVEDATA_FLASH1M, HW_NONE, 0x800072A },
	{ {'A', 'X', '4', 'E'},  GBA_SAVEDATA_FLASH1M, HW_NONE, 0x800072A },
	{ {'A', 'X', '4', 'P'},  GBA_SAVEDATA_FLASH1M, HW_NONE, 0x800072A },

	// Super Monkey Ball Jr.
	{ {'A', 'L', 'U', 'E'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },
	{ {'A', 'L', 'U', 'P'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Top Gun - Combat Zones
	{ {'A', '2', 'Y', 'E'},  GBA_SAVEDATA_FORCE_NONE, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Ueki no Housoku - Jingi Sakuretsu! Nouryokusha Battle
	{ {'B', 'U', 'H', 'J'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE },

	// Wario Ware Twisted
	{ {'R', 'Z', 'W', 'J'},  GBA_SAVEDATA_SRAM, HW_RUMBLE | HW_GYRO, GBA_IDLE_LOOP_NONE },
	{ {'R', 'Z', 'W', 'E'},  GBA_SAVEDATA_SRAM, HW_RUMBLE | HW_GYRO, GBA_IDLE_LOOP_NONE },
	{ {'R', 'Z', 'W', 'P'},  GBA_SAVEDATA_SRAM, HW_RUMBLE | HW_GYRO, GBA_IDLE_LOOP_NONE },

	// Yoshi's Universal Gravitation
	{ {'K', 'Y', 'G', 'J'},  GBA_SAVEDATA_EEPROM, HW_TILT, GBA_IDLE_LOOP_NONE },
	{ {'K', 'Y', 'G', 'E'},  GBA_SAVEDATA_EEPROM, HW_TILT, GBA_IDLE_LOOP_NONE },
	{ {'K', 'Y', 'G', 'P'},  GBA_SAVEDATA_EEPROM, HW_TILT, GBA_IDLE_LOOP_NONE },

	// Aging cartridge
	{ {'T', 'C', 'H', 'K'},  GBA_SAVEDATA_EEPROM, HW_NONE, GBA_IDLE_LOOP_NONE, },

	{ { 0, 0, 0, 0 }, static_cast<enum GBASavedataType>(0), 0, GBA_IDLE_LOOP_NONE, false }
};

bool GBAOverrideFindConfig(const struct Configuration* config, struct GBACartridgeOverride* override) {
	bool found = false;
	if (config) {
		char sectionName[16];
		snprintf(sectionName, sizeof(sectionName), "override.%c%c%c%c", override->id[0], override->id[1], override->id[2], override->id[3]);
		const char* savetype = ConfigurationGetValue(config, sectionName, "savetype");
		const char* hardware = ConfigurationGetValue(config, sectionName, "hardware");
		const char* idleLoop = ConfigurationGetValue(config, sectionName, "idleLoop");

		if (savetype) {
			if (strcasecmp(savetype, "SRAM") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_SRAM;
			} else if (strcasecmp(savetype, "SRAM512") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_SRAM512;
			} else if (strcasecmp(savetype, "EEPROM") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_EEPROM;
			} else if (strcasecmp(savetype, "EEPROM512") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_EEPROM512;
			} else if (strcasecmp(savetype, "FLASH512") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_FLASH512;
			} else if (strcasecmp(savetype, "FLASH1M") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_FLASH1M;
			} else if (strcasecmp(savetype, "NONE") == 0) {
				found = true;
				override->savetype = GBA_SAVEDATA_FORCE_NONE;
			}
		}

		if (hardware) {
			char* end;
			long type = strtoul(hardware, &end, 0);
			if (end && !*end) {
				override->hardware = type & ~HW_NO_OVERRIDE;
				found = true;
			}
		}

		if (idleLoop) {
			char* end;
			uint32_t address = strtoul(idleLoop, &end, 16);
			if (end && !*end) {
				override->idleLoop = address;
				found = true;
			}
		}
	}
	return found;
}

bool GBAOverrideFind(const struct Configuration* config, struct GBACartridgeOverride* override) {
	override->savetype = GBA_SAVEDATA_AUTODETECT;
	override->hardware = HW_NO_OVERRIDE;
	override->idleLoop = GBA_IDLE_LOOP_NONE;
	override->vbaBugCompat = false;
	bool found = false;

	int i;
	for (i = 0; _overrides[i].id[0]; ++i) {
		if (memcmp(override->id, _overrides[i].id, sizeof(override->id)) == 0) {
			*override = _overrides[i];
			found = true;
			break;
		}
	}
	if (!found && override->id[0] == 'F') {
		// Classic NES Series
		override->savetype = GBA_SAVEDATA_EEPROM;
		found = true;
	}

	if (config) {
		found = GBAOverrideFindConfig(config, override) || found;
	}
	return found;
}

void GBAOverrideSave(struct Configuration* config, const struct GBACartridgeOverride* override) {
	char sectionName[16];
	snprintf(sectionName, sizeof(sectionName), "override.%c%c%c%c", override->id[0], override->id[1], override->id[2], override->id[3]);
	const char* savetype = 0;
	switch (override->savetype) {
	case GBA_SAVEDATA_SRAM:
		savetype = "SRAM";
		break;
	case GBA_SAVEDATA_SRAM512:
		savetype = "SRAM512";
		break;
	case GBA_SAVEDATA_EEPROM:
		savetype = "EEPROM";
		break;
	case GBA_SAVEDATA_EEPROM512:
		savetype = "EEPROM512";
		break;
	case GBA_SAVEDATA_FLASH512:
		savetype = "FLASH512";
		break;
	case GBA_SAVEDATA_FLASH1M:
		savetype = "FLASH1M";
		break;
	case GBA_SAVEDATA_FORCE_NONE:
		savetype = "NONE";
		break;
	case GBA_SAVEDATA_AUTODETECT:
		break;
	}
	ConfigurationSetValue(config, sectionName, "savetype", savetype);

	if (override->hardware != HW_NO_OVERRIDE) {
		ConfigurationSetIntValue(config, sectionName, "hardware", override->hardware);
	} else {
		ConfigurationClearValue(config, sectionName, "hardware");
	}

	if (override->idleLoop != GBA_IDLE_LOOP_NONE) {
		ConfigurationSetUIntValue(config, sectionName, "idleLoop", override->idleLoop);
	} else {
		ConfigurationClearValue(config, sectionName, "idleLoop");
	}
}

void GBAOverrideApply(struct GBA* gba, const struct GBACartridgeOverride* override) {
	if (override->savetype != GBA_SAVEDATA_AUTODETECT) {
		GBASavedataForceType(&gba->memory.savedata, override->savetype);
	}

	gba->vbaBugCompat = override->vbaBugCompat;

	if (override->hardware != HW_NO_OVERRIDE) {
		GBAHardwareClear(&gba->memory.hw);
		gba->memory.hw.devices &= ~HW_NO_OVERRIDE;

		if (override->hardware & HW_RTC) {
			GBAHardwareInitRTC(&gba->memory.hw);
			GBASavedataRTCRead(&gba->memory.savedata);
		}

		if (override->hardware & HW_GYRO) {
			GBAHardwareInitGyro(&gba->memory.hw);
		}

		if (override->hardware & HW_RUMBLE) {
			GBAHardwareInitRumble(&gba->memory.hw);
		}

		if (override->hardware & HW_LIGHT_SENSOR) {
			GBAHardwareInitLight(&gba->memory.hw);
		}

		if (override->hardware & HW_TILT) {
			GBAHardwareInitTilt(&gba->memory.hw);
		}

		if (override->hardware & HW_EREADER) {
			GBACartEReaderInit(&gba->memory.ereader);
		}

		if (override->hardware & HW_GB_PLAYER_DETECTION) {
			gba->memory.hw.devices |= HW_GB_PLAYER_DETECTION;
		} else {
			gba->memory.hw.devices &= ~HW_GB_PLAYER_DETECTION;
		}
	}

	if (override->idleLoop != GBA_IDLE_LOOP_NONE) {
		gba->idleLoop = override->idleLoop;
		if (gba->idleOptimization == IDLE_LOOP_DETECT) {
			gba->idleOptimization = IDLE_LOOP_REMOVE;
		}
	}
}

void GBAOverrideApplyDefaults(struct GBA* gba, const struct Configuration* overrides) {
	struct GBACartridgeOverride override = { .idleLoop = GBA_IDLE_LOOP_NONE };
	const struct GBACartridge* cart = (const struct GBACartridge*) gba->memory.rom;
	if (cart) {
		if (gba->memory.unl.type == GBA_UNL_CART_MULTICART) {
			override.savetype = GBA_SAVEDATA_SRAM;
			GBAOverrideApply(gba, &override);
			return;
		}

		memcpy(override.id, &cart->id, sizeof(override.id));

		static const uint32_t pokemonTable[] = {
			// Emerald
			0x4881F3F8, // BPEJ
			0x8C4D3108, // BPES
			0x1F1C08FB, // BPEE
			0x34C9DF89, // BPED
			0xA3FDCCB1, // BPEF
			0xA0AEC80A, // BPEI

			// FireRed
			0x1A81EEDF, // BPRD
			0x3B2056E9, // BPRJ
			0x5DC668F6, // BPRF
			0x73A72167, // BPRI
			0x84EE4776, // BPRE rev 1
			0x9F08064E, // BPRS
			0xBB640DF7, // BPRJ rev 1
			0xDD88761C, // BPRE

			// Ruby
			0x61641576, // AXVE rev 1
			0xAEAC73E6, // AXVE rev 2
			0xF0815EE7, // AXVE
		};

		bool isPokemon = false;
		isPokemon = isPokemon || !strncmp("pokemon red version", &((const char*) gba->memory.rom)[0x108], 20);
		isPokemon = isPokemon || !strncmp("pokemon emerald version", &((const char*) gba->memory.rom)[0x108], 24);
		isPokemon = isPokemon || !strncmp("AXVE", &((const char*) gba->memory.rom)[0xAC], 4);
		bool isKnownPokemon = false;
		if (isPokemon) {
			size_t i;
			for (i = 0; !isKnownPokemon && i < sizeof(pokemonTable) / sizeof(*pokemonTable); ++i) {
				isKnownPokemon = gba->romCrc32 == pokemonTable[i];
			}
		}

		if (isPokemon && !isKnownPokemon) {
			// Enable FLASH1M and RTC on Pokémon ROM hacks
			override.savetype = GBA_SAVEDATA_FLASH1M;
			override.hardware = HW_RTC;
			override.vbaBugCompat = true;
			// Allow overrides from config file but not from defaults
			GBAOverrideFindConfig(overrides, &override);
			GBAOverrideApply(gba, &override);
		} else if (GBAOverrideFind(overrides, &override)) {
			GBAOverrideApply(gba, &override);
		}
	}
}
#ifdef __cplusplus
#pragma GCC diagnostic pop
#endif
