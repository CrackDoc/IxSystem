#include "ProcessSemaphore.h"
#include "SystemUtility.h"

CProcessSemaphore::CProcessSemaphore( const char* strKey, int nInitialCount /*= -1*/, E_ACCESS_MODE eE_ACCESS_MODE /*= E_ACCESS_MODE_OPEN*/ )
{
	memset(m_KeyBufer, '\0', sizeof(char) * 128);
	strcat_s(m_KeyBufer, strKey);

	m_nInitialCount = nInitialCount;

	#ifdef WIN32
		m_hHandle = CreateSemaphore(NULL,m_nInitialCount,1, m_KeyBufer);
	#elif defined __linux__
		m_hHandle = sem_open(m_KeyBufer,0,eE_ACCESS_MODE,m_nInitialCount);
	#endif

}

CProcessSemaphore::~CProcessSemaphore()
{
#ifdef WIN32
	CloseHandle(m_hHandle);
#elif defined __linux__
	sem_close(m_hHandle);
	sem_unlink(m_strKey.c_str());
#endif

}

bool CProcessSemaphore::Signal()
{
	long nPreCnt;
#ifdef WIN32
	int nRet = ReleaseSemaphore(m_hHandle,1,&nPreCnt);
	return nRet != 0;
#elif defined __linux__
	int nRet = sem_post(m_hHandle);
	return nRet == 0?true:false;
#endif
}

bool CProcessSemaphore::Acquire(int nMilliseconds)
{
#ifdef WIN32
	int nRet = WaitForSingleObject(m_hHandle,nMilliseconds);
	return nRet == WAIT_OBJECT_0;
#elif defined __linux__
	timespec spectime = ConvertMilliSeconds(nMilliseconds);
	int nRet = sem_timedwait(m_hHandle,&spectime);
	return nRet == 0?true:false;
#endif
}

bool CProcessSemaphore::Release()
{
	long nPreCnt;
#ifdef WIN32
	int nRet = ReleaseSemaphore(m_hHandle,0,&nPreCnt);
	return nRet != 0;
#elif defined __linux__
#endif
}

ProcessSemaphoreHandle& CProcessSemaphore::GetHandle()
{
	return m_hHandle;
}

const char* CProcessSemaphore::GetKey()
{
	return m_KeyBufer;
}

