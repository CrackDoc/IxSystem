/**
* @file      Condition.h
* @brief     ��������
*          
* @note      ������windows��linux��vxworks����Ҫ������ģ��Linux�µ�����������
*			  Windows��ʹ�õ����¼���Linux��ʹ�õ�����������
*			  Vxworks��ʹ�õ��Ƕ�ֵ�ź���
*			  ��Linux�£����һ���߳��ȷ��źš�����һ���߳���Wait�Ļ��������Wait���ܷ���
*			  Windows��Vxworks�£�����ȷ��źţ���Wait���������ء�
*			  Waitʱ��Ҫ����һ���ⲿ��������windows����Waitʱ�Ὣ�����ͷŵ�����wait�ɹ����ٽ�����ȡ
*			  ���Ƽ�ֱ��ʹ��CCondition
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
* @brief ��������
* @note  ��������
*/
class SYSTEM_EXPORT CCondition
{
public:
	CCondition();
	~CCondition();

public:
	/**
	 * @fn       bool Signal()   
	 * @brief    ����Ϊ����̬        
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false     
	*/
	bool Signal();

	/**
	 * @fn       bool Wait(CThreadMutex& rThreadMutex,int nMilliseconds)   
	 * @brief    �ȴ���������Ϊ����״̬   
	 * @param    CThreadMutex & rThreadMutex  �̻߳�����     
	 * @param    int nMilliseconds  �ȴ���ʱ�䣬�Ժ���Ϊ��λ          
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false     
	*/
	bool Wait(int nMilliseconds = -1) const;

	/**
	 * @fn       ConditionHandle& GetHandle()   
	 * @brief    ��ȡ�����������       
	 * @return   ConditionHandle&	�����������       
	*/
	ConditionHandle& GetHandle() const;

	/**
	 * @fn       bool Reset()   
	 * @brief    ���¼�����Ϊ�Ǽ���״̬.windows����Ч        
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	bool Reset() const;

	/**
	 * @fn       bool GetCThreadMutex()   
	 * @brief    ���� �����ź���     
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	CThreadMutex &GetCThreadMutex() const;


protected:
	mutable ConditionHandle m_hHandle;	///<�����������
	mutable pthread_condattr_t mAttr;			//����������ֵ
	mutable CThreadMutex m_ThreadMutex;		// ������
private:
	mutable bool bConditionValue;			// ����������ֵ
};
#endif
