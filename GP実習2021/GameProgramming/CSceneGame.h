#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame : public CScene {
public:

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGame();

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
