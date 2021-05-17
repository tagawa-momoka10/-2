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
	// タスクが削除されていない可能性があります。(TaskManagerの方でタスクを削除するときに一緒に外しているはず)
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
	// 更新(描画)
	DrawTask* currentTask = m_FirstList;
	
	// 
	while (currentTask)
	{
		// 一時停止していない場合は描画
		if (!currentTask->m_IsPause)
		{
			currentTask->Draw();
		}

		// 次のタスク
		currentTask = currentTask->m_Next;
	}
}

void DrawTaskManager::AddDrawTask(DrawTask * task)
{
	// 先頭ポインタがnullの場合は先頭ポインタに設定して追加終了
	if (!m_FirstList)
	{
		m_FirstList = task;
		return;
	}

	// 指定のグループと優先度の場所に追加
	DrawTask* currentTask = m_FirstList;
	DrawTask* nextTask = currentTask->m_Next;

	// グループ
	while (currentTask)
	{
		// 優先度がリストのタスクより低い場合はその前のところにタスクを追加
		if (task->m_Priority < currentTask->m_Priority)
		{
			// 追加したタスクの前後を設定
			task->m_Prev = currentTask->m_Prev;
			task->m_Next = currentTask;

			// リストのタスクを繋ぎ変える
			if (currentTask->m_Prev)
			{
				currentTask->m_Prev->m_Next = task;
			}

			currentTask->m_Prev = task;

			// 先頭に追加された場合は先頭ポインタ変更
			if (m_FirstList == currentTask)
			{
				m_FirstList = task;
			}

			return;
		}

		// 次のタスクがない場合は、最後に追加する
		if (!currentTask->m_Next)
		{
			currentTask->m_Next = task;
			task->m_Prev = currentTask;
			return;
		}

		// 次のタスク
		currentTask = currentTask->m_Next;
	}
}

void DrawTaskManager::RemoveTask(DrawTask * removeTask)
{
	DrawTask * prev = removeTask->m_Prev;
	DrawTask * next = removeTask->m_Next;

	// タスクのグループの前後
	if (prev)
	{
		prev->m_Next = next;

	}
	if (next)
	{
		next->m_Prev = prev;
	}

	// 先頭ポインタを入れ替える場合更新
	if (removeTask == m_FirstList)
	{
		m_FirstList = removeTask->m_Next;
	}

	// 前後左右のつながりを初期化
	removeTask->m_Prev = nullptr;
	removeTask->m_Next = nullptr;
}

void DrawTaskManager::RemoveTask(Task * removeTask)
{
	DrawTask* currentTask = m_FirstList;

	// タスク検索(複数登録があるかもしれないので全部確認する)
	while (currentTask)
	{
		DrawTask* nextTask = currentTask->m_Next;

		// タスクポインタが一致している場合はリストから解除
		if (currentTask->m_Task == removeTask)
		{
			RemoveTask(currentTask);
		}

		// 次のタスク
		currentTask = nextTask;
	}
}

void DrawTaskManager::ChangePriority(DrawTask * task)
{
	// 描画リストから外す
	RemoveTask(task);

	// 描画リストに追加
	AddDrawTask(task);
}
