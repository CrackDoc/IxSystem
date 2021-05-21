/**
* @file      ThreadEvent.h
* @brief     �߳��¼�
*          
* @note      ������windows��linux��vxworks����Ҫ������ģ��Windows�µ��¼���
*             Windows��ʹ�õ����¼���Linux��ʹ�õ�������������Vxworks��ʹ�õ��Ƕ�ֵ�ź�����
*			  ���һ���߳��ȷ��źš�����һ���߳���Wait�Ļ�������ƽ̨�¶����������ء�
*			  ���ֻ��Ҫ�ȴ�һ���¼����Ƽ�ʹ��CThreadEvent
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
* @brief �߳��¼�
* @note  ģ������Windows��Event�¼�
*/
class SYSTEM_EXPORT CThreadEvent: public IThreadEvent
{
public:
	CThreadEvent();
	virtual ~CThreadEvent();

public:
	/**
	 * @fn       bool Signal()   
	 * @brief    ����Ϊ����̬          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Signal();

	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    �ȴ��¼�Ϊ����״̬     
	 * @param    int nMilliseconds  �ȴ���ʱ�䣬�Ժ���Ϊ��λ          
	 * @return   bool 	�ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Wait(int nMilliseconds = -1);

	/**
	 * @fn       bool Reset()   
	 * @brief    ���¼�����Ϊ�Ǽ���״̬          
	 * @return   bool	 bool �ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Reset();

	/**
	 * @fn       void TravelEvents()   
	 * @brief    ��������IThreadEvent       
	 * @return   void    
	*/
	virtual void TravelEvents(IThreadEventVisitor &rVistor);

	/**
	 * @fn       ThreadEventHandle& GetHandle()   
	 * @brief    ��ȡ�¼����        
	 * @return   ThreadEventHandle&	�¼����       
	*/
	ThreadEventHandle& GetHandle();

private:
	ThreadEventHandle m_hHandle;	///<�¼����

};
#endif
