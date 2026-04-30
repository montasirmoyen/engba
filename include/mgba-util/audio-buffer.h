#ifndef M_AUDIO_BUFFER_H
#define M_AUDIO_BUFFER_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba-util/circle-buffer.h>

struct mAudioBuffer {
	struct mCircleBuffer data;
	unsigned channels;
};

void mAudioBufferInit(struct mAudioBuffer* buffer, size_t capacity, unsigned channels);
void mAudioBufferDeinit(struct mAudioBuffer* buffer);

size_t mAudioBufferAvailable(const struct mAudioBuffer* buffer);
size_t mAudioBufferCapacity(const struct mAudioBuffer* buffer);

void mAudioBufferClear(struct mAudioBuffer* buffer);
int16_t mAudioBufferPeek(const struct mAudioBuffer* buffer, unsigned channel, size_t offset);
size_t mAudioBufferDump(const struct mAudioBuffer* buffer, int16_t* samples, size_t count, size_t offset);
size_t mAudioBufferRead(struct mAudioBuffer* buffer, int16_t* samples, size_t count);
size_t mAudioBufferWrite(struct mAudioBuffer* buffer, const int16_t* samples, size_t count);

CXX_GUARD_END

#endif
