#ifndef MEMORY_DEBUGGER_H
#define MEMORY_DEBUGGER_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct ARMDebugger;

void ARMDebuggerInstallMemoryShim(struct ARMDebugger* debugger);
void ARMDebuggerRemoveMemoryShim(struct ARMDebugger* debugger);

CXX_GUARD_END

#endif
