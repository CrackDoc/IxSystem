#include "Process.h" 
#include <string>
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#include <locale.h>  
#include <locale> 
#elif defined __linux__
#include "pthread.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#elif defined VXWORKS
#	include "ThreadEvent.h"
#	include "Library.h"
#	ifdef REWORKS
#		include <reworks/types.h>
#		include "types/vxTypesOld.h"
#	endif
#endif

#ifdef VXWORKS
void CProcess::ProcessProc( void* lpParameter )
	
{

}
#endif

CProcess::CProcess()
{
	m_ProcessInfo = new PROCESS_INFORMATION;

	m_ProStartuoInfo = new STARTUPINFO;

	memset(m_WorkDirBuf, '\0', sizeof(char) * 256);

}

CProcess::~CProcess()
{
	//等待进程退出
	Wait();
#ifdef WIN32
	if(((PPROCESS_INFORMATION)m_ProcessInfo)->hThread != NULL)
	{
		CloseHandle(((PPROCESS_INFORMATION)m_ProcessInfo)->hThread);
		delete m_ProcessInfo;
	}
	if(((PPROCESS_INFORMATION)m_ProcessInfo)->hProcess != NULL)
	{
		CloseHandle(((PPROCESS_INFORMATION)m_ProcessInfo)->hProcess);
		delete m_ProcessInfo;
	}
#elif defined __linux__
#elif defined VXWORKS
#endif
}

bool CProcess::KillProcess( const char* szstrProcessName )
{
	std::string strProcessName = szstrProcessName;
	bool bSucc = false;
#ifdef WIN32
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}

	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		if (strcmp(pe.szExeFile, strProcessName.c_str()) == 0) {
			bSucc = true;
			break;
		}
	}
	CloseHandle(hSnapshot);
	if(!bSucc)
	{
		return false;
	}
	bSucc = KillProcess(pe.th32ProcessID);
	return bSucc;
#elif defined __linux__
	FILE *fp;
	char buf[100];
	char cmd[200] = {'\0'};
	pid_t pid = -1;
	sprintf(cmd, "pidof %s", proc_name);

	if((fp = popen(cmd, "r")) != NULL)
	{
		if(fgets(buf, 255, fp) != NULL)
			pid = atoi(buf);
	}
	pclose(fp);
	return KillProcess(pid);
#elif defined VXWORKS
#endif

}
bool CProcess::KillProcess( int nProcessID )
{
	bool bSucc = false;
#ifdef WIN32
	DWORD pId = nProcessID;

	HANDLE hHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);

	if(hHandle == NULL)
	{
		return false;
	}
	int nRet = TerminateProcess(hHandle,0);
	bSucc = (nRet==0?false:true);
	if(hHandle != NULL)
	{
		CloseHandle(hHandle);
	}
	return bSucc;
#elif defined __linux__
	int status;
	kill(nProcessID ,SIGABRT);
	wait(&status);
	return WIFSIGNALED(status);
#elif defined VXWORKS
#endif


}
void CProcess::SetWorkingDir( const char* strWorkingDir )
{
	memset(m_WorkDirBuf,'\0', sizeof(char) * 256);
	strcat_s(m_WorkDirBuf, strWorkingDir);
}
// 对访问其他进程的进程描述符进行ACE RSA 加密模块,加密模块重新设计,对资源模块进行访问,得到程序的控制入口,注入dll 程序到相应的代码中
bool CProcess::Create( const char* szstrFilePath, const char *szstrParam, int nShowCMD /*= -1*/ )
{
	bool bSucc = false;
#ifdef WIN32
	std::locale loc = std::locale::global(std::locale(""));
	ZeroMemory( m_ProStartuoInfo, sizeof(m_ProStartuoInfo));
	((STARTUPINFO*)m_ProcessInfo)->cb = sizeof(m_ProStartuoInfo);
	((STARTUPINFO*)m_ProcessInfo)->wShowWindow = (nShowCMD<0)?SW_HIDE:SW_SHOWNORMAL;
	ZeroMemory( m_ProcessInfo, sizeof(m_ProcessInfo));

	
	// Start the child process. 
	int nRet = CreateProcess(szstrFilePath,   // No module name (use command line)
		(LPSTR)szstrParam,        //cmd line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		m_WorkDirBuf,        // Use parent's starting directory 
		(STARTUPINFO*)m_ProStartuoInfo,				// Pointer to STARTUPINFO structure
		(PPROCESS_INFORMATION)m_ProcessInfo );				// Pointer to PROCESS_INFORMATION structure
	std::locale::global(loc);
	bSucc = (nRet == 0)?false:true;
#elif defined __linux__
	int len = strParam.length();
	memccpy(m_pArgv,strParam.c_str(),sizeof(char)*len);
	int nRet;
	m_nProcessId=fork()
	if(!m_nProcessId)
	{
		nRet = execv(strFilePath,strParam.c_str());
	}
	bSucc = (nRet==0?true:false);
#elif defined VXWORKS
#endif
	return bSucc;
}

bool CProcess::Wait( int nMilliSecond /*= -1*/ )
{
#ifdef WIN32
	int nRet = WaitForSingleObject(((PPROCESS_INFORMATION)m_ProcessInfo)->hProcess, nMilliSecond);// 等待程序退出
	return nRet == WAIT_OBJECT_0?true:false;
#elif defined __linux__
	int chlidPId = wait();
	return (chlidPId==m_nProcessId?true:false);
#elif defined VXWORKS
#endif
}

bool CProcess::Terminate()
{
	bool bSucc = false;
#ifdef WIN32
	int nRet = TerminateProcess(((PPROCESS_INFORMATION)m_ProcessInfo)->hProcess,0);
	bSucc = (nRet==0?false:true);
#elif defined __linux__
#elif defined VXWORKS
#endif
	return bSucc;
}
int CProcess::GetProcessId()
{
#ifdef WIN32
	return ((PPROCESS_INFORMATION)m_ProcessInfo)->dwProcessId;
#elif defined __linux__
	return m_nProcessId;
#elif defined VXWORKS
#endif

}
int CProcess::GetMainThreadId()
{
#ifdef WIN32
	return ((PPROCESS_INFORMATION)m_ProcessInfo)->dwProcessId;
#elif defined __linux__
	return pthread_self();
#elif defined VXWORKS
#endif

}
