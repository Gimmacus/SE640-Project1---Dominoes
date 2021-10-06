#pragma once

#include <vector>
#include "CDominoes.h"
#include <string>

#ifndef CPLAYER
#define CPLAYER

class CPlayer
{
	public:

		//Default constructor. Initializes default values
		//@params: none
		//@pre: none
		//@post: m_Score, m_PlayerNumber, m_Passed, m_PlayerName set to default values
		CPlayer();

		//Default deconstructor. calls clearHand
		//@params: none
		//@pre: none
		//@post: m_Hand has each element deleted and is then cleared
		~CPlayer();

		//Adds a game piece to player hand
		//@params: none
		//@pre: param is initialized
		//@post: m_Hand has a game piece added to it
		void AddToHand(CDominoes*);

		//returns player hand
		//@params: none
		//@pre: none
		//@post: m_Hand is returned
		std::vector<CDominoes*> Hand();

		//deletes every gamepiece in the player hand and then clears the hand
		//@params: none
		//@pre: none
		//@post: m_Hand is empty
		void clearHand();

		//Returns the gamepiece at the specified index and removes it from the hand
		//@params: int is the index of m_Hand to return
		//@pre: param is >=0 and < m_Hand size
		//@post: m_Hand has game piece removed at param value.
		CDominoes* Play(int);

		//Set the player name
		//@params: string is the name of the given player
		//@pre: none
		//@post: none
		void SetPlayerName(std::string);

		// returns the player's name
		//@params: none
		//@pre: none
		//@post: returns m_playername
		std::string PlayerName();

		//sets the player number
		//@params: int is the player's number
		//@pre: none
		//@post: m_PlayerNumberUpdated
		void setPlayerNumber(int);

		//returns the player number
		//@params: none
		//@pre: none
		//@post: returns m_PlayerNumber
		int PlayerNumber();

		//updates the value of m_Score by adding to the existing score
		//@params: int is the numberical value of score
		//@pre: param is > 0
		//@post: m_Score is increased by the given amount
		void setScore(int);

		//updates the value of m_Score to 0
		//@params: none
		//@pre: none
		//@post: m_Score is set to 0
		void ResetScore();

		//returns the value of m_Score
		//@params: none
		//@pre: none
		//@post: none
		int Score();

		// updates the passed status of the player.
		//@params: bool indicates true for passed, false otherwise
		//@pre: none
		//@post: none
		void setPassed(bool);

		//Returns m_Passed value
		//@params: none
		//@pre: none
		//@post: none
		bool Passed();
	private:
		std::vector<CDominoes*> m_Hand;
		std::string m_PlayerName;
		int m_PlayerNumber;
		bool m_Passed;
		int m_Score;

};

#endif
