#pragma once
#ifndef GAMEAPIBASE
#define GAMEAPIBASE
#include <vector>
#include "CGamePieceBase.h"

class CGameAPIBase
{
	public:
		virtual std::vector<int> DeterminePlayable(CGamePieceBase) = 0;
	private:
		virtual void GenerateSetList() = 0;
};

#endif