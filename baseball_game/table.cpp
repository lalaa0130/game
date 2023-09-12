#include "table.h"


void C_TABLE::init(int nStrike, int nBall1, int nBall2, int nBall3)
{
	m_arResult[nStrike] = E_STRIKE;
	m_arResult[nBall1] = E_BALL;
	m_arResult[nBall2] = E_BALL;
	m_arResult[nBall3] = E_BALL;

}


C_TABLE::E_RESULT C_TABLE::getResult(int nNumber)
{
	return m_arResult[nNumber];
}
