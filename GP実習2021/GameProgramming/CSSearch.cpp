#include "CSSearch.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"
#include "CEnemy.h"

#define ANIATTACK 20		//�U���A�j���[�V�����p
#define ANICNT 40		//�A�j���[�V����
#define ATTACKRANGE 20	//�U���˒�
#define POSITION 100		//�v���C���[�ʒu

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture TextureEnemy1;
CSSearch*CSSearch::spInstance = 0;


CSSearch::CSSearch()
: mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CSSearch::Render, DrawPriority::Transparent, "CSSearch");
	mRect1.x = 300;
	mRect1.y = 200;
	mRect1.w = 150;
	mRect1.h = 100;

	mTag = EENEMMY_SS;
	spInstance = this;
	//mCSPosition = POSITION;
}

void CSSearch::Update() {

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (m_Attack == false){
		mMoving = true;
		mAniMoving++;
	}



	if (mMoving = true){
		CEnemy::spInstance->mRect1.x = mRect.x + CEnemy::mEnemyPosition;
		mMoving = true;

	}

	if (mMoving = true){
		CEnemy::spInstance->mRect1.x = mRect.x + CEnemy::mEnemyPosition;
		mMoving = true;

	}

	if (mMoving = true){
		CEnemy::spInstance->mRect1.y = mRect.y + CEnemy::mEnemyPosition;
		mMoving = true;

	}


	if (mMoving = true){
		CEnemy::spInstance->mRect1.y = mRect.y + CEnemy::mEnemyPosition;
		mMoving = true;

	}
}


void CSSearch::Render() {
	//������
	if (mRect1.x > CEnemy::spInstance->mRect1.x){


		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//�ړ����Ă���Ƃ�
		else{
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}

		//���G�t���O�������Ă��Ȃ��Ƃ�

		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//�ړ����Ă���Ƃ�
		else{
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
	}

	

	//�E����
	else{
		//���G�t���O�������Ă��Ȃ��Ƃ�
		//�ړ����Ă��Ȃ��Ƃ�
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			//�U���A�j���[�V����
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack >= -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//�ړ����Ă���Ƃ�
		else{
			//�ړ��A�j���[�V����
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
	}

	//���G��ԃt���O�������Ă���Ƃ�

	//�ړ����Ă��Ȃ��Ƃ�
	if (mMoving == false){
		if (mAniAttack == -10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		//�U���A�j���[�V����
		else if (mAniAttack > 10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniAttack > 0){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniAttack >= -10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
	}
	//�ړ����Ă���Ƃ�
	else{
		//�ړ��A�j���[�V����
		if (mAniMoving % 60 < 30){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniMoving % 60 < 60){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}

	}

}


void CSSearch::Collision(CBase *i, CBase *y) {
	//�v���C���[1�Ɠ��������Ƃ�
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect1.Collision(y->mRect1)){
				if (m_Attack == true && mAttackLag == 0){
					mEnabled = false;
					//CEnemy::mAttack = true;
				}
			}
		}
	}

}