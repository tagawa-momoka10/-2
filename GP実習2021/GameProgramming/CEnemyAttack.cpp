#include "CEnemyAttack.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CKey.h"

#define GRAVITY 1				//�d��
#define ENEMY_BULLET_SPEED 10	//�U�R�̒e�̃X�s�[�h
#define BOSS_BULLET_SPEED 1		//�{�X�̒e�̃X�s�[�h
#define JUMPPOWER 25			//�W�����v��
#define ERASELAG 60				//������܂ł̃��O

extern CTexture TextureEnemy1;
extern CTexture TextureEnemy2;
//extern CTexture TextureBoss1;
//extern CTexture TextureBoss2;
//extern CTexture TextureBoss3;

CEnemyAttack::CEnemyAttack()
: mLandingPoint_EA(0)
, mEraseLag(ERASELAG)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemyAttack::Render, DrawPriority::Transparent, "CEnemyAttack");
}

void CEnemyAttack::Update(){

	//////////////////////////////////////////////////////////////////////////

	//�{�X�̋ߋ����U��
	if (mTag == EBOSSATTACK_S){
		mAttackTime--;
		//�U������̏o���I��
		if (mAttackTime <= 0){
			Kill();
		}
	}

	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////



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