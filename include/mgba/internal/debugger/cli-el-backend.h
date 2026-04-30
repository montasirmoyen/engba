#ifndef CLI_EL_BACKEND_H
#define CLI_EL_BACKEND_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/internal/debugger/cli-debugger.h>

#include <histedit.h>

struct CLIDebuggerBackend* CLIDebuggerEditLineBackendCreate(void);

CXX_GUARD_END

#endif
