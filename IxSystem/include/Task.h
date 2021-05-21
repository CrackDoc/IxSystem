/**
* @file      Task.h
* @brief     �̵߳ķ�װ
*          
* @note      ������windows��linux��vxworks��vxworks������CThreadEvent��
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
* @brief �̵߳ķ�װ
* @note  ����ֻ��ͨ���̳з�ʽʵ��
*/
typedef void *SpecificData;

class SYSTEM_EXPORT CTask
{
	friend void* TaskProc(void* lpParameter);

public:
	///�߳����ȼ���ȡֵ��ΧΪ0-255����ҪΪ������vxworks��ȡֵ��Χ��Ȼ��������7���ȼ�������windows��linux��ȡֵԽС���ȼ�Խ��
	enum E_PRIORITY
	{
		E_PRIORITY_IDLE = 255,		///<����
		E_PRIORITY_LOWEST = 200,		///<������ȼ�
		E_PRIORITY_LOW = 160,		///<�����ȼ�
		E_PRIORITY_NORMAL = 120,	///<�������ȼ�
		E_PRIORITY_HIGH = 80,		///<�����ȼ�
		E_PRIORITY_HIGHEST = 40,	///<������ȼ�
		E_PRIORITY_TIME_CRITICAL = 0,		///<�ؼ����ȼ�
	};
	/// �̵߳ĵ����㷨
	enum E_SCHEDULE_ALGORITHM
	{
		E_SCHED_OTHER = 0, //��������ʵʱ
		E_SCHED_FIFO,	// ʵʱ����ת��
		E_SCHED_RR		// ʵʱ�������ȳ�
	};
	// �̷߳���״̬
	enum E_TASK_STATE
	{
		E_INVAILD = -1, // NULL
		E_RUNNING,		// ��������״̬
		E_SUSPEND,		// ����״̬
		E_CANCEL,		// ȡ��״̬
		E_COMPLETED,    // ���״̬
		E_TIME_OUT		// ��ʱ״̬
	};
	/**
	 * @fn       CTask(bool bInherit = true,E_SCHEDULE_ALGORITHM eSchedAlgorithm = E_SCHED_OTHER,bool bAutoFree = true,bool bCompetitionGlobalCPU = false)   
	 * @brief    �̹߳��캯��     
	 * @param    bool bInherit �̳е������̵߳�һЩ����
	 * @param    E_SCHEDULE_ALGORITHM eSchedAlgorithm  �̵߳ĵ����㷨
	 * @param    bool bAutoFree  �߳��Ƿ��Զ��ͷ���Դ
	 * @param    bool bCompetitionGlobalCPU  �Ƿ���ȫ�־�����Դ
	 * @return   void     
	*/
	CTask(bool bInherit = true,E_SCHEDULE_ALGORITHM eSchedAlgorithm = E_SCHED_OTHER,bool bAutoFree = true,bool bCompetitionGlobalCPU = true);

	virtual ~CTask();

public:
	/**
	 * @fn       bool Activate(const std::string& strTaskName,E_PRIORITY ePriority,int nStackSize)   
	 * @brief    �����߳�     
	 * @param    const std::string& strTaskName  �̵߳����֣���vxworks����Ч     
	 * @param    E_PRIORITY ePriority  �̵߳����ȼ�,����ö�ٷ�ʽ,ͬʱҲ���Դ����������֣���ΧΪ0��255     
	 * @param    int nStackSize  �̵߳�ջ��С����vxworks����Ч          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Activate(const char* strTaskName = "",E_PRIORITY ePriority = E_PRIORITY_NORMAL,int nStackSize = 1024*100);
	
	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    �ȴ��߳��˳�     
	 * @param    int nMilliseconds  �ȴ���ʱ�䣬�Ժ���Ϊ��λ,���С��0��ʾһֱ�ȴ�ֱ���˳��������ʾ��ȴ�ʱ��          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Wait(int nMilliseconds = -1);
	
	/**
	 * @fn       bool SetPriority(E_PRIORITY ePriority)   
	 * @brief    �����߳����ȼ�     
	 * @param    E_PRIORITY ePriority  �߳����ȼ�          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool SetPriority(E_PRIORITY ePriority);
	
	/**
	 * @fn       bool Suspend()   
	 * @brief    �����߳�          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Suspend();
	
	/**
	 * @fn       bool Resume()   
	 * @brief    �����߳�         
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Resume();
	
	/**
	 * @fn       bool IsQuit()   
	 * @brief    ��ǰ�߳��Ƿ��Ѿ��˳�          
	 * @return   bool	 �˳�����true�����򷵻�false       
	*/
	bool IsQuit();

	/**
	 * @fn       bool IsRunning()   
	 * @brief    ��ǰ�߳��Ƿ���������         
	 * @return   bool	 �˳�����true�����򷵻�false       
	*/
	bool IsRunning();
	
	/**
	 * @fn       bool IsSuspend()   
	 * @brief    ��ǰ�߳��Ƿ��Ѿ�����         
	 * @return   bool	 ���𷵻�true�����򷵻�false       
	*/ 
	// ˵�� �����ȼ��߳�����������ȼ����߳�
	bool IsSuspend();
	
	/**
	 * @fn       bool IsStart()   
	 * @brief    ��ǰ�߳��Ƿ��Ѿ�����        
	 * @return   bool	 ��������true�����򷵻�false       
	*/
	bool IsStart();
	
	/**
	 * @fn       void Quit()   
	 * @brief    �����߳��˳���־Ϊtrue���߳̽��Զ��˳�������Ҫ��ȫ�����߳���Դ����Ҫ����Wait����          
	 * @return   void       
	*/
	void Quit();

	/**
	 * @fn       void Terminate()   
	 * @brief    ǿ���˳��߳�       
	 * @return   bool       
	*/
	bool Terminate();

	/**
	 * @fn       bool TaskSleep(int nSleepTime)   
	 * @brief    ��100msΪ�жϱ�׼��Sleepʵ�֣����ڳ�ʱ���Sleep������ȴ��߳��˳��������100ms֮�ڵȴ��ɹ�     
	 * @param    int nSleepTime  �߳�˯���¼�         
	 * @return   bool       
	*/
	bool TaskSleep(int nSleepTime);

	/**
	 * @fn       void CancleThread(int nSleepTime)   
	 * @brief    ����cancleʱ���ָ�����߳�
	 * @param          
	 * @return   bool       
	*/
	bool CancleThread(bool bCancle = true);

	/**
	 * @fn       void GetTaskState()   
	 * @brief    ��ȡ�߳�����״̬
	 * @param          
	 * @return   bool       
	*/
	E_TASK_STATE GetTaskState();


	/**
	 * @fn      pthread_key_t GetSpecificKey()   
	 * @brief   ��ȡ�߳���˽��key
	 * @param          
	 * @return   bool       
	*/

	 pthread_key_t GetSpecificKey();

	/**
	 * @fn       void DelSpecificData()   
	 * @brief    ����߳�˽������
	 * @param          
	 * @return   bool       
	*/
	 bool DelSpecificKeyData();

	 /**
	 * @fn       SpecificData OnInputSpecificData(int &nLen),��ȡ�߳�˽��
	 * @brief    void
	 * @param    void   
	 * @return   SpecificData       
	*/
	SpecificData OnOutSpecificData(pthread_key_t key);

protected:
	/**
	 * @fn       virtual E_TASK_STATE OnRunTask()   
	 * @brief    �߳�ִ�еĻص��������������ʵ�ָú���           
	 * @return   void 
	*/
	virtual E_TASK_STATE OnRunTask() = 0;

	/**
	 * @fn       bool OnRecycleThreadQuit(),�߳��˳����������
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
	 * @fn       bool OnCriticalNonBlock(),�����߳�˽������
	 * @brief    void
	 * @param    int nMilliseconds = -1
	 * @return   bool       
	*/
	bool OnCriticalNonBlock(int nMilliseconds = -1);

	/**
	 * @fn       bool OnInputSpecificData(),�����߳�˽������
	 * @brief    void
	 * @param    SpecificData pData 
	 * @return   bool       
	*/
	virtual bool OnInputSpecificData(SpecificData *pData);

protected:
	// 
	char m_TaskBufName[32];
	//std::string m_strTaskName;	///<�̵߳�����

	bool m_bTaskSuspend;		///<�߳��Ƿ����

	bool m_bTaskStart;			///<�߳��Ƿ�����

	ThreadHandle m_hHandle;		///<�߳̾��

	E_TASK_STATE m_eTaskState;		// �̵߳�ǰ״̬

private:

	pthread_attr_t m_Abttribute; // ����

	SpecificData m_SpecificData; //�߳�˽������

	pthread_key_t m_pthreadSpecificKey; // �߳�˽��key

	CThreadEvent m_NonBlockEvent;  //�������¼�

	CTaskSemaphore m_ExitSemaphore; // �˳��߳��ź���

};

class SYSTEM_EXPORT CTaskEx;

/**
* @class CTaskExUser
* @brief CTaskEx�Ĺ۲���
* @note  CTaskEx�Ĺ۲���
*/
class SYSTEM_EXPORT CTaskExUser
{
public:
	CTaskExUser();
	virtual ~CTaskExUser();

public:
	/**
	 * @fn       virtual void OnRunTask(CTaskEx* pTask)   
	 * @brief    �߳�ִ�еĻص�����     
	 * @param    CTaskEx * pTask  ��Ӧ���̶߳���          
	 * @return   void
	*/
	virtual CTask::E_TASK_STATE OnRunTask(CTaskEx* pTask);
};

/**
* @class CTaskEx
* @brief CTask����չ
* @note  �������ͨ����Ϸ�ʽ�£�ע��۲��ߵķ�ʽʹ��
*/
class SYSTEM_EXPORT CTaskEx : public CTask
{
public:
	CTaskEx();
	virtual ~CTaskEx();

public:
	/**
	 * @fn       void AttachUser(CTaskExUser* pUser)   
	 * @brief    ���ù۲���    
	 * @param    CTaskExUser * pUser   �۲���ָ��         
	 * @return   void       
	*/
	void AttachUser(CTaskExUser* pUser);

protected:
	///ʵ�ֻ�����߳�ִ�лص�����
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
