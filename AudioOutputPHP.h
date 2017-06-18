//
// libtgvoip is free and unencumbered public domain software.
// For more information, see http://unlicense.org or the UNLICENSE file
// you should have received with this source code distribution.
//

#ifndef LIBTGVOIP_AUDIOOUTPUTPHP_H
#define LIBTGVOIP_AUDIOOUTPUTPHP_H

#include "libtgvoip/audio/AudioOutput.h"

namespace tgvoip{ namespace audio{
class AudioOutputPHP : public AudioOutput{

public:

	AudioOutputPHP();
	virtual ~AudioOutputPHP();
	virtual void Configure(uint32_t sampleRate, uint32_t bitsPerSample, uint32_t channels);
	virtual void Start();
	virtual void Stop();
	virtual bool IsPlaying() override;
	virtual float GetLevel() override;
	void HandleCallback(JNIEnv* env, jbyteArray buffer);
	static jmethodID initMethod;
	static jmethodID releaseMethod;
	static jmethodID startMethod;
	static jmethodID stopMethod;
	static jclass jniClass;

private:
	jobject javaObject;
	bool running;

};
}}

#endif //LIBTGVOIP_AUDIOOUTPUTPHP_H
