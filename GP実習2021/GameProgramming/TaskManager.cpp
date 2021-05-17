#include "TaskManager.h"
#include "DrawTaskManager.h"

// printf_s ���g�p���邽�߃C���N���[�h
#include <iostream>

#include <assert.h>

#define ARRAY_LENGTH(ary) (sizeof(ary) / sizeof(ary[0]))

TaskManager* TaskManager::m_Instance = nullptr;

TaskManager * TaskManager::GetInstance()
{
	// �C���X�^���X���Ȃ��ꍇ�͐���
	if (!m_Instance)	m_Instance = new TaskManager();

	return m_Instance;
}

void TaskManager::ReleaseInstance()
{
	// �S�����폜����
	m_Instance->AllKill();

	// �^�X�N���c���Ă��邩�ǂ����ȈՊm�F

	// �X�V�^�X�N���폜����Ă��Ȃ��\��������܂��B
	assert(!m_Instance->m_ListFirst);
	// �폜�^�X�N���폜����Ă��Ȃ��\��������܂��B
	assert(!m_Instance->m_DeleteListFirst);


	delete m_Instance;
	m_Instance = nullptr;
}

TaskManager::TaskManager():
	m_ListFirst(nullptr),
	m_DeleteListFirst(nullptr)
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::Update()
{
	// �^�X�N�폜(�O��̃t���[���ō폜�\��̂��̂����폜)
	KillTask();

	// �X�V�^�X�N
	Task* currentTask = m_ListFirst;

	// �X�V
	while (currentTask)
	{
		// ���̃^�X�N
		Task* nextTask = currentTask->m_Next;

		// State���ʏ�̏ꍇ�ɍX�V����
		if (!currentTask->m_IsPause)
		{
			currentTask->Update();
		}

		// ���̃^�X�N
		currentTask = nextTask;
	}
}

void TaskManager::AddTask(Task * addTask)
{
	// �擪�^�X�N���Ȃ��ꍇ�͐擪�^�X�N�ɐݒ肵�ďI��
	if (!m_ListFirst)
	{
		m_ListFirst = addTask;
		return;
	}

	Task* currentTask = m_ListFirst;

	// ���X�g�ɒǉ�
	while (currentTask)
	{
		// �ǉ�����^�X�N�̕����D��x���Ⴂ�ꍇ�͌���̈�O�Ƀ^�X�N��ǉ�
		if (addTask->m_Priority < currentTask->m_Priority)
		{
			// �ǉ������^�X�N�̑O���ݒ�
			addTask->m_Prev = currentTask->m_Prev;
			addTask->m_Next = currentTask;

			// ���X�g�̃^�X�N���q���ς���
			if (currentTask->m_Prev)
			{
				currentTask->m_Prev->m_Next = addTask;
			}

			currentTask->m_Prev = addTask;


			// �擪�ɒǉ����ꂽ�ꍇ�͐擪�|�C���^�ύX
			if (m_ListFirst == currentTask)
			{
				m_ListFirst = addTask;
			}

			return;
		}

		// ���̃^�X�N���Ȃ��ꍇ�́A�Ō�ɒǉ�����
		if (!currentTask->m_Next)
		{
			currentTask->m_Next = addTask;
			addTask->m_Prev = currentTask;
			return;
		}

		currentTask = currentTask->m_Next;
	}
}

void TaskManager::AddKill(Task * killTask)
{
	// �X�V���X�g����^�X�N���O��
	RemoveUpdateTaskList(killTask);


	// ��[�|�C���^���Ȃ��ꍇ�͐�[�|�C���^�ɐݒ�
	if (!m_DeleteListFirst)
	{
		m_DeleteListFirst = killTask;
		return;
	}

}

void TaskManager::AddTaskList(Task * firstList, Task * addTask)
{
	Task* currentTask = firstList;

	while (currentTask)
	{
		// ���̃^�X�N�����邩�ǂ����m�F
		if (currentTask->m_Next)
		{
			// ���̃^�X�N
			currentTask = currentTask->m_Next;
		}
		else
		{
			// �����Ƀ^�X�N��ǉ�
			addTask->m_Prev = currentTask;
			addTask->m_Next = nullptr;
			currentTask->m_Next = addTask;
		}
	}
}

void TaskManager::RemoveUpdateTaskList(Task * removeTask)
{
	Task * prev = removeTask->m_Prev;
	Task * next = removeTask->m_Next;


	// �^�X�N�̗D�揇��(�O��)
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}
			
	// �擪�|�C���^���O���ꍇ�͎��̃^�X�N(��������null)��ݒ肷��
	if (removeTask == m_ListFirst)
	{
		m_ListFirst = removeTask->m_Next;
	}

	// �O�㍶�E�̂Ȃ����������
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;

}

void TaskManager::RemoveKillTaskList(Task * removeTask)
{
	Task * prev = removeTask->m_Prev;
	Task * next = removeTask->m_Next;


	// �^�X�N�̗D�揇��(�O��)
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}

	// �擪�|�C���^���O���ꍇ�͎��̃^�X�N(��������null)��ݒ肷��
	if (removeTask == m_DeleteListFirst)
	{
		m_DeleteListFirst = removeTask->m_Next;
	}

	// �O�㍶�E�̂Ȃ����������
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;

}

void TaskManager::KillTask()
{
	// �폜���X�g������ꍇ�̓��X�g���̃^�X�N���폜����
	if (m_DeleteListFirst)
	{
		Task* currentTask = m_DeleteListFirst;

		while (currentTask)
		{
			// ���̃^�X�N�ۑ�
			Task* nextTask = currentTask->m_Next;

			// ���X�g����O��
			RemoveKillTaskList(currentTask);

			// �^�X�N�폜
			delete currentTask;

			// ���̃^�X�N
			currentTask = nextTask;
		}
	}
}

void TaskManager::AllKill()
{
	// �^�X�N���폜
	Task* listfirstGroup[] = {m_DeleteListFirst, m_ListFirst };

	for (int i = 0; i < ARRAY_LENGTH(listfirstGroup); i++)
	{
		Task* currentTask = listfirstGroup[i];

		// ���X�g���܂킷
		while (currentTask)
		{
			// ���̃^�X�N��ێ����Ă���
			Task* nextTask = currentTask->m_Next;

			// ���X�g����O��
			if (i == 0)
			{
				// �폜���X�g
				RemoveKillTaskList(currentTask);
			}
			else
			{
				// �X�V���X�g
				RemoveUpdateTaskList(currentTask);
			}

			// �`�惊�X�g����폜����
			DrawTaskManager::GetInstance()->RemoveTask(currentTask);

			// �^�X�N�폜
			delete currentTask;

			// ���̃^�X�N�ɐi�߂�
			currentTask = nextTask;
		}
	}
}

void TaskManager::Collision()
{
	CBase *ci = (CBase*)m_ListFirst;	// ���݈ʒu���X�V
	while (ci){
		// ���̃^�X�N
		CBase *cy = (CBase*)ci->m_Next;
		while (cy){
			// State���ʏ�̏ꍇ�ɍX�V����
			if (!ci->m_IsPause)
			{
				ci->Collision(ci, cy);
			}
			if (!cy->m_IsPause)
			{
				cy->Collision(cy, ci);
			}
			cy = (CBase*)cy->m_Next;
		}
		// ���̃^�X�N
		ci = (CBase*)ci->m_Next;
	}

}
