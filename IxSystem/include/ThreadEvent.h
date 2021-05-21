/**
* @file      ThreadEvent.h
* @brief     线程事件
*          
* @note      适用于windows、linux、vxworks，主要功能是模拟Windows下的事件，
*             Windows下使用的是事件、Linux下使用的是条件变量、Vxworks下使用的是二值信号量，
*			  如果一个线程先发信号、另外一个线程再Wait的话，所有平台下都会立即返回。
*			  如果只需要等待一个事件，推荐使用CThreadEvent
*          
* @author    crack
* @date      2020-07-06
* @version   1.0.0.0
* @CopyRight IxLab
*/

#ifndef _THREAD_EVENT_H_
#define _THREAD_EVENT_H_

#include "IxSystemExport.h"
#include "IThreadEvent.h"

#include "ThreadMutex.h"
#include "Condition.h"

typedef CCondition ThreadEventHandle;

#if defined(WIN32) || defined(__linux__)
	typedef CCondition ThreadEventHandle;
#elif defined VXWORKS	
#endif
/**
* @class CThreadMutex
* @brief 线程事件
* @note  模拟类似Windows的Event事件
*/
class SYSTEM_EXPORT CThreadEvent: public IThreadEvent
{
public:
	CThreadEvent();
	virtual ~CThreadEvent();

public:
	/**
	 * @fn       bool Signal()   
	 * @brief    设置为激发态          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	virtual bool Signal();

	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    等待事件为激发状态     
	 * @param    int nMilliseconds  等待的时间，以毫秒为单位          
	 * @return   bool 	成功返回true，失败返回false       
	*/
	virtual bool Wait(int nMilliseconds = -1);

	/**
	 * @fn       bool Reset()   
	 * @brief    将事件设置为非激发状态          
	 * @return   bool	 bool 成功返回true，失败返回false       
	*/
	virtual bool Reset();

	/**
	 * @fn       void TravelEvents()   
	 * @brief    遍历所有IThreadEvent       
	 * @return   void    
	*/
	virtual void TravelEvents(IThreadEventVisitor &rVistor);

	/**
	 * @fn       ThreadEventHandle& GetHandle()   
	 * @brief    获取事件句柄        
	 * @return   ThreadEventHandle&	事件句柄       
	*/
	ThreadEventHandle& GetHandle();

private:
	ThreadEventHandle m_hHandle;	///<事件句柄

};
#endif
