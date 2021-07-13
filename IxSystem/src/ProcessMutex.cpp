#include "ProcessMutex.h"

CProcessMutex::CProcessMutex( const char* strKey )
{
	memset(m_KeyBufer, '\0', sizeof(char) * 128);
	strcat(m_KeyBufer, strKey);
#ifdef WIN32
	
	m_hHandle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, m_KeyBufer);
	if(m_hHandle == NULL)
	{
		m_hHandle = CreateMutex(NULL, FALSE, m_KeyBufer);
	}
#elif defined __linux__
		m_hHandle = sem_open(m_KeyBufer, O_RDWR | O_CREAT, 0644, 1);
#elif defined VXWORKS
#endif
}

CProcessMutex::~CProcessMutex()
{
#ifdef WIN32
	CloseHandle(m_hHandle);
#elif defined __linux__
	sem_close(m_hHandle);
	sem_unlink(m_strKey.c_str());
#elif defined VXWORKS
#endif
}

bool CProcessMutex::Acquire(int nMilliseconds) const
{
#ifdef WIN32
	 if(WAIT_OBJECT_0 == WaitForSingleObject(m_hHandle,nMilliseconds))
	 {
		 return true;
	 }
	 return false;
#elif defined __linux__
	timespec time = ConvertMilliSeconds(nMilliseconds);
	int nRet = sem_timedwait(m_hHandle,&time);
	return nRet == 0;
#elif defined VXWORKS
#endif
}

bool CProcessMutex::Release() const
{
#ifdef WIN32
	int nRet =ReleaseMutex(m_hHandle);
	return nRet == 0?false:true;
#elif defined __linux__
	int ret = sem_post(m_hHandle);
	return ret==0
#elif defined VXWORKS
#endif
}

ProcessMutexHandle& CProcessMutex::GetHandle()
{
	return m_hHandle;
}

const char* CProcessMutex::GetKey()
{
	return m_KeyBufer;
}
