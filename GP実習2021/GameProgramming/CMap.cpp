#include"CMap.h"
#include "SampleProperty.h"

CMap::CMap()
{
	// •`‰æƒ^ƒXƒN‚É“o˜^
	m_Draw.RegistDraw(this, (DrawFunc)&CMap::Render, DrawPriority::Opacity, "SamplePlayer");
}

void CMap::Render(){
	//m_Rect1.Render(TextureBos_background, 0, TextureBos_background.mHeader.width, TextureBos_background.mHeader.height, 0);
	
}
