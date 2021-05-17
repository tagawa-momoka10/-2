#include "CCircle.h"
#define G -1
#define VJ0 30
extern CTexture Texture;

CCircle::CCircle()
:Task(UpdatePriority::Player,"Circle")
,mFx(1)
, mVj(0)
{
	//•`‰æƒ^ƒXƒN‚É“o˜^
	mDraw.RegistDraw(this, (DrawFunc)&CCircle::Draw, DrawPriority::Transparent , "Circle");
}

void CCircle::Update()
{
	mRect.x += mFx;
	mVj += G;
	mRect.y += mVj;
	if (mRect.y - mRect.h < -300) {
		mRect.y = -300 + mRect.h;
		mVj = VJ0;
	}
	if (mRect.x>400){
		Kill();
	}
}
void CCircle::Draw()
{
//	if (mEnabled){
		mRect.Render(Texture,56,216,221,60);
//	}
}