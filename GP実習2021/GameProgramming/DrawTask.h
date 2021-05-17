#ifndef INCLUDE_DRAW_TASK
#define	INCLUDE_DRAW_TASK

#include "Task.h"

typedef void(Task::*DrawFunc)();

class DrawTask
{
	friend class DrawTaskManager;

public:
	DrawTask();
	~DrawTask();

private:
	
	DrawTask* m_Prev;			// �D�揇�ʂ̑O�̃|�C���^
	DrawTask* m_Next;			// �D�揇�ʂ̌�̃|�C���^

	int m_Priority;				// �D�揇��
	const char* m_Name;			// �f�o�b�O�p���O

	Task* m_Task;				// �^�X�N�|�C���^
	DrawFunc m_Func;			// �֐��|�C���^

	bool m_IsPause;				// �ꎞ��~�t���O

public: 
	// �`��֐��o�^
	void RegistDraw(Task* task, DrawFunc func, int priority,  const char * name);
	// �o�^����
	void Remove();
	// �D�揇�ʕύX
	void ChangePriority(int priority);

	// �ꎞ��~
	void SetPause(bool isPause);
	// �o�^����Ă��邩�ǂ���
	bool IsRegist()const;
	// �D��x�擾
	int GetPriority()const;
	// �ꎞ��~���Ă��邩�ǂ���
	bool IsPause()const;
	// �`��^�X�N�̖��O
	const char* GetName()const;

private:
	// �`��(�֐��|�C���^�Ăяo��)
	void Draw();
	
};




#endif // !INCLUDE_DRAW_TASK


