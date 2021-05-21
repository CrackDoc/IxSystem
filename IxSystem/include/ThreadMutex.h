/**
* @file      ThreadMutex.h
* @brief     �̻߳�����
*          
* @note      ������windows��linux��vxworks�����GUARDʹ��
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
* @brief �̻߳�����
* @note  �̻߳�����
*/
class SYSTEM_EXPORT CThreadMutex
{
public:
	CThreadMutex();
	~CThreadMutex();

	/**
	 * @fn       bool Acquire()   
	 * @brief    ��ȡ�̻߳�����          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Acquire() const;

	/**
	 * @fn       bool Release()   
	 * @brief    �ͷ��̻߳�����          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	bool Release() const;

	/**
	 * @fn       ThreadMutexHandle& GetHandle()   
	 * @brief    ��ȡ�̻߳������ľ��         
	 * @return   ThreadMutexHandle&	�̻߳������ľ��       
	*/
	ThreadMutexHandle& GetHandle();

private:
	mutable ThreadMutexHandle m_hHandle;	///<�̻߳��������
};

#endif
