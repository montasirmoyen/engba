#ifndef M_INTERPOLATOR_H
#define M_INTERPOLATOR_H

#include <mgba-util/common.h>

CXX_GUARD_START

enum mInterpolatorType {
	mINTERPOLATOR_SINC,
	mINTERPOLATOR_COSINE,
};

struct mInterpolationData {
	int16_t (*at)(int index, const void* context);
	void* context;
};

struct mInterpolator {
	int16_t (*interpolate)(const struct mInterpolator* interp, const struct mInterpolationData* data, double time, double sampleStep);
};

struct mInterpolatorSinc {
	struct mInterpolator d;

	unsigned resolution;
	unsigned width;
	double* sincLut;
	double* windowLut;
};

struct mInterpolatorCosine {
	struct mInterpolator d;

	unsigned resolution;
	double* lut;
};

void mInterpolatorSincInit(struct mInterpolatorSinc* interp, unsigned resolution, unsigned width);
void mInterpolatorSincDeinit(struct mInterpolatorSinc* interp);

void mInterpolatorCosineInit(struct mInterpolatorCosine* interp, unsigned resolution);
void mInterpolatorCosineDeinit(struct mInterpolatorCosine* interp);

CXX_GUARD_END

#endif
