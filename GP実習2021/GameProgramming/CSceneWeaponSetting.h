#ifndef CSCENEWEAPONETTING_H
#define CSCENEWEAPONETTING_H

#include "CScene.h"
#include "CText.h"

class CSceneWeaponSetting : public CScene {
public:
	int m_Line;
	int m_Score;
	CSceneWeaponSetting();

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーンの取得
	EScene GetNextScene();
};

#endif
