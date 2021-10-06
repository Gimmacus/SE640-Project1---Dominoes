#pragma once
#ifndef CDOMINOES
#define CDOMINOES
class CDominoes
{
	public:

		//Default Constructor. Sets default values.
		//@params: none
		//@pre: none
		//@post: m_IsDouble, m_Played, m_Head, m_Tail, m_...Available set to defaults
		CDominoes();

		//Default Deconstructor.
		//@params: none
		//@pre: none
		//@post: none
		~CDominoes();

		//Updates the Head value of the domino piece
		//@params: param is int
		//@pre: param is between 0 and 6.
		//@post: m_Head updated
		void setHead(int);

		//Updates the tail value of the domino piece
		//@params: param is int
		//@pre: param is between 0 and 6.
		//@post: m_Tail updated
		void setTail(int);

		//Sets the head availability of the domino piece
		//@params: param is bool
		//@pre: none
		//@post: m_HeadAvailable updated
		void setHeadAvailable(bool);

		//Sets the tail availability of the domino piece
		//@params: param is bool
		//@pre: none
		//@post: m_TailAvailable updated
		void setTailAvailable(bool);

		//Sets m_IsDouble to the specified value
		//@params: param is bool
		//@pre: none
		//@post: m_IsDouble updated
		void setIsDouble(bool);

		//Sets m_Played to the specified value
		//@params: param is nool
		//@pre: none
		//@post: m_Played is updated
		void setPlayed(bool);

		// Returns the head value of the game piece
		//@params: none
		//@pre: none 
		//@post: m_Head is returned
		int Head();

		// Returns the head value of the game piece
		//@params: none
		//@pre: none 
		//@post: m_Head is returned
		int Tail();

		// Returns the availability of playing off of the head side of the piece
		//@params: none
		//@pre: none 
		//@post: m_HeadAvailable is returned
		bool HeadAvailable();

		// Returns the availability of playing off of the tail side of the piece
		//@params: none
		//@pre: none 
		//@post: m_TailAvailable is returned
		bool TailAvailable();

		// Returns the state of being a double or not
		//@params: none
		//@pre: none 
		//@post: m_IsDouble is returned
		bool IsDouble();

		// Returns the state of being played or not
		//@params: none
		//@pre: none 
		//@post: m_Played is returned
		bool Played();

	private:
		int m_Head;
		int m_Tail;
		bool m_IsDouble;
		bool m_Played;
		bool m_HeadAvailable;
		bool m_TailAvailable;
};

#endif

