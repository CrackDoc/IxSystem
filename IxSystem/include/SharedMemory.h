/**
* @file      SharedMemory.h
* @brief     共享内存的相关操作
*          
* @note      适用于windows、linux
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
* @brief 共享内存的相关操作
* @note  
*/
class CProcessMutex;
class SYSTEM_EXPORT CSharedMemory
{
public:
	enum E_ACCESS_MODE
	{
		E_ACCESS_MODE_READ_ONLY = 0,	///<只读模式
		E_ACCESS_MODE_READ_WRITE = 1	///<读写模式
	};

	enum E_ERROR
	{
		E_ERROR_NO = 0,					///<没有错误
		E_ERROR_HANDLE_IS_NULL = 1,		///<句柄为空
		E_ERROR_PERMISSION_DENIED = 2,	///<没有权限
		E_ERROR_INVALID_SIZE = 3,		///<无效的大小
		E_ERROR_KEY_ERROR = 4,			///<关键字错误
		E_ERROR_ALREADY_EXISTS = 5,		///<已经存在
		E_ERROR_NOT_FOUND = 6,			///<未找到
		E_ERROR_LOCK_ERROR = 7,			///<加锁错误
		E_ERROR_OUT_OF_RESOURCES = 8,	///<没有资源
		E_ERROR_UNKNOWN = 9				///<未知错误
	};

	/**
	 * @fn       CSharedMemory(const std::string& strKey)
	 * @brief    构造函数
	 * @param    const std::string& strKey  共享内存的关键字
	*/
	CSharedMemory(const char* strKey);

	~CSharedMemory();

	/**
	 * @fn       bool Create(int nSize, E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    创建共享内存,如果要创建的共享内存已经存在，也将返回false
	 * @param    int nSize  共享内存的大小
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  共享内存的访问模式
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Create(int nSize, E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_READ_WRITE);

	/**
	 * @fn       bool Attach(E_ACCESS_MODE eE_ACCESS_MODE)
	 * @brief    将共享内存映射到本地地址中来
	 * @param    E_ACCESS_MODE eE_ACCESS_MODE  共享内存的访问模式
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Attach(E_ACCESS_MODE eE_ACCESS_MODE = E_ACCESS_MODE_READ_WRITE);

	/**
	 * @fn       bool Detach()
	 * @brief    取消共享内存的地址映射,在Linux上，如果没有用户映射到该共享内存上时，将删除该共享内存
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Detach();

	/**
	 * @fn       bool IsAttached()
	 * @brief    共享内存的是否已经地址映射
	 * @return   bool  成功返回true，失败返回false
	*/
	bool IsAttached();

	/**
	 * @fn       bool Acquire()
	 * @brief    获取共享内存的进程互斥量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Acquire() const;

	/**
	 * @fn       bool Release()
	 * @brief    释放共享内存的进程互斥量
	 * @return   bool  成功返回true，失败返回false
	*/
	bool Release() const;

	/**
	 * @fn       void* GetData()
	 * @brief    获取共享内存的映射地址
	 * @return   void*  地址指针
	*/
	void* GetData();

	/**
	 * @fn       int GetSize()
	 * @brief    获取共享内存的大小
	 * @return   int  共享内存的大小
	*/
	int GetSize();

	/**
	 * @fn       std::string GetKey()
	 * @brief    获取共享内存的关键字
	 * @return   std::string  共享内存的关键字
	*/
	const char* GetKey();

	/**
	 * @fn       void CleanHandle()
	 * @brief    清除共享内存的Handle
	 * @return   void  
	*/
	void CleanHandle();

	/**
	 * @fn       CSharedMemory::E_ERROR GetError()
	 * @brief    获取当前出错的原因
	 * @return   CSharedMemory::E_ERROR  出错的枚举
	*/
	E_ERROR GetError();
	
private:
	void SetError();

private:
	SharedMemoryHandle m_hHandle;	///<共享内存的Handle

	char m_KeyBufer[128];

	//std::string m_strKey;	///<共享内存的关键字

	void* m_pSharedData;	///<共享内存的地址映射指针

	CProcessMutex *m_pLock;	///<共享内存的进程互斥量

	int m_nSize;	///<共享内存的大小

	mutable bool m_bLockByMe;	///<共享内存是否已经被自己锁住

	E_ERROR m_eError;	///<共享内存操作的错误枚举变量
};

#endif
#endif

