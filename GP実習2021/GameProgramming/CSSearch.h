#ifndef CSSEARCH_H
#define CSSEARCH_H

#include "CBase.h"

class CSSearch : public CBase
{
private:
	bool mAttack;			//�U���t���O
	int mAttackLag;			//�U���t���O����������̍U���J�n�܂ł̃��O

	bool mMoving;			//�ړ���Ԃ��ǂ����Ԃ��t���O

	int mAniAttack;			//�U���A�j���[�V�����p
	int mAniMoving;			//�ړ��A�j���[�V�����p
	void Update();
	void Render();
	DrawTask m_Draw; //�`��^�X�N
	void Collision(CBase *i, CBase *y); //�Փ˔���
public:
	CSSearch();
	static CSSearch*spInstance;	//�G�̍��W���擾
};

#endif