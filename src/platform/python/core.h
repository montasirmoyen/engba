#include <mgba-util/common.h>

#include "pycommon.h"

struct mCoreCallbacks* mCorePythonCallbackCreate(void* pyobj);

PYEXPORT void _mCorePythonCallbacksVideoFrameStarted(void* user);
PYEXPORT void _mCorePythonCallbacksVideoFrameEnded(void* user);
PYEXPORT void _mCorePythonCallbacksCoreCrashed(void* user);
PYEXPORT void _mCorePythonCallbacksSleep(void* user);
PYEXPORT void _mCorePythonCallbacksKeysRead(void* user);
