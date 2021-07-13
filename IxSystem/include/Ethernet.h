#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include "IxSystemExport.h"

#include <vector>
#include <string>

/**
 * @class CNetAddress
 * @brief 网络地址信息类
 * @note   
 */
class SYSTEM_EXPORT CNetAddress
{
	friend class CNetAdapter;
	friend class CEthernet;
public:
	///构造函数
	CNetAddress();
	///析构函数
	~CNetAddress();

	///拷贝构造函数
	CNetAddress(const CNetAddress& rParam);

	///赋值函数
	CNetAddress& operator = (const CNetAddress& rParam);

	///比较相等函数
	bool operator == (const CNetAddress& rParam) const;

	///比较不等函数
	bool operator != (const CNetAddress& rParam) const;

public:

	/**
	 * @fn       std::string GetIpAddressString()
	 * @brief    返回IP地址字符串
	 * @return   std::string  IP地址字符串
	*/
	std::string GetIpAddressString() const;

	/**
	 * @fn       std::string GetNetMaskString()
	 * @brief    返回子网掩码字符串
	 * @return   std::string 子网掩码字符串
	*/
	std::string GetNetMaskString() const;

	/**
	 * @fn       unsigned int GetIpAddressUInt32()
	 * @brief    返回IP地址整数值
	 * @return   unsigned int  IP地址整数值
	*/
	unsigned int GetIpAddressUInt32() const;

	/**
	 * @fn       unsigned int GetNetMaskUInt32()
	 * @brief    返回子网掩码地址整数值
	 * @return   unsigned int  子网掩码整数值
	*/
	unsigned int GetNetMaskUInt32() const;

private:
#ifdef WIN32
	ULONG m_ulContext; ///<Network table entry (NTE)
#elif defined(__linux__) || defined(VXWORKS)
	std::string m_strInterfaceName; ///<Interface Name
#endif
	std::string m_strIpAddress;	///<IP地址
	std::string m_strNetMask;	///<子网掩码
};

/**
 * @class CNetAdapter
 * @brief 网卡信息类
 * @note   
 */
class SYSTEM_EXPORT CNetAdapter
{
	friend class CEthernet;
public:
	///构造函数
	CNetAdapter();

	///析构函数
	~CNetAdapter();

	///拷贝构造函数
	CNetAdapter(const CNetAdapter& rParam);

	///赋值函数
	CNetAdapter& operator = (const CNetAdapter& rParam);

public:
	/**
	 * @fn       std::string GetName()
	 * @brief    返回网卡名字
	 * @return   std::string  网卡名字
	*/
	std::string GetName() const;

	/**
	 * @fn       std::string GetDescription()
	 * @brief    返回网卡描述
	 * @return   std::string  网卡描述
	*/
	std::string GetDescription() const;

	/**
	 * @fn       std::string GetMacAddress()
	 * @brief    返回网卡物理地址
	 * @return   std::string  物理地址
	*/
	std::string GetMacAddress() const;

	/**
	 * @fn       std::vector<CNetAddress> GetNetAddresses()
	 * @brief    返回该网卡上所有的网络地址信息
	 * @return   std::vector<CNetAddress>  网络地址信息
	*/
	std::vector<CNetAddress> GetNetAddresses() const;

	/**
	 * @fn       std::vector<CNetAddress> GetGatewayAddresses()
	 * @brief    返回网关地址信息
	 * @return   std::vector<CNetAddress>  网关地址信息
	*/
	std::vector<CNetAddress> GetGatewayAddresses() const;

	/**
	 * @fn       bool AddNetAddress(const CNetAddress& rNetAddress)
	 * @brief    添加网络地址信息
	 * @param    const CNetAddress & rNetAddress  网络地址信息
	 * @return   bool  是否添加成功
	*/
	bool AddNetAddress(const CNetAddress& rNetAddress);

	/**
	 * @fn       bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strIpV4NetMask)
	 * @brief    添加IPV4地址信息
	 * @param    const std::string & strIpV4Address  IP地址
	 * @param    const std::string & strIpV4NetMask  子网掩码
	 * @return   bool  是否添加成功
	*/
	bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strIpV4NetMask);

	/**
	 * @fn       bool RemoveNetAddress(const CNetAddress& rNetAddress)
	 * @brief    删除网络地址信息
	 * @param    const CNetAddress & rNetAddress  网络地址信息
	 * @return   bool  是否删除成功
	*/
	bool RemoveNetAddress(const CNetAddress& rNetAddress);

	/**
	 * @fn       bool RemoveNetAddress(int nIndex)
	 * @brief    删除网络地址信息
	 * @param    int nIndex  网络地址信息的索引
	 * @return   bool  是否删除成功
	*/
	bool RemoveNetAddress(int nIndex);

	/**
	 * @fn       bool RemoveIpV4Address(const std::string& strIpV4Address)
	 * @brief    删除IPV4地址信息
	 * @param    const std::string & strIpV4Address  IP地址
	 * @return   bool  是否删除成功
	*/
	bool RemoveIpV4Address(const std::string& strIpV4Address);

	/**
	 * @fn       bool IsHaveIpAddress(const std::string& strIpAddress)
	 * @brief    返回该网卡中是否有指定的IP地址
	 * @param    const std::string & strIpAddress  指定的IP地址
	 * @return   bool  是否有指定的IP地址
	*/
	bool IsHaveIpAddress(const std::string& strIpAddress);

private:

#ifdef WIN32
	DWORD m_dwAdapterIndex; ///<Adapter序号
#elif defined __linux__
	int m_nAdapterIndex; ///<Adapter序号
#endif
	std::string m_strName; ///<名字
	std::string m_strDescription; ///<描述
	std::string m_strMacAddress; ///<MAC地址
	std::vector<CNetAddress> m_vecNetAddresses; ///<网卡地址列表
	std::vector<CNetAddress> m_vecGatewayAddresses; ///<网关地址列表
};

/**
 * @class CEthernet
 * @brief 以太网接口类
 * @note   
 */
class SYSTEM_EXPORT CEthernet
{
public:
	///构造函数
	CEthernet();

	///析构函数
	~CEthernet();

public:
	/**
	 * @fn       bool GetAllNetAdapterInfo(std::vector<CNetAdapter>& vecNetAdapters)
	 * @brief    获取所有网卡信息
	 * @param    std::vector<CNetAdapter> & vecNetAdapters  网卡信息列表
	 * @return   bool  是否获取成功
	*/
	static bool GetAllNetAdapterInfo(std::vector<CNetAdapter>& vecNetAdapters);

	/**
	 * @fn       bool GetNetAdapterInfo(CNetAdapter& rNetAdapter,int nIndex)
	 * @brief    获取指定序号的网络信息
	 * @param    CNetAdapter & rNetAdapter  网卡信息
	 * @param    int nIndex  指定的序号
	 * @return   bool  是否获取成功
	*/
	static bool GetNetAdapterInfo(CNetAdapter& rNetAdapter,int nIndex = 0);

	/**
	 * @fn       bool GetNetAddresses(std::vector<CNetAddress>& vecNetAddresses,int nIndex)
	 * @brief    获取指定序号网卡的网络地址信息
	 * @param    std::vector<CNetAddress> & vecNetAddresses  网络地址信息
	 * @param    int nIndex  指定的网卡序号，如果小于0，则获取所有的网卡的网络地址信息
	 * @return   bool  是否获取成功
	*/
	static bool GetNetAddresses(std::vector<CNetAddress>& vecNetAddresses,int nIndex = 0);

	/**
	 * @fn       bool GetIpV4Addresses(std::vector<std::string>& vecIpV4Addresses,int nIndex)
	 * @brief    获取指定序号网卡的IPV4地址信息
	 * @param    std::vector<std::string> & vecIpV4Addresses  IP地址列表
	 * @param    int nIndex  指定的网卡序号，如果小于0，则获取所有的网卡的IPV4地址信息
	 * @return   bool  是否获取成功
	*/
	static bool GetIpV4Addresses(std::vector<std::string>& vecIpV4Addresses,int nIndex = 0);

	/**
	 * @fn       bool GetFirstIpV4Address(std::string& strIpAddr,bool bContainLoop)
	 * @brief    获取第一个有效的IP地址
	 * @param    std::string & strIpAddr  IP地址
	 * @param    bool bContainLoop  是否包含127.0.0.1
	 * @return   bool  成功返回true，失败返回false
	*/
	static bool GetFirstIpV4Address(std::string& strIpAddr,bool bContainLoop = false);

	/**
	 * @fn       bool GetFirstIpV4Address(std::string& strIpAddr,CNetAdapter& rNetAdapter,bool bContainLoop)
	 * @brief    根据IP地址获取网卡信息
	 * @param    std::string & strIpAddr  IP地址
	 * @param    CNetAdapter & rNetAdapter  该IP地址所属的网卡信息
	 * @return   bool  成功返回true，失败返回false
	*/
	static bool GetNetAdapter(const std::string& strIpAddr,CNetAdapter& rNetAdapter);

	/**
	 * @fn       bool RemoveIpV4Address(const std::string& strIpV4Address,int nIndex)
	 * @brief    从指定序号的网卡中删除指定的IPV4地址
	 * @param    const std::string & strIpV4Address  IP地址
	 * @param    int nIndex  指定的网卡序号，如果小于0，则删除所有网卡中的该IP地址
	 * @return   bool  是否删除成功
	*/
	static bool RemoveIpV4Address(const std::string& strIpV4Address,int nIndex = 0);
	
	/**
	 * @fn       bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strNetMask,int nIndex)
	 * @brief    向指定序号的网卡中添加IPV4地址
	 * @param    const std::string & strIpV4Address  IP地址
	 * @param    const std::string & strNetMask  子网掩码
	 * @param    int nIndex  指定的网卡序号
	 * @return   bool  是否删除成功
	*/
	static bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strNetMask,int nIndex = 0);

	/**
	 * @fn       int GetAdapterNumber()
	 * @brief    获取网卡的数量
	 * @return   int  网卡的数量
	*/
	static int GetAdapterNumber();
private:
	///从二进制数据中获取物理地址
	static std::string GetMacAddressByData(unsigned char* pucData, int nLen);
};

#endif
