#include "TaskManager.h"
#include "DrawTaskManager.h"

// printf_s を使用するためインクルード
#include <iostream>

// コンストラクタ
Task::Task(int Priority, const char * name) :
	m_Prev(nullptr),
	m_Next(nullptr),
	m_Priority(Priority),
	m_IsPause(false),
	m_Name(name)
{
	// タスクマネージャーに登録
	TaskManager::GetInstance()->AddTask(this);
}

Task::Task() :
	m_Prev(nullptr),
	m_Next(nullptr),
	m_Priority(0),
	m_IsPause(false),
	m_Name("Task")
{
	// タスクマネージャーに登録
	TaskManager::GetInstance()->AddTask(this);
}

// デストラクタ
Task::~Task()
{
}

void Task::Kill()
{
	// 更新リストから外して削除リストに追加する
	TaskManager::GetInstance()->AddKill(this);
	
	// 描画リストから外す
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
	printf_s("%s は既定クラスの更新を呼び出しています。\n", m_Name);

}