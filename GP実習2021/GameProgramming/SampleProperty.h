#ifndef INCLUDE_SAMPLE_PROPERTY
#define INCLUDE_SAMPLE_PROPERTY

// 更新優先度
enum UpdatePriority

{
	Map,			//マップ
	Player,			// プレイヤー
	Camera,			// カメラ
	Enemy,			// 敵
};

// 描画優先度
enum DrawPriority
{
	Opacity ,		// 不透明
	Transparent,	// 半透明
};

#endif // !INCLUDE_PROPERTY
