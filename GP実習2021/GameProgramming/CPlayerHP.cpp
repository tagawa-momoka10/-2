#include "CPlayerHP.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "minmax.h"
#include "CPlayer.h"

extern CTexture TexturePlayerHP;//主人公HP
extern CTexture TexturePlayerHPb;//HPバック

CPlayerHP::CPlayerHP()
:m_Max(10), m_Min(0)
, mPositionX1(0), mPositionX2(0),
  mPositionY1(0), mPositionY2(0)
{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	
	m_Rect1.x = 200;
	m_Rect1.y = 50;
	m_Rect1.w = 100;
	m_Rect1.h = 25;

	m_Rect2.x = 200;
	m_Rect2.y = 50;
	m_Rect2.w = 100;
	m_Rect2.h = 25;

	spInstance = this;

}

void CPlayerHP::Update(){
	//mPositionY1 = m_Rect1.y;
	//mPositionX1 = m_Rect1.x;
	//m_Rect1.x = CPlayer::mPlayerPosition ;
	//m_Rect1.y = CPlayer::mPlayerPosition ;

	//mPositionY2 = m_Rect2.y;
	//mPositionX2 = m_Rect2.x;
	//m_Rect2.x = CPlayer::mPlayerPosition ;
	//m_Rect2.y = CPlayer::mPlayerPosition ;

	CPlayer::mMoving = false;
	if (CPlayer::mChara1Hp > 0){
		if (CPlayer::mAttackCount <= 0 ){

			if (CKey::Push('A')) {
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('D')) {
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('W')){
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
			if (CKey::Push('S')){
				CPlayer::mMoving = true;
				if (CPlayer::mCharaSwitch == true){
					CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
					CPlayer::mMoving = true;
				}
			}
		}
		if (CPlayer::mMoving == true){
			mAniMoving++;
		}
		if (CPlayer::mMoving == false){
			CPlayer::mMoving = INITIALIZE;
		}

		if (CKey::Once('J') /*&& mJflag == false*/){
			CPlayer::spInstance->mRect.y = mRect.y + CPlayer::mPlayerPosition;
			CPlayer::spInstance->mRect.x = mRect.x + CPlayer::mPlayerPosition;
			CPlayer::mMoving = true;
		}

}

void CPlayerHP::Render() {
	m_Rect1.Render(TexturePlayerHP, 0, 200, 50, 0);

	m_Rect2.Render(TexturePlayerHP, 0, 200, 50, 0);
	
}

// 最大値、最小値、現在値のゲッター
float CPlayerHP::getMax(){ return m_Max; }
float CPlayerHP::getMin(){ return m_Min; }
float CPlayerHP::get(){ return CPlayer::mChara1Hp; }


// 最大値をセットする時は最小値より小さくならないようにする
// また現在値が最大値を超えているなら、最大値と同じにする
void CPlayerHP::setMax(float value)
{
	m_Max = max(m_Min, value);
	if (m_Max < get()) set(m_Max);
}


// 最小値をセットする時は最大値より大きくならないようにする
// 現在値が最小値未満になるなら、最小値と同じにする
void CPlayerHP::setMin(float value)
{
	m_Min = min(value, m_Max);
	if (get() < m_Min) set(m_Min);
}


// 現在値をセットする時は最小値以上、最大値以下になるようにする
void CPlayerHP::set(float value)
{
	value = min(value, m_Max);
	value = max(value, m_Min);
	CPlayer::mChara1Hp = value;
}


// 現在値を追加、戻り値で最終的な値を返す
float CPlayerHP::add(float value)
{
	set(get() + value);
	return get();
}


// 最大値を追加
float CPlayerHP::addMax(float value)
{
	setMax(getMax() + value);
	return getMax();
}


// 最小値を追加
float CPlayerHP::addMin(float value){
	setMin(getMin() + value);
	return getMin();
}


// HPが空
bool CPlayerHP::isEmpty(){
	return (get() <= getMin()); // 最小値以下なら空
}


// HPが満タン
bool CPlayerHP::isFull(){
	return (getMax() <= get()); // 最大値以上なら満タン
}


// 割合
float CPlayerHP::rate(){
	return (get() / getMax()); // 現在値 / 最大値
}
CPlayerHP*CPlayerHP::spInstance = 0;