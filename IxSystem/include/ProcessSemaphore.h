/**
* @file      ProcessSemaphore.h
* @brief     ���̼���ź���
*          
* @note      ������windows��linux
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
* @brief ���̼���ź���
* @note  
*/
class SYSTEM_EXPORT CProcessSemaphore
{
public:
	enum E_ACCESS_MODE
	{
		E_ACCESS_MODE_OPEN = 0,		///<����ģʽ��
		E_ACCESS_MODE_CREATE = 1	///<����ģʽ����
	};

	/**
	 * @fn       CProcessSemaphore(const std::string& strKey, int nInitialCount, E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    
	 * @param    const std::string& strKey  �����ź����Ĺؼ���
	 * @param    int nInitialCount  �����ź����ĳ�ʼֵ
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  �����ź����ķ���ģʽ
	*/
	CProcessSemaphore(const char* strKey, int nInitialCount = -1, E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_OPEN);

	~CProcessSemaphore();

	/**
	 * @fn       bool Signal()
	 * @brief    �����ź���
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Signal();

	/**
	 * @fn       bool Acquire()
	 * @brief    ��ȡ�����ź���
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Acquire(int nMilliseconds = -1);


		/**
	 * @fn       bool Release()
	 * @brief    �ͷŽ����ź���
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Release();

	/**
	 * @fn       ProcessSemaphoreHandle& GetHandle()
	 * @brief    ��ȡ�����ź����ľ��
	 * @return   ProcessSemaphoreHandle&  �����ź����ľ��
	*/
	ProcessSemaphoreHandle& GetHandle();

	/**
	 * @fn       std::string GetKey()
	 * @brief    ��ȡ�����ź����Ĺؼ���
	 * @return   std::string  �����ź����Ĺؼ���
	*/
	const char* GetKey();

	/**
	 * @fn       int GetCurrentCount()
	 * @brief    ��ȡ�����ź����ĵ�ǰֵ
	 * @return   int  �����ź����ĵ�ǰֵ
	*/
	int GetCurrentCount();

private:
	ProcessSemaphoreHandle m_hHandle;	///<�����ź����ľ��
	char m_KeyBufer[128];
	//std::string m_strKey;	///<�����ź����Ĺؼ���

	int m_nInitialCount;	///<�����ź����ĳ�ʼֵ

};

#endif
#endif

