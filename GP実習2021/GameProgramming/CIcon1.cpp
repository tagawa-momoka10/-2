#include "CIcon1.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "CPlayer.h"

extern CTexture Texturech_icon1;//��l���A�C�R��


CIcon1::CIcon1()
{
	//�`��^�X�N�ɓo�^
	mDraw.RegistDraw(this, (DrawFunc)&CIcon1::Render, DrawPriority::Transparent, "CIcon1");
	mTag = EICON1;

	m_Rect1.x = -800;
	m_Rect1.y = 420;
	m_Rect1.w = 100;
	m_Rect1.h = 100;
}

void CIcon1::Render(){
}