#pragma once
#ifndef TABLEINTERFACE
#define TABLEINTERFACE
#include <vector>

template<class GamePiece>
class CTableInterFace
{
	virtual int getPlayerCount = 0;
	virtual int getDeckCount = 0;
	virtual int getDiscardPileCount = 0;
	virtual int getFullGameSetCount = 0;
	virtual std::vector<GamePiece>* getDeck = 0;
	virtual std::vector<GamePiece>* getDiscardPile = 0;
	virtual std::vector<GamePiece>* getFullGameSet = 0;

	virtual void setFirstPlayer = 0;
	virtual void setFullGameSet = 0;
	virtual void addToDiscardPile = 0;
	virtual void addPlayerToGame = 0;
	virtual void addToDeck = 0;
	virtual void resetGame = 0;
	virtual void runGame = 0;

};

#endif
