#include "Condition.h"
#include "SystemUtility.h"

void cleanup(void* arg)
{
	pthread_mutex_unlock((pthread_mutex_t*)arg);
}
CCondition::CCondition()
	:m_hHandle(NULL)
	,bConditionValue(false)
{
#if defined WIN32 || defined __linux__
	pthread_condattr_init(&mAttr);
	pthread_cond_init(&m_hHandle,&mAttr); 
#elif defined VXWORKS
#endif

}

CCondition::~CCondition()
{
#if defined WIN32 || defined __linux__
	if(m_hHandle != NULL)
	{
		pthread_cond_destroy(&m_hHandle);
		m_hHandle = NULL;
	}
#elif defined VXWORKS
#endif

}
bool CCondition::Signal()
{
	int nRet = 0;
	pthread_cleanup_push(cleanup, (void*)&GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle());
	bConditionValue = true;
	nRet = pthread_cond_broadcast(&m_hHandle);
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle());
	pthread_cleanup_pop(0);
	return (nRet == 0 ? true : false);
}

bool CCondition::Wait(int nMilliseconds /*= -1*/ ) const
{
	int nRet = 0;
	timespec time = ConvertMilliSeconds(nMilliseconds);
	pthread_cleanup_push(cleanup, (void*)&GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle());
	while (!bConditionValue && nRet != ETIMEDOUT)
	{
		nRet = pthread_cond_timedwait(&m_hHandle, &GetCThreadMutex().GetHandle(), &time);
	}
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle());
	pthread_cleanup_pop(0);
	return (nRet == 0 ? true : false);
}

ConditionHandle& CCondition::GetHandle() const
{
	return m_hHandle;
}

bool CCondition::Reset() const
{
	int nRet = 0;
	pthread_cleanup_push(cleanup, (void*)&GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle());
	nRet = pthread_condattr_destroy(&mAttr);
	bConditionValue = false;
	pthread_cond_init(&m_hHandle, &mAttr);
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle());
	pthread_cleanup_pop(0);
	return (nRet == 0 ? true : false);
}

CThreadMutex &CCondition::GetCThreadMutex() const
{
	return m_ThreadMutex;
}
