#ifndef TaskSemaphore_h__
#define TaskSemaphore_h__
#include "IThreadEvent.h"

#if defined(WIN32) || defined(__linux__)
#include "semaphore.h"
typedef sem_t SemaphoreHandle;
#elif defined VXWORKS	
#endif

class CTaskSemaphore : public IThreadEvent
{
public:
	CTaskSemaphore();
	~CTaskSemaphore();

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
	 * @brief    ���¼�����Ϊ�Ǽ���״̬          
	 * @return   void    
	*/
	virtual void TravelEvents(IThreadEventVisitor &rVistor);
public:
	/**
	 * @fn       int GetSemaphoreValue()   
	 * @brief             
	 * @return   int    
	*/
	int GetSemaphoreValue(); 

private:
	SemaphoreHandle m_hHandle;
};
#endif // TaskSemaphore_h__

