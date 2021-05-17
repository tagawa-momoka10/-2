#ifndef INCLUDE_TASK_MANAGER
#define INCLUDE_TASK_MANAGER

#include "Task.h"
#include "CBase.h"

// �V���O���g��

class TaskManager
{
private:
	static TaskManager* m_Instance;		// �C���X�^���X(���s����1�����C���X�^���X�𐶐������Ȃ�)

	Task* m_ListFirst;					// �X�V���X�g�̐�[�|�C���^

	Task* m_DeleteListFirst;			// �폜���X�g�̐�[�|�C���^

public:
	// �C���X�^���X�擾
	static TaskManager* GetInstance();	
	// �C���X�^���X���
	static void ReleaseInstance();		

	// �^�X�N���S����(��Еt���Ɏg�p����)
	void AllKill();						


	// Task�X�V
	void Update();

	// �^�X�N�����X�g�ɒǉ�
	void AddTask(Task* addTask);

	// �폜���X�g�ɒǉ�
	void AddKill(Task* killTask);

	//�Փ˔���X�V
	void Collision();
	
private:
	TaskManager();
	~TaskManager();

	// �^�X�N�폜
	void KillTask();

	// Task�����X�g����O��
	void RemoveUpdateTaskList(Task* removeTask);
	void RemoveKillTaskList(Task* removeTask);

	// Task�����X�g�ɒǉ�����
	void AddTaskList(Task* firstTask, Task* removeTask);

};

#endif // !INCLUDE_TASK_MANAGER
