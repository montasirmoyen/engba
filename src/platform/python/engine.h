#ifndef PYTHON_ENGINE_H
#define PYTHON_ENGINE_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mScriptBridge;
struct mPythonScriptEngine;
struct mPythonScriptEngine* mPythonCreateScriptEngine(void);
void mPythonSetup(struct mScriptBridge* sb);

CXX_GUARD_END

#endif
