#include "Condition.h"
#include "SystemUtility.h"

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
	int nRet;
#if defined(WIN32) || defined(__linux__)
	pthread_cleanup_push(pthread_mutex_unlock, (void *) &GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle()); 
	bConditionValue = true;
	nRet = pthread_cond_broadcast(&m_hHandle); 
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle()); 
	pthread_cleanup_pop(0); 
	return (nRet == 0?true:false);
#elif defined VXWORKS
#endif
	
}

bool CCondition::Wait(int nMilliseconds /*= -1*/ ) const
{
	int nRet = 0;
#if defined(WIN32) || defined(__linux__)
	timespec time = ConvertMilliSeconds(nMilliseconds);
	pthread_cleanup_push(pthread_mutex_unlock, (void *) &GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle()); 
	while (!bConditionValue && nRet != ETIMEDOUT) 
	{
		nRet = pthread_cond_timedwait(&m_hHandle,&GetCThreadMutex().GetHandle(),&time); 
	}
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle()); 
	pthread_cleanup_pop(0); 
	return (nRet == 0?true:false);
#elif defined VXWORKS
#endif
}

ConditionHandle& CCondition::GetHandle() const
{
	return m_hHandle;
}

bool CCondition::Reset() const
{
	int nRet;
#if defined(WIN32) || defined(__linux__)
	pthread_cleanup_push(pthread_mutex_unlock, (void *) &GetCThreadMutex().GetHandle());
	pthread_mutex_lock(&GetCThreadMutex().GetHandle()); 
	nRet = pthread_condattr_destroy(&mAttr);
	bConditionValue = false;
	pthread_cond_init(&m_hHandle,&mAttr); 
	pthread_mutex_unlock(&GetCThreadMutex().GetHandle()); 
	pthread_cleanup_pop(0);
	return (nRet == 0?true:false);
#elif defined VXWORKS
#endif
	
}

CThreadMutex &CCondition::GetCThreadMutex() const
{
	return m_ThreadMutex;
}
