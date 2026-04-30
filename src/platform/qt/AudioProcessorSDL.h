#pragma once

#include "AudioProcessor.h"

#ifdef BUILD_SDL

#define SDL_MAIN_HANDLED
#include "platform/sdl/sdl-audio.h"

namespace QGBA {

class AudioProcessorSDL : public AudioProcessor {
Q_OBJECT

public:
	AudioProcessorSDL(QObject* parent = nullptr);

	virtual unsigned sampleRate() const override;

public slots:
	virtual void setInput(std::shared_ptr<CoreController> input) override;
	virtual void stop() override;
	virtual bool start() override;
	virtual void pause() override;

	virtual void setBufferSamples(int samples) override;
	virtual void inputParametersChanged() override;

	virtual void requestSampleRate(unsigned) override;

private:
	mSDLAudio m_audio{2048, 44100};
};

}

#endif
