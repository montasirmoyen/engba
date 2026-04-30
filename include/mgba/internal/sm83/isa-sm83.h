#ifndef ISA_SM83_H
#define ISA_SM83_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct SM83Core;

typedef void (*SM83Instruction)(struct SM83Core*);
extern const SM83Instruction _sm83InstructionTable[0x100];

CXX_GUARD_END

#endif
