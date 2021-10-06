#include "CDominoesAPI.h"
#include <iostream>

using namespace std;

CDominoesAPI::CDominoesAPI()
{
	GenerateSetList(); 
} // end default constructor

CDominoesAPI::~CDominoesAPI()
{
	//set ptr to NULL, CTable will delete the pieces
	m_HeadPiece = NULL;
	m_TailPiece = NULL;
} // end default deconstructor

int CDominoesAPI::DetermineStartingPiece(vector<CDominoes*> hand)
{
	int largestDouble = -1;
	int largestDoublePosition = -1;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i]->IsDouble())
		{
			if (hand[i]->Head() > largestDouble)
			{
				largestDouble = hand[i]->Head();
				largestDoublePosition = i;
			} // end if
		} // end if
	} // end for

	return largestDoublePosition;
} // end DetermineStartingPiece

vector<CDominoes> CDominoesAPI::getPieceSetList()
{
	return m_SetList;
} // end getPieceSetList

int CDominoesAPI::MaxPlayers()
{
	return m_MaxPlayers;
} // end MaxPlayers

int CDominoesAPI::MinPlayers() 
{
	return m_MinPlayers;
} // end MinPlayers

int CDominoesAPI::StartingHandSize(int playerCount)
{
	return (14 - playerCount * 2);
} // end StartingHandSize

void CDominoesAPI::GenerateSetList()
{
	for (int i = 0; i <= 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			CDominoes tempDomino;
			tempDomino.setHead(i);
			tempDomino.setTail(j);
			tempDomino.setIsDouble(i == j);
			tempDomino.setPlayed(false);
			m_SetList.push_back(tempDomino);
		} // end for
	}// end for
} // end GenerateSetList

void CDominoesAPI::UpdateGameStatus(CDominoes* aDomino, char side)
{
	if (side == '1')
	{
		if (m_HeadPiece->HeadAvailable())
		{
			m_HeadPiece->setHeadAvailable(false);
			if (aDomino->Head() == m_HeadPiece->Head())
			{
				aDomino->setHeadAvailable(false);
				cout << "Head updated to: " << aDomino->Tail() << endl;
			}// end if
			else
			{
				aDomino->setTailAvailable(false);
				cout << "Head updated to: " << aDomino->Head() << endl;
			}// end else
		}// end if
		m_HeadPiece = aDomino;
	}// end if
	else
	{
		if (m_TailPiece->TailAvailable())
		{
			m_TailPiece->setTailAvailable(false);
			if (aDomino->Head() == m_TailPiece->Head())
			{
				aDomino->setHeadAvailable(false);
				cout << "Tail updated to: " << aDomino->Tail() << endl;
			}// end if
			else
			{
				aDomino->setTailAvailable(false);
				cout << "Tail updated to: " << aDomino->Head() << endl;
			}// end else
		}// end if
		m_TailPiece = aDomino;
	}// end else
} // end UpdateGameStatus

void CDominoesAPI::StartingMoveUpdate(CDominoes* aDomino)
{
	m_HeadPiece = aDomino;
	m_TailPiece = aDomino;
}// end StartingMoveUpdate

vector<int> CDominoesAPI::CheckHeadForPlayablePieces(vector<CDominoes*> hand)
{
	vector<int> playablePieceIndexList;
	for (int i = 0; i < hand.size(); i++)
	{
		if (m_HeadPiece->HeadAvailable())
		{
			if (hand[i]->Head() == m_HeadPiece->Head() || hand[i]->Tail() == m_HeadPiece->Head())
			{
				playablePieceIndexList.push_back(i);
			}// end if
		}// end if
		else
		{
			if (hand[i]->Head() == m_HeadPiece->Tail() || hand[i]->Tail() == m_HeadPiece->Tail())
			{
				playablePieceIndexList.push_back(i);
			}// end if
		}// end if
	}// end for
	return playablePieceIndexList;
}// end CheckHeadForPlayablePieces

vector<int> CDominoesAPI::CheckTailForPlayablePieces(vector<CDominoes*> hand)
{
	vector<int> playablePieceIndexList;
	for (int i = 0; i < hand.size(); i++)
	{
		if (m_TailPiece->TailAvailable())
		{
			if (hand[i]->Head() == m_TailPiece->Tail() || hand[i]->Tail() == m_TailPiece->Tail())
			{
				playablePieceIndexList.push_back(i);
			}// end if
		}// end if
		else
		{
			if (hand[i]->Head() == m_TailPiece->Head() || hand[i]->Tail() == m_TailPiece->Head())
			{
				playablePieceIndexList.push_back(i);
			}// end if
		}// end else
	}// end for
	return playablePieceIndexList;
}// end CheckTailForPlayablePieces