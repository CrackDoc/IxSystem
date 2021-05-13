#include "TaskSemaphore.h"
#include "SystemUtility.h"

CTaskSemaphore::CTaskSemaphore()
{
#if defined(WIN32) || defined(__linux__)
	sem_init(&m_hHandle,0,0);
#elif defined VXWORKS
#endif
}
CTaskSemaphore::~CTaskSemaphore()
{
#if defined(WIN32) || defined(__linux__)
	sem_t *psem_t = &m_hHandle;
	if(psem_t != NULL)
	{
		sem_destroy(psem_t);
		psem_t = NULL;
	}
#elif defined VXWORKS
#endif

}

bool CTaskSemaphore::Signal()
{
	bool bSignal = false;
#if defined(WIN32) || defined(__linux__)
	int nRet = sem_post(&m_hHandle);
	bSignal = (nRet == 0?true:false);
#elif defined VXWORKS
#endif
	return bSignal;
}
bool CTaskSemaphore::Wait(int nMilliseconds /*= -1*/)
{
	int nRet;
#if defined(WIN32) || defined(__linux__)
	timespec time = ConvertMilliSeconds(nMilliseconds);
	time.tv_nsec = nMilliseconds;
	nRet = sem_timedwait(&m_hHandle,&time);
	return nRet==0?true:false;
#elif defined VXWORKS
#endif
}

bool CTaskSemaphore::Reset()
{
	bool bRest = false;
#if defined(WIN32) || defined(__linux__)
	sem_t *psem_t = &m_hHandle;
	if(psem_t != NULL)
	{
		sem_destroy(psem_t);
		psem_t = NULL;
	}
	sem_init(&m_hHandle,0,0);
#elif defined VXWORKS
#endif
	return bRest;
}

void CTaskSemaphore::TravelEvents(IThreadEventVisitor &rVistor)
{

}

int CTaskSemaphore::GetSemaphoreValue()
{
	int nPreValueCnt = 0;
#if defined(WIN32) || defined(__linux__)
	sem_getvalue(&m_hHandle, &nPreValueCnt);
#elif defined VXWORKS
#endif
	return nPreValueCnt;
}
