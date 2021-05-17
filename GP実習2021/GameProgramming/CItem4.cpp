#include "CItem4.h"

#include "CPlayer.h"
#include "CScore.h"
#include "CRectangle.h"
#include "SampleProperty.h"
#include "TaskManager.h"

extern CTexture Textureitem4;

CItem4::CItem4()

{
	//•`‰æƒ^ƒXƒN‚É“o˜^
	mDraw.RegistDraw(this, (DrawFunc)&CItem4::Render, DrawPriority::Opacity, "CItem4");

	mRect.x = 0;
	mRect.y = 0;
	mRect.w = 30;
	mRect.h = 30;

}

void CItem4::Update(){
	CScore::mScore += 200;

}


void CItem4::Collision(CBase *i, CBase *y){
	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			Kill();
		}
	}
}

void CItem4::Render(){
	if (mTag == EITEM4){
		mRect.Render(Textureitem4, 0, Textureitem4.mHeader.width, Textureitem4.mHeader.height, 0);
	}
}
