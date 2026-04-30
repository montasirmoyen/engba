#ifndef SM83_MEMORY_DEBUGGER_H
#define SM83_MEMORY_DEBUGGER_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct SM83Debugger;

void SM83DebuggerInstallMemoryShim(struct SM83Debugger* debugger);
void SM83DebuggerRemoveMemoryShim(struct SM83Debugger* debugger);

CXX_GUARD_END

#endif
