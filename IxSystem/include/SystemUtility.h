#ifndef _CSYSTEMUTILITY_H_
#define _CSYSTEMUTILITY_H_
#include "IxSystemExport.h"
#include "SystemConfig.h"
#include<iostream>
#include<sstream>

#if defined WIN32
#include "pthread.h"
#include <windows.h>
#define sleep(sec)   Sleep(sec * 1000)
#define msleep(msec) Sleep(msec)
#pragma warning(disable: 4996) // avoid GetVersionEx to be warned  
#elif defined __linux__
#include <unistd.h>
#include <sys/stat.h> 　
#include <sys/types.h>
#include <sys/time.h>
#include "pthread.h"
#define msleep(msec) usleep(msec * 1000)
#elif defined VXWORKS
#endif



#define  MBYTES  1048576  

#if defined WIN32
/**
	* @fn       void gettimeofday(struct timeval* tp, void* tz)   
	* @brief    获取系统时间  以1900 1月
	* @param    struct timeval* tp, void* tz        
	* @return   int       
*/
extern SYSTEM_EXPORT int gettimeofday(struct timeval* tp, void* tz);
/**
	* @fn       void usleep(u_int64 usec)  微秒
	* @brief    延时时间
	* @param    unsigned long usec   
	* @return   NULL      
*/
extern SYSTEM_EXPORT void usleep(int64_t usec);

#endif

/**
	* @fn       timespec ConvertMilliSeconds(int nMilliseconds)   
	* @brief    将相对时间转化为绝对时间 1970 7月1日开始
	* @param    int nMilliseconds       
	* @return   timespec       
*/
extern SYSTEM_EXPORT timespec ConvertMilliSeconds(int nMilliseconds);

/**
	* @fn       u_int64 ConvertTimevalSeconds(timeval* tp))   
	* @brief    将 timeval 转化为 seconds 
	* @param    timeval* tp      
	* @return   u_int64       
*/
extern SYSTEM_EXPORT u_int64 ConvertTimevalSeconds(timeval* tp);

/**
	* @fn       u_int64 ConvertTimevalMilliSeconds(timeval* tp))   
	* @brief    将 timeval 转化为 毫秒 
	* @param    timeval* tp      
	* @return   u_int64       
*/

extern SYSTEM_EXPORT u_int64 ConvertTimevalMilliSeconds(timeval* tp);

/**
	* @fn       u_int64 ConvertTimevalusSeconds(timeval* tp)   
	* @brief    将 timeval 转化为 微秒 
	* @param    timeval* tp      
	* @return   u_int64       
*/

extern SYSTEM_EXPORT u_int64 ConvertTimevalUsSeconds(timeval* tp);

/**
	* @fn       u_int64 GetCurrentTimeUsSeconds()   
	* @brief    获取当前时间的微妙数
	* @param    NULL    
	* @return   u_int64       
*/
extern SYSTEM_EXPORT u_int64 GetCurrentTimeUsSeconds();

/**
	* @fn       u_int64 GetCurrentTimeMsSeconds()   
	* @brief    获取当前时间的毫秒数
	* @param        
	* @return   u_int64       
*/
extern SYSTEM_EXPORT u_int64 GetCurrentTimeMsSeconds();

/**
	* @fn       u_int64 GetCurrentTimeSeconds()   
	* @brief    获取当前时间的毫秒数
	* @param    timeval* tp      
	* @return   u_int64       
*/
extern SYSTEM_EXPORT u_int64 GetCurrentTimeSeconds();
#endif
