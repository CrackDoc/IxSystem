/**
* @file      ThreadMutex.h
* @brief     线程互斥量
*          
* @note      适用于windows、linux、vxworks，配合GUARD使用
*          
* @author    crack
* @date      2020-07-08
* @version   1.0.0.0
* @CopyRight IxLab
*/

#ifndef _THREAD_MUTEX_H_
#define _THREAD_MUTEX_H_

#include "IxSystemExport.h"

#if defined(WIN32) || defined(__linux__)
#include <pthread.h>
typedef pthread_mutex_t ThreadMutexHandle;
#elif defined VXWORKS
#endif

/**
* @class CThreadMutex
* @brief 线程互斥量
* @note  线程互斥量
*/
class SYSTEM_EXPORT CThreadMutex
{
public:
	CThreadMutex();
	~CThreadMutex();

	/**
	 * @fn       bool Acquire()   
	 * @brief    获取线程互斥量          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Acquire() const;

	/**
	 * @fn       bool Release()   
	 * @brief    释放线程互斥量          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	bool Release() const;

	/**
	 * @fn       ThreadMutexHandle& GetHandle()   
	 * @brief    获取线程互斥量的句柄         
	 * @return   ThreadMutexHandle&	线程互斥量的句柄       
	*/
	ThreadMutexHandle& GetHandle();

private:
	mutable ThreadMutexHandle m_hHandle;	///<线程互斥量句柄
};

#endif
