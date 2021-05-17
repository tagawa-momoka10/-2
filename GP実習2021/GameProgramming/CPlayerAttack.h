#ifndef CPLAYERATTACK_H
#define CPLAYERATTACK_H

#include "CRectangle.h"
#include "CBase.h"
#include "CPlayer.h"

class CPlayerAttack:public CBase
{
public:
	CPlayerAttack();
	int mExistCount;

private:
	void Update();
	void Render();
	DrawTask m_Draw;

};

#endif