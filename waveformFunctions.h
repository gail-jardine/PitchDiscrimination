#pragma once

/* note that it makes sense for waveform generators to return a waveform, but for this application,
 it is more important that they play the waveform on each call, and in some cases they may only return
 a null, as this makes it easier to use e.g. the Beep function, which does not rely on my waveform function */

 /* below won't really be necessary, because I can just include https://github.com/zserge/beep/blob/master/beep.h as an external file  */
#ifdef _WIN32 || _NT
#include <Windows.h>
#else
BOOL Beep(
	[in] DWORD dwFreq,
	[in] DWORD dwDuration
) {
	printf("sorry, Windows.h not included, so Beep(%d, %d) does nothing\n", (int)dwFreq, (int)dwDuration);
}
#endif


/* default form of a function:
int (*fnWaveform) (waveform* pWave, int nSamples, int nSampleRate, double frequency)
returns the number of elements pointed to by pWave.
This number will be 0 if pWave is null, and will likely be close to nSamples otherwise unless otherwise specified.

allocates, generates, and plays waveform* pWave at the given frequency and with duration set by nSamples and nSampleRate

or else plays a sound at specified frequency and with duration set by nSamples and nSampleRate, without using waveform*
*/

/* *
* Calls the Beep function for the specified time and frequency.
* waveform* pWave is not generated by this function. Therefore, we return a null instead of allocating a waveform*.
* time is specified by approximating nSamples / nSampleRate in milliseconds
*/

int beepFunction(waveform* pWave, int nSamples, int nSampleRate, double frequency);