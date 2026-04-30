#ifndef GBA_CLI_H
#define GBA_CLI_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/internal/debugger/cli-debugger.h>

struct mCore;

struct GBACLIDebugger {
	struct CLIDebuggerSystem d;

	struct mCore* core;

	bool frameAdvance;
	bool inVblank;
};

struct GBACLIDebugger* GBACLIDebuggerCreate(struct mCore*);

CXX_GUARD_END

#endif
