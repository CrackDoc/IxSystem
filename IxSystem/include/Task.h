/**
* @file      Task.h
* @brief     线程的封装
*          
* @note      适用于windows、linux、vxworks，vxworks下依赖CThreadEvent类
*          
* @author    crack
* @date      2020-07-03
* @version   1.0.0.0
* @CopyRight IxLab
*/

#ifndef _TASK_H_
#define _TASK_H_

#include "IxSystemExport.h"
#include "SystemConfig.h"
#include "pthread.h"
#include "TaskSemaphore.h"
#include "ThreadEvent.h"

#if defined(WIN32) || defined(__linux__)
typedef pthread_t ThreadHandle;
#elif defined VXWORKS
	typedef int ThreadHandle;
#endif


/**
* @class CTask
* @brief 线程的封装
* @note  该类只能通过继承方式实现
*/
typedef void *SpecificData;

class SYSTEM_EXPORT CTask
{
	friend void* TaskProc(void* lpParameter);

public:
	///线程优先级，取值范围为0-255，主要为了适配vxworks的取值范围，然后设置了7个等级，适配windows和linux，取值越小优先级越高
	enum E_PRIORITY
	{
		E_PRIORITY_IDLE = 255,		///<空闲
		E_PRIORITY_LOWEST = 200,		///<最低优先级
		E_PRIORITY_LOW = 160,		///<低优先级
		E_PRIORITY_NORMAL = 120,	///<正常优先级
		E_PRIORITY_HIGH = 80,		///<高优先级
		E_PRIORITY_HIGHEST = 40,	///<最高优先级
		E_PRIORITY_TIME_CRITICAL = 0,		///<关键优先级
	};
	/// 线程的调度算法
	enum E_SCHEDULE_ALGORITHM
	{
		E_SCHED_OTHER = 0, //正常、非实时
		E_SCHED_FIFO,	// 实时、轮转法
		E_SCHED_RR		// 实时、先入先出
	};
	// 线程返回状态
	enum E_TASK_STATE
	{
		E_INVAILD = -1, // NULL
		E_RUNNING,		// 正在运行状态
		E_SUSPEND,		// 挂起状态
		E_CANCEL,		// 取消状态
		E_COMPLETED,    // 完成状态
		E_TIME_OUT		// 超时状态
	};
	/**
	 * @fn       CTask(bool bInherit = true,E_SCHEDULE_ALGORITHM eSchedAlgorithm = E_SCHED_OTHER,bool bAutoFree = true,bool bCompetitionGlobalCPU = false)   
	 * @brief    线程构造函数     
	 * @param    bool bInherit 继承调用者线程的一些属性
	 * @param    E_SCHEDULE_ALGORITHM eSchedAlgorithm  线程的调度算法
	 * @param    bool bAutoFree  线程是否自动释放资源
	 * @param    bool bCompetitionGlobalCPU  是否是全局竞争资源
	 * @return   void     
	*/
	CTask(bool bInherit = true,E_SCHEDULE_ALGORITHM eSchedAlgorithm = E_SCHED_OTHER,bool bAutoFree = true,bool bCompetitionGlobalCPU = true);

	virtual ~CTask();

public:
	/**
	 * @fn       bool Activate(const std::string& strTaskName,E_PRIORITY ePriority,int nStackSize)   
	 * @brief    启动线程     
	 * @param    const std::string& strTaskName  线程的名字，在vxworks下有效     
	 * @param    E_PRIORITY ePriority  线程的优先级,传入枚举方式,同时也可以传入整形数字，范围为0到255     
	 * @param    int nStackSize  线程的栈大小，在vxworks下有效          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Activate(const char* strTaskName = "",E_PRIORITY ePriority = E_PRIORITY_NORMAL,int nStackSize = 1024*100);
	
	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    等待线程退出     
	 * @param    int nMilliseconds  等待的时间，以毫秒为单位,如果小于0表示一直等待直到退出，否则表示最长等待时间          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Wait(int nMilliseconds = -1);
	
	/**
	 * @fn       bool SetPriority(E_PRIORITY ePriority)   
	 * @brief    设置线程优先级     
	 * @param    E_PRIORITY ePriority  线程优先级          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool SetPriority(E_PRIORITY ePriority);
	
	/**
	 * @fn       bool Suspend()   
	 * @brief    挂起线程          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Suspend();
	
	/**
	 * @fn       bool Resume()   
	 * @brief    唤醒线程         
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Resume();
	
	/**
	 * @fn       bool IsQuit()   
	 * @brief    当前线程是否已经退出          
	 * @return   bool	 退出返回true，否则返回false       
	*/
	bool IsQuit();

	/**
	 * @fn       bool IsRunning()   
	 * @brief    当前线程是否在运行中         
	 * @return   bool	 退出返回true，否则返回false       
	*/
	bool IsRunning();
	
	/**
	 * @fn       bool IsSuspend()   
	 * @brief    当前线程是否已经挂起         
	 * @return   bool	 挂起返回true，否则返回false       
	*/ 
	// 说明 高优先级线程来挂起低优先级的线程
	bool IsSuspend();
	
	/**
	 * @fn       bool IsStart()   
	 * @brief    当前线程是否已经启动        
	 * @return   bool	 启动返回true，否则返回false       
	*/
	bool IsStart();
	
	/**
	 * @fn       void Quit()   
	 * @brief    设置线程退出标志为true，线程将自动退出，但是要完全销毁线程资源还需要调用Wait函数          
	 * @return   void       
	*/
	void Quit();

	/**
	 * @fn       void Terminate()   
	 * @brief    强制退出线程       
	 * @return   bool       
	*/
	bool Terminate();

	/**
	 * @fn       bool TaskSleep(int nSleepTime)   
	 * @brief    以100ms为判断标准的Sleep实现，对于长时间的Sleep，如果等待线程退出，则会在100ms之内等待成功     
	 * @param    int nSleepTime  线程睡眠事件         
	 * @return   bool       
	*/
	bool TaskSleep(int nSleepTime);

	/**
	 * @fn       void CancleThread(int nSleepTime)   
	 * @brief    发送cancle时间给指定的线程
	 * @param          
	 * @return   bool       
	*/
	bool CancleThread(bool bCancle = true);

	/**
	 * @fn       void GetTaskState()   
	 * @brief    获取线程运行状态
	 * @param          
	 * @return   bool       
	*/
	E_TASK_STATE GetTaskState();


	/**
	 * @fn      pthread_key_t GetSpecificKey()   
	 * @brief   获取线程是私有key
	 * @param          
	 * @return   bool       
	*/

	 pthread_key_t GetSpecificKey();

	/**
	 * @fn       void DelSpecificData()   
	 * @brief    清除线程私有数据
	 * @param          
	 * @return   bool       
	*/
	 bool DelSpecificKeyData();

	 /**
	 * @fn       SpecificData OnInputSpecificData(int &nLen),读取线程私有
	 * @brief    void
	 * @param    void   
	 * @return   SpecificData       
	*/
	SpecificData OnOutSpecificData(pthread_key_t key);

protected:
	/**
	 * @fn       virtual E_TASK_STATE OnRunTask()   
	 * @brief    线程执行的回调函数，子类必须实现该函数           
	 * @return   void 
	*/
	virtual E_TASK_STATE OnRunTask() = 0;

	/**
	 * @fn       bool OnRecycleThreadQuit(),线程退出后回收数据
	 * @brief    void
	 * @param    void   
	 * @return   void       
	*/
	virtual void OnRecycleThreadQuit();

public:
	/**
	 * @fn       bool OnCriticalCanclePoint(int nMilliseconds = 1),1ms
	 * @brief    void
	 * @param    void   
	 * @return   void       
	*/
	bool OnCriticalCanclePoint(int nMilliseconds = 1);

	/**
	 * @fn       bool OnCriticalNonBlock(),输入线程私有数据
	 * @brief    void
	 * @param    int nMilliseconds = -1
	 * @return   bool       
	*/
	bool OnCriticalNonBlock(int nMilliseconds = -1);

	/**
	 * @fn       bool OnInputSpecificData(),输入线程私有数据
	 * @brief    void
	 * @param    SpecificData pData 
	 * @return   bool       
	*/
	virtual bool OnInputSpecificData(SpecificData *pData);

protected:
	// 
	char m_TaskBufName[32];
	//std::string m_strTaskName;	///<线程的名字

	bool m_bTaskSuspend;		///<线程是否挂起

	bool m_bTaskStart;			///<线程是否启动

	ThreadHandle m_hHandle;		///<线程句柄

	E_TASK_STATE m_eTaskState;		// 线程当前状态

private:

	pthread_attr_t m_Abttribute; // 属性

	SpecificData m_SpecificData; //线程私有数据

	pthread_key_t m_pthreadSpecificKey; // 线程私有key

	CThreadEvent m_NonBlockEvent;  //非阻塞事件

	CTaskSemaphore m_ExitSemaphore; // 退出线程信号量

};

class SYSTEM_EXPORT CTaskEx;

/**
* @class CTaskExUser
* @brief CTaskEx的观察者
* @note  CTaskEx的观察者
*/
class SYSTEM_EXPORT CTaskExUser
{
public:
	CTaskExUser();
	virtual ~CTaskExUser();

public:
	/**
	 * @fn       virtual void OnRunTask(CTaskEx* pTask)   
	 * @brief    线程执行的回调函数     
	 * @param    CTaskEx * pTask  对应的线程对象          
	 * @return   void
	*/
	virtual CTask::E_TASK_STATE OnRunTask(CTaskEx* pTask);
};

/**
* @class CTaskEx
* @brief CTask的扩展
* @note  该类可以通过组合方式下，注册观察者的方式使用
*/
class SYSTEM_EXPORT CTaskEx : public CTask
{
public:
	CTaskEx();
	virtual ~CTaskEx();

public:
	/**
	 * @fn       void AttachUser(CTaskExUser* pUser)   
	 * @brief    设置观察者    
	 * @param    CTaskExUser * pUser   观察者指针         
	 * @return   void       
	*/
	void AttachUser(CTaskExUser* pUser);

protected:
	///实现基类的线程执行回调函数
	virtual CTask::E_TASK_STATE OnRunTask();

private:
	void* lpListCTaskExUsers;
	//std::list<CTaskExUser*> m_ListCTaskExUsers;

};
#define IMPLEMENT_TASK_CRITICAL(pTaskVal)\
	if(pTaskVal->OnCriticalCanclePoint())\
		return CTask::E_CANCEL;\
	if(!pTaskVal->OnCriticalNonBlock())\
		continue;\
	if(pTaskVal->OnCriticalCanclePoint())\
		return CTask::E_CANCEL;
#endif
