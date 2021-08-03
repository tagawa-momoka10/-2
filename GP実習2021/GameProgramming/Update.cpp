#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// テクスチャクラスのインクルード
#include "CTexture.h"
CTexture TextureChara1; //主人公画像
CTexture TextureChara1Attack;	//主人公画像2
CTexture Texture2; //マップの画像
CTexture TextureChara2;	//ヒロイン画像
CTexture TextureChara2Attack;	//ヒロイン画像2

CTexture TextureEnemy; //敵画像
CTexture TextureEnemy1; //敵画像1

CTexture TextureMine; //敵
CTexture TextureMine2; //敵


CTexture TexturePlayerHP;//主人公HP
CTexture TexturePlayerHPb;//HPバック

CTexture Texturech_icon1;	//主人公アイコン

CTexture TextureTitleLogo;	//タイトルロゴ
CTexture TextureTitlebg;	//タイトル背景
CTexture TextureGameOver;	//ゲームオーバー画面
CTexture TextureResult;		//リザルト画面

CTexture Textureitem1;//アイテム1
CTexture Textureitem2;//アイテム2
CTexture Textureitem3;//アイテム3
CTexture Textureitem4;//アイテム4


CTexture Texturekihou;//気泡
CTexture TextureBuki;//武器
CTexture Texturewa;//ワカメ

//シーンマネージャのインスタンス
CSceneManager SceneManager;



//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	TextureChara1.Load("resource\\hasiri.tga");
	TextureChara1Attack.Load("resource\\ch102.tga");

	TextureChara2.Load("resource\\ch201.tga");
	TextureChara2Attack.Load("resource\\ch202.tga");

	TextureEnemy.Load("resource\\same.tga");//サメ

	TextureMine.Load("resource\\mine.png");//機雷　
	TextureMine2.Load("resource\\mine2.png");//機雷　爆発

	Texturewa.Load("resource\\wakame.tga"); //ワカメ

	TexturePlayerHP.Load("resource\\HP.jpg");//主人公HP max
	TexturePlayerHPb.Load("resource\\HPg.jpg");//主人公HPバック

	Texturech_icon1.Load("resource\\ch_icon1.tga");//主人公

	TextureTitleLogo.Load("resource\\title logo3.tga");
	TextureTitlebg.Load("resource\\title bg.tga");

	TextureGameOver.Load("resource\\GameOver.tga");
	TextureResult.Load("resource\\result.tga");


	Textureitem1.Load("resource\\akikan.png");
	Textureitem2.Load("resource\\item2.tga");
	Textureitem3.Load("resource\\item3.tga");
	Textureitem4.Load("resource\\item4.tga");

	Texturekihou.Load("resource\\kihou.png");
	TextureBuki.Load("resource\\mori.jpg");

	//シーンマネージャの初期化
	SceneManager.Init();
}
//Update関数
//プログラムの実行中、繰り返し呼ばれる関数
void Update() {

	

	//シーンマネージャの更新
	SceneManager.Update();
}
