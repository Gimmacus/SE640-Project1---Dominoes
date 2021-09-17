#pragma once
#include "CDominoes.h"
#include <vector>
class CDominoesAPI
{
	public:
		CDominoesAPI();
		~CDominoesAPI();
	private:
		std::vector<CDominoes> setList;
};

