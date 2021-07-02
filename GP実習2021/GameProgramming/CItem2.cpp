#include "CItem2.h"

#include "CPlayer.h"
#include "CScore.h"
#include "CRectangle.h"
#include "SampleProperty.h"
#include "TaskManager.h"

extern CTexture Textureitem2;

CItem2::CItem2()

{
	//•`‰æƒ^ƒXƒN‚É“o˜^
	mDraw.RegistDraw(this, (DrawFunc)&CItem2::Render, DrawPriority::Opacity, "CItem2");

	mRect.x = 80;
	mRect.y = 10;
	mRect.w = 40;
	mRect.h = 5;

}

void CItem2::Update(){
	CScore::mScore += 50;

}


void CItem2::Collision(CBase *i, CBase *y){
	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			Kill();
		}
	}
}

void CItem2::Render(){

	if (mTag == EITEM2){
		mRect.Render(Textureitem2, 0, Textureitem2.mHeader.width, Textureitem2.mHeader.height, 0);
	}
}
