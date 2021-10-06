#pragma once

#ifndef CDOMINOESAPI
#define CDOMINOESAPI

#include "CDominoes.h"
#include <vector>
class CDominoesAPI
{
	public:

		//Default constructor. Generates set list and initializes member values.
		//@params: none
		//@pre: none
		//@post: calls GenerateSetList and sets m_Tail and m_Head to default values
		CDominoesAPI();

		//Default deconstructor
		//@params: none
		//@pre: none
		//@post: none
		~CDominoesAPI();

		//Determines the starting piece from a vector of game pieces and returns its position or -1 if no suitable pieces.
		//@params: param is an vector of pointers to CDominoes objects
		//@pre: pointers point to initalized objects
		//@post: returns starting piece index or -1 if no pieces found.
		int DetermineStartingPiece(std::vector<CDominoes*>);

		//Returns the max player count value
		//@params: none
		//@pre: none
		//@post: returns m_maxPlayers
		int MaxPlayers();

		//Returns the min player count value
		//@params: none
		//@pre: none
		//@post: returns m_MinPlayers
		int MinPlayers();

		//Returns the starting hand size based on player count
		//@params: param is int
		//@pre: param >=min players and <= max players
		//@post: returns starting hand size
		int StartingHandSize(int);

		//Returns the complete list of dominoes game pieces
		//@params: none
		//@pre: m_setList is generated
		//@post: returns m_setList
		std::vector<CDominoes> getPieceSetList();

		//Updates the game state by updating the head or the tail
		//@params: pointer to CDominoes object, int
		//@pre: Dominoe object is not null
		//@post: m_Head, m_Tail availability updated. m_Head,m_Tail pointers updated.
		void UpdateGameStatus(CDominoes*, char);

		//Performs the starting move of the game
		//@params: param is a pointer to a CDominoes object
		//@pre: param is not null, param is a double
		//@post: Head and Tail are updated
		void StartingMoveUpdate(CDominoes*);

		//Returns the indexes of pieces that can be played off of the tail end of the domino train.
		//@params: param is a vector of pointers to CDominoes objects
		//@pre: none
		//@post: none
		std::vector<int> CheckHeadForPlayablePieces(std::vector<CDominoes*>);

		//Returns the indexes of pieces that can be played off of the tail end of the domino train.
		//@params: param is a vector of pointers to CDominoes objects
		//@pre: none
		//@post: none
		std::vector<int> CheckTailForPlayablePieces(std::vector<CDominoes*>);

	private:

		//Creates the set of game pieces for a Dominoes game
		//@params: none
		//@pre: none
		//@post: m_SetList is populated
		void GenerateSetList();

		std::vector<CDominoes> m_SetList;
		const int m_MinPlayers = 2;
		const int m_MaxPlayers = 4;
		CDominoes* m_TailPiece;
		CDominoes* m_HeadPiece;

};

#endif

