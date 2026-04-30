#include "core.h"

#include <mgba/core/core.h>

struct mCoreCallbacks* mCorePythonCallbackCreate(void* pyobj) {
	struct mCoreCallbacks* callbacks = malloc(sizeof(*callbacks));
	callbacks->videoFrameStarted = _mCorePythonCallbacksVideoFrameStarted;
	callbacks->videoFrameEnded = _mCorePythonCallbacksVideoFrameEnded;
	callbacks->coreCrashed = _mCorePythonCallbacksCoreCrashed;
	callbacks->sleep = _mCorePythonCallbacksSleep;
	callbacks->keysRead = _mCorePythonCallbacksKeysRead;

	callbacks->context = pyobj;
	return callbacks;
}
