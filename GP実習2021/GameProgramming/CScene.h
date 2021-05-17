#ifndef CSCENE_H
#define CSCENE_H

/*
シーンの基底クラス
*/
class CScene {
public:
	//シーンの識別子
	enum EScene {
		EGAME,	//ゲーム
		EGAME2,	//ゲーム場面2
		EGAMEBOSS,	//ボスステージ
		ETITLE, //タイトル
		ETUTORIAL, //チュートリアル
		EWEAPONSETTING, //剣設定
		EOPTION, //オプション
		EGAMEOVER,	//ゲームオーバー
		ERESULT,	//リザルト
	};
	//次のシーン
	EScene mScene;
	//virtual 仮想関数
	//ポリモーフィズムの実装
	//=0 純粋仮想関数の設定
	virtual void Init() = 0;	//純粋仮想関数 初期化処理
	virtual void Update() = 0; //純粋仮想関数 更新処理
	//次のシーンの取得
	virtual EScene GetNextScene() = 0;
	virtual ~CScene() {}	//デストラクタの定義
};


#endif
