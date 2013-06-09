#ifndef OPENSHOT_RESAMPLER_H
#define OPENSHOT_RESAMPLER_H

/**
 * \file
 * \brief Header file for AudioResampler class
 * \author Copyright (c) 2011 Jonathan Thomas
 */

/// Do not include the juce unittest headers, because it collides with unittest++
#ifndef __JUCE_UNITTEST_JUCEHEADER__
	#define __JUCE_UNITTEST_JUCEHEADER__
#endif

#ifndef _NDEBUG
	// Define NO debug for JUCE on mac os
	#define _NDEBUG
#endif

#include "JuceLibraryCode/JuceHeader.h"
#include "AudioBufferSource.h"
#include "Exceptions.h"

/// This namespace is the default namespace for all code in the openshot library.
namespace openshot {

	/**
	 * \brief This class is used to resample audio data for many sequential frames. It maintains some data from the last
	 * call to GetResampledBuffer(), so there are no pops and clicks between frames.
	 */
	class AudioResampler {
	private:
		AudioSampleBuffer *buffer;
		AudioSampleBuffer *resampled_buffer;
		AudioBufferSource *buffer_source;
		ResamplingAudioSource *resample_source;
		AudioSourceChannelInfo resample_callback_buffer;

		int num_of_samples;
		int new_num_of_samples;
		double dest_ratio;
		double source_ratio;
		bool isPrepared;

	public:
		/// Default constructor
		AudioResampler();

		/// Destructor
		~AudioResampler();

		/// Sets the audio buffer and key settings
		int SetBuffer(AudioSampleBuffer *new_buffer, double sample_rate, double new_sample_rate);

		/// Sets the audio buffer and key settings
		int SetBuffer(AudioSampleBuffer *new_buffer, double ratio);

		/// Get the resampled audio buffer
		AudioSampleBuffer* GetResampledBuffer();
	};

}

#endif
