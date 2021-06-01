#include "CPlayerHP.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "minmax.h"
#include "CPlayer.h"

extern CTexture TexturePlayerHP;//��l��HP
extern CTexture TexturePlayerHPb;//HP�o�b�N

CPlayerHP::CPlayerHP()
:m_Max(10), m_Min(0)
, mPositionX1(0), mPositionX2(0),
  mPositionY1(0), mPositionY2(0)
{
	//�`��^�X�N�ɓo�^
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

// �ő�l�A�ŏ��l�A���ݒl�̃Q�b�^�[
float CPlayerHP::getMax(){ return m_Max; }
float CPlayerHP::getMin(){ return m_Min; }
float CPlayerHP::get(){ return CPlayer::mChara1Hp; }


// �ő�l���Z�b�g���鎞�͍ŏ��l��菬�����Ȃ�Ȃ��悤�ɂ���
// �܂����ݒl���ő�l�𒴂��Ă���Ȃ�A�ő�l�Ɠ����ɂ���
void CPlayerHP::setMax(float value)
{
	m_Max = max(m_Min, value);
	if (m_Max < get()) set(m_Max);
}


// �ŏ��l���Z�b�g���鎞�͍ő�l���傫���Ȃ�Ȃ��悤�ɂ���
// ���ݒl���ŏ��l�����ɂȂ�Ȃ�A�ŏ��l�Ɠ����ɂ���
void CPlayerHP::setMin(float value)
{
	m_Min = min(value, m_Max);
	if (get() < m_Min) set(m_Min);
}


// ���ݒl���Z�b�g���鎞�͍ŏ��l�ȏ�A�ő�l�ȉ��ɂȂ�悤�ɂ���
void CPlayerHP::set(float value)
{
	value = min(value, m_Max);
	value = max(value, m_Min);
	CPlayer::mChara1Hp = value;
}


// ���ݒl��ǉ��A�߂�l�ōŏI�I�Ȓl��Ԃ�
float CPlayerHP::add(float value)
{
	set(get() + value);
	return get();
}


// �ő�l��ǉ�
float CPlayerHP::addMax(float value)
{
	setMax(getMax() + value);
	return getMax();
}


// �ŏ��l��ǉ�
float CPlayerHP::addMin(float value){
	setMin(getMin() + value);
	return getMin();
}


// HP����
bool CPlayerHP::isEmpty(){
	return (get() <= getMin()); // �ŏ��l�ȉ��Ȃ��
}


// HP�����^��
bool CPlayerHP::isFull(){
	return (getMax() <= get()); // �ő�l�ȏ�Ȃ疞�^��
}


// ����
float CPlayerHP::rate(){
	return (get() / getMax()); // ���ݒl / �ő�l
}
CPlayerHP*CPlayerHP::spInstance = 0;