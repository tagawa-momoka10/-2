#include "CBubble.h"

#include "glut.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"

extern CTexture Texturekihou;//‹C–A

CBubble::CBubble(){
	mDraw.RegistDraw(this, (DrawFunc)&CBubble::Render, DrawPriority::Transparent, "Bubble");
	mRect.x = 600;
	mRect.y = 100;
	mRect.w = 25;
	mRect.h = 25;

}


void CBubble::Update(){
	mTag = EKIHOU;
	mEnabled = true;
	mRect.y += 1;

}


void CBubble::Render(){
	if (mTag == EKIHOU){
		mRect.Render(Texturekihou, 0, Texturekihou.mHeader.width, Texturekihou.mHeader.height, 0);
	}

}

void CBubble::Collision(CBase *i, CBase *y){

	if (y->mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			Kill();
		}
	}
}
