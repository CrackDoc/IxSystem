/**
* @file      Process.h
* @brief     跨平台进程封装
*          
* @note      适用于windows、linux、vxworks
*          
* @author    crack
* @date      2020-06-07
* @version   1.0.0.0
* @CopyRight IxLab
*/
#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "IxSystemExport.h"
/**
* @class CProcess
* @brief 跨平台进程封装
* @note  
*/
class SYSTEM_EXPORT CProcess
{
#ifdef VXWORKS
	friend void ProcessProc(void* lpParameter);
#endif

public:
	CProcess();
	~CProcess();

	/**
	 * @fn  KillProcess        
	 * @brief 通过进程名称杀掉进程  
	 * @param const std::string & strProcessName: 
	 * @return bool
	 */
	static bool KillProcess(const char * strProcessName);

	/**
	 * @fn  KillProcess        
	 * @brief 通过进程名称杀掉进程  
	 * @param const int nProcessID
	 * @return bool
	 */
	static bool KillProcess(int nProcessID);

public:
	/**
	 * @fn       void SetWorkingDir(const std::string& strWorkingDir)   
	 * @brief    设置开启进程的工作目录   
	 * @param    const std::string& strWorkingDir  工作目录          
	 * @return   void       
	*/
	void SetWorkingDir(const char * strWorkingDir);

	/**
	 * @fn       bool Create(const std::string& strFilePath, const std::string& strParam)   
	 * @brief    创建进程   
	 * @param    const std::string& strFilePath  文件的路径     
	 * @param    const std::string& strParam   进程的输入参数，以空格分割不同的参数        
	 * @return   bool	成功返回true，失败返回false       
	*/
	// 如果执行CMD 批处理命名的话  strFilePath =    GetSystemDirectory(szPath, sizeof(szPath))+"/cmd.exe"  strParam = /c c:\\batch.dat
	bool Create(const char* strFilePath, const char* strParam = "", int nShowCMD = -1);

	/**
	 * @fn  Wait        
	 * @brief 等待  
	 * @param int nMilliSecond: 
	 * @return bool
	 */
	bool Wait(int nMilliSecond = -1);

	/**
	 * @fn       bool Terminate()   
	 * @brief    结束进程       
	 * @return   bool	成功返回true，失败返回false       
	*/
	bool Terminate();

	/**
	 * @fn       int GetProcessId()   
	 * @brief    获取进程的ID        
	 * @return   int	进程的ID       
	*/
	int GetProcessId();

	/**
	 * @fn       int GetMainThreadId()   
	 * @brief    获取进程主线程的ID        
	 * @return   int	进程主线程的ID       
	*/
	int GetMainThreadId();

private:
#ifndef WIN32
	///<释放动态分配的arg数组
	void ReleaseArgv();
#endif

private:
	char m_WorkDirBuf[256];
	//std::string m_strWorkingDir;	///<进程工作路径

#ifdef WIN32
	//PROCESS_INFORMATION m_ProcessInfo;	///<进程信息
	//STARTUPINFO m_ProStartuoInfo;

	void* m_ProcessInfo;
	void* m_ProStartuoInfo;
#elif defined __linux__
	char* m_pArgv[100];	///<agv参数
	int m_nProcessId;	///<进程ID
#elif defined VXWORKS
	int m_nProcessId;	///<进程ID

	int m_nArgc;	///<agc参数

	char* m_pArgv[100];		///<agv参数

	FUNCPTR m_pEntryFun;	///<入口函数地址

	FUNCPTR m_pQuitFunc;	///<退出函数地址

	CLibrary m_Library;		///<动态库加载对象

	CThreadEvent m_WaitTask;	///<等待任务退出的事件
#endif
};
#endif
