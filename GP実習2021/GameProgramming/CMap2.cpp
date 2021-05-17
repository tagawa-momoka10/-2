#include"CMap2.h"
#include "SampleProperty.h"

CMap2::CMap2()
{
	// •`‰æƒ^ƒXƒN‚É“o˜^
	m_Draw.RegistDraw(this, (DrawFunc)&CMap2::Render, DrawPriority::Opacity, "SamplePlayer");

	mRect.w = 50;
	mRect.h = 100;
}

void CMap2::Render(){
	m_Rect1.Render(Texture2, 0, 3600, 600, 0);
}

