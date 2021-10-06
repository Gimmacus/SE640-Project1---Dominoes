#pragma once
#ifndef TABLEINTERFACE
#define TABLEINTERFACE
#include <vector>
#include "CPlayer.h"
#include "CGamePieceBase.h"
#include "CGameAPIBase.h"

class CTableBase
{
	public:
		virtual int getPlayerCount() = 0;
		virtual int getDeckCount() = 0;
		virtual int getDiscardPileCount() = 0;
		virtual int getFullGameSetCount() = 0;
		virtual std::vector<CGamePieceBase*> getDeck() = 0;
		virtual std::vector<CGamePieceBase*> getDiscardPile() = 0;
		virtual std::vector<CGamePieceBase> getFullGameSet() = 0;

		virtual void setGameAPI(CGameAPIBase*);
		virtual CGameAPIBase* getGameAPI();
		virtual void setFullGameSet() = 0;
		virtual void addToDeck(CGamePieceBase*) = 0;
		virtual CGamePieceBase* drawFromDeck() = 0;
		virtual void addToDiscardPile(CGamePieceBase*) = 0;
		virtual void addPlayerToGame(CPlayer*) = 0;
		virtual void removePlayerFromGame(CPlayer*) = 0;
		virtual void resetGame() = 0;
		virtual void resetRound() = 0;
		virtual void startGame() = 0;
		virtual int determineWinner() = 0;
		virtual int getStartingPlayer(int) = 0;
		virtual void shuffleSet(std::vector<CGamePieceBase*>) = 0;

};

#endif
