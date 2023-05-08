#include "AudioBasics.h"

int safetyboundWaveform(struct WAVEFORM* pWave)
{
	int i = 0;
	for (i = 0; i < pWave->nSampleRate; i++)
	{
		dSamp = *(pWave->pdWaveform + i);
		if (dSamp > 1 || dSamp < -1) {
			*(pWave->pdWaveform + i) = 0.0;
			printf("Warning! Samples detected out of range, index %d, value %.1f\n", i, dSamp);
		}
	}
	return 0;
}

waveform* initWaveform(unsigned long nSamples, int nSampleRate, int bZero)
/* not: int initWaveform(struct WAVEFORM* pWave, unsigned long nSamples, int nSampleRate, int bZero)*/
{
	waveform* pWave = malloc(sizeof(waveform));
	pWave = (waveform*)malloc(sizeof(waveform) * nSamples);
		/* ToDo: should it be sizeof(waveform) itself, not WAVEFORM or struct WAVEFORM ?*/
	if(bZero)
		for (int i = 0; i < nSamples; i++)
			*(pWave->pdWaveform + i) = 0.0;
	return 0;
}

freeWaveForm

/* in current version, does NOT malloc anything. but perhaps it really ought to. ... ? need to consider use.*/
int copyWaveform(waveform* pWaveTarget, waveform* pWaveSource, int bOverwrite, int bZero)
{
	for (int i = 0; i < pWaveTarget->nSamples; i++)
	{
		if (i < pWaveSource->nSamples) {
			*(pWaveTarget->pdWaveform + i) = *(pWaveSource->pdWaveform + i);
			if (bZero) {
				double dWaveform = *(pWaveTarget->pdWaveform);
				if (dWaveform < -1.0 || dWaveform > 1.0)
					*(pWaveTarget->pdWaveform + i) = 0.0; /* warning */
			}
		}
		else if(bOverwrite)
			*(pWaveTarget->pdWaveform + i) = 0.0;
	}
	return 0;
}
