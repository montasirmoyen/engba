#ifndef M_SCRIPT_BASE_H
#define M_SCRIPT_BASE_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/script/macros.h>
#include <mgba-util/geometry.h>
#include <mgba-util/image.h>

mSCRIPT_DECLARE_STRUCT(mImage)
mSCRIPT_DECLARE_STRUCT(mRectangle);
mSCRIPT_DECLARE_STRUCT(mSize);

struct mScriptContext;
void mScriptContextAttachImage(struct mScriptContext* context);
void mScriptContextAttachStdlib(struct mScriptContext* context);
void mScriptContextAttachSocket(struct mScriptContext* context);

CXX_GUARD_END

#endif
