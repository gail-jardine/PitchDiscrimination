#pragma once

/* *
* This file contains headers for functions that are used to play a simple tone,
* e.g. sine waves, sawtooth waves, square wave, and a preset waveform.
* (May 2023)
* */

/* basic form of a function */
/* should pWave have anything input into it to start, or what?
probably not, since we are probably mallocing pWave here.
*/
int waveformFunction(waveform* pWave, int nSamples, int nSampleRate, double frequency);
/* could include 'double maxAmplitude', but NOTE I want to require amplitude is at most 1.0
to that end, I should define a new data type 'maxAmplitude'... oh, at this rate, I will want maxAmplitude
to be a class....
*/

/* approximate a sine wave at the specified frequency and sample rate.
amplitude: should amplitude be configurable? probably! but not what I want to deal with right now.*/
int waveformSin(waveform* pWave, int nSamples, int nSampleRate, double frequency);


/* approximate a sawtooth wave at the specified frequency and sample rate.
amplitude: should amplitude be configurable? probably! but not what I want to deal with right now.*/
int waveformSawtooth(waveform* pWave, int nSamples, int nSampleRate, double frequency);

/* this is not necessary, and if I did have it, the 'frequency' info would be bogus
I mean really, the waveform initializer function initWave initializes to 0 anyway...*/
/*int blankTone(waveform* pWave, int nSamples, int nSampleRate);*/


/* * Plays the first nSamples of the waveform.
* */
int playWaveform(waveform* pWave, int nSamples, int nSampleRate);