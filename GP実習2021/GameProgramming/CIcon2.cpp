#include "CIcon2.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "CPlayer.h"

extern CTexture Texturech_icon2;//ヒロインアイコン

CIcon2::CIcon2()
{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CIcon2::Render, DrawPriority::Transparent, "CIcon2");
	mTag = EICON2;

	m_Rect1.x = -850;
	m_Rect1.y = 320;
	m_Rect1.w = 100;
	m_Rect1.h = 100;
}

void CIcon2::Render()
{
	//if (CPlayer::mCharaSwitch == true){
	//	m_Rect1.Render(Texturech_icon1, 0, Texturech_icon1.mHeader.width, Texturech_icon1.mHeader.height, 0);
	//}
}
