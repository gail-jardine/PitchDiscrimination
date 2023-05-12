/* PitchDiscrimination.c : Defines the entry point for the pitch-discrimination test application. */
#include "PitchDiscrimination.h"

/* note: the distribution used to generate frequencies matters
  let's be simple and just observe that octaves are logarithmic
*/
int genFrequency(int iLow, int iHigh)
{
	double dOctaveEstimate = log(iHigh - iLow) / log(2);
	// now we want to distribute values so that each octave is equally likely to be the one we pick

	return 0; //ToDo: implement
}

int genFrequencyNearby(int iFirstFreq, int iMinCentsAway, int iMaxCentsAway, float fSameFreq)
{
	return 0; //ToDo: implement
}

/* helper function for frequencyTest */
char printHigherOrLower(int iAbove0)
{
	if (iAbove0 > 0)
		return 'H';
	else if (iAbove0 < 0)
		return 'L';
	return '=';
}
/*
szTestOutput:
specify: we don't need to specify the type of frequency, that will be at the header of each function anyway
we do need to specify the guess, whether it was correct, the correct answer, and the two frequencies
this has some redundncy, but nothing too bad
the string size will be variable depending on the number of digits in iFirstFreq and iSecFreq, but let's just give it an upper bound
and make it static length
lets assume no frequencies about 30,000 Hz, so 5 digits.
*/
void frequencyTest(char* szTestOutput, int* piStringLen, int iFirstFreq, int iSecFreq,
	int (*fnWaveform)(waveform* pWave, int nSamples, int nSampleRate, double frequency))
{
	int nSampleRate = nSamples;
	int nSamples = nSampleRate * 3; /* 3 seconds */
	int done = 0;
	int sgnAns = 0;	/* 0 for equality, 1 for higher second frequency, -1 for lower second frequency */
	int sgnCorrect = 0;
	if (iSecFreq > iFirstFreq
		cCorrectAns = 1;
	else if (iSecFreq < iFirstFreq)
		cCorrectAns = -1;
		while (!bDone) /* play 2 beeps, let user guess if the second beep is higher, lower, or equal */
		{
			fnWaveForm(waveform * pWave1, nSamples, nSampleRate, iFirstFreq); /* verify if this works */
				fnWaveForm(waveform * pWave1, nSamples, nSampleRate, iSecFreq);
				/* I might want to add a blank moment between the pitches, but not for now */
				char cAns = tolower(getch());
				switch (cAns)
				{
				case 'h': case 'u': //'high' or 'up', second note was higher?
					bDone = 1;
					sgnAns = 1;
					break;
				case 'l': case 'd': //'low' or 'down', second note was lower?
					bDone = 1;
					sgnAns = -1;
					break;
				case 's': case 'e': case '=': //'same' or 'equal', no difference?
					bDone = 1;
					sgnAns = 0;
					break;
				default:	// otherwise, try again.
					bDone = 0;
				}
		}
	int bCorrectAnswer = (sgnAns == sgnCorrect);
	int* piStringLen = &(int)sizeof("guess: G; ans: A; correct: C; 20000 20000"); /* verify if this works */
	szTestOutput = (char*)malloc((size_t)*piStringLen);
	sprintf(szTestOutput, "guess: %c; ans: %c; correct: %1d; %5d %5d",
		printHigherOrLower(sgnAns), printHigherOrLower(sgnCorrect), sgnAns == sgnCorrect, iFirstFreq, iSecFreq);
}

int pitchDiscriminationMain()
{
	/* initialize values */
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

	/* now set which tone generator to use
		this affects name of file and tone
		currently, just use beep. */
	int (*fnWaveform)(waveform * pWave, int nSamples, int nSampleRate, double frequency)); // ToDo: fix this

	// ToDo: write to file.

	/* get ready to write to or append file. make a new file unless on the same date, the same tone has been used for a test already. */
	for (int i = 0; i < nTries; i++)
	{
		/* randomly select frequencies */
		int iFreqFirst = genFrequency(iLow, iHigh);
		int iFreqSec = genFrequencyNearby(iFreqFirst, iCentsMin, iCentsHigh, fSameFreq);

		/* test the user */
		frequencyTest(szTestOutput, piStringLen, iFirstFreq, iSecFreq, *fnWaveform);
		char* szTrialOutput;
		int* piStringLen;
		/* write to file and clear szTrialOutput */
		// ToDo: Write.
		free(szTrialOutput);
	}
	/* close files, etc. Perhaps offer to tell the user how they did. */
	// ToDo: close files.
	return 0;
}


int main()
{
	pitchDiscriminationMain();
	return 0;
}
