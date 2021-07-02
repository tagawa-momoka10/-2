#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame2 : public CScene {
public:

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGame2();

	static int Time;
	char buf[10];

	static int mCharaHp1store;
	static int mCharaHp2store;
	static int mSpstore;
	static int mCombostore;
	static int mScorestore;
	float mFadeout;	//フェードアウト
	float mFadein;	//フェードイン
};

#endif
