#include "CEnemyAttack.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CKey.h"

#define GRAVITY 1				//�d��
#define JUMPPOWER 25			//�W�����v��
#define ERASELAG 60				//������܂ł̃��O

extern CTexture TextureEnemy1;
extern CTexture TextureEnemy2;


CEnemyAttack::CEnemyAttack()
: mEraseLag(ERASELAG)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemyAttack::Render, DrawPriority::Transparent, "CEnemyAttack");
}

void CEnemyAttack::Update(){


	//////////////////////////////////////////////////////////////////////////

	//�ߋ����^�̃U�R�G�̍U��
	if (mTag == EENEMYATTACK_F){
		mAttackTime--;
		//�U������̏o���I��
		if (mAttackTime <= 0){
			Kill();
		}
	}

	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
}

void CEnemyAttack::Render(){
	
}

void CEnemyAttack::Collision(CBase *i, CBase *y) {
	//�v���C���[�ƏՓ˂�����
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
			
				return;
			}
		}
	}
	//�v���C���[�̍U�����󂯂���
	if (y->mTag == EPLAYERATTACK){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
				
				return;
			}
		}
	}

}