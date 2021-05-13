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
	 * @brief    设置为激发态          
	 * @return   bool	 成功返回true，失败返回false       
	*/
	virtual bool Signal() = 0;

	/**
	 * @fn       bool Wait(int nMilliseconds)   
	 * @brief    等待事件为激发状态     
	 * @param    int nMilliseconds  等待的时间，以毫秒为单位          
	 * @return   bool 	成功返回true，失败返回false       
	*/
	virtual bool Wait(int nMilliseconds = -1) = 0;

	/**
	 * @fn       bool Reset()   
	 * @brief    将事件设置为非激发状态          
	 * @return   bool	 bool 成功返回true，失败返回false       
	*/
	virtual bool Reset() = 0;
	/**
	 * @fn       void TravelEvents()   
	 * @brief    将事件设置为非激发状态          
	 * @return   void    
	*/
	virtual void TravelEvents(IThreadEventVisitor &rVistor) = 0;

};

#endif // IThreadEvent_h__
