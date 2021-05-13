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
	 * @brief    将事件设置为非激发状态          
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

