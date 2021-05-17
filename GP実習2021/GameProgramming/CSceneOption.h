#ifndef CSCENEOPTION_H
#define CSCENEOPTION_H

#include "CScene.h"
#include "CText.h"

class CSceneOption : public CScene {
public:
	int m_Line;

	CSceneOption();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーンの取得
	EScene GetNextScene();
};

#endif
