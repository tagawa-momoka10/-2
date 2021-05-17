#include "TaskManager.h"
#include "DrawTaskManager.h"

// printf_s ���g�p���邽�߃C���N���[�h
#include <iostream>

// �R���X�g���N�^
Task::Task(int Priority, const char * name) :
	m_Prev(nullptr),
	m_Next(nullptr),
	m_Priority(Priority),
	m_IsPause(false),
	m_Name(name)
{
	// �^�X�N�}�l�[�W���[�ɓo�^
	TaskManager::GetInstance()->AddTask(this);
}

Task::Task() :
	m_Prev(nullptr),
	m_Next(nullptr),
	m_Priority(0),
	m_IsPause(false),
	m_Name("Task")
{
	// �^�X�N�}�l�[�W���[�ɓo�^
	TaskManager::GetInstance()->AddTask(this);
}

// �f�X�g���N�^
Task::~Task()
{
}

void Task::Kill()
{
	// �X�V���X�g����O���č폜���X�g�ɒǉ�����
	TaskManager::GetInstance()->AddKill(this);
	
	// �`�惊�X�g����O��
	DrawTaskManager::GetInstance()->RemoveTask(this);
}

void Task::SetPause(bool isPause)
{
	m_IsPause = isPause;
}

int Task::GetPriority()const
{
	return m_Priority;
}

bool Task::IsPause()const
{
	return m_IsPause;
}

const char * Task::GetName()const
{
	return m_Name;
}

void Task::Update()
{
	printf_s("%s �͊���N���X�̍X�V���Ăяo���Ă��܂��B\n", m_Name);

}