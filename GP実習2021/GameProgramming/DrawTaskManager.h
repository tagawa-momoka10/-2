#ifndef INCLUDE_TASK_DRAW_MANAGER
#define INCLUDE_TASK_DRAW_MANAGER

#include "DrawTask.h"

class DrawTaskManager
{
private:
	static DrawTaskManager* m_Instance;		// �C���X�^���X

	DrawTask* m_FirstList;					// �`�惊�X�g�̐�[�|�C���^

public:
	// �C���X�^���X�擾
	static DrawTaskManager* GetInstance();	
	// �C���X�^���X���
	static void ReleaseInstance();			

	// �`��
	void Draw();				
	// �ǉ�
	void AddDrawTask(DrawTask* task);
	// �o�^����
	void RemoveTask(DrawTask* removeTask);
	// �o�^����(Task���猟��)
	void RemoveTask(Task* removeTask);

	// �D��x�ύX
	void ChangePriority(DrawTask* task);

private:
	DrawTaskManager();
	~DrawTaskManager();


};
#endif // !INCLUDE_TASK_DRAW_MANAGER
