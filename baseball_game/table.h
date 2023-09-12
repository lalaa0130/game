#pragma once

class C_TABLE
{
public:
	enum E_RESULT
	{
		E_OUT = 0,
		E_STRIKE,
		E_BALL,
		E_MAX
	};

private:
	E_RESULT m_arResult[10];

public:
	C_TABLE() = default;
	void init(int nStrike,int nBall1,int nBall2, int nBall3);
	E_RESULT getResult(int nNumber);
};