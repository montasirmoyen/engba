#include <mgba/core/log.h>

#include "pycommon.h"

struct mLoggerPy {
    struct mLogger d;
    void* pyobj;
};

struct mLogger* mLoggerPythonCreate(void* pyobj);

PYEXPORT void _pyLog(void* logger, int category, enum mLogLevel level, const char* message);
