#include "ThreadMutex.h"

CThreadMutex::CThreadMutex()
{
#if defined(WIN32) || defined(__linux__)
	pthread_mutex_init(&m_hHandle,NULL); 
#elif defined VXWORKS
#endif
}

CThreadMutex::~CThreadMutex()
{
#if defined(WIN32) || defined(__linux__)
	pthread_mutex_destroy(&m_hHandle);
#elif defined VXWORKS
#endif
}

bool CThreadMutex::Acquire() const
{
#if defined(WIN32) || defined(__linux__)
	pthread_mutex_lock(&m_hHandle); 
#elif defined VXWORKS
#endif
	return true;
}

bool CThreadMutex::Release() const
{
#if defined(WIN32) || defined(__linux__)
	pthread_mutex_unlock(&m_hHandle); 
#elif defined VXWORKS
#endif
	return true;
}
ThreadMutexHandle& CThreadMutex::GetHandle()
{
	return m_hHandle;
}
