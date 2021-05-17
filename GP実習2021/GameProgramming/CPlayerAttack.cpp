#include "CPlayerAttack.h"
#include "SampleProperty.h"
#include "CEnemy.h"
#include "DrawTaskManager.h"
extern CTexture TextureChara1Attack;

CPlayerAttack::CPlayerAttack()
:mExistCount(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CPlayerAttack::Render, DrawPriority::Opacity , "PlayerAttack_S");
	mRect.w = 70;
	mRect.h = 80;
}

void CPlayerAttack::Update()
{
	mExistCount--;
	if (mExistCount <= 0){
		Kill();
	}
	if (mRect.y <= CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}
}
void CPlayerAttack::Render()
{
	if (CBase::mFx >= 0){
		mRect.Render(TextureChara1Attack, 242, 1, 1021, 730);
	}
	else{
		mRect.Render(TextureChara1Attack, 1, 242, 1021, 730);
	}
}