#ifndef GUI_FILE_CHOOSER_H
#define GUI_FILE_CHOOSER_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba-util/gui.h>

struct VFile;

bool GUISelectFile(struct GUIParams*, char* outPath, size_t outLen, bool (*filterName)(const char* name), bool (*filterContents)(struct VFile*), const char* preselect);

CXX_GUARD_END

#endif
