#include "DrawTaskManager.h"

#include <assert.h>

DrawTask::DrawTask():
	m_Prev(nullptr),
	m_Next(nullptr),
	m_Priority(0),
	m_Name(nullptr),
	m_Task(nullptr),
	m_Func(nullptr),
	m_IsPause(false)
{
}

DrawTask::~DrawTask()
{
	// ���X�g����O��
	DrawTaskManager::GetInstance()->RemoveTask(this);
}

void DrawTask::Draw()
{
	// �֐��|�C���^�Ăяo��
	(m_Task->*m_Func)();
}

void DrawTask::RegistDraw(Task * task, DrawFunc func, int priority, const char * name)
{
	// �^�X�N�|�C���^���֐��|�C���^�����ɐݒ肳��Ă���ꍇ�͌x��
	assert(((m_Func == nullptr) && (m_Task == nullptr)));

	// �^�X�N�|�C���^�Ɗ֐��|�C���^�̂ǂ��炩�ł�null�̏ꍇ�͌x��
	assert(((func != nullptr) && (task != nullptr)));

	// �ϐ��ݒ�
	m_Task = task;
	m_Func = func;
	m_Priority = priority;
	m_Name = name;

	// DrawTaskManager�ɓo�^
	DrawTaskManager::GetInstance()->AddDrawTask(this);
}

void DrawTask::Remove()
{
	// ���X�g����O��
	DrawTaskManager::GetInstance()->RemoveTask(this);

	// �ϐ�������
	m_Task = nullptr;
	m_Func = nullptr;
	m_Priority = 0;
	m_Name = "";
}

void DrawTask::ChangePriority(int priority)
{
	// �o�^����Ă���ꍇ�̂ݗD��x�ύX
	if (IsRegist())
	{
		m_Priority = priority;
		DrawTaskManager::GetInstance()->ChangePriority(this);
	}
}

void DrawTask::SetPause(bool isPause)
{
	m_IsPause = isPause;
}

bool DrawTask::IsRegist()const
{
	// �^�X�N�|�C���^�Ɗ֐��|�C���^���ݒ肳��Ă���ꍇ�͓o�^����Ă��锻��
	return (m_Task || m_Func);
}

int DrawTask::GetPriority()const
{
	return m_Priority;
}

bool DrawTask::IsPause()const
{
	return m_IsPause;
}

const char * DrawTask::GetName()const
{
	return m_Name;
}
