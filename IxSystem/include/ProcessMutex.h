/**
* @file      ProcessMutex.h
* @brief     ���̼�Ļ������
*          
* @note      ������windows��linux
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
* @brief ���̼�Ļ������
* @note  
*/
class SYSTEM_EXPORT CProcessMutex
{
public:
	/**
	 * @fn       CProcessMutex(const std::string& strKey)
	 * @brief    ���캯��
	 * @param    const std::string& strKey  ���̻������Ĺؼ���
	*/
	CProcessMutex(const char* strKey);
	~CProcessMutex();

public:
	/**
	 * @fn       bool Acquire()
	 * @brief    ��ȡ���̻�����
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Acquire(int nMilliseconds = -1) const;

	/**
	 * @fn       bool Release()
	 * @brief    �ͷŽ��̻�����
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Release() const;

	/**
	 * @fn       ProcessMutexHandle& GetHandle()
	 * @brief    ��ȡ���̻������ľ��
	 * @return   ProcessMutexHandle&  ���̻������ľ��
	*/
	ProcessMutexHandle& GetHandle();

	/**
	 * @fn       std::string& GetKey()
	 * @brief    ��ȡ���̻������Ĺؼ���
	 * @return   std::string&  ���̻������Ĺؼ���
	*/
	const char* GetKey();

private:
	mutable ProcessMutexHandle m_hHandle;	///<���̻������ľ��

	char m_KeyBufer[128];
	//std::string m_strKey;	///<���̻������Ĺؼ���

};
#endif // ProcessMutex_h__