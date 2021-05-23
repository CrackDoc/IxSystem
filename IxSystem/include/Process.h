/**
* @file      Process.h
* @brief     ��ƽ̨���̷�װ
*          
* @note      ������windows��linux��vxworks
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
* @brief ��ƽ̨���̷�װ
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
	 * @brief ͨ����������ɱ������  
	 * @param const std::string & strProcessName: 
	 * @return bool
	 */
	static bool KillProcess(const char * strProcessName);

	/**
	 * @fn  KillProcess        
	 * @brief ͨ����������ɱ������  
	 * @param const int nProcessID
	 * @return bool
	 */
	static bool KillProcess(int nProcessID);

public:
	/**
	 * @fn       void SetWorkingDir(const std::string& strWorkingDir)   
	 * @brief    ���ÿ������̵Ĺ���Ŀ¼   
	 * @param    const std::string& strWorkingDir  ����Ŀ¼          
	 * @return   void       
	*/
	void SetWorkingDir(const char * strWorkingDir);

	/**
	 * @fn       bool Create(const std::string& strFilePath, const std::string& strParam)   
	 * @brief    ��������   
	 * @param    const std::string& strFilePath  �ļ���·��     
	 * @param    const std::string& strParam   ���̵�����������Կո�ָͬ�Ĳ���        
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	// ���ִ��CMD �����������Ļ�  strFilePath =    GetSystemDirectory(szPath, sizeof(szPath))+"/cmd.exe"  strParam = /c c:\\batch.dat
	bool Create(const char* strFilePath, const char* strParam = "", int nShowCMD = -1);

	/**
	 * @fn  Wait        
	 * @brief �ȴ�  
	 * @param int nMilliSecond: 
	 * @return bool
	 */
	bool Wait(int nMilliSecond = -1);

	/**
	 * @fn       bool Terminate()   
	 * @brief    ��������       
	 * @return   bool	�ɹ�����true��ʧ�ܷ���false       
	*/
	bool Terminate();

	/**
	 * @fn       int GetProcessId()   
	 * @brief    ��ȡ���̵�ID        
	 * @return   int	���̵�ID       
	*/
	int GetProcessId();

	/**
	 * @fn       int GetMainThreadId()   
	 * @brief    ��ȡ�������̵߳�ID        
	 * @return   int	�������̵߳�ID       
	*/
	int GetMainThreadId();

private:
#ifndef WIN32
	///<�ͷŶ�̬�����arg����
	void ReleaseArgv();
#endif

private:
	char m_WorkDirBuf[256];
	//std::string m_strWorkingDir;	///<���̹���·��

#ifdef WIN32
	//PROCESS_INFORMATION m_ProcessInfo;	///<������Ϣ
	//STARTUPINFO m_ProStartuoInfo;

	void* m_ProcessInfo;
	void* m_ProStartuoInfo;
#elif defined __linux__
	char* m_pArgv[100];	///<agv����
	int m_nProcessId;	///<����ID
#elif defined VXWORKS
	int m_nProcessId;	///<����ID

	int m_nArgc;	///<agc����

	char* m_pArgv[100];		///<agv����

	FUNCPTR m_pEntryFun;	///<��ں�����ַ

	FUNCPTR m_pQuitFunc;	///<�˳�������ַ

	CLibrary m_Library;		///<��̬����ض���

	CThreadEvent m_WaitTask;	///<�ȴ������˳����¼�
#endif
};
#endif
