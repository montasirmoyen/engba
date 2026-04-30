#ifndef GUI_CONFIG_H
#define GUI_CONFIG_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mGUIRunner;
struct GUIMenuItem;
void mGUIShowConfig(struct mGUIRunner* runner, struct GUIMenuItem* extra, size_t nExtra);

CXX_GUARD_END

#endif
