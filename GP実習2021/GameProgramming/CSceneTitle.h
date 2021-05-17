#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"
#include"CRectangle.h"

class CSceneTitle : public CScene, CRectangle{
public:
	//何段目か
	int m_Line;
	int m_Score;
	bool mGame;
	float mFadeout;
	char buf[10];

	CRectangle mRect;
	DrawTask mDraw;

	CSceneTitle();

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーンの取得
	EScene GetNextScene();

};

#endif
