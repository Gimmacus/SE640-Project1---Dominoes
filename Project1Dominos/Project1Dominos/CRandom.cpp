#ifndef CRANDOM_CPP
#define CRANDOM_CPP

#include "CRandom.h"

using namespace std;

template<class item>
CRandom<item>::CRandom()
{
	m_Randomizer = std::default_random_engine{};
	setSeed();
}// end default constructor

template<class item>
CRandom<item>::~CRandom()
{
}// end default deconstructor

template<class item>
void CRandom<item>::setSeed(int seed)
{
	m_Seed = seed;
	m_Randomizer.seed(m_Seed);
}// end setSeed(int)

template<class item>
void CRandom<item>::setSeed()
{
	m_Seed = time(0);
	m_Randomizer.seed(m_Seed);
}// end setSeed()

template<class item>
int CRandom<item>::Seed()
{
	return m_Seed;
}// end Seed

template<class item>
void CRandom<item>::shuffle(vector<item>& aSet)
{
	std::shuffle(aSet.begin(), aSet.end(), m_Randomizer);
}// end shuffle

template<class item>
int CRandom<item>::determineStartingPosition(int min, int max)
{
	double aRand = rand() / (1.0 + RAND_MAX);
	int range = max - min + 1;
	int randomvalue = (aRand * range) + min;
	return randomvalue;
}// end determineStartingPosition
#endif