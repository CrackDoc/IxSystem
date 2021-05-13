/**
* @file      ProcessMutex.h
* @brief     进程间的互斥变量
*          
* @note      适用于windows、linux
*          
* @author    crack
* @date      2020-07-06
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef ProcessMutex_h__
#define ProcessMutex_h__

#include "SystemExport.h"
#include <string>

#ifdef WIN32
#	include <windows.h>
	typedef HANDLE ProcessMutexHandle;
#elif defined __linux__
#include "pthread.h"
	sem_t* ProcessMutexHandle;
#elif VXWORKS
#endif

/**
* @class CProcessMutex
* @brief 进程间的互斥变量
* @note  
*/
class SYSTEM_EXPORT CProcessMutex
{
public:
	/**
	 * @fn       CProcessMutex(const std::string& strKey)
	 * @brief    构造函数
	 * @param    const std::string& strKey  进程互斥量的关键字
	*/
	CProcessMutex(const char* strKey);
	~CProcessMutex();

public:
	/**
	 * @fn       bool Acquire()
	 * @brief    获取进程互斥量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Acquire(int nMilliseconds = -1) const;

	/**
	 * @fn       bool Release()
	 * @brief    释放进程互斥量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Release() const;

	/**
	 * @fn       ProcessMutexHandle& GetHandle()
	 * @brief    获取进程互斥量的句柄
	 * @return   ProcessMutexHandle&  进程互斥量的句柄
	*/
	ProcessMutexHandle& GetHandle();

	/**
	 * @fn       std::string& GetKey()
	 * @brief    获取进程互斥量的关键字
	 * @return   std::string&  进程互斥量的关键字
	*/
	const char* GetKey();

private:
	mutable ProcessMutexHandle m_hHandle;	///<进程互斥量的句柄

	char m_KeyBufer[128];
	//std::string m_strKey;	///<进程互斥量的关键字

};
#endif // ProcessMutex_h__