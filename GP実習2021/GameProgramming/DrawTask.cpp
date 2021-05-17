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
	// リストから外す
	DrawTaskManager::GetInstance()->RemoveTask(this);
}

void DrawTask::Draw()
{
	// 関数ポインタ呼び出し
	(m_Task->*m_Func)();
}

void DrawTask::RegistDraw(Task * task, DrawFunc func, int priority, const char * name)
{
	// タスクポインタか関数ポインタが既に設定されている場合は警告
	assert(((m_Func == nullptr) && (m_Task == nullptr)));

	// タスクポインタと関数ポインタのどちらかでもnullの場合は警告
	assert(((func != nullptr) && (task != nullptr)));

	// 変数設定
	m_Task = task;
	m_Func = func;
	m_Priority = priority;
	m_Name = name;

	// DrawTaskManagerに登録
	DrawTaskManager::GetInstance()->AddDrawTask(this);
}

void DrawTask::Remove()
{
	// リストから外す
	DrawTaskManager::GetInstance()->RemoveTask(this);

	// 変数初期化
	m_Task = nullptr;
	m_Func = nullptr;
	m_Priority = 0;
	m_Name = "";
}

void DrawTask::ChangePriority(int priority)
{
	// 登録されている場合のみ優先度変更
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
	// タスクポインタと関数ポインタが設定されている場合は登録されている判定
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
