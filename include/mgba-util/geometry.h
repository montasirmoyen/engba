#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <mgba-util/common.h>

CXX_GUARD_START

struct mSize {
	int width;
	int height;
};

struct mRectangle {
	int x;
	int y;
	int width;
	int height;
};

void mRectangleUnion(struct mRectangle* dst, const struct mRectangle* add);
bool mRectangleIntersection(struct mRectangle* dst, const struct mRectangle* add);
void mRectangleCenter(const struct mRectangle* ref, struct mRectangle* rect);

CXX_GUARD_END

#endif
