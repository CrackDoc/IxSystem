/**
* @file      Guard.h
* @brief     Guard
*          
* @note      具有自动调用Acquire和Release的功能
*          
* @author    crack
* @date      2020-07-06
* @version   1.0.0.0
* @CopyRight IxLab
*/

#ifndef _GUARD_H_
#define _GUARD_H_
#include <string.h>

/**
* @class CGuard
* @brief 具有自动调用Acquire和Release的功能
* @note  
*/
template<typename T>
class CGuard
{
public:
	/**
	 * @fn       CGuard(T* pLock)   
	 * @brief    构造函数
	 * @param    T * pLock   传入需要进行Guard的对象指针，会自动调用Acquire操作
	*/
	CGuard(const T* pLock)
		:m_pLock(pLock),
		m_bOwner(false)
	{
		if(m_pLock != NULL)
		{
			if(m_pLock->Acquire() == true)
			{
				m_bOwner = true;
			}
		}
	}

	/**
	 * @fn        ~CGuard()   
	 * @brief     析构函数，会自动调用Release
	*/
	~CGuard()
	{
		if((m_bOwner == true) && (m_pLock != NULL))
		{
			m_pLock->Release();
		}
	}

	/**
	 * @fn       bool IsAcquire()   
	 * @brief    Acquire是否成功
	 * @return   bool  成功返回true失败返回false
	*/
	bool IsAcquire()
	{
		return m_bOwner;
	}

private:
	const T* m_pLock;		///<具体的对象类型

	bool m_bOwner;	///<记录lock是否accquired成功
};

/**
 * @fn        GUARD(lockType,lockVar)
 * @brief	    锁住一段代码
 * @param     lockType   锁的类型
 * @param     lockVar    锁变量
*/
#define GUARD(lockType,lockVar)\
	CGuard<lockType> guard(&lockVar);

/**
 * @fn        GUARD_RETURN(lockType,lockVar,returnValue)
 * @brief	    锁住一段代码，如果出错返回一个值
 * @param     lockType   锁的类型
 * @param     lockVar    锁变量
 * @return    returnValue    出错时的返回值
*/
#define GUARD_RETURN(lockType,lockVar,returnValue)\
	CGuard<lockType> guard(&lockVar);\
	if(guard.IsAcquire() == false)\
		return returnValue;

#endif
