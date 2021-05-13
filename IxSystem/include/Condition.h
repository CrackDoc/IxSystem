/**
* @file      Condition.h
* @brief     条件变量
*          
* @note      适用于windows、linux、vxworks，主要功能是模拟Linux下的条件变量，
*			  Windows下使用的是事件、Linux下使用的是条件变量
*			  Vxworks下使用的是二值信号量
*			  在Linux下，如果一个线程先发信号、另外一个线程再Wait的话，会造成Wait不能返回
*			  Windows和Vxworks下，如果先发信号，再Wait会立即返回。
*			  Wait时需要传入一个外部的锁，在windows下在Wait时会将锁先释放掉，等wait成功后再将锁获取
*			  不推荐直接使用CCondition
*          
* @author    crack
* @date      2020-07-08
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef _CONDITION_H_
#define _CONDITION_H_

#include "ThreadMutex.h"

#if defined(WIN32) || defined(__linux__)
	typedef pthread_cond_t ConditionHandle;
#elif defined VXWORKS
#endif
/**
* @class CCondition
* @brief 条件变量
* @note  条件变量
*/
class SYSTEM_EXPORT CCondition
{
public:
	CCondition();
	~CCondition();

public:
	/**
	 * @fn       bool Signal()   
	 * @brief    设置为激发态        
	 * @return   bool  成功返回true，失败返回false     
	*/
	bool Signal();

	/**
	 * @fn       bool Wait(CThreadMutex& rThreadMutex,int nMilliseconds)   
	 * @brief    等待条件变量为激发状态   
	 * @param    CThreadMutex & rThreadMutex  线程互斥量     
	 * @param    int nMilliseconds  等待的时间，以毫秒为单位          
	 * @return   bool  成功返回true，失败返回false     
	*/
	bool Wait(int nMilliseconds = -1) const;

	/**
	 * @fn       ConditionHandle& GetHandle()   
	 * @brief    获取条件变量句柄       
	 * @return   ConditionHandle&	条件变量句柄       
	*/
	ConditionHandle& GetHandle() const;

	/**
	 * @fn       bool Reset()   
	 * @brief    将事件设置为非激发状态.windows下有效        
	 * @return   bool	成功返回true，失败返回false       
	*/
	bool Reset() const;

	/**
	 * @fn       bool GetCThreadMutex()   
	 * @brief    返回 互斥信号量     
	 * @return   bool	成功返回true，失败返回false       
	*/
	CThreadMutex &GetCThreadMutex() const;


protected:
	mutable ConditionHandle m_hHandle;	///<条件变量句柄
	mutable pthread_condattr_t mAttr;			//条件变量的值
	mutable CThreadMutex m_ThreadMutex;		// 互斥锁
private:
	mutable bool bConditionValue;			// 条件变量的值
};
#endif
