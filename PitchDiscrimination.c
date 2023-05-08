/* PitchDiscrimination.c : Defines the entry point for the pitch-discrimination test application. */
#include "PitchDiscrimination.h"

int genFrequency(int iLow, int iHigh)
{
	return 0;
}

int genFrequencyNearby(int iFirstFreq, int iMinCentsAway, int iMaxCentsAway, dist enDistribution, float fSameFreq)
{
	return 0;
}

void frequencyTest(char* szTestOutput, int* piStringLen, int iFirstFreq, int iSecFreq, int(*fnWaveform)(waveform* pWave, int nSamples, int nSampleRate, double frequency))
{
}

int runFrequencyTests(char* szTestOutput, int* piStringLen, int iLow, int iHigh, int(*fnWaveform)(waveform* pWave, int nSamples, int nSampleRate, double frequency), dist enDistOfCentsDifference, float fSameFreq)
{
	return 0;
}

int pitchDiscriminationMain()
{
	int nSampleRate = 32000;		/* why do high res? */
	int nSamples = nSampleRate * 2; /* 2 seconds */
	int iLow, iHigh, nTries = 0;
	int iCentsMin, iCentsHigh;
	float fSameFreq = 0.0;
	printf("Type the settings separated by a space, then enter.\n");
	printf("Lowest frequency for first tone? Highest frequency for first tone? Number of tries?\n");
	scanf("%d %d %d", &iLow, &iHigh, &nTries);
	printf("Probability that both tones will have the same frequency?\n");
	scanf("%1.3f", &fSameFreq); /* be sure this works like you want it to.*/
	printf("For a pair of non-equal tones: least magnitude difference of second tone from first tone in cents, greatest magnitude difference of second tone from first tone in cents?\n");
	scanf("%d %d", iCentsMin, iCentsHigh);

	/* now query which tone generator to use */
	/* get ready to write to or append file. make a new file unless on the same date, the same tone has been used for a test already. */
	for (int i = 0; i < nTries; i++)
	{

	}
	return 0;
}


int main()
{
	pitchDiscriminationMain();
	return 0;
}
