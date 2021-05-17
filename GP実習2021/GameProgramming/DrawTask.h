#ifndef INCLUDE_DRAW_TASK
#define	INCLUDE_DRAW_TASK

#include "Task.h"

typedef void(Task::*DrawFunc)();

class DrawTask
{
	friend class DrawTaskManager;

public:
	DrawTask();
	~DrawTask();

private:
	
	DrawTask* m_Prev;			// 優先順位の前のポインタ
	DrawTask* m_Next;			// 優先順位の後のポインタ

	int m_Priority;				// 優先順位
	const char* m_Name;			// デバッグ用名前

	Task* m_Task;				// タスクポインタ
	DrawFunc m_Func;			// 関数ポインタ

	bool m_IsPause;				// 一時停止フラグ

public: 
	// 描画関数登録
	void RegistDraw(Task* task, DrawFunc func, int priority,  const char * name);
	// 登録解除
	void Remove();
	// 優先順位変更
	void ChangePriority(int priority);

	// 一時停止
	void SetPause(bool isPause);
	// 登録されているかどうか
	bool IsRegist()const;
	// 優先度取得
	int GetPriority()const;
	// 一時停止しているかどうか
	bool IsPause()const;
	// 描画タスクの名前
	const char* GetName()const;

private:
	// 描画(関数ポインタ呼び出し)
	void Draw();
	
};




#endif // !INCLUDE_DRAW_TASK


