#include "CIcon1.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "CPlayer.h"

extern CTexture Texturech_icon1;//主人公アイコン


CIcon1::CIcon1()
{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CIcon1::Render, DrawPriority::Transparent, "CIcon1");
	mTag = EICON1;

	m_Rect1.x = -800;
	m_Rect1.y = 420;
	m_Rect1.w = 100;
	m_Rect1.h = 100;
}

void CIcon1::Render(){
}