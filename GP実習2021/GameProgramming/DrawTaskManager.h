#ifndef INCLUDE_TASK_DRAW_MANAGER
#define INCLUDE_TASK_DRAW_MANAGER

#include "DrawTask.h"

class DrawTaskManager
{
private:
	static DrawTaskManager* m_Instance;		// インスタンス

	DrawTask* m_FirstList;					// 描画リストの先端ポインタ

public:
	// インスタンス取得
	static DrawTaskManager* GetInstance();	
	// インスタンス解放
	static void ReleaseInstance();			

	// 描画
	void Draw();				
	// 追加
	void AddDrawTask(DrawTask* task);
	// 登録解除
	void RemoveTask(DrawTask* removeTask);
	// 登録解除(Taskから検索)
	void RemoveTask(Task* removeTask);

	// 優先度変更
	void ChangePriority(DrawTask* task);

private:
	DrawTaskManager();
	~DrawTaskManager();


};
#endif // !INCLUDE_TASK_DRAW_MANAGER
