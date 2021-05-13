/**
* @file      ProcessSemaphore.h
* @brief     进程间的信号量
*          
* @note      适用于windows、linux
*          
* @author    crack
* @date      2020-07-06
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef _PROCESS_SEMAPHORE_H_
#define _PROCESS_SEMAPHORE_H_

#include "SystemExport.h"
#include "semaphore.h"

#ifndef VXWORKS
#ifdef WIN32
#include <Windows.h>
	typedef HANDLE ProcessSemaphoreHandle;
#elif defined __linux__
#include "pthread.h"
	typedef sem_t* ProcessSemaphoreHandle;
#endif

/**
* @class CProcessSemaphore
* @brief 进程间的信号量
* @note  
*/
class SYSTEM_EXPORT CProcessSemaphore
{
public:
	enum E_ACCESS_MODE
	{
		E_ACCESS_MODE_OPEN = 0,		///<访问模式打开
		E_ACCESS_MODE_CREATE = 1	///<访问模式创建
	};

	/**
	 * @fn       CProcessSemaphore(const std::string& strKey, int nInitialCount, E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    
	 * @param    const std::string& strKey  进程信号量的关键字
	 * @param    int nInitialCount  进程信号量的初始值
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  进程信号量的访问模式
	*/
	CProcessSemaphore(const char* strKey, int nInitialCount = -1, E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_OPEN);

	~CProcessSemaphore();

	/**
	 * @fn       bool Signal()
	 * @brief    发送信号量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Signal();

	/**
	 * @fn       bool Acquire()
	 * @brief    获取进程信号量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Acquire(int nMilliseconds = -1);


		/**
	 * @fn       bool Release()
	 * @brief    释放进程信号量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Release();

	/**
	 * @fn       ProcessSemaphoreHandle& GetHandle()
	 * @brief    获取进程信号量的句柄
	 * @return   ProcessSemaphoreHandle&  进程信号量的句柄
	*/
	ProcessSemaphoreHandle& GetHandle();

	/**
	 * @fn       std::string GetKey()
	 * @brief    获取进程信号量的关键字
	 * @return   std::string  进程信号量的关键字
	*/
	const char* GetKey();

	/**
	 * @fn       int GetCurrentCount()
	 * @brief    获取进程信号量的当前值
	 * @return   int  进程信号量的当前值
	*/
	int GetCurrentCount();

private:
	ProcessSemaphoreHandle m_hHandle;	///<进程信号量的句柄
	char m_KeyBufer[128];
	//std::string m_strKey;	///<进程信号量的关键字

	int m_nInitialCount;	///<进程信号量的初始值

};

#endif
#endif

