#ifndef IThreadEvent_h__
#define IThreadEvent_h__

#include "SystemExport.h"

class SYSTEM_EXPORT IThreadEvent
{
public:
	class IThreadEventVisitor
	{
	public:
		virtual ~IThreadEventVisitor(){}
		virtual void AppendEvent(IThreadEvent *pIThreadEvent) = 0;
	};
public:
	virtual ~IThreadEvent(){}

	/**
	 * @fn       bool Signal()   
	 * @brief    ����Ϊ����̬          
	 * @return   bool	 �ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Signal() = 0;

	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    �ȴ��¼�Ϊ����״̬     
	 * @param    int nMilliseconds  �ȴ���ʱ�䣬�Ժ���Ϊ��λ          
	 * @return   bool 	�ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Wait(int nMilliseconds = -1) = 0;

	/**
	 * @fn       bool Reset()   
	 * @brief    ���¼�����Ϊ�Ǽ���״̬          
	 * @return   bool	 bool �ɹ�����true��ʧ�ܷ���false       
	*/
	virtual bool Reset() = 0;
	/**
	 * @fn       void TravelEvents()   
	 * @brief    ���¼�����Ϊ�Ǽ���״̬          
	 * @return   void    
	*/
	virtual void TravelEvents(IThreadEventVisitor &rVistor) = 0;

};

#endif // IThreadEvent_h__
