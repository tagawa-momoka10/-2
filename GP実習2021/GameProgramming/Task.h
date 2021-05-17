#ifndef	INCLUDE_TASK
#define	INCLUDE_TASK

class Task
{
	friend class TaskManager;

private:
	Task * m_Prev;					// �D�揇�ʂ̑O�̃|�C���^
	Task * m_Next;					// �D�揇�ʂ̌�̃|�C���^

	int m_Priority;					// �D�揇��(�������̂��珈��������)
	bool m_IsPause;					// �|�[�Y
	
	const char * m_Name;			// �^�X�N�̖��O	

public:
	// �R���X�g���N�^ �E �f�X�g���N�^
	Task(int Priority, const char * name);
	Task();
	virtual ~Task();

	// �ʏ�֐�

	// �폜
	void Kill();	

	// �ꎞ��~
	void SetPause(bool isPause);
	// �D��x�擾
	int GetPriority()const;
	// �ꎞ��~���Ă��邩�ǂ���
	bool IsPause()const;
	// �^�X�N�̖��O
	const char* GetName()const;

private:

	// �X�V
	virtual void Update();

};

#endif // INCLUDE_TASK