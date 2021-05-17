#ifndef CSCENEGAMEOVER_H
#define CSCENEGAMEOVER_H

#include "CScene.h"
#include "CText.h"
#include "CRectangle.h"

class CSceneGameOver :public CScene{
private:
	void Init();
	void Update();
	EScene GetNextScene();
	CRectangle mRect;
	float mFadein;
public:
	CSceneGameOver();
};


#endif