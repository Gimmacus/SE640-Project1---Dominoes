#pragma once

#ifndef CTABLE
#define CTABLE

#include "CRandom.h"
#include "CDominoes.h"
#include "CDominoesAPI.h"
#include "CPlayer.h"

class CTable
{

	public:

		//Default constructor.
		//@params: none
		//@pre: none
		//@post: initializes m_API, sets the full gameset, and sets default value for playerIndex
		CTable();

		//Default Deconstructor. Deletes all vectors containing pointers.
		//@params: none
		//@pre: none
		//@post: m_Deck, m_PlayedPieces, m_PlayerList all cleared
		~CTable();

		//returns count of players in m_PlayerList
		//@params: none
		//@pre: none
		//@post: returns size of m_PlayerList
		int PlayerCount();

		//returns count of game pieces in m_Deck
		//@params: none
		//@pre: none
		//@post: returns size of m_Deck
		int DeckCount();

		//returns count of game pieces in m_PlayedPieces
		//@params: none
		//@pre: none
		//@post: returns size of m_PlayedPieces
		int PlayedPiecesCount();

		//returns count of game pieces in m_FullGameSet
		//@params: none
		//@pre: none
		//@post: returns size of m_FullGameSet
		int FullGameSetCount();

		//Returns m_Deck
		//@params: none
		//@pre: none
		//@post: returns m_Deck
		std::vector<CDominoes*> Deck();

		//Returns m_PlayedPieces
		//@params: none
		//@pre: none
		//@post: returns m_PlayedPieces
		std::vector<CDominoes*> PlayedPieces();

		//Returns m_FullGameSet
		//@params: none
		//@pre: none
		//@post: Returns m_FullGameSet
		std::vector<CDominoes> FullGameSet();

		//Returns m_API
		//@params: none
		//@pre: m_API is not null
		//@post: Returns m_FullGameSet
		CDominoesAPI* GameAPI();

		//sets m_API
		//@params: CDominoesAPI is pointer to dominoesAPI object
		//@pre: none
		//@post: m_API points to new object
		void setGameAPI(CDominoesAPI*);

		//adds CPlayer object to m_PlayerList
		//@params: CPlayer is point to player object
		//@pre: player is not null
		//@post: m_PlayerList has a player added to it
		void addPlayerToGame(CPlayer*);

		//removes player from m_PlayerList
		//@params: CPlayer points to a player object
		//@pre: CPlayer exists in m_PlayerList
		//@post: m_PlayerList has existing player removed and deleted.
		void removePlayerFromGame(CPlayer*);

		// begins the gameloop
		//@params: none
		//@pre: m_Playerlist is not empty
		//@post: game is finished.
		void PlayGame();

		//Sets game back to default state and sets player scores to 0
		//@params: none
		//@pre: none
		//@post: players in m_Player have their hands and score cleared, m_Deck is cleared, m_PlayedPieces is cleared, m_API resets gamestate
		void resetGame();

		//Sets game back to default state
		//@params: none
		//@pre: none
		//@post: players in m_Player have their hands cleared, m_Deck is cleared, m_PlayedPieces is cleared, m_API resets gamestate
		void resetRound();

		//Shuffles a given vector of game piece objects.
		//@params: param is a reference to a vector of pointers to game piece objects
		//@pre: param is not empty
		//@post: param reference is shuffled.
		void ShuffleSet(std::vector<CDominoes*>&);

	private:
		std::vector<CPlayer*> m_PlayerList;
		std::vector<CDominoes*> m_Deck;
		std::vector<CDominoes*> m_PlayedPieces;
		std::vector<CDominoes> m_FullGameSet;
		std::vector<std::string> m_EventList;

		CDominoesAPI* m_API;
		CRandom<CDominoes*> m_Randomizer;
		int m_PlayerIndex;

		//Deletes and clears list of players
		//@params: none
		//@pre: none
		//@post: frees memory allocated to players in m_PlayerList and clears m_PlayerList
		void clearPlayerList();

		//Deletes and clears list of game pieces in deck
		//@params: none
		//@pre: none
		//@post: frees memory allocated to gamepieces in m_Deck and clears m_Deck
		void clearDeck();

		//Deletes and clears list of game pieces in Played Pieces List
		//@params: none
		//@pre: none
		//@post: frees memory allocated to gamepieces in m_PlayedPieces and clears m_PlayedPieces
		void clearPlayedPieces();

		//Collects full list of game pieces from game API
		//@params: none
		//@pre: m_API is not null
		//@post: m_FullSetList populated
		void setFullGameSet();

		//Adds the object to list of played pieces
		//@params: param is a pointer to a game piece object
		//@pre: none
		//@post: m_PlayedPieces updated
		void addToPlayedPieces(CDominoes*);

		//Performs the core game functions
		//@params: none
		//@pre: Game is setup and starting round performed (if necesarry)
		//@post: Game is played until the end
		void PerformMainGameLoop();

		//Checks to see if someone has won after they finish their turn. Also checks to see if a draw scenario has occured.
		//@params: none
		//@pre: m_PlayerList is not empty
		//@post: returns true if a winner or draw has occured
		bool CheckForWinner();

		//Randomly selects a player index to start the game from.
		//@params: none
		//@pre: m_PlayerList is not empty
		//@post: none
		void GetStartingPlayer();

		//Determines player starting hand based off of the game API.
		//@params: param is a pointer to a player
		//@pre: param is not null
		//@post: param has game pieces add to his hand.
		void getPlayerStartingHand(CPlayer*);

		//Moves the player counter to the next player.
		//@params: none
		//@pre: none
		//@post: m_PlayerIndex is updated
		void IncrementPlayerIndex();

		//Adds gamepiece to the deck.
		//@params: none
		//@pre: none
		//@post: m_Deck updated;
		void addToDeck(CDominoes*);

		//Performs special starting move conditions
		//@params: param is pointer to CDominoes object
		//@pre: param is not null
		//@post: m_PlayedPieces updated.
		void StartingMove(CDominoes*);

		//Creates deck of pointers to game piece from the full set list.
		//@params: none
		//@pre: full set list is not empty
		//@post: m_Deck is populated.
		void createDeck();

		//Returns a game piece from the deck.
		//@params: none
		//@pre: deck is not empty
		//@post: returns the top of m_deck.
		CDominoes* DrawFromDeck();

		//Performs the beginning round that has a different function from other rounds.
		//@params: none
		//@pre: none
		//@post: various elements updated
		void PerformBeginningRound();

		//Displays a recap of events, player scores, and remaining pieces per player.
		//@params: none
		//@pre: none
		//@post: none
		void DisplayEndStatistics();

		//Logs a message to the list of game events.
		//@params: param is a string
		//@pre: none
		//@post: m_EventLog has message added to it
		void LogEvent(string);

		//Acquires input from user to determine if the game should reset and play again.
		//@params: none
		//@pre: none
		//@post: none
		bool PlayAgain();
};

#endif
