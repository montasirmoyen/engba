#ifndef GB_CLI_H
#define GB_CLI_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/internal/debugger/cli-debugger.h>

struct GBCLIDebugger {
	struct CLIDebuggerSystem d;

	struct mCore* core;

	bool frameAdvance;
	bool inVblank;
};

struct CLIDebuggerSystem* GBCLIDebuggerCreate(struct mCore*);

CXX_GUARD_END

#endif
