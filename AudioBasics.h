/* refer to https://en.wikipedia.org/wiki/C_data_types */
typedef struct WAVEFORM
{
	double* pdWaveform;		/* could be uninitialized */
	unsigned long nSamples; /* do I really prefer this to 'int' ? %ul : %d. 
								besides, a waveform that needs more than a short amount of samples...
								really ought to be broken up into smaller waveforms, and is beyond the scope
								of this struct */
	int nSampleRate;		/* arguable. this might be managed by the overall process, not the individual waveform... but, er, bad idea. */
} waveform;

/* *
* A function that ensures every sample pointed to by pWave->pdWaveform has magnitude at most 1,
*	to prevent the creation of unusually dangerous audio volume levels.
* returns: '0' for success.
*	Or should it return '0' for no samples out of range, and some other number for too many samples found OR an error?
* in/out: *pWaveform
* */
/*
* If pWave->nSamples is not the correct number of samples, we could have memory problems
*	OR the function might not limit the dynamics of every sample causing unusually dangerous audio volume!
*/
int safetyboundWaveform(struct WAVEFORM* pWave);

/* *
* A function that creates a struct WAVEFORM and allocates its pdWaveform to have the specified number of nSamples.
*	does NOT allocate the struct WAVEFORM itself.
* returns: '0' for success
* out: pWave, the waveform initialized
* in: nSamples: samples for the new waveform
* in: nSampleRate: 
* in: (bool or int) bZero: whether or not to set every sample of pWave->pdWaveform to 0.0
*/
waveform* initWaveform(unsigned long nSamples, int nSampleRate, int bZero);


/*
* ... decide: will this reinit 
* ALWAYS safety-check it, even if I shouldn't.
* in: bOverwrite: overwrites samples in pWaveTarget beyond the length of pWaveSource
* in: bZero: whether to check magnitude of pWaveSource samples before sending in.
*/
/* in current version, does NOT malloc anything. but perhaps it really ought to. ... ? need to consider use. */
int copyWaveform(waveform* pWaveTarget, waveform* pWaveSource, int bOverwrite, int bZero);