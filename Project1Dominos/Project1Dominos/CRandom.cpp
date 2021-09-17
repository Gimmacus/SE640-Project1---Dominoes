#ifndef CRANDOM_CPP
#define CRANDOM_CPP

#include "CRandom.h"

using namespace std;

template<class item>
CRandom<item>::CRandom()
{
	m_Randomizer = std::default_random_engine{};
	setSeed();
}

template<class item>
CRandom<item>::~CRandom()
{
}

template<class item>
void CRandom<item>::setSeed(int seed)
{
	m_Seed = seed;
	m_Randomizer.seed(m_Seed);
}

template<class item>
void CRandom<item>::setSeed()
{
	m_Seed = time(0);
	m_Randomizer.seed(m_Seed);
}

template<class item>
int CRandom<item>::getSeed()
{
	return m_Seed;
}

template<class item>
void CRandom<item>::shuffle(vector<item>& aSet)
{
	std::shuffle(aSet.begin(), aSet.end(), m_Randomizer);
}

template<class item>
int CRandom<item>::determineStartingPosition(int min, int max)
{
	double aRand = rand() / (1.0 + RAND_MAX);
	int range = max - min + 1;
	int randomvalue = (aRand * range) + min;
	return randomvalue;
}
#endif