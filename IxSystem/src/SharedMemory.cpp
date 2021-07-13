#include "SharedMemory.h"
#include "ProcessMutex.h"
#include <iostream>
#include <string>
#ifdef WIN32
#include <windows.h>
#include <winbase.h>
#elif defined __linux__
#	include <sys/types.h>
#	include <sys/ipc.h>
#	include <sys/shm.h>
#include <system_error>
#endif

CSharedMemory::CSharedMemory( const char* szstrKey )
{
	memset(m_KeyBufer, '\0', sizeof(char) * 128);
	strcat(m_KeyBufer, szstrKey);
	strcat(m_KeyBufer, "_ProcessMutex");
	m_pLock = new CProcessMutex(m_KeyBufer);

}

CSharedMemory::~CSharedMemory()
{
	if(m_pLock != NULL)
	{
		delete m_pLock;
		m_pLock = NULL;
	}
	if(m_hHandle != NULL)
	{
		CloseHandle(m_hHandle);
		m_hHandle = NULL;
	}
}

bool CSharedMemory::Create( int nSize, E_ACCESS_MODE eE_ACCESS_MODE /*= E_ACCESS_MODE_READ_WRITE*/ )
{
#ifdef WIN32
	m_nSize = nSize;

	int nMode = 1 <<(eE_ACCESS_MODE+1);

	m_hHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		nMode,					 // read/write access
		0,                       // maximum object size (high-order DWORD)
		nSize,					 // maximum object size (low-order DWORD)
		m_KeyBufer);       // name of mapping object
	if (m_hHandle == NULL)
	{
		printf("Could not create file mapping object (%d).\n",
			GetLastError());
		return false;
	}
	return true;
#elif defined __linux__
#endif
}

bool CSharedMemory::Attach( E_ACCESS_MODE eE_ACCESS_MODE /*= E_ACCESS_MODE_READ_WRITE*/ )
{
#ifdef WIN32
	int nFileAcessMode = FILE_MAP_ALL_ACCESS;

	if(eE_ACCESS_MODE == 0)
	{
		nFileAcessMode = FILE_MAP_READ;
	}

	m_pSharedData = (LPTSTR)MapViewOfFile(m_hHandle,   // handle to map object
		nFileAcessMode,                  // read/write permission
		0,
		0,
		m_nSize);

	if (m_pSharedData == NULL)
	{
		printf("Could not map view of file (%d).\n",
			GetLastError());

		CloseHandle(m_hHandle);

		return false;
	}
	return false;
#elif defined __linux__
#endif
}

bool CSharedMemory::Detach()
{
	#ifdef WIN32
	int nRet = UnmapViewOfFile(m_pSharedData);
	m_pSharedData = NULL;
	return (nRet == 0?true:false);
#elif defined __linux__
#endif
}

bool CSharedMemory::IsAttached()
{
	return (m_pSharedData != NULL?true:false);
}

bool CSharedMemory::Acquire() const
{
	return m_pLock->Acquire();
}

bool CSharedMemory::Release() const
{
	return m_pLock->Release();
}

void* CSharedMemory::GetData()
{
	return m_pSharedData;
}

int CSharedMemory::GetSize()
{
	return m_nSize;
}

const char* CSharedMemory::GetKey()
{
	return m_KeyBufer;
}

void CSharedMemory::CleanHandle()
{
	if(m_hHandle != NULL)
	{
		CloseHandle(m_hHandle);
		m_hHandle = NULL;
	}
}

CSharedMemory::E_ERROR CSharedMemory::GetError()
{
	return E_ERROR_NO;
}

void CSharedMemory::SetError()
{

}
