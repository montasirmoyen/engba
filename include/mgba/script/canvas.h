#ifndef M_SCRIPT_CANVAS_H
#define M_SCRIPT_CANVAS_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/script/context.h>
#include <mgba/script/macros.h>

struct VideoBackend;
void mScriptContextAttachCanvas(struct mScriptContext* context);
void mScriptCanvasUpdate(struct mScriptContext* context);
void mScriptCanvasUpdateBackend(struct mScriptContext* context, struct VideoBackend*);
void mScriptCanvasSetInternalScale(struct mScriptContext* context, unsigned scale);

CXX_GUARD_END

#endif
