#include "CPlayerHP.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "minmax.h"
#include "CPlayer.h"

extern CTexture TexturePlayerHPm;//��l��HP max
extern CTexture TexturePlayerHPh;//���� harf
extern CTexture TexturePlayerHPe;//�J�� empty

CPlayerHP::CPlayerHP()
:m_Max(10), m_Min(0)
, mPositionX1(0), mPositionX2(0), mPositionX3(0), mPositionX4(0), mPositionX5(0)
, mPositionY1(0), mPositionY2(0), mPositionY3(0), mPositionY4(0), mPositionY5(0)
{
	//�`��^�X�N�ɓo�^
	mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	
	m_Rect1.x = -550;
	m_Rect1.y = 300;
	m_Rect1.w = 30;
	m_Rect1.h = 30;

	m_Rect2.x = -480;
	m_Rect2.y = 300;
	m_Rect2.w = 30;
	m_Rect2.h = 30;

	m_Rect3.x = -410;
	m_Rect3.y = 300;
	m_Rect3.w = 30;
	m_Rect3.h = 30;

	m_Rect4.x = -330;
	m_Rect4.y = 300;
	m_Rect4.w = 30;
	m_Rect4.h = 30;

	m_Rect5.x = -260;
	m_Rect5.y = 300;
	m_Rect5.w = 30;
	m_Rect5.h = 30;
	spInstance = this;
}

void CPlayerHP::Update(){
	
}

void CPlayerHP::Render() {
	if (CPlayer::mChara1Hp == 10){
		m_Rect5.Render(TexturePlayerHPm, 0, TexturePlayerHPm.mHeader.width, TexturePlayerHPm.mHeader.height, 0);
	}
	else if (CPlayer::mChara1Hp == 9){
		m_Rect5.Render(TexturePlayerHPh, 0, TexturePlayerHPh.mHeader.width, TexturePlayerHPh.mHeader.height, 0);
	}
	else {
		m_Rect5.Render(TexturePlayerHPe, 0, TexturePlayerHPe.mHeader.width, TexturePlayerHPe.mHeader.height, 0);
	}

	if (CPlayer::mChara1Hp > 7){
		m_Rect4.Render(TexturePlayerHPm, 0, TexturePlayerHPm.mHeader.width, TexturePlayerHPm.mHeader.height, 0);
	}
	else if (CPlayer::mChara1Hp == 7){
		m_Rect4.Render(TexturePlayerHPh, 0, TexturePlayerHPh.mHeader.width, TexturePlayerHPh.mHeader.height, 0);
	}
	else {
		m_Rect4.Render(TexturePlayerHPe, 0, TexturePlayerHPe.mHeader.width, TexturePlayerHPe.mHeader.height, 0);
	}

	if (CPlayer::mChara1Hp > 5){
		m_Rect3.Render(TexturePlayerHPm, 0, TexturePlayerHPm.mHeader.width, TexturePlayerHPm.mHeader.height, 0);
	}
	else if (CPlayer::mChara1Hp == 5){
		m_Rect3.Render(TexturePlayerHPh, 0, TexturePlayerHPh.mHeader.width, TexturePlayerHPh.mHeader.height, 0);
	}
	else {
		m_Rect3.Render(TexturePlayerHPe, 0, TexturePlayerHPe.mHeader.width, TexturePlayerHPe.mHeader.height, 0);
	}

	if (CPlayer::mChara1Hp > 3){
		m_Rect2.Render(TexturePlayerHPm, 0, TexturePlayerHPm.mHeader.width, TexturePlayerHPm.mHeader.height, 0);
	}
	else if (CPlayer::mChara1Hp == 3){
		m_Rect2.Render(TexturePlayerHPh, 0, TexturePlayerHPh.mHeader.width, TexturePlayerHPh.mHeader.height, 0);
	}
	else {
		m_Rect2.Render(TexturePlayerHPe, 0, TexturePlayerHPe.mHeader.width, TexturePlayerHPe.mHeader.height, 0);
	}

	if (CPlayer::mChara1Hp > 1){
		m_Rect1.Render(TexturePlayerHPm, 0, TexturePlayerHPm.mHeader.width, TexturePlayerHPm.mHeader.height, 0);
	}
	else if (CPlayer::mChara1Hp == 1){
		m_Rect1.Render(TexturePlayerHPh, 0, TexturePlayerHPh.mHeader.width, TexturePlayerHPh.mHeader.height, 0);
	}
	else {
		m_Rect1.Render(TexturePlayerHPe, 0, TexturePlayerHPe.mHeader.width, TexturePlayerHPe.mHeader.height, 0);
	}
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