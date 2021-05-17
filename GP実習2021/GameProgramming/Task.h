#ifndef	INCLUDE_TASK
#define	INCLUDE_TASK

class Task
{
	friend class TaskManager;

private:
	Task * m_Prev;					// 優先順位の前のポインタ
	Task * m_Next;					// 優先順位の後のポインタ

	int m_Priority;					// 優先順位(高いものから処理をする)
	bool m_IsPause;					// ポーズ
	
	const char * m_Name;			// タスクの名前	

public:
	// コンストラクタ ・ デストラクタ
	Task(int Priority, const char * name);
	Task();
	virtual ~Task();

	// 通常関数

	// 削除
	void Kill();	

	// 一時停止
	void SetPause(bool isPause);
	// 優先度取得
	int GetPriority()const;
	// 一時停止しているかどうか
	bool IsPause()const;
	// タスクの名前
	const char* GetName()const;

private:

	// 更新
	virtual void Update();

};

#endif // INCLUDE_TASK