/**
 * @file      TimeUtility.h
 * @brief     时间信息类和时间类
 *          
 * @note      适用于windows、linux、vxworks
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
 * @brief 封装时间信息类,提供各种格式转换
 * @note   
 */
class SYSTEM_EXPORT CTimeInfo
{
public:
    CTimeInfo();

	CTimeInfo(int nYear,int nMonth,int nDay,int nHour = 0,int nMinute = 0,int nSecond = 0,int nMilliseconds = 0);

	CTimeInfo(const CTimeInfo& rParam);
	
	~CTimeInfo();

	///赋值函数
	CTimeInfo& operator=(const CTimeInfo& rParam);
	
	/**
	 * @fn       bool operator==(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息和被比较时间信息是否相等
	 * @param    const CTimeInfo & rParam    被比较的时间信息
	 * @return   bool   相等返回true，失败返回false
	*/
	bool operator==(const CTimeInfo& rParam) const;

	/**
	 * @fn       bool operator!=(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息和被比较时间信息是否不相等
	 * @param    const CTimeInfo & rParam    被比较的时间信息
	 * @return   bool   不相等返回true，失败返回false
	*/
	bool operator!=(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息是否大于被比较时间信息
	 * @param    const CTimeInfo & rParam    被比较时间信息
	 * @return   bool   大于返回true，否则返回false
	*/
	bool operator>(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息是否小于被比较时间信息
	 * @param    const CTimeInfo & rParam    被比较时间信息
	 * @return   bool   小于返回true，否则返回false
	*/
	bool operator<(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息是否大于等于被比较时间信息
	 * @param    const CTimeInfo & rParam    被比较时间信息
	 * @return   bool   大于等于返回true，否则返回false
	*/
	bool operator>=(const CTimeInfo& rParam) const;
	
	/**
	 * @fn       bool operator>(const CTimeInfo& rParam) const
	 * @brief    比较当前时间信息是否小于等于被比较时间信息
	 * @param    const CTimeInfo & rParam    被比较时间信息
	 * @return   bool   小于等于返回true，否则返回false
	*/
	bool operator<=(const CTimeInfo& rParam) const;

public:
	/**
	 * @fn       void Clear()   
	 * @brief    清零     
	 * @return   void       
	*/
	void Clear();

	/**
	 * @fn       bool IsValid() const
	 * @brief    是否为合法的日期时间
	 * @return   bool  成功返回true，否则返回false
	*/
	bool IsValid() const;
	
	/**
	 * @fn       std::string ToLongDateTimeStringWithMs() const
	 * @brief    将时间转换为字符串，格式为"2000-01-01 03:01:01.123" （年月日时分秒毫秒）     
	 * @return   std::string	 时间字符串       
	*/
	std::string ToLongDateTimeStringWithMs() const;
	
	/**
	 * @fn       bool SetLongDateTimeStringWithMs(const std::string& strDateTimeWithMs)   
	 * @brief    以字符串格式设置时间，格式为"2000-01-01 03:01:01.123" （年月日时分秒毫秒）     
	 * @param    const std::string& strDateTimeWithMs 输入的时间字符串           
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetLongDateTimeStringWithMs(const std::string& strDateTimeWithMs);	
	
	/**
	 * @fn       std::string ToLongDateTimeString() const
	 * @brief    将时间转换为字符串，格式为"2000-01-01 03:01:01" （年月日时分秒）     
	 * @return   std::string	 时间字符串       
	*/
	std::string ToLongDateTimeString() const;
	
	/**
	 * @fn       bool SetLongDateTimeString(const std::string& strDateTime)   
	 * @brief    以字符串格式设置时间，格式为"2000-01-01 03:01:01" （年月日时分秒）     
	 * @param    const std::string& strDateTime  输入的时间字符串          
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetLongDateTimeString(const std::string& strDateTime);	
	
	/**
	 * @fn       std::string ToShortDateTimeString() const
	 * @brief    将时间转换为字符串，格式为"20000101030101" (年月日时分秒)     
	 * @return   std::string	 时间字符串       
	*/
	std::string ToShortDateTimeString() const;
	
	/**
	 * @fn       bool SetShortDateTimeString(const std::string& strDateTime)   
	 * @brief    以字符串格式设置时间，格式为"20000101030101" (年月日时分秒)     
	 * @param    const std::string& strDateTime 输入的时间字符串          
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetShortDateTimeString(const std::string& strDateTime);
	
	/**
	 * @fn       std::string ToShortTimeString() const
	 * @brief    将时间转换为字符串，格式为"010101" (时分秒)    
	 * @return   std::string	时间字符串       
	*/
	std::string ToShortTimeString() const;
	
	/**
	 * @fn       bool SetShortTimeString(const std::string& strTime)   
	 * @brief    以字符串格式设置时间，格式为"010101" (时分秒)     
	 * @param    const std::string& strTime 输入的时间字符串          
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetShortTimeString(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToLongTimeString() const
	 * @brief    将时间转换为字符串，格式为"01:01:01" (时分秒)     
	 * @return   std::string	时间字符串       
	*/
	std::string ToLongTimeString() const;
	
	/**
	 * @fn       bool SetLongTimeString(const std::string& strTime)
	 * @brief    以字符串格式设置时间，格式为"01:01:01" (时分秒)     
	 * @param    const std::string& strTime  输入的时间字符串         
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetLongTimeString(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToLongTimeStringWithMs() const
	 * @brief    将时间转换为字符串，格式为"01:01:01.001" (时分秒毫秒)     
	 * @return   std::string	时间字符串       
	*/
	std::string ToLongTimeStringWithMs() const;
	
	/**
	 * @fn       bool SetLongTimeStringWithMs(const std::string& strTime)   
	 * @brief    以字符串格式设置时间，格式为"01:01:01.001" (时分秒毫秒)     
	 * @param    const std::string& strTime  输入的时间字符串          
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetLongTimeStringWithMs(const std::string& strTime);	
	
	/**
	 * @fn       std::string ToShortDateString() const
	 * @brief    将日期转换为字符串，格式为"20000101" (年月日)     
	 * @return   std::string	日期字符串       
	*/
	std::string ToShortDateString() const;
	
	/**
	 * @fn       bool SetShortDateString(const std::string& strDate)   
	 * @brief    以字符串格式设置日期，格式为"20000101" (年月日)     
	 * @param    const std::string& strDate  输入的日期字符串         
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetShortDateString(const std::string& strDate);	
	
	/**
	 * @fn       unsigned int ToTimeTag() const
	 * @brief    将从0点开始的时间转换为整数，单位为毫秒    
	 * @return   unsigned int	 0点开始的时间标签       
	*/
	unsigned int ToTimeTag() const;
	
	/**
	 * @fn       bool SetTimeTag(unsigned int unTimeTag)   
	 * @brief    设置时间，输入为从0点开始的时间，单位为毫秒     
	 * @param    unsigned int unTimeTag 需要设置的时间           
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	bool SetTimeTag(unsigned int unTimeTag);
	
	/**
	 * @fn       std::string GetYearString() const
	 * @brief    以字符串形式返回年     
	 * @return   std::string	年       
	*/
	std::string GetYearString() const;
	
	/**
	 * @fn       std::string GetMonthString() const
	 * @brief    以字符串形式返回月     
	 * @return   std::string	月       
	*/
	std::string GetMonthString() const;
	
	/**
	 * @fn       std::string GetDayString() const
	 * @brief    以字符串形式返回天     
	 * @return   std::string	天       
	*/
	std::string GetDayString() const;
	
	/**
	 * @fn       std::string GetHourString() const
	 * @brief    以字符串形式返回时     
	 * @param      时 
	 * @return   std::string	时       
	*/
	std::string GetHourString() const;
	
	/**
	 * @fn       std::string GetMinuteString() const
	 * @brief    以字符串形式返回分     
	 * @return   std::string	分       
	*/
	std::string GetMinuteString() const;
	
	/**
	 * @fn       std::string GetSecondString() const
	 * @brief    以字符串形式返回秒     
	 * @return   std::string	秒       
	*/
	std::string GetSecondString() const;
	
	/**
	 * @fn       std::string GetMSecondString() const
	 * @brief    以字符串形式返回毫秒     
	 * @return   std::string	毫秒       
	*/
	std::string GetMSecondString() const;
	
	/**
	 * @fn       int GetYear() const
	 * @brief    获取年
	 * @return   int  年
	*/
	int GetYear() const;

	/**
	 * @fn       int GetMonth() const
	 * @brief    获取月
	 * @return   int  月
	*/
	int GetMonth() const;

	/**
	 * @fn       int GetDay() const
	 * @brief    获取日
	 * @return   int  日
	*/
	int GetDay() const;

	/**
	 * @fn       int GetHour() const
	 * @brief    获取小时
	 * @return   int  小时
	*/
	int GetHour() const;

	/**
	 * @fn       int GetMinute() const
	 * @brief    获取分
	 * @return   int  分
	*/
	int GetMinute() const;

	/**
	 * @fn       int GetSecond() const
	 * @brief    获取秒
	 * @return   int  秒
	*/
	int GetSecond() const;

	/**
	 * @fn       int GetMilliseconds() const
	 * @brief    获取毫秒
	 * @return   int  毫秒
	*/
	int GetMilliseconds() const;

	/**
	 * @fn       void SetYear(int nYear)
	 * @brief    设置年
	 * @param    int nYear  年
	 * @return   void  
	*/
	void SetYear(int nYear);

	/**
	 * @fn       void SetMonth(int nMonth)
	 * @brief    设置月
	 * @param    int nMonth  月
	 * @return   void  
	*/
	void SetMonth(int nMonth);

	/**
	 * @fn       void SetDay(int nDay)
	 * @brief    设置日
	 * @param    int nDay  日
	 * @return   void  
	*/
	void SetDay(int nDay);

	/**
	 * @fn       void SetHour(int nHour)
	 * @brief    获取小时
	 * @param    int nHour  小时
	 * @return   void  
	*/
	void SetHour(int nHour);

	/**
	 * @fn       void SetMinute(int nMinute)
	 * @brief    设置分
	 * @param    int nMinute  分
	 * @return   void  
	*/
	void SetMinute(int nMinute);

	/**
	 * @fn       void SetSecond(int nSecond)
	 * @brief    设置秒
	 * @param    int nSecond  秒
	 * @return   void  
	*/
	void SetSecond(int nSecond);
	
	/**
	 * @fn       void SetMilliseconds(int nMilliseconds)
	 * @brief    设置毫秒
	 * @param    int nMilliseconds  毫秒
	 * @return   void  
	*/
	void SetMilliseconds(int nMilliseconds);

	/**
	 * @fn       void SetDateTime(int nYear,int nMonth,int nDay,int nHour,int nMinute,int nSecond,int nMilliseconds)
	 * @brief    设置日期时间
	 * @param    int nYear  年
	 * @param    int nMonth  月
	 * @param    int nDay  日
	 * @param    int nHour  小时
	 * @param    int nMinute  分钟
	 * @param    int nSecond  秒
	 * @param    int nMilliseconds  毫秒
	 * @return   void  
	*/
	void SetDateTime(int nYear,int nMonth,int nDay,int nHour = 0,int nMinute = 0,int nSecond = 0,int nMilliseconds = 0);

	/**
	 * @fn       void SetTime(int nHour,int nMinute,int nSecond,int nMilliseconds)
	 * @brief    设置时间
	 * @param    int nHour  小时
	 * @param    int nMinute  分钟
	 * @param    int nSecond  秒
	 * @param    int nMilliseconds  毫秒
	 * @return   void  
	*/
	void SetTime(int nHour,int nMinute,int nSecond,int nMilliseconds);

	/**
	 * @fn       unsigned int GetJdDays() const
	 * @brief    获取儒略日天数
	 * @return   unsigned int  儒略日天数
	*/
	unsigned int GetJdDays() const;

	/**
	 * @fn       unsigned int GetMjdDays() const
	 * @brief    获取简化儒略日天数
	 * @return   unsigned int  简化儒略日天数
	*/
	unsigned int GetMjdDays() const;

	/**
	 * @fn       void SetJdDays(unsigned int unJdDays)
	 * @brief    设置儒略日天数
	 * @param    unsigned int unJdDays  儒略日天数
	 * @return   void  
	*/
	void SetJdDays(unsigned int unJdDays);

	/**
	 * @fn       void SetMjdDays(unsigned int unMjdDays)
	 * @brief    设置简化儒略日天数
	 * @param    unsigned int unMjdDays  简化儒略日天数
	 * @return   void  
	*/
	void SetMjdDays(unsigned int unMjdDays);

	/**
	 * @fn       int DaysTo(const CTimeInfo& rTimeInfo) const
	 * @brief    计算两个时间的日期差值rTimeInfo - *this，不将时间计算在内，只计算日期
	 * @param    const CTimeInfo & rTimeInfo  被计算的时间
	 * @return   int  天数差值
	*/
	int DaysTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       int64_t SecondsTo(const CTimeInfo& rTimeInfo)
	 * @brief    计算两个时间的秒差值rTimeInfo - *this，将日期计算在内
	 * @param    const CTimeInfo & rTimeInfo  被计算的时间
	 * @return   int64_t  秒差值
	*/
	int64_t SecondsTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       int64_t MillisecondsTo(const CTimeInfo& rTimeInfo) const
	 * @brief    计算两个时间的毫秒差值rTimeInfo - *this，将日期计算在内
	 * @param    const CTimeInfo & rTimeInfo  被计算的时间
	 * @return   int64_t  毫秒差值
	*/
	int64_t MillisecondsTo(const CTimeInfo& rTimeInfo) const;

	/**
	 * @fn       CTimeInfo AddYears(int nYears) const
	 * @brief    在该时间的基础上添加年数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nYears  添加的年数
	 * @return   CTimeInfo  添加年数后的时间
	*/
	CTimeInfo AddYears(int nYears) const;

	/**
	 * @fn       CTimeInfo AddMonths(int nMonths) const
	 * @brief    在该时间的基础上添加月数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nMonths  添加的月数
	 * @return   CTimeInfo  添加月数后的时间
	*/
	CTimeInfo AddMonths(int nMonths) const;

	/**
	 * @fn       CTimeInfo AddDays(int nDays) const
	 * @brief    在该时间的基础上添加天数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nDays  添加的天数
	 * @return   CTimeInfo  添加天数后的时间
	*/
	CTimeInfo AddDays(int nDays) const;

	/**
	 * @fn       CTimeInfo AddHours(int nHours) const
	 * @brief    添加小时，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nHours  添加的小时数
	 * @return   CTimeInfo  添加小时数后的时间
	*/
	CTimeInfo AddHours(int nHours) const;

	/**
	 * @fn       CTimeInfo AddMinutes(int nMinutes) const
	 * @brief    添加分钟数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nMinutes  添加的分钟数
	 * @return   CTimeInfo  添加分钟数后的时间
	*/
	CTimeInfo AddMinutes(int nMinutes) const;

	/**
	 * @fn       CTimeInfo AddSeconds(int nSeconds) const
	 * @brief    添加秒数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int nSeconds  添加的秒数
	 * @return   CTimeInfo  添加秒数后的时间
	*/
	CTimeInfo AddSeconds(int nSeconds) const;

	/**
	 * @fn       CTimeInfo AddSeconds(int64_t nSeconds) const
	 * @brief    添加秒数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int64_t nSeconds  添加的秒数
	 * @return   CTimeInfo  添加秒数后的时间
	*/
	CTimeInfo AddSeconds(int64_t nSeconds) const;

	/**
	 * @fn       CTimeInfo AddMilliseconds(int64_t nMilliseconds) const
	 * @brief    添加毫秒数，可以为负值，不改变自身的值，返回新的时间
	 * @param    int64_t nMilliseconds   添加的毫秒数
	 * @return   CTimeInfo  添加毫秒数后的时间
	*/
	CTimeInfo AddMilliseconds(int64_t nMilliseconds) const;

	/**
	 * @fn       int64_t GetKeyMilliseconds(CTimeInfo* pBaseTimeInfo) const
	 * @brief    获取以基准值时间为基准的毫秒数
	 * @param    CTimeInfo * pBaseTimeInfo  基准时间
	 * @return   int64_t  以基准值时间为基准的毫秒数（当前时间-rBaseTimeInfo的毫秒数）
	*/
	int64_t GetBaseTimeMilliseconds(CTimeInfo* pBaseTimeInfo = NULL) const;

	/**
	 * @fn       bool SetBaseTimeMilliseconds(int64_t nMilliseconds,CTimeInfo* pBaseTimeInfo)
	 * @brief    设置以基准值时间为基准的毫秒数
	 * @param    int64_t nMilliseconds  以基准值时间为基准的毫秒数（当前时间-rBaseTimeInfo的毫秒数）
	 * @param    CTimeInfo * pBaseTimeInfo  基准时间
	 * @return   bool  成功返回true，失败返回false
	*/
	bool SetBaseTimeMilliseconds(int64_t nMilliseconds,CTimeInfo* pBaseTimeInfo = NULL);

private:
	int m_nYear;		///<年
	int m_nMonth;		///<月
	int m_nDay;			///<日
	int m_nHour;		///<时
	int m_nMinute;		///<分
	int m_nSecond;		///<秒
	int m_nMilliseconds;///<毫秒
};

/**
 * @class CTimeUtility
 * @brief 封装时间工具类,获取、设置时间
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
	 * @brief    获取当前时间     
	 * @return   CTimeInfo  当前时间，格式为CTimeInfo的结构体       
	*/
	static CTimeInfo GetCurrentTimeInfo();	
	
	/**
	 * @fn       static unsigned int GetTimeTag()   
	 * @brief    获取从0点开始的时间，单位为毫秒     
	 * @return   unsigned int	 从0点开始的时间       
	*/
	static unsigned int GetTimeTag();
	
	/**
	 * @fn       static uint64_t GetHighResTimeTag()   
	 * @brief    返回毫秒级的时间间隔，程序第一次调用时返回0，以后调用返回经过的毫秒数     
	 * @return   uint64_t	 时间间隔，单位毫秒       
	*/
	static uint64_t GetHighResTimeTag();

	/**
	 * @fn       uint64_t GetOsTickTimeTag()
	 * @brief    返回OS从运行起来后的毫秒数
	 * @return   uint64_t  运行起来后的毫秒数
	*/
	static uint64_t GetOsTickTimeTag();
	
	/**
	 * @fn       static bool SetSystemTime(const CTimeInfo& rTimeInfo)   
	 * @brief    设置系统的时间     
	 * @param    CTimeInfo & rTimeInfo  需要设置的时间         
	 * @return   bool	 true:设置成功;false:设置失败       
	*/
	static bool SetSystemTime(const CTimeInfo& rTimeInfo);
	
	/**
	 * @fn       static int64_t GetDifferentTime(const CTimeInfo& rEndTime, const CTimeInfo& rStartTime)   
	 * @brief    比较时间差，rEndTime - rStartTime     
	 * @param    CTimeInfo & rEndTime  结束时间     
	 * @param    CTimeInfo & rStartTime  起始时间         
	 * @return   int64_t	时间差，单位毫秒       
	*/
	static int64_t GetDifferentTime(const CTimeInfo& rEndTime, const CTimeInfo& rStartTime);
	
	/**
	 * @fn       static int GetMillisecondsPassed(unsigned int unEndTime, unsigned int unStartTime)   
	 * @brief    比较时间差，unEndTime - unStartTime     
	 * @param    unsigned int unEndTime  结束时间；单位为毫秒     
	 * @param    unsigned int unStartTime  起始时间  单位为毫秒         
	 * @return   int	时间差，单位毫秒     
	*/
	static int GetMillisecondsPassed(unsigned int unEndTime, unsigned int unStartTime);
	
	/**
	 * @fn       static void SetExternTimeFunc(ExternTimeFunc pGetExternTime, ExternTimeFunc pSetExternTime)   
	 * @brief    设置外部时间设置于获取的接口     
	 * @param    ExternTimeFunc pGetExternTime  外部时间获取函数指针     
	 * @param    ExternTimeFunc pSetExternTime  外部时间设置函数指针          
	 * @return   void       
	*/
	static void SetExternTimeFunc(ExternTimeFunc pGetExternTime, ExternTimeFunc pSetExternTime);
	
	/**
	 * @fn       void Sleep(unsigned int unMilliseconds)   
	 * @brief    Sleep睡眠     
	 * @param    unsigned int unMilliseconds 睡眠时间以毫秒为单位           
	 * @return   void       
	*/
	static void Sleep(unsigned int unMilliseconds);
	
	/**
	 * @fn       void Sleep(const CTimeInfo& rTimeInfo)   
	 * @brief    Sleep睡眠     
	 * @param    CTimeInfo & rTimeInfo 睡眠时间        
	 * @return   void       
	*/
	static void Sleep(const CTimeInfo& rTimeInfo);

private:
	static ExternTimeFunc ms_pGetExternTimeFunc;	///<外部时间获取函数指针
	static ExternTimeFunc ms_pSetExternTimeFunc;	///<外部时间设置函数指针
};

/**
 * @class CTimeAlgorithm
 * @brief 封装时间相关的算法
 * @note   
 */
class SYSTEM_EXPORT CTimeAlgorithm
{
public:
	/**
	 * @fn           bool IsLeapYear(int nYear)   
	 * @brief        判断年是否为闰年
	 * @param        int nYear   年
	 * @return       bool   为闰年返回true，否则返回false
	*/
	static bool IsLeapYear(int nYear);

	/**
	 * @fn           int GetMonthDays(int nYear, int nMonth)   
	 * @brief        获取某年某月有几日
	 * @param        int nYear    年
	 * @param        int nMonth   月
	 * @return       int   有几日
	*/
	static int GetMonthDays(int nYear, int nMonth);

	/**
	 * @fn       unsigned int GetJdDays(int nYear,int nMonth,int nDay)
	 * @brief    计算指定年月日距离儒略日的天数，计算出来的结果与Matlab的juliandate函数基本一致，总是比其多0.5天
	 * @param    int nYear  年
	 * @param    int nMonth  月
	 * @param    int nDay  日
	 * @return   unsigned int  离儒略日的天数
	*/
	static unsigned int GetJdDays(int nYear,int nMonth,int nDay);
	
	/**
	 * @fn       unsigned int GetMjdDays(int nYear,int nMonth,int nDay)
	 * @brief    由于儒略日数字位数太多，国际天文学联合会于1973年采用简化儒略日（MJD）其定义为MJD = JD - 2400000.5，MJD相应的起点是1858年11月17日世界时0时
	 * @param    int nYear  年
	 * @param    int nMonth  月
	 * @param    int nDay  日
	 * @return   unsigned int  简化儒略日天数
	*/
	static unsigned int GetMjdDays(int nYear,int nMonth,int nDay);

	/**
	 * @fn       void GetDateFromJd(unsigned int unJds,int& nYear,int& nMonth,int& nDay)
	 * @brief    根据儒略日天数获取对应的年月日
	 * @param    unsigned int unJds  儒略日天数
	 * @param    int & nYear  转换后的年
	 * @param    int & nMonth  转换后的月
	 * @param    int & nDay  转换后的日
	 * @return   void  
	*/
	static void GetDateFromJd(unsigned int unJds,int& nYear,int& nMonth,int& nDay);

	/**
	 * @fn       void GetDateFromMjd(unsigned int unMjds,int& nYear,int& nMonth,int& nDay)
	 * @brief    根据简化儒略日天数获取对应的年月日
	 * @param    unsigned int unMjds  简化儒略日天数
	 * @param    int & nYear  转换后的年
	 * @param    int & nMonth  转换后的月
	 * @param    int & nDay  转换后的日
	 * @return   void  
	*/
	static void GetDateFromMjd(unsigned int unMjds,int& nYear,int& nMonth,int& nDay);
};

#endif
