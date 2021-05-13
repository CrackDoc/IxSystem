/**
* @file      Guard.h
* @brief     Guard
*          
* @note      �����Զ�����Acquire��Release�Ĺ���
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
* @brief �����Զ�����Acquire��Release�Ĺ���
* @note  
*/
template<typename T>
class CGuard
{
public:
	/**
	 * @fn       CGuard(T* pLock)   
	 * @brief    ���캯��
	 * @param    T * pLock   ������Ҫ����Guard�Ķ���ָ�룬���Զ�����Acquire����
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
	 * @brief     �������������Զ�����Release
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
	 * @brief    Acquire�Ƿ�ɹ�
	 * @return   bool  �ɹ�����trueʧ�ܷ���false
	*/
	bool IsAcquire()
	{
		return m_bOwner;
	}

private:
	const T* m_pLock;		///<����Ķ�������

	bool m_bOwner;	///<��¼lock�Ƿ�accquired�ɹ�
};

/**
 * @fn        GUARD(lockType,lockVar)
 * @brief	    ��סһ�δ���
 * @param     lockType   ��������
 * @param     lockVar    ������
*/
#define GUARD(lockType,lockVar)\
	CGuard<lockType> guard(&lockVar);

/**
 * @fn        GUARD_RETURN(lockType,lockVar,returnValue)
 * @brief	    ��סһ�δ��룬���������һ��ֵ
 * @param     lockType   ��������
 * @param     lockVar    ������
 * @return    returnValue    ����ʱ�ķ���ֵ
*/
#define GUARD_RETURN(lockType,lockVar,returnValue)\
	CGuard<lockType> guard(&lockVar);\
	if(guard.IsAcquire() == false)\
		return returnValue;

#endif
