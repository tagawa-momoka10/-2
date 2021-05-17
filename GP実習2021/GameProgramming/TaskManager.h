#ifndef INCLUDE_TASK_MANAGER
#define INCLUDE_TASK_MANAGER

#include "Task.h"
#include "CBase.h"

// シングルトン

class TaskManager
{
private:
	static TaskManager* m_Instance;		// インスタンス(実行中に1個しかインスタンスを生成させない)

	Task* m_ListFirst;					// 更新リストの先端ポインタ

	Task* m_DeleteListFirst;			// 削除リストの先端ポインタ

public:
	// インスタンス取得
	static TaskManager* GetInstance();	
	// インスタンス解放
	static void ReleaseInstance();		

	// タスク即全消去(後片付けに使用する)
	void AllKill();						


	// Task更新
	void Update();

	// タスクをリストに追加
	void AddTask(Task* addTask);

	// 削除リストに追加
	void AddKill(Task* killTask);

	//衝突判定更新
	void Collision();
	
private:
	TaskManager();
	~TaskManager();

	// タスク削除
	void KillTask();

	// Taskをリストから外す
	void RemoveUpdateTaskList(Task* removeTask);
	void RemoveKillTaskList(Task* removeTask);

	// Taskをリストに追加する
	void AddTaskList(Task* firstTask, Task* removeTask);

};

#endif // !INCLUDE_TASK_MANAGER
