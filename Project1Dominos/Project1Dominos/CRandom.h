#pragma once
#ifndef CRANDOM
#define CRANDOM

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

template<class item>
class CRandom
{
	public:

		//Default Constructor. Calls setSeed() and sets m_Randomizer
		//@params: none
		//@pre: none
		//@post: m_Seed and m_Randomizer updated
		CRandom();

		//Default Deconstructor
		//@params: none
		//@pre: none
		//@post: none
		~CRandom();

		//Takes the vector of the templated type and shuffles the contents
		//@params: aSet is a reference to a vector of templated itemTypes
		//@pre: none
		//@post: reference vector has contents shuffled
		void shuffle( std::vector<item>& aSet);

		//sets the seed of the random engine based off of the current time
		//@params: none
		//@pre: none
		//@post: m_Seed and m_Randomizer updated
		void setSeed();

		//sets the seed of the random engine to the specified value
		//@params: seed is int
		//@pre: none
		//@post: m_Seed and m_Randomizer updated
		void setSeed(int seed);

		//returns m_Seed
		//@params: none
		//@pre: none
		//@post: m_Seed is returned
		int Seed();

		//Returns whole number in the range [min,max]
		//@params: min,max are int
		//@pre: max > min
		//@post: none
		int determineStartingPosition(int min, int max);
	private:
		int m_Seed;
		std::default_random_engine m_Randomizer;
};
#include "CRandom.cpp"


#endif