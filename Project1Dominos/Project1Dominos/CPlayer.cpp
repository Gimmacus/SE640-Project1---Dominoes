#include "CPlayer.h"
using namespace std;

CPlayer::CPlayer()
{
	m_Passed = false;
	m_PlayerName = "";
	m_PlayerNumber = 0;
	m_Score = 0;
}// end default constructor

CPlayer::~CPlayer()
{
	clearHand();
}// end default deconstructor

void CPlayer::AddToHand(CDominoes* piece)
{
	m_Hand.push_back(piece);
}// end AddToHand

vector<CDominoes*> CPlayer::Hand()
{
	return m_Hand;
}// end Hand

void CPlayer::clearHand()
{
	for (CDominoes* dominoPiece : m_Hand)
	{
		delete dominoPiece;
		dominoPiece = NULL;
	}// end for
	m_Hand.clear();
}// end clearHand

CDominoes* CPlayer::Play(int handIndex)
{
	CDominoes* temp = m_Hand.at(handIndex);
	m_Hand.erase(m_Hand.begin() + handIndex);
	temp->setPlayed(true);
	return temp;
}// end Play

void CPlayer::SetPlayerName(string name)
{
	m_PlayerName = name;
}// end SetPlayerName

string CPlayer::PlayerName()
{
	return m_PlayerName;
}// end PlayerName

void CPlayer::setPlayerNumber(int playerNumber)
{
	m_PlayerNumber = playerNumber;
}// end setPlayerNumber

int CPlayer::PlayerNumber()
{
	return m_PlayerNumber;
}// end PlayerNumber

void CPlayer::setScore(int points)
{
	m_Score += points;
}// end setScore

int CPlayer::Score()
{
	return m_Score;
}// end Score

void CPlayer::setPassed(bool passed)
{
	m_Passed = passed;
} // end setPassed

bool CPlayer::Passed()
{
	return m_Passed;
} // end Passed

void CPlayer::ResetScore()
{
	m_Score = 0;
}// end ResetScore