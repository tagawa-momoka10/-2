#ifndef CSCENETUTORIAL_H
#define CSCENETUTORIAL_H

#include "CScene.h"
#include "CText.h"

class CSceneTutorial : public CScene {
public:
	int m_Line;
	CSceneTutorial();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーンの取得
	EScene GetNextScene();
};

#endif
