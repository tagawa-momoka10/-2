#include "CSmg.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "CEnemy.h"
#include "CPlayer.h"

CSmg*CSmg::spInstance = 0;
extern CTexture TextureSp_MGg;//ÉQÅ[ÉW
extern CTexture TextureSp_MG;//ïKéEãZÉQÅ[ÉWãÛ
extern CTexture TextureSp_MG2;//ïKéEãZÉQÅ[ÉWó≠
extern CTexture TextureSp_MG3;//ïKéEãZÉQÅ[ÉWäÆëS

CSmg::CSmg()
:m_Max(10), m_Min(0)
{
	//ï`âÊÉ^ÉXÉNÇ…ìoò^
	mDraw.RegistDraw(this, (DrawFunc)&CSmg::Render, DrawPriority::Transparent, "CSmg");

	m_Rect1.x = -640;
	m_Rect1.y = 400;
	m_Rect1.w = 15;
	m_Rect1.h = 15;

	m_Rect2.x = -600;
	m_Rect2.y = 400;
	m_Rect2.w = 15;
	m_Rect2.h = 15;

	m_Rect3.x = -560;
	m_Rect3.y = 400;
	m_Rect3.w = 15;
	m_Rect3.h = 15;

	m_Rect4.x = -520;
	m_Rect4.y = 400;
	m_Rect4.w = 15;
	m_Rect4.h = 15;

	m_Rect5.x = -480;
	m_Rect5.y = 400;
	m_Rect5.w = 15;
	m_Rect5.h = 15;

	m_Rect6.x = -440;
	m_Rect6.y = 400;
	m_Rect6.w = 15;
	m_Rect6.h = 15;

	m_Rect7.x = -400;
	m_Rect7.y = 400;
	m_Rect7.w = 15;
	m_Rect7.h = 15;

	m_Rect8.x = -360;
	m_Rect8.y = 400;
	m_Rect8.w = 15;
	m_Rect8.h = 15;

	m_Rect9.x = -320;
	m_Rect9.y = 400;
	m_Rect9.w = 15;
	m_Rect9.h = 15;

	m_Rect10.x = -280;
	m_Rect10.y = 400;
	m_Rect10.w = 15;
	m_Rect10.h = 15;

	m_Rect11.x = -460;
	m_Rect11.y = 400;
	m_Rect11.w = 270;
	m_Rect11.h = 20;

	spInstance = this;
}

void CSmg::Update(){
	
}

void CSmg::Render() {
	
}
	