#include "CDominoes.h"

CDominoes::CDominoes()
{
	m_IsDouble = false;
	m_Played = false;
	m_Head = -1;
	m_Tail = -1;
	m_HeadAvailable = true;
	m_TailAvailable = true;
}// end default constructor

CDominoes::~CDominoes()
{
}// end default deconstructor

void CDominoes::setHead(int value)
{
	m_Head = value;
}// end setHead

void CDominoes::setTail(int value)
{
	m_Tail = value;
}// end setTail

void CDominoes::setIsDouble(bool isdouble)
{
	m_IsDouble = isdouble;
}// end setIsDouble

void CDominoes::setPlayed(bool played)
{
	m_Played = played;
}// end setPlayed

int CDominoes::Head()
{
	return m_Head;
}// end Head

int CDominoes::Tail()
{
	return m_Tail;
}// end Tail

bool CDominoes::IsDouble()
{
	return m_IsDouble;
}// end IsDouble

bool CDominoes::Played()
{
	return m_Played;
}// end Played

void CDominoes::setHeadAvailable(bool available)
{
	m_HeadAvailable = available;
}// end setHeadAvailable

void CDominoes::setTailAvailable(bool available)
{
	m_TailAvailable = available;
}// end setTailAvailable

bool CDominoes::HeadAvailable()
{
	return m_HeadAvailable;
}// end HeadAvailable

bool CDominoes::TailAvailable()
{
	return m_TailAvailable;
}// end TailAvailable