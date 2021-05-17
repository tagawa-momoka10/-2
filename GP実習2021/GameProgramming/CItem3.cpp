#include "CItem3.h"

#include "CPlayer.h"
#include "CScore.h"
#include "CRectangle.h"
#include "SampleProperty.h"
#include "TaskManager.h"

extern CTexture Textureitem3;

CItem3::CItem3()

{
	//•`‰æƒ^ƒXƒN‚É“o˜^
	mDraw.RegistDraw(this, (DrawFunc)&CItem3::Render, DrawPriority::Opacity, "CItem3");

	mRect.x = 0;
	mRect.y = 0;
	mRect.w = 30;
	mRect.h = 30;

}

void CItem3::Update(){
	CScore::mScore += 100;

}


void CItem3::Collision(CBase *i, CBase *y){
	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			Kill();
		}
	}
}

void CItem3::Render(){
	if (mTag == EITEM3){
		mRect.Render(Textureitem3, 0, Textureitem3.mHeader.width, Textureitem3.mHeader.height, 0);
	}
}
