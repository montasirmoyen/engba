#ifndef GUI_REMAP_H
#define GUI_REMAP_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct GUIInputKeys {
	const char* name;
	uint32_t id;
	const char* const* keyNames;
	size_t nKeys;
};

struct GUIParams;
struct mInputMap;

void mGUIRemapKeys(struct GUIParams*, struct mInputMap*, const struct GUIInputKeys*);

CXX_GUARD_END

#endif
