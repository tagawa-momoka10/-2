#ifndef CSCENEGAMEBOSS_H
#define CSCENEGAMEBOSS_H
#include "CScene.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGameBoss : public CScene {
public:

	char buf[10];

	float mFadeout;
	float mFadein;

	static int mBossCount;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGameBoss();

};

#endif
