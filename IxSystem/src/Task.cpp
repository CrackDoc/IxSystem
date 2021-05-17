#include "Task.h"
#include <string>
#include <list>

// 友元函数访问pTask 受保护的(Protected)成员变量或者函数
void* TaskProc( void* lpParameter )
{
	CTask *pTask = static_cast<CTask*>(lpParameter);
	if(pTask != NULL)
	{
		pTask->m_eTaskState = pTask->OnRunTask();
		//局部变量自己释放,成员变量pthread_exit 传递给pthread_join 指向指针的指针调用
		pthread_exit(lpParameter);
	}
	return pTask;
}
static void Specific_Destroy(void * buf)
{
	free(buf);
}
CTask::CTask( bool bInherit /*= true*/,E_SCHEDULE_ALGORITHM eSchedAlgorithm /*= E_SCHED_OTHER*/,bool bAutoFree /*= true*/ ,bool bCompetitionGlobalCPU /*= true*/):
	m_eTaskState(E_INVAILD)
	
{
	memset(m_TaskBufName, '\0', sizeof(char) * 32);
#ifdef WIN32
	m_pthreadSpecificKey = GetSpecificKey();
#elif defined __linux__
	m_pthreadSpecificKey = GetSpecificKey();
	m_hHandle = NULL;
#endif
	if(!bInherit)
	{
		pthread_attr_init(&m_Abttribute);

		pthread_attr_setschedpolicy(&m_Abttribute,(int)eSchedAlgorithm);

		pthread_attr_setscope(&m_Abttribute, PTHREAD_SCOPE_PROCESS);

		pthread_attr_setdetachstate(&m_Abttribute, bAutoFree?PTHREAD_CREATE_JOINABLE:PTHREAD_CREATE_DETACHED);

		pthread_attr_setinheritsched(&m_Abttribute,PTHREAD_EXPLICIT_SCHED);

		pthread_attr_setscope(&m_Abttribute,bCompetitionGlobalCPU?PTHREAD_SCOPE_SYSTEM:PTHREAD_SCOPE_PROCESS);
	}
	else
	{
		pthread_attr_init(&m_Abttribute);
		pthread_attr_setinheritsched(&m_Abttribute,PTHREAD_INHERIT_SCHED);
	}

}

CTask::~CTask()
{
	pthread_attr_t *ppthread_attr_t = &m_Abttribute;
	if(ppthread_attr_t != NULL)
	{
		pthread_attr_destroy(ppthread_attr_t);
		ppthread_attr_t = NULL;
	}
}

bool CTask::Activate( const char* strTaskName /*= ""*/,E_PRIORITY ePriority /*= E_PRIORITY_NORMAL*/,int nStackSize /*= 1024*100*/ )
{
	strcat_s(m_TaskBufName, strTaskName);

	int nRet = pthread_create((pthread_t*)&m_hHandle,&m_Abttribute,TaskProc,this);
	if(nRet != 0)
	{
		return false;
	}
	m_eTaskState = E_RUNNING;
	return m_NonBlockEvent.Signal();
}

bool CTask::Wait( int nMilliseconds /*= -1*/ )
{
	// 处理线程在取消点退出过后,一些成员变量的内存处理
	void *pRet = NULL;
	int nRet = pthread_join(m_hHandle,&pRet);
	CTask *pTask = static_cast<CTask*>(pRet);
	if(pTask != NULL)
	{
		pTask->OnRecycleThreadQuit();
	}
	return (nRet == 0)?true:false;
}

bool CTask::SetPriority( E_PRIORITY ePriority )
{
	sched_param schParam;
	schParam.sched_priority = ePriority;
	int nRet = pthread_setschedparam(m_hHandle,ePriority,&schParam);

	return nRet == 0?true:false;
}

// 挂起信号
bool CTask::Suspend()
{
	return m_NonBlockEvent.Reset();
}
// 恢复信号
bool CTask::Resume()
{
	return m_NonBlockEvent.Signal();
}
bool CTask::IsQuit()
{
	if(m_eTaskState == E_CANCEL || m_eTaskState == E_COMPLETED)
	{
		return true;
	}
	return false;
}

bool CTask::IsRunning()
{
	if(m_eTaskState == E_INVAILD || m_eTaskState == E_CANCEL || m_eTaskState == E_COMPLETED)
	{
		return false;
	}
	return true;
}

bool CTask::IsSuspend()
{
	bool block = m_NonBlockEvent.Wait(50);

	return !block;
}

bool CTask::IsStart()
{
	if(m_eTaskState == E_INVAILD)
	{
		return false;
	}
	return true;
}

void CTask::Quit()
{
	// cancle 信号失效
	m_ExitSemaphore.Reset();
	// 重新唤醒线程
	Resume();
}

bool CTask::Terminate()
{
#ifdef _WIN32
	m_eTaskState = E_INVAILD;
	int nRet = TerminateThread(&m_hHandle,0);
	return (nRet== 0)?false:true;
#elif defined __linux__
	Quit();
	Wait();
#elif defined VXWORKS
#endif // _WIN32
}

bool CTask::TaskSleep( int nSleepTime )
{
#ifdef _WIN32
	Sleep(nSleepTime);
#elif defined 
__linux__
	usleep(nMilSecond * 1000);
#elif defined VXWORKS
#endif // _WIN32
	return true;
}

bool CTask::CancleThread(bool bCancle)
{
	return m_ExitSemaphore.Signal();
}

CTask::E_TASK_STATE CTask::GetTaskState()
{
	//如果当前已经是挂起状态
	if(m_eTaskState == E_SUSPEND)
	{
		return m_eTaskState;
	}
	if(IsRunning())
	{
		if(IsSuspend())
		{
			m_eTaskState = E_SUSPEND;
		}
		else
		{
			m_eTaskState = E_RUNNING;
		}
	}
	return m_eTaskState;
}

pthread_key_t CTask::GetSpecificKey()
{
#if defined(WIN32)|| defined(__linux__)
	int nRet = pthread_key_create(&m_pthreadSpecificKey,Specific_Destroy); 
#elif defined VXWORKS
#endif
	return m_pthreadSpecificKey;
}
bool CTask::DelSpecificKeyData()
{
#if defined(WIN32)|| defined(__linux__)
	int nRet = pthread_key_delete(m_pthreadSpecificKey);
	return nRet == 0;
#elif defined VXWORKS
#endif
}
void CTask::OnRecycleThreadQuit()
{

}
bool CTask::OnCriticalCanclePoint(int nMilliseconds)
{
	pthread_testcancel(); 

	return m_ExitSemaphore.Wait(nMilliseconds);
}

bool CTask::OnCriticalNonBlock(int nMilliseconds /*= -1*/)
{
	bool bBlok = m_NonBlockEvent.Wait(nMilliseconds);
	return bBlok;
}
bool CTask::OnInputSpecificData( SpecificData *pData)
{
#if defined(WIN32)|| defined(__linux__)
	SpecificData ppSpecificData = &pData;
	int nRet = pthread_setspecific(m_pthreadSpecificKey,ppSpecificData);
	return nRet == 0;
#elif defined VXWORKS
#endif

}

SpecificData CTask::OnOutSpecificData(pthread_key_t key)
{
#if defined(WIN32)|| defined(__linux__)
	return pthread_getspecific(m_pthreadSpecificKey);
#elif defined VXWORKS
#endif

}
CTaskExUser::CTaskExUser()
{

}

CTaskExUser::~CTaskExUser()
{

}

CTask::E_TASK_STATE CTaskExUser::OnRunTask( CTaskEx* pTask )
{
	return CTask::E_COMPLETED;
}

CTaskEx::CTaskEx()
	:lpListCTaskExUsers(new std::list<CTaskExUser*>())
{

}

CTaskEx::~CTaskEx()
{

}

void CTaskEx::AttachUser( CTaskExUser* pUser )
{
	std::list<CTaskExUser*> &m_ListCTaskExUsers = *static_cast<std::list<CTaskExUser*>*>(lpListCTaskExUsers);
	m_ListCTaskExUsers.push_back(pUser);
}
CTask::E_TASK_STATE CTaskEx::OnRunTask()
{
	CTask::E_TASK_STATE eTaskState = CTask::E_INVAILD;
	std::list<CTaskExUser*>& m_ListCTaskExUsers = *static_cast<std::list<CTaskExUser*>*>(lpListCTaskExUsers);

	std::list<CTaskExUser*>::iterator it0 = m_ListCTaskExUsers.begin();
	for(;it0 != m_ListCTaskExUsers.end();++it0)
	{
		CTaskExUser* pUser = *it0;
		eTaskState = pUser->OnRunTask(this);
	}
	return eTaskState;
}
