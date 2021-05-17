#ifndef CSCENERESULT_H
#define CSCENERESULT_H

#include "CScene.h"
#include "CText.h"
#include "CRectangle.h"

class CSceneResult :public CScene{
private:
	char buf[10];
	void Init();
	void Update();
	EScene GetNextScene();
	CRectangle mRect;
	float mFadein;
public:
	CSceneResult();
};


#endif