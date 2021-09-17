#pragma once
#ifndef _CRANDOM
#define _CRANDOM

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

template<class item>
class CRandom
{
	public:
		CRandom(); // constructor
		~CRandom(); // destructor
		void shuffle( std::vector<item>& aSet);
		void setSeed();
		void setSeed(int seed);
		int getSeed();
		int determineStartingPosition(int min, int max);
	private:
		int m_Seed;
		std::default_random_engine m_Randomizer;
};
#include "CRandom.cpp"


#endif