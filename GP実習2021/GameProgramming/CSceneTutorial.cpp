#include "CSceneTutorial.h"
#include "CKey.h"

CSceneTutorial::CSceneTutorial()
:m_Line(1)
{

}

void CSceneTutorial::Init() {
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	CText::mFont.Load("resource\\font.tga");
	//�V�[���̐ݒ�
	mScene = ETUTORIAL;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneTutorial::Update() {
	//������̕`��
	CText::DrawString("Tutorial", -205, 200, 30, 30);
	CText::DrawString("Push ENTER Key", -200, 100, 16, 16);
	CText::DrawString("Back", -200, -400, 20, 20);

	CText::DrawString("1", -200, -100, 20, 20);
	CText::DrawString("2", -200, -200, 20, 20);
	CText::DrawString("3", -200, -300, 20, 20);

	//�J�[�\��
	if (m_Line == 1){
		CText::DrawString(">",
			-250, -100, 16, 16);
	}
	else if (m_Line == 2){
		CText::DrawString(">",
			-250, -200, 16, 16);

	}
	else if (m_Line == 3){
		CText::DrawString(">",
			-250, -300, 16, 16);

	}
	else if (m_Line == 4){
		CText::DrawString(">",
			-250, -400, 16, 16);

	}

	//������������
	if (CKey::Once(VK_DOWN)){
		if (m_Line == 1){
			m_Line = 2;
		}

		else if (m_Line == 2){
			m_Line = 3;
		}

		else if (m_Line == 3){
			m_Line = 4;
		}

		else if (m_Line == 4){
			m_Line = 1;
		}
	}
	//������������
	if (CKey::Once(VK_UP)){
		if (m_Line == 4){
			m_Line = 3;
		}

		else if (m_Line == 3){
			m_Line = 2;
		}

		else if (m_Line == 2){
			m_Line = 1;
		}

		else if (m_Line == 1){
			m_Line = 4;
		}
	}

	if (CKey::Push(VK_RETURN)) {
		if (m_Line == 4){
			//���̃V�[���̓^�C�g��
			mScene = ETITLE;
		}
	}
}
//���̃V�[���̎擾
CScene::EScene CSceneTutorial::GetNextScene() {
	return mScene;
}
