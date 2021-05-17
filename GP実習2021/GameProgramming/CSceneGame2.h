#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame2 : public CScene {
public:

	char buf[10];

	float mFadeout;
	float mFadein;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGame2();

};

#endif
