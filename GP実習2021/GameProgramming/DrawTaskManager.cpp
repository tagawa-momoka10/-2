#include "DrawTaskManager.h"

#include <assert.h>

DrawTaskManager* DrawTaskManager::m_Instance;

DrawTaskManager * DrawTaskManager::GetInstance()
{
	if (!m_Instance)
	{
		m_Instance = new DrawTaskManager();
	}
	return m_Instance;
}

void DrawTaskManager::ReleaseInstance()
{
	// �^�X�N���폜����Ă��Ȃ��\��������܂��B(TaskManager�̕��Ń^�X�N���폜����Ƃ��Ɉꏏ�ɊO���Ă���͂�)
	assert(!m_Instance->m_FirstList);

	delete m_Instance;
	m_Instance = nullptr;
}

DrawTaskManager::DrawTaskManager():
	m_FirstList(nullptr)
{
}

DrawTaskManager::~DrawTaskManager()
{
}

void DrawTaskManager::Draw()
{
	// �X�V(�`��)
	DrawTask* currentTask = m_FirstList;
	
	// 
	while (currentTask)
	{
		// �ꎞ��~���Ă��Ȃ��ꍇ�͕`��
		if (!currentTask->m_IsPause)
		{
			currentTask->Draw();
		}

		// ���̃^�X�N
		currentTask = currentTask->m_Next;
	}
}

void DrawTaskManager::AddDrawTask(DrawTask * task)
{
	// �擪�|�C���^��null�̏ꍇ�͐擪�|�C���^�ɐݒ肵�Ēǉ��I��
	if (!m_FirstList)
	{
		m_FirstList = task;
		return;
	}

	// �w��̃O���[�v�ƗD��x�̏ꏊ�ɒǉ�
	DrawTask* currentTask = m_FirstList;
	DrawTask* nextTask = currentTask->m_Next;

	// �O���[�v
	while (currentTask)
	{
		// �D��x�����X�g�̃^�X�N���Ⴂ�ꍇ�͂��̑O�̂Ƃ���Ƀ^�X�N��ǉ�
		if (task->m_Priority < currentTask->m_Priority)
		{
			// �ǉ������^�X�N�̑O���ݒ�
			task->m_Prev = currentTask->m_Prev;
			task->m_Next = currentTask;

			// ���X�g�̃^�X�N���q���ς���
			if (currentTask->m_Prev)
			{
				currentTask->m_Prev->m_Next = task;
			}

			currentTask->m_Prev = task;

			// �擪�ɒǉ����ꂽ�ꍇ�͐擪�|�C���^�ύX
			if (m_FirstList == currentTask)
			{
				m_FirstList = task;
			}

			return;
		}

		// ���̃^�X�N���Ȃ��ꍇ�́A�Ō�ɒǉ�����
		if (!currentTask->m_Next)
		{
			currentTask->m_Next = task;
			task->m_Prev = currentTask;
			return;
		}

		// ���̃^�X�N
		currentTask = currentTask->m_Next;
	}
}

void DrawTaskManager::RemoveTask(DrawTask * removeTask)
{
	DrawTask * prev = removeTask->m_Prev;
	DrawTask * next = removeTask->m_Next;

	// �^�X�N�̃O���[�v�̑O��
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}

	// �擪�|�C���^�����ւ���ꍇ�X�V
	if (removeTask == m_FirstList)
	{
		m_FirstList = removeTask->m_Next;
	}

	// �O�㍶�E�̂Ȃ����������
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;
}

void DrawTaskManager::RemoveTask(Task * removeTask)
{
	DrawTask* currentTask = m_FirstList;

	// �^�X�N����(�����o�^�����邩������Ȃ��̂őS���m�F����)
	while (currentTask)
	{
		DrawTask* nextTask = currentTask->m_Next;

		// �^�X�N�|�C���^����v���Ă���ꍇ�̓��X�g�������
		if (currentTask->m_Task == removeTask)
		{
			RemoveTask(currentTask);
		}

		// ���̃^�X�N
		currentTask = nextTask;
	}
}

void DrawTaskManager::ChangePriority(DrawTask * task)
{
	// �`�惊�X�g����O��
	RemoveTask(task);

	// �`�惊�X�g�ɒǉ�
	AddDrawTask(task);
}
