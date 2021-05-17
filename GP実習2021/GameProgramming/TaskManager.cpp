#include "TaskManager.h"
#include "DrawTaskManager.h"

// printf_s を使用するためインクルード
#include <iostream>

#include <assert.h>

#define ARRAY_LENGTH(ary) (sizeof(ary) / sizeof(ary[0]))

TaskManager* TaskManager::m_Instance = nullptr;

TaskManager * TaskManager::GetInstance()
{
	// インスタンスがない場合は生成
	if (!m_Instance)	m_Instance = new TaskManager();

	return m_Instance;
}

void TaskManager::ReleaseInstance()
{
	// 全佐を削除する
	m_Instance->AllKill();

	// タスクが残っているかどうか簡易確認

	// 更新タスクが削除されていない可能性があります。
	assert(!m_Instance->m_ListFirst);
	// 削除タスクが削除されていない可能性があります。
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
	// タスク削除(前回のフレームで削除予定のものだけ削除)
	KillTask();

	// 更新タスク
	Task* currentTask = m_ListFirst;

	// 更新
	while (currentTask)
	{
		// 次のタスク
		Task* nextTask = currentTask->m_Next;

		// Stateが通常の場合に更新する
		if (!currentTask->m_IsPause)
		{
			currentTask->Update();
		}

		// 次のタスク
		currentTask = nextTask;
	}
}

void TaskManager::AddTask(Task * addTask)
{
	// 先頭タスクがない場合は先頭タスクに設定して終了
	if (!m_ListFirst)
	{
		m_ListFirst = addTask;
		return;
	}

	Task* currentTask = m_ListFirst;

	// リストに追加
	while (currentTask)
	{
		// 追加するタスクの方が優先度が低い場合は現状の一個前にタスクを追加
		if (addTask->m_Priority < currentTask->m_Priority)
		{
			// 追加したタスクの前後を設定
			addTask->m_Prev = currentTask->m_Prev;
			addTask->m_Next = currentTask;

			// リストのタスクを繋ぎ変える
			if (currentTask->m_Prev)
			{
				currentTask->m_Prev->m_Next = addTask;
			}

			currentTask->m_Prev = addTask;


			// 先頭に追加された場合は先頭ポインタ変更
			if (m_ListFirst == currentTask)
			{
				m_ListFirst = addTask;
			}

			return;
		}

		// 次のタスクがない場合は、最後に追加する
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
	// 更新リストからタスクを外す
	RemoveUpdateTaskList(killTask);


	// 先端ポインタがない場合は先端ポインタに設定
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
		// 次のタスクがあるかどうか確認
		if (currentTask->m_Next)
		{
			// 次のタスク
			currentTask = currentTask->m_Next;
		}
		else
		{
			// 末尾にタスクを追加
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


	// タスクの優先順位(前後)
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}
			
	// 先頭ポインタを外す場合は次のタスク(もしくはnull)を設定する
	if (removeTask == m_ListFirst)
	{
		m_ListFirst = removeTask->m_Next;
	}

	// 前後左右のつながりを初期化
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;

}

void TaskManager::RemoveKillTaskList(Task * removeTask)
{
	Task * prev = removeTask->m_Prev;
	Task * next = removeTask->m_Next;


	// タスクの優先順位(前後)
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}

	// 先頭ポインタを外す場合は次のタスク(もしくはnull)を設定する
	if (removeTask == m_DeleteListFirst)
	{
		m_DeleteListFirst = removeTask->m_Next;
	}

	// 前後左右のつながりを初期化
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;

}

void TaskManager::KillTask()
{
	// 削除リストがある場合はリスト内のタスクを削除する
	if (m_DeleteListFirst)
	{
		Task* currentTask = m_DeleteListFirst;

		while (currentTask)
		{
			// 次のタスク保存
			Task* nextTask = currentTask->m_Next;

			// リストから外す
			RemoveKillTaskList(currentTask);

			// タスク削除
			delete currentTask;

			// 次のタスク
			currentTask = nextTask;
		}
	}
}

void TaskManager::AllKill()
{
	// タスクを削除
	Task* listfirstGroup[] = {m_DeleteListFirst, m_ListFirst };

	for (int i = 0; i < ARRAY_LENGTH(listfirstGroup); i++)
	{
		Task* currentTask = listfirstGroup[i];

		// リストをまわす
		while (currentTask)
		{
			// 次のタスクを保持しておく
			Task* nextTask = currentTask->m_Next;

			// リストから外す
			if (i == 0)
			{
				// 削除リスト
				RemoveKillTaskList(currentTask);
			}
			else
			{
				// 更新リスト
				RemoveUpdateTaskList(currentTask);
			}

			// 描画リストから削除する
			DrawTaskManager::GetInstance()->RemoveTask(currentTask);

			// タスク削除
			delete currentTask;

			// 次のタスクに進める
			currentTask = nextTask;
		}
	}
}

void TaskManager::Collision()
{
	CBase *ci = (CBase*)m_ListFirst;	// 現在位置を更新
	while (ci){
		// 次のタスク
		CBase *cy = (CBase*)ci->m_Next;
		while (cy){
			// Stateが通常の場合に更新する
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
		// 次のタスク
		ci = (CBase*)ci->m_Next;
	}

}
