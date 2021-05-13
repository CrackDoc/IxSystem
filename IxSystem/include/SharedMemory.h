/**
* @file      SharedMemory.h
* @brief     �����ڴ����ز���
*          
* @note      ������windows��linux
*          
* @author    crack
* @date      2020-07-06
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef _SHARED_MEMORY_H_
#define _SHARED_MEMORY_H_

#include "SystemExport.h"

#ifndef VXWORKS
#ifdef WIN32
#include <windows.h>
#include <winbase.h>
	typedef HANDLE SharedMemoryHandle;
#elif defined __linux__
#	include <sys/types.h>
#	include <sys/ipc.h>
#	include <sys/shm.h>
#include <system_error>
	typedef int SharedMemoryHandle;
#endif

/**
* @class CSharedMemory
* @brief �����ڴ����ز���
* @note  
*/
class CProcessMutex;
class SYSTEM_EXPORT CSharedMemory
{
public:
	enum E_ACCESS_MODE
	{
		E_ACCESS_MODE_READ_ONLY = 0,	///<ֻ��ģʽ
		E_ACCESS_MODE_READ_WRITE = 1	///<��дģʽ
	};

	enum E_ERROR
	{
		E_ERROR_NO = 0,					///<û�д���
		E_ERROR_HANDLE_IS_NULL = 1,		///<���Ϊ��
		E_ERROR_PERMISSION_DENIED = 2,	///<û��Ȩ��
		E_ERROR_INVALID_SIZE = 3,		///<��Ч�Ĵ�С
		E_ERROR_KEY_ERROR = 4,			///<�ؼ��ִ���
		E_ERROR_ALREADY_EXISTS = 5,		///<�Ѿ�����
		E_ERROR_NOT_FOUND = 6,			///<δ�ҵ�
		E_ERROR_LOCK_ERROR = 7,			///<��������
		E_ERROR_OUT_OF_RESOURCES = 8,	///<û����Դ
		E_ERROR_UNKNOWN = 9				///<δ֪����
	};

	/**
	 * @fn       CSharedMemory(const std::string& strKey)
	 * @brief    ���캯��
	 * @param    const std::string& strKey  �����ڴ�Ĺؼ���
	*/
	CSharedMemory(const char* strKey);

	~CSharedMemory();

	/**
	 * @fn       bool Create(int nSize, E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    ���������ڴ�,���Ҫ�����Ĺ����ڴ��Ѿ����ڣ�Ҳ������false
	 * @param    int nSize  �����ڴ�Ĵ�С
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  �����ڴ�ķ���ģʽ
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Create(int nSize, E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_READ_WRITE);

	/**
	 * @fn       bool Attach(E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    �������ڴ�ӳ�䵽���ص�ַ����
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  �����ڴ�ķ���ģʽ
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Attach(E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_READ_WRITE);

	/**
	 * @fn       bool Detach()
	 * @brief    ȡ�������ڴ�ĵ�ַӳ��,��Linux�ϣ����û���û�ӳ�䵽�ù����ڴ���ʱ����ɾ���ù����ڴ�
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Detach();

	/**
	 * @fn       bool IsAttached()
	 * @brief    �����ڴ���Ƿ��Ѿ���ַӳ��
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool IsAttached();

	/**
	 * @fn       bool Acquire()
	 * @brief    ��ȡ�����ڴ�Ľ��̻�����
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Acquire() const;

	/**
	 * @fn       bool Release()
	 * @brief    �ͷŹ����ڴ�Ľ��̻�����
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool Release() const;

	/**
	 * @fn       void* GetData()
	 * @brief    ��ȡ�����ڴ��ӳ���ַ
	 * @return   void*  ��ַָ��
	*/
	void* GetData();

	/**
	 * @fn       int GetSize()
	 * @brief    ��ȡ�����ڴ�Ĵ�С
	 * @return   int  �����ڴ�Ĵ�С
	*/
	int GetSize();

	/**
	 * @fn       std::string GetKey()
	 * @brief    ��ȡ�����ڴ�Ĺؼ���
	 * @return   std::string  �����ڴ�Ĺؼ���
	*/
	const char* GetKey();

	/**
	 * @fn       void CleanHandle()
	 * @brief    ��������ڴ��Handle
	 * @return   void  
	*/
	void CleanHandle();

	/**
	 * @fn       CSharedMemory::E_ERROR GetError()
	 * @brief    ��ȡ��ǰ�����ԭ��
	 * @return   CSharedMemory::E_ERROR  �����ö��
	*/
	E_ERROR GetError();
	
private:
	void SetError();

private:
	SharedMemoryHandle m_hHandle;	///<�����ڴ��Handle

	char m_KeyBufer[128];

	//std::string m_strKey;	///<�����ڴ�Ĺؼ���

	void* m_pSharedData;	///<�����ڴ�ĵ�ַӳ��ָ��

	CProcessMutex *m_pLock;	///<�����ڴ�Ľ��̻�����

	int m_nSize;	///<�����ڴ�Ĵ�С

	mutable bool m_bLockByMe;	///<�����ڴ��Ƿ��Ѿ����Լ���ס

	E_ERROR m_eError;	///<�����ڴ�����Ĵ���ö�ٱ���
};

#endif
#endif

