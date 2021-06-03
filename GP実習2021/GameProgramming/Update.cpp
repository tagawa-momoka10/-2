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

CTexture TextureEnemy2; //敵画像2

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

CTexture TextureSp_MG;//必殺技ゲージ空
CTexture TextureSp_MG2;//必殺技ゲージ溜
CTexture TextureSp_MG3;//必殺技ゲージ完全
CTexture TextureSp_MGg;//ゲージ

CTexture Texturekihou;//気泡
CTexture TextureBuki;//武器

//シーンマネージャのインスタンス
CSceneManager SceneManager;



//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	TextureChara1.Load("resource\\hasiri.tga");
	TextureChara1Attack.Load("resource\\ch102.tga");

	TextureChara2.Load("resource\\ch201.tga");
	TextureChara2Attack.Load("resource\\ch202.tga");

	TextureEnemy.Load("resource\\same.tga");
	TextureEnemy1.Load("resource\\same s.tga");

	//TextureEnemy2.Load("resource\\em201.tga"); 


	TexturePlayerHP.Load("resource\\HP.tga");//主人公HP max
	TexturePlayerHPb.Load("resource\\HPg.tga");//主人公HPバック



	Texturech_icon1.Load("resource\\ch_icon1.tga");//主人公

	TextureTitleLogo.Load("resource\\title logo3.tga");
	TextureTitlebg.Load("resource\\title bg.tga");

	TextureGameOver.Load("resource\\GameOver.tga");
	TextureResult.Load("resource\\result.tga");


	Textureitem1.Load("resource\\akikan.tga");
	Textureitem2.Load("resource\\item2.tga");
	Textureitem3.Load("resource\\item3.tga");
	Textureitem4.Load("resource\\item4.tga");

	TextureSp_MG.Load("resource\\Sp_MG.tga");
	TextureSp_MG2.Load("resource\\Sp_MG2.tga");
	TextureSp_MG3.Load("resource\\Sp_MG3.tga");
	TextureSp_MGg.Load("resource\\Sp_MGg.tga");

	Texturekihou.Load("resource\\kihou.tga");
	TextureBuki.Load("resource\\mori.tga");

	//シーンマネージャの初期化
	SceneManager.Init();
}
//Update関数
//プログラムの実行中、繰り返し呼ばれる関数
void Update() {

	

	//シーンマネージャの更新
	SceneManager.Update();
}
