int beepFunction(waveform* pWave, int nSamples, int nSampleRate, double frequency)
{
	Beep(frequency, nSampleRate / nSamples);
	return 0;
}