#include "CTable.h"
#include <iostream>
using namespace std;

CTable::CTable()
{
	m_API = new CDominoesAPI();
	setFullGameSet();
	m_PlayerIndex = 0;
} //end default constructer

CTable::~CTable()
{
	clearDeck();
	clearPlayedPieces();
	clearPlayerList();
	delete m_API;
	m_API = NULL;
} //end deconstructor

int CTable::PlayerCount()
{
	return m_PlayerList.size();
}// end PlayerCount

int CTable::DeckCount()
{
	return m_Deck.size();
}// end DeckCount

int CTable::PlayedPiecesCount()
{
	return m_PlayedPieces.size();
}// end PlayedPiecesCount

int CTable::FullGameSetCount()
{
	return m_FullGameSet.size();
}// end FullGameSetCount

vector<CDominoes*> CTable::Deck()
{
	return m_Deck;
}// end Deck

vector<CDominoes*> CTable::PlayedPieces()
{
	return m_PlayedPieces;
}// end PlayedPieces

vector<CDominoes> CTable::FullGameSet()
{
	return m_FullGameSet;
}// end FullGameSet

CDominoesAPI* CTable::GameAPI()
{
	return m_API;
}// end GameAPI

void CTable::PlayGame()
{
	createDeck();
	ShuffleSet(m_Deck);

	for (m_PlayerIndex = 0; m_PlayerIndex<m_PlayerList.size();m_PlayerIndex++)
	{
		getPlayerStartingHand(m_PlayerList[m_PlayerIndex]);
	} //end for

	GetStartingPlayer();
	PerformBeginningRound();
	PerformMainGameLoop();
	DisplayEndStatistics();
	if (PlayAgain())
	{
		resetRound();
		PlayGame();
	}// end if
}// end StartGame

void CTable::StartingMove(CDominoes* aGamePiece)
{
	cout << "started the round with [" << aGamePiece->Head() << "|" << aGamePiece->Tail() << "]." << endl;
	addToPlayedPieces(aGamePiece);
	m_API->StartingMoveUpdate(aGamePiece);
	string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " started the game with [" + to_string(aGamePiece->Head()) + "|" + to_string(aGamePiece->Tail()) + "].";
	LogEvent(eventMessage);
}// end StartingMove

void CTable::setGameAPI(CDominoesAPI* api)
{
	m_API = api;
}// end setGameAPI

void CTable::setFullGameSet()
{
	m_FullGameSet = m_API->getPieceSetList();
}// end setFullGameSet

void CTable::addToPlayedPieces(CDominoes* aGamePiece)
{
	m_PlayedPieces.push_back(aGamePiece);
}// end addToPlayedPieces

void CTable::addPlayerToGame(CPlayer* newPlayer)
{
	m_PlayerList.push_back(newPlayer);
}// end addPlayerToGame

void CTable::removePlayerFromGame(CPlayer* aPlayer)
{
	m_PlayerList.erase(remove(m_PlayerList.begin(), m_PlayerList.end(), aPlayer), m_PlayerList.end());
	delete aPlayer;
	aPlayer = NULL;
}// end removePlayerFromGame

void CTable::addToDeck(CDominoes* aGamePiece)
{
	m_Deck.push_back(aGamePiece);
}// end addToDeck

void CTable::createDeck()
{
	for (CDominoes piece : m_FullGameSet)
	{
		CDominoes* tempPiece = new CDominoes(piece);
		m_Deck.push_back(tempPiece);
	}// end for
}// end createDeck

void CTable::resetGame()
{
	for (CPlayer* player : m_PlayerList)
	{
		player->clearHand();
		player->setScore(0);
		player->setPassed(false);
	}// end for
	clearDeck();
	clearPlayedPieces();
	m_EventList.clear();
}// end resetGame

void CTable::resetRound()
{
	for (CPlayer* player : m_PlayerList)
	{
		player->clearHand();
		player->setPassed(false);
	}// end for
	clearDeck();
	clearPlayedPieces();
	m_EventList.clear();
}// end resetRound

bool CTable::CheckForWinner()
{
	if (m_PlayerList[m_PlayerIndex]->Hand().size() == 0)
	{
		cout << "Congratulations " << m_PlayerList[m_PlayerIndex]->PlayerName() << ", you've won the round!" << endl;
		string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " won.";
		LogEvent(eventMessage);
		m_PlayerList[m_PlayerIndex]->setScore(1);
		return true;
	}
	else
	{
		bool allPassed = true;
		for (CPlayer* p : m_PlayerList)
		{
			allPassed = allPassed && p->Passed();
		}
		if (allPassed)
		{
			cout << "All players were forced to pass, resulting in a draw." << endl;
			string eventMessage = "A draw has occured.";
			LogEvent(eventMessage);
			return true;
		}
	}
	return false;
}// end CheckForWinner

void CTable::GetStartingPlayer()
{
	m_PlayerIndex = m_Randomizer.determineStartingPosition(1, m_PlayerList.size()) - 1;
	cout << endl << "Starting player: " << m_PlayerList[m_PlayerIndex]->PlayerName() << endl;
}// end GetStartingPlayer

void CTable::ShuffleSet(std::vector<CDominoes*>& aSet)
{
	m_Randomizer.shuffle(aSet);
}// end ShuffleSet

CDominoes* CTable::DrawFromDeck()
{
	CDominoes* tempGamePiece = m_Deck[0];
	m_Deck.erase(m_Deck.begin());
	cout << "Drew [" << tempGamePiece->Head() << "|" << tempGamePiece->Tail() << "]." << endl;
	string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " drew [" + to_string(tempGamePiece->Head()) + "|" + to_string(tempGamePiece->Tail()) + "].";
	LogEvent(eventMessage);
	return tempGamePiece;
}// end DrawFromDeck

void CTable::clearDeck()
{
	for (CDominoes* dominoPiece : m_Deck)
	{
		delete dominoPiece;
		dominoPiece = NULL;
	}// end for
	m_Deck.clear();
}// end  clearDeck

void CTable::clearPlayedPieces()
{
	for (CDominoes* dominoPiece : m_PlayedPieces)
	{
		delete dominoPiece;
		dominoPiece = NULL;
	}// end for
	m_PlayedPieces.clear();
}// end clearPlayedPieces

void CTable::clearPlayerList()
{
	for (CPlayer* player : m_PlayerList)
	{
		delete player;
		player = NULL;
	}// end for
	m_PlayerList.clear();
}// end clearPlayerList

void CTable::IncrementPlayerIndex()
{
	m_PlayerIndex++;

	if (m_PlayerIndex >= m_PlayerList.size())
	{
		m_PlayerIndex = 0;
	}// end if
}// end IncrementPlayerIndex

void CTable::getPlayerStartingHand(CPlayer* player)
{
	for (int i = 1; i <= m_API->StartingHandSize(m_PlayerList.size()); i++)
	{
		cout << player->PlayerName() << " starting hand addition: ";
		player->AddToHand(DrawFromDeck());
	}// end for
}// end getPlayerStartingHand

void CTable::PerformBeginningRound()
{
	while (m_PlayedPieces.empty())
	{
		int startPiecePosition = m_API->DetermineStartingPiece(m_PlayerList[m_PlayerIndex]->Hand());
		if (startPiecePosition == -1)
		{
			cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": player does not have a double to start the round. ";
			if (m_Deck.size() != 0)
			{
				m_PlayerList[m_PlayerIndex]->AddToHand(DrawFromDeck());
			}// end if
			else
			{
				cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": How unfortunate, you drew the whole deck and still no double. Switching players." << endl;
				IncrementPlayerIndex();
			}// end else
		}// end if
		else
		{
			cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": ";
			StartingMove(m_PlayerList[m_PlayerIndex]->Play(startPiecePosition));
		}//end else
	}// end while
}// end PerformBeginningRound

void CTable::PerformMainGameLoop()
{
	do
	{
		IncrementPlayerIndex();
		m_PlayerList[m_PlayerIndex]->setPassed(false);
		vector<int> headPlayablePieceIndexList = m_API->CheckHeadForPlayablePieces(m_PlayerList[m_PlayerIndex]->Hand());
		vector<int> tailPlayablePieceIndexList = m_API->CheckTailForPlayablePieces(m_PlayerList[m_PlayerIndex]->Hand());
		while (headPlayablePieceIndexList.size() == 0 && tailPlayablePieceIndexList.size() == 0)
		{
			cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": Unable to play with current pieces. ";
			if (m_Deck.size() != 0)
			{
				m_PlayerList[m_PlayerIndex]->AddToHand(DrawFromDeck()); 
				headPlayablePieceIndexList = m_API->CheckHeadForPlayablePieces(m_PlayerList[m_PlayerIndex]->Hand());
				tailPlayablePieceIndexList = m_API->CheckTailForPlayablePieces(m_PlayerList[m_PlayerIndex]->Hand());
			}// end if
			else
			{
				cout << m_PlayerList[m_PlayerIndex]->PlayerName() << "The deck is empty. You must pass." << endl;
				m_PlayerList[m_PlayerIndex]->setPassed(true);
				string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " had to pass.";
				LogEvent(eventMessage);
				break;
			}// end else
		}// end while
		if (!m_PlayerList[m_PlayerIndex]->Passed())
		{
			if (tailPlayablePieceIndexList.size() == 0)
			{
				int pieceChoice = 0;
				cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": No pieces can be played on the tail. Which piece would you like to play on the head? " << endl;
				for (int i = 0; i < headPlayablePieceIndexList.size(); i++)
				{
					cout << "\t" << (i + 1) << ". [" << m_PlayerList[m_PlayerIndex]->Hand()[headPlayablePieceIndexList[i]]->Head() << "|" << m_PlayerList[m_PlayerIndex]->Hand()[headPlayablePieceIndexList[i]]->Tail() << "]" << endl;
				}// end for
				cout << "Piece Choice: ";
				cin >> pieceChoice;
				while (pieceChoice < 0 && pieceChoice >= headPlayablePieceIndexList.size())
				{
					cout << "Invalid input.Try again : ";
					cin >> pieceChoice;
				}// end while
				CDominoes* tempChosenPiece = m_PlayerList[m_PlayerIndex]->Play(headPlayablePieceIndexList[pieceChoice - 1]);
				addToPlayedPieces(tempChosenPiece);
				m_API->UpdateGameStatus(tempChosenPiece, '1');
				string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " played [" + to_string(tempChosenPiece->Head()) + "|" + to_string(tempChosenPiece->Tail()) + "] on the head.";
				LogEvent(eventMessage);
			}// end if
			else if (headPlayablePieceIndexList.size() == 0)
			{
				int pieceChoice = 0;
				cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": No pieces can be played on the head. Which piece would you like to play on the tail? " << endl;
				for (int i = 0; i < tailPlayablePieceIndexList.size(); i++)
				{
					cout << "\t" << (i + 1) << ". [" << m_PlayerList[m_PlayerIndex]->Hand()[tailPlayablePieceIndexList[i]]->Head() << "|" << m_PlayerList[m_PlayerIndex]->Hand()[tailPlayablePieceIndexList[i]]->Tail() << "]" << endl;
				}// end for
				cout << "Piece Choice: ";
				cin >> pieceChoice;
				while (pieceChoice < 0 && pieceChoice >= tailPlayablePieceIndexList.size())
				{
					cout << "Invalid input.Try again : ";
					cin >> pieceChoice;
				}// end while
				CDominoes* tempChosenPiece = m_PlayerList[m_PlayerIndex]->Play(tailPlayablePieceIndexList[pieceChoice - 1]);
				addToPlayedPieces(tempChosenPiece);
				m_API->UpdateGameStatus(tempChosenPiece, '2');
				string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " played [" + to_string(tempChosenPiece->Head()) + "|" + to_string(tempChosenPiece->Tail()) + "] on the tail.";
				LogEvent(eventMessage);
			}// end else if
			else
			{
				char endToPlayOn = '0';
				cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": Which end would you like to play on? " << endl;
				cout << "\t 1. Head" << endl;
				cout << "\t 2. Tail" << endl;
				cin >> endToPlayOn;
				while (endToPlayOn != '1' && endToPlayOn != '2')
				{
					cout << "Invalid input. Try again: ";
					cin >> endToPlayOn;
				}// end while
				if (endToPlayOn == '1')
				{
					int pieceChoice = 0;
					cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": Which piece would you like to play on the head? " << endl;
					for (int i = 0; i < headPlayablePieceIndexList.size(); i++)
					{
						cout << "\t" << (i + 1) << ". [" << m_PlayerList[m_PlayerIndex]->Hand()[headPlayablePieceIndexList[i]]->Head() << "|" << m_PlayerList[m_PlayerIndex]->Hand()[headPlayablePieceIndexList[i]]->Tail() << "]" << endl;
					}// end for
					cout << "Piece Choice: ";
					cin >> pieceChoice;
					while (pieceChoice < 0 && pieceChoice >= headPlayablePieceIndexList.size())
					{
						cout << "Invalid input.Try again : ";
						cin >> pieceChoice;
					}// end while
					CDominoes* tempChosenPiece = m_PlayerList[m_PlayerIndex]->Play(headPlayablePieceIndexList[pieceChoice - 1]);
					addToPlayedPieces(tempChosenPiece);
					m_API->UpdateGameStatus(tempChosenPiece, endToPlayOn);
					string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " played [" + to_string(tempChosenPiece->Head()) + "|" + to_string(tempChosenPiece->Tail()) + "] on the head.";
					LogEvent(eventMessage);
				}// end if
				else
				{
					int pieceChoice = 0;
					cout << m_PlayerList[m_PlayerIndex]->PlayerName() << ": Which piece would you like to play on the tail? " << endl;
					for (int i = 0; i < tailPlayablePieceIndexList.size(); i++)
					{
						cout << "\t" << (i + 1) << ". [" << m_PlayerList[m_PlayerIndex]->Hand()[tailPlayablePieceIndexList[i]]->Head() << "|" << m_PlayerList[m_PlayerIndex]->Hand()[tailPlayablePieceIndexList[i]]->Tail() << "]" << endl;
					}// end for
					cout << "Piece Choice: ";
					cin >> pieceChoice;
					while (pieceChoice < 0 && pieceChoice >= tailPlayablePieceIndexList.size())
					{
						cout << "Invalid input.Try again : ";
						cin >> pieceChoice;
					}// end while
					CDominoes* tempChosenPiece = m_PlayerList[m_PlayerIndex]->Play(tailPlayablePieceIndexList[pieceChoice - 1]);
					addToPlayedPieces(tempChosenPiece);
					m_API->UpdateGameStatus(tempChosenPiece, endToPlayOn);
					string eventMessage = m_PlayerList[m_PlayerIndex]->PlayerName() + " played [" + to_string(tempChosenPiece->Head()) + "|" + to_string(tempChosenPiece->Tail()) + "] on the tail.";
					LogEvent(eventMessage);
				}// end else
			}// end else
			
		}// end if
	}// end do
	while (!CheckForWinner());
}// end PerformMainGameLoop

void CTable::DisplayEndStatistics()
{
	cout << endl << "END RESULTS" << endl << endl;
	cout << "\t TURN RECAP" << endl;
	for (int i = 0; i < m_EventList.size(); i++)
	{
		cout << "\t\t" << m_EventList[i] << endl;
	}// end for
	cout << endl;
	for (int i = 0; i < m_PlayerList.size(); i++)
	{
		cout << m_PlayerList[i]->PlayerName() << ":" << endl;
		cout << "\t Total Rounds Won: " << m_PlayerList[i]->Score() << endl;
		cout << "\t Remaining Pieces:" << endl;
		for (CDominoes* p : m_PlayerList[i]->Hand())
		{
			cout << "\t\t [" << p->Head() << "|" << p->Tail() << "]" << endl;
		}// end for
	}// end for
	cout << endl;
}// end DisplayEndStatistics

bool CTable::PlayAgain()
{
	char replayInput = ' ';
	cout << "Would you like to play again? Y/N: ";
	cin >> replayInput;
	while (replayInput != 'Y' && replayInput != 'y' && replayInput != 'N' && replayInput != 'n')
	{
		cout << "Invalid Input. Please try again, Y/N: ";
		cin >> replayInput;
	}// end while
	if (replayInput == 'Y' || replayInput == 'y')
		return true;
	return false;
}// end PlayAgain

void CTable::LogEvent(string EventMessage)
{
	m_EventList.push_back(EventMessage);
}// end LogEvent