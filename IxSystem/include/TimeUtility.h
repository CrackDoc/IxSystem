/**
 * @file      TimeUtility.h
 * @brief     ʱ����Ϣ���ʱ����
 *          
 * @note      ������windows��linux��vxworks
 *          
 * @author    crack
 * @date      2020/06/07
 * @version   1.0.0.0
 * @CopyRight IxLab
 */
#ifndef _TIME_UTILITY_H_
#define _TIME_UTILITY_H_

#include "SystemExport.h"

#include <string>

/**
 * @class CTimeInfo
 * @brief ��װʱ����Ϣ��,�ṩ���ָ�ʽת��
 * @note   
 */
class SYSTEM_EXPORT CTimeInfo
{
public:
    CTimeInfo();

	CTimeInfo(int nYear,int nMonth,int nDay,int nHour = 0,int nMinute = 0,int nSecond = 0,int nMilliseconds = 0);

	CTimeInfo(const CTimeInfo& rParam);
	
	~CTimeInfo();

	///��ֵ����
	CTimeInfo& operator=(const CTimeInfo& rParam);
	
	/**
	 * @fn       bool operator==(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�ͱ��Ƚ�ʱ����Ϣ�Ƿ����
	 * @param    const CTimeInfo & rParam    ���Ƚϵ�ʱ����Ϣ
	 * @return   bool   ��ȷ���true��ʧ�ܷ���false
	*/
	bool operator==(const CTimeInfo& rParam) const;

	/**
	 * @fn       bool operator!=(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�ͱ��Ƚ�ʱ����Ϣ�Ƿ����
	 * @param    const CTimeInfo & rParam    ���Ƚϵ�ʱ����Ϣ
	 * @return   bool   ����ȷ���true��ʧ�ܷ���false
	*/
	bool operator!=(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�Ƿ���ڱ��Ƚ�ʱ����Ϣ
	 * @param    const CTimeInfo & rParam    ���Ƚ�ʱ����Ϣ
	 * @return   bool   ���ڷ���true�����򷵻�false
	*/
	bool operator>(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�Ƿ�С�ڱ��Ƚ�ʱ����Ϣ
	 * @param    const CTimeInfo & rParam    ���Ƚ�ʱ����Ϣ
	 * @return   bool   С�ڷ���true�����򷵻�false
	*/
	bool operator<(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�Ƿ���ڵ��ڱ��Ƚ�ʱ����Ϣ
	 * @param    const CTimeInfo & rParam    ���Ƚ�ʱ����Ϣ
	 * @return   bool   ���ڵ��ڷ���true�����򷵻�false
	*/
	bool operator>=(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    �Ƚϵ�ǰʱ����Ϣ�Ƿ�С�ڵ��ڱ��Ƚ�ʱ����Ϣ
	 * @param    const CTimeInfo & rParam    ���Ƚ�ʱ����Ϣ
	 * @return   bool   С�ڵ��ڷ���true�����򷵻�false
	*/
	bool operator<=(const CTimeInfo& rParam) const;

public:
	/**
	 * @fn       void Clear()   
	 * @brief    ����     
	 * @return   void       
	*/
	void Clear();

	/**
	 * @fn       bool IsValid() const
	 * @brief    �Ƿ�Ϊ�Ϸ�������ʱ��
	 * @return   bool  �ɹ�����true�����򷵻�false
	*/
	bool IsValid() const;
	
	/**
	 * @fn       std::string ToLongDateTimeStringWithMs() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"2000-01-01 03:01:01.123" ��������ʱ������룩     
	 * @return   std::string	 ʱ���ַ���       
	*/
	std::string ToLongDateTimeStringWithMs() const;
	
	/**
	 * @fn       bool SetLongDateTimeStringWithMs(const std::string& strDateTimeWithMs)   
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"2000-01-01 03:01:01.123" ��������ʱ������룩     
	 * @param    const std::string& strDateTimeWithMs �����ʱ���ַ���           
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetLongDateTimeStringWithMs(const std::string& strDateTimeWithMs);	
	
	/**
	 * @fn       std::string ToLongDateTimeString() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"2000-01-01 03:01:01" ��������ʱ���룩     
	 * @return   std::string	 ʱ���ַ���       
	*/
	std::string ToLongDateTimeString() const;
	
	/**
	 * @fn       bool SetLongDateTimeString(const std::string& strDateTime)   
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"2000-01-01 03:01:01" ��������ʱ���룩     
	 * @param    const std::string& strDateTime  �����ʱ���ַ���          
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetLongDateTimeString(const std::string& strDateTime);	
	
	/**
	 * @fn       std::string ToShortDateTimeString() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"20000101030101" (������ʱ����)     
	 * @return   std::string	 ʱ���ַ���       
	*/
	std::string ToShortDateTimeString() const;
	
	/**
	 * @fn       bool SetShortDateTimeString(const std::string& strDateTime)   
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"20000101030101" (������ʱ����)     
	 * @param    const std::string& strDateTime �����ʱ���ַ���          
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetShortDateTimeString(const std::string& strDateTime);
	
	/**
	 * @fn       std::string ToShortTimeString() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"010101" (ʱ����)    
	 * @return   std::string	ʱ���ַ���       
	*/
	std::string ToShortTimeString() const;
	
	/**
	 * @fn       bool SetShortTimeString(const std::string& strTime)   
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"010101" (ʱ����)     
	 * @param    const std::string& strTime �����ʱ���ַ���          
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetShortTimeString(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToLongTimeString() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"01:01:01" (ʱ����)     
	 * @return   std::string	ʱ���ַ���       
	*/
	std::string ToLongTimeString() const;
	
	/**
	 * @fn       bool SetLongTimeString(const std::string& strTime)
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"01:01:01" (ʱ����)     
	 * @param    const std::string& strTime  �����ʱ���ַ���         
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetLongTimeString(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToLongTimeStringWithMs() const
	 * @brief    ��ʱ��ת��Ϊ�ַ�������ʽΪ"01:01:01.001" (ʱ�������)     
	 * @return   std::string	ʱ���ַ���       
	*/
	std::string ToLongTimeStringWithMs() const;
	
	/**
	 * @fn       bool SetLongTimeStringWithMs(const std::string& strTime)   
	 * @brief    ���ַ�����ʽ����ʱ�䣬��ʽΪ"01:01:01.001" (ʱ�������)     
	 * @param    const std::string& strTime  �����ʱ���ַ���          
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetLongTimeStringWithMs(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToShortDateString() const
	 * @brief    ������ת��Ϊ�ַ�������ʽΪ"20000101" (������)     
	 * @return   std::string	�����ַ���       
	*/
	std::string ToShortDateString() const;
	
	/**
	 * @fn       bool SetShortDateString(const std::string& strDate)   
	 * @brief    ���ַ�����ʽ�������ڣ���ʽΪ"20000101" (������)     
	 * @param    const std::string& strDate  ����������ַ���         
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetShortDateString(const std::string& strDate);	
	
	/**
	 * @fn       unsigned int ToTimeTag() const
	 * @brief    ����0�㿪ʼ��ʱ��ת��Ϊ��������λΪ����    
	 * @return   unsigned int	 0�㿪ʼ��ʱ���ǩ       
	*/
	unsigned int ToTimeTag() const;
	
	/**
	 * @fn       bool SetTimeTag(unsigned int unTimeTag)   
	 * @brief    ����ʱ�䣬����Ϊ��0�㿪ʼ��ʱ�䣬��λΪ����     
	 * @param    unsigned int unTimeTag ��Ҫ���õ�ʱ��           
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	bool SetTimeTag(unsigned int unTimeTag);
	
	/**
	 * @fn       std::string GetYearString() const
	 * @brief    ���ַ�����ʽ������     
	 * @return   std::string	��       
	*/
	std::string GetYearString() const;
	
	/**
	 * @fn       std::string GetMonthString() const
	 * @brief    ���ַ�����ʽ������     
	 * @return   std::string	��       
	*/
	std::string GetMonthString() const;
	
	/**
	 * @fn       std::string GetDayString() const
	 * @brief    ���ַ�����ʽ������     
	 * @return   std::string	��       
	*/
	std::string GetDayString() const;
	
	/**
	 * @fn       std::string GetHourString() const
	 * @brief    ���ַ�����ʽ����ʱ     
	 * @param      ʱ 
	 * @return   std::string	ʱ       
	*/
	std::string GetHourString() const;
	
	/**
	 * @fn       std::string GetMinuteString() const
	 * @brief    ���ַ�����ʽ���ط�     
	 * @return   std::string	��       
	*/
	std::string GetMinuteString() const;
	
	/**
	 * @fn       std::string GetSecondString() const
	 * @brief    ���ַ�����ʽ������     
	 * @return   std::string	��       
	*/
	std::string GetSecondString() const;
	
	/**
	 * @fn       std::string GetMSecondString() const
	 * @brief    ���ַ�����ʽ���غ���     
	 * @return   std::string	����       
	*/
	std::string GetMSecondString() const;
	
	/**
	 * @fn       int GetYear() const
	 * @brief    ��ȡ��
	 * @return   int  ��
	*/
	int GetYear() const;

	/**
	 * @fn       int GetMonth() const
	 * @brief    ��ȡ��
	 * @return   int  ��
	*/
	int GetMonth() const;

	/**
	 * @fn       int GetDay() const
	 * @brief    ��ȡ��
	 * @return   int  ��
	*/
	int GetDay() const;

	/**
	 * @fn       int GetHour() const
	 * @brief    ��ȡСʱ
	 * @return   int  Сʱ
	*/
	int GetHour() const;

	/**
	 * @fn       int GetMinute() const
	 * @brief    ��ȡ��
	 * @return   int  ��
	*/
	int GetMinute() const;

	/**
	 * @fn       int GetSecond() const
	 * @brief    ��ȡ��
	 * @return   int  ��
	*/
	int GetSecond() const;

	/**
	 * @fn       int GetMilliseconds() const
	 * @brief    ��ȡ����
	 * @return   int  ����
	*/
	int GetMilliseconds() const;

	/**
	 * @fn       void SetYear(int nYear)
	 * @brief    ������
	 * @param    int nYear  ��
	 * @return   void  
	*/
	void SetYear(int nYear);

	/**
	 * @fn       void SetMonth(int nMonth)
	 * @brief    ������
	 * @param    int nMonth  ��
	 * @return   void  
	*/
	void SetMonth(int nMonth);

	/**
	 * @fn       void SetDay(int nDay)
	 * @brief    ������
	 * @param    int nDay  ��
	 * @return   void  
	*/
	void SetDay(int nDay);

	/**
	 * @fn       void SetHour(int nHour)
	 * @brief    ��ȡСʱ
	 * @param    int nHour  Сʱ
	 * @return   void  
	*/
	void SetHour(int nHour);

	/**
	 * @fn       void SetMinute(int nMinute)
	 * @brief    ���÷�
	 * @param    int nMinute  ��
	 * @return   void  
	*/
	void SetMinute(int nMinute);

	/**
	 * @fn       void SetSecond(int nSecond)
	 * @brief    ������
	 * @param    int nSecond  ��
	 * @return   void  
	*/
	void SetSecond(int nSecond);
	
	/**
	 * @fn       void SetMilliseconds(int nMilliseconds)
	 * @brief    ���ú���
	 * @param    int nMilliseconds  ����
	 * @return   void  
	*/
	void SetMilliseconds(int nMilliseconds);

	/**
	 * @fn       void SetDateTime(int nYear,int nMonth,int nDay,int nHour,int nMinute,int nSecond,int nMilliseconds)
	 * @brief    ��������ʱ��
	 * @param    int nYear  ��
	 * @param    int nMonth  ��
	 * @param    int nDay  ��
	 * @param    int nHour  Сʱ
	 * @param    int nMinute  ����
	 * @param    int nSecond  ��
	 * @param    int nMilliseconds  ����
	 * @return   void  
	*/
	void SetDateTime(int nYear,int nMonth,int nDay,int nHour = 0,int nMinute = 0,int nSecond = 0,int nMilliseconds = 0);

	/**
	 * @fn       void SetTime(int nHour,int nMinute,int nSecond,int nMilliseconds)
	 * @brief    ����ʱ��
	 * @param    int nHour  Сʱ
	 * @param    int nMinute  ����
	 * @param    int nSecond  ��
	 * @param    int nMilliseconds  ����
	 * @return   void  
	*/
	void SetTime(int nHour,int nMinute,int nSecond,int nMilliseconds);

	/**
	 * @fn       unsigned int GetJdDays() const
	 * @brief    ��ȡ����������
	 * @return   unsigned int  ����������
	*/
	unsigned int GetJdDays() const;

	/**
	 * @fn       unsigned int GetMjdDays() const
	 * @brief    ��ȡ������������
	 * @return   unsigned int  ������������
	*/
	unsigned int GetMjdDays() const;

	/**
	 * @fn       void SetJdDays(unsigned int unJdDays)
	 * @brief    ��������������
	 * @param    unsigned int unJdDays  ����������
	 * @return   void  
	*/
	void SetJdDays(unsigned int unJdDays);

	/**
	 * @fn       void SetMjdDays(unsigned int unMjdDays)
	 * @brief    ���ü�����������
	 * @param    unsigned int unMjdDays  ������������
	 * @return   void  
	*/
	void SetMjdDays(unsigned int unMjdDays);

	/**
	 * @fn       int DaysTo(const CTimeInfo& rTimeInfo) const
	 * @brief    ��������ʱ������ڲ�ֵrTimeInfo - *this������ʱ��������ڣ�ֻ��������
	 * @param    const CTimeInfo & rTimeInfo  �������ʱ��
	 * @return   int  ������ֵ
	*/
	int DaysTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       int64_t SecondsTo(const CTimeInfo& rTimeInfo)
	 * @brief    ��������ʱ������ֵrTimeInfo - *this�������ڼ�������
	 * @param    const CTimeInfo & rTimeInfo  �������ʱ��
	 * @return   int64_t  ���ֵ
	*/
	int64_t SecondsTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       int64_t MillisecondsTo(const CTimeInfo& rTimeInfo) const
	 * @brief    ��������ʱ��ĺ����ֵrTimeInfo - *this�������ڼ�������
	 * @param    const CTimeInfo & rTimeInfo  �������ʱ��
	 * @return   int64_t  �����ֵ
	*/
	int64_t MillisecondsTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       CTimeInfo AddYears(int nYears) const
	 * @brief    �ڸ�ʱ��Ļ������������������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nYears  ��ӵ�����
	 * @return   CTimeInfo  ����������ʱ��
	*/
	CTimeInfo AddYears(int nYears) const;

	/**
	 * @fn       CTimeInfo AddMonths(int nMonths) const
	 * @brief    �ڸ�ʱ��Ļ������������������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nMonths  ��ӵ�����
	 * @return   CTimeInfo  ����������ʱ��
	*/
	CTimeInfo AddMonths(int nMonths) const;

	/**
	 * @fn       CTimeInfo AddDays(int nDays) const
	 * @brief    �ڸ�ʱ��Ļ������������������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nDays  ��ӵ�����
	 * @return   CTimeInfo  ����������ʱ��
	*/
	CTimeInfo AddDays(int nDays) const;

	/**
	 * @fn       CTimeInfo AddHours(int nHours) const
	 * @brief    ���Сʱ������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nHours  ��ӵ�Сʱ��
	 * @return   CTimeInfo  ���Сʱ�����ʱ��
	*/
	CTimeInfo AddHours(int nHours) const;

	/**
	 * @fn       CTimeInfo AddMinutes(int nMinutes) const
	 * @brief    ��ӷ�����������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nMinutes  ��ӵķ�����
	 * @return   CTimeInfo  ��ӷ��������ʱ��
	*/
	CTimeInfo AddMinutes(int nMinutes) const;

	/**
	 * @fn       CTimeInfo AddSeconds(int nSeconds) const
	 * @brief    �������������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int nSeconds  ��ӵ�����
	 * @return   CTimeInfo  ����������ʱ��
	*/
	CTimeInfo AddSeconds(int nSeconds) const;

	/**
	 * @fn       CTimeInfo AddSeconds(int64_t nSeconds) const
	 * @brief    �������������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int64_t nSeconds  ��ӵ�����
	 * @return   CTimeInfo  ����������ʱ��
	*/
	CTimeInfo AddSeconds(int64_t nSeconds) const;

	/**
	 * @fn       CTimeInfo AddMilliseconds(int64_t nMilliseconds) const
	 * @brief    ��Ӻ�����������Ϊ��ֵ�����ı������ֵ�������µ�ʱ��
	 * @param    int64_t nMilliseconds   ��ӵĺ�����
	 * @return   CTimeInfo  ��Ӻ��������ʱ��
	*/
	CTimeInfo AddMilliseconds(int64_t nMilliseconds) const;

	/**
	 * @fn       int64_t GetKeyMilliseconds(CTimeInfo* pBaseTimeInfo) const
	 * @brief    ��ȡ�Ի�׼ֵʱ��Ϊ��׼�ĺ�����
	 * @param    CTimeInfo * pBaseTimeInfo  ��׼ʱ��
	 * @return   int64_t  �Ի�׼ֵʱ��Ϊ��׼�ĺ���������ǰʱ��-rBaseTimeInfo�ĺ�������
	*/
	int64_t GetBaseTimeMilliseconds(CTimeInfo* pBaseTimeInfo = NULL) const;

	/**
	 * @fn       bool SetBaseTimeMilliseconds(int64_t nMilliseconds,CTimeInfo* pBaseTimeInfo)
	 * @brief    �����Ի�׼ֵʱ��Ϊ��׼�ĺ�����
	 * @param    int64_t nMilliseconds  �Ի�׼ֵʱ��Ϊ��׼�ĺ���������ǰʱ��-rBaseTimeInfo�ĺ�������
	 * @param    CTimeInfo * pBaseTimeInfo  ��׼ʱ��
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	bool SetBaseTimeMilliseconds(int64_t nMilliseconds,CTimeInfo* pBaseTimeInfo = NULL);

private:
	int m_nYear;		///<��
	int m_nMonth;		///<��
	int m_nDay;			///<��
	int m_nHour;		///<ʱ
	int m_nMinute;		///<��
	int m_nSecond;		///<��
	int m_nMilliseconds;///<����
};

/**
 * @class CTimeUtility
 * @brief ��װʱ�乤����,��ȡ������ʱ��
 * @note   
 */
typedef void (* ExternTimeFunc)(const CTimeInfo& rTimeInfo);
class SYSTEM_EXPORT CTimeUtility
{
public:
	CTimeUtility();
	~CTimeUtility();

	/**
	 * @fn       static CTimeInfo GetCurrentTimeInfo()   
	 * @brief    ��ȡ��ǰʱ��     
	 * @return   CTimeInfo  ��ǰʱ�䣬��ʽΪCTimeInfo�Ľṹ��       
	*/
	static CTimeInfo GetCurrentTimeInfo();	
	
	/**
	 * @fn       static unsigned int GetTimeTag()   
	 * @brief    ��ȡ��0�㿪ʼ��ʱ�䣬��λΪ����     
	 * @return   unsigned int	 ��0�㿪ʼ��ʱ��       
	*/
	static unsigned int GetTimeTag();
	
	/**
	 * @fn       static uint64_t GetHighResTimeTag()   
	 * @brief    ���غ��뼶��ʱ�����������һ�ε���ʱ����0���Ժ���÷��ؾ����ĺ�����     
	 * @return   uint64_t	 ʱ��������λ����       
	*/
	static uint64_t GetHighResTimeTag();

	/**
	 * @fn       uint64_t GetOsTickTimeTag()
	 * @brief    ����OS������������ĺ�����
	 * @return   uint64_t  ����������ĺ�����
	*/
	static uint64_t GetOsTickTimeTag();
	
	/**
	 * @fn       static bool SetSystemTime(const CTimeInfo& rTimeInfo)   
	 * @brief    ����ϵͳ��ʱ��     
	 * @param    CTimeInfo & rTimeInfo  ��Ҫ���õ�ʱ��         
	 * @return   bool	 true:���óɹ�;false:����ʧ��       
	*/
	static bool SetSystemTime(const CTimeInfo& rTimeInfo);
	
	/**
	 * @fn       static int64_t GetDifferentTime(const CTimeInfo& rEndTime, const CTimeInfo& rStartTime)   
	 * @brief    �Ƚ�ʱ��rEndTime - rStartTime     
	 * @param    CTimeInfo & rEndTime  ����ʱ��     
	 * @param    CTimeInfo & rStartTime  ��ʼʱ��         
	 * @return   int64_t	ʱ����λ����       
	*/
	static int64_t GetDifferentTime(const CTimeInfo& rEndTime, const CTimeInfo& rStartTime);
	
	/**
	 * @fn       static int GetMillisecondsPassed(unsigned int unEndTime, unsigned int unStartTime)   
	 * @brief    �Ƚ�ʱ��unEndTime - unStartTime     
	 * @param    unsigned int unEndTime  ����ʱ�䣻��λΪ����     
	 * @param    unsigned int unStartTime  ��ʼʱ��  ��λΪ����         
	 * @return   int	ʱ����λ����     
	*/
	static int GetMillisecondsPassed(unsigned int unEndTime, unsigned int unStartTime);
	
	/**
	 * @fn       static void SetExternTimeFunc(ExternTimeFunc pGetExternTime, ExternTimeFunc pSetExternTime)   
	 * @brief    �����ⲿʱ�������ڻ�ȡ�Ľӿ�     
	 * @param    ExternTimeFunc pGetExternTime  �ⲿʱ���ȡ����ָ��     
	 * @param    ExternTimeFunc pSetExternTime  �ⲿʱ�����ú���ָ��          
	 * @return   void       
	*/
	static void SetExternTimeFunc(ExternTimeFunc pGetExternTime, ExternTimeFunc pSetExternTime);
	
	/**
	 * @fn       void Sleep(unsigned int unMilliseconds)   
	 * @brief    Sleep˯��     
	 * @param    unsigned int unMilliseconds ˯��ʱ���Ժ���Ϊ��λ           
	 * @return   void       
	*/
	static void Sleep(unsigned int unMilliseconds);
	
	/**
	 * @fn       void Sleep(const CTimeInfo& rTimeInfo)   
	 * @brief    Sleep˯��     
	 * @param    CTimeInfo & rTimeInfo ˯��ʱ��        
	 * @return   void       
	*/
	static void Sleep(const CTimeInfo& rTimeInfo);

private:
	static ExternTimeFunc ms_pGetExternTimeFunc;	///<�ⲿʱ���ȡ����ָ��
	static ExternTimeFunc ms_pSetExternTimeFunc;	///<�ⲿʱ�����ú���ָ��
};

/**
 * @class CTimeAlgorithm
 * @brief ��װʱ����ص��㷨
 * @note   
 */
class SYSTEM_EXPORT CTimeAlgorithm
{
public:
	/**
	 * @fn           bool IsLeapYear(int nYear)   
	 * @brief        �ж����Ƿ�Ϊ����
	 * @param        int nYear   ��
	 * @return       bool   Ϊ���귵��true�����򷵻�false
	*/
	static bool IsLeapYear(int nYear);

	/**
	 * @fn           int GetMonthDays(int nYear, int nMonth)   
	 * @brief        ��ȡĳ��ĳ���м���
	 * @param        int nYear    ��
	 * @param        int nMonth   ��
	 * @return       int   �м���
	*/
	static int GetMonthDays(int nYear, int nMonth);

	/**
	 * @fn       unsigned int GetJdDays(int nYear,int nMonth,int nDay)
	 * @brief    ����ָ�������վ��������յ���������������Ľ����Matlab��juliandate��������һ�£����Ǳ����0.5��
	 * @param    int nYear  ��
	 * @param    int nMonth  ��
	 * @param    int nDay  ��
	 * @return   unsigned int  �������յ�����
	*/
	static unsigned int GetJdDays(int nYear,int nMonth,int nDay);
	
	/**
	 * @fn       unsigned int GetMjdDays(int nYear,int nMonth,int nDay)
	 * @brief    ��������������λ��̫�࣬��������ѧ���ϻ���1973����ü������գ�MJD���䶨��ΪMJD = JD - 2400000.5��MJD��Ӧ�������1858��11��17������ʱ0ʱ
	 * @param    int nYear  ��
	 * @param    int nMonth  ��
	 * @param    int nDay  ��
	 * @return   unsigned int  ������������
	*/
	static unsigned int GetMjdDays(int nYear,int nMonth,int nDay);

	/**
	 * @fn       void GetDateFromJd(unsigned int unJds,int& nYear,int& nMonth,int& nDay)
	 * @brief    ����������������ȡ��Ӧ��������
	 * @param    unsigned int unJds  ����������
	 * @param    int & nYear  ת�������
	 * @param    int & nMonth  ת�������
	 * @param    int & nDay  ת�������
	 * @return   void  
	*/
	static void GetDateFromJd(unsigned int unJds,int& nYear,int& nMonth,int& nDay);

	/**
	 * @fn       void GetDateFromMjd(unsigned int unMjds,int& nYear,int& nMonth,int& nDay)
	 * @brief    ���ݼ�������������ȡ��Ӧ��������
	 * @param    unsigned int unMjds  ������������
	 * @param    int & nYear  ת�������
	 * @param    int & nMonth  ת�������
	 * @param    int & nDay  ת�������
	 * @return   void  
	*/
	static void GetDateFromMjd(unsigned int unMjds,int& nYear,int& nMonth,int& nDay);
};

#endif
