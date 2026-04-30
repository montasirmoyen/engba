#ifndef SDL_GL_COMMON_H
#define SDL_GL_COMMON_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct VideoBackend;
struct mSDLRenderer;
void mSDLGLDoViewport(int w, int h, struct VideoBackend* v);
void mSDLGLCommonSwap(struct VideoBackend* context);
bool mSDLGLCommonInit(struct mSDLRenderer* renderer);
void mSDLGLCommonRunloop(struct mSDLRenderer* renderer, void* user);
bool mSDLGLCommonLoadBackground(struct VideoBackend* context);

CXX_GUARD_END

#endif
