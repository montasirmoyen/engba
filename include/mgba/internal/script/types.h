#ifndef M_SCRIPT_TYPES_INTERNAL_H
#define M_SCRIPT_TYPES_INTERNAL_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct Table;
void mScriptContextGetInputTypes(struct Table*);

void mScriptTypeAdd(struct Table*, const struct mScriptType* type);

CXX_GUARD_END

#endif
