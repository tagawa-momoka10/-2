#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

class CPlayer : public CBase {
private:
	float mj;		//�W�����v�p�ϐ�
	int mJump;		//�W�����v�ʒu�L��
	int mDash;		//�_�b�V���ʒu�L��
	int mAniCnt;	//�A�j���[�V�����J�E���g
	bool mJflag;	//�W�����v�t���O(false�Ȃ�\,true�Ȃ�s��)
	bool mDflag;	//�_�b�V���t���O(false�Ȃ�\,true�Ȃ�s��)
	void Update();
	void Render();
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);		//�Փ˔���
	int mInvincibleTime;		//���G����

	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�
	int mAniDash;	//�_�b�V���A�j���[�V�����p�̕ϐ�
	int mAniJump;	//�W�����v�A�j���[�V�����p�̕ϐ�
	int mChara1Die;	//�L�����N�^�[���S���A�j���[�V����
	bool mChara1Dieflg;	//�L�����N�^�[���S����t���O
public:
	CPlayer();
	static bool mCharaSwitch;		//���[�h�`�F���W����
	static CPlayer*spInstance;		//�v���C���[���݈ʒu�擾�C���X�^���X
	static bool mAttackFlag;		//�U������t���O
	static bool mHpSwitch;			//HP��UI�؂�ւ��t���O
	static int mAttackCount;		//�U������
	static int mDashCount;			//�_�b�V������
	static int mPlayerPosition;		//�v���C���[�ʒu
	static int mHp;	//��l��HP
	static bool mMoving;	//true(���s��)	false(�Î~���)
	static bool CPlayer::mJumping;	//�v���C���[�W�����v���t���O

};

#endif
