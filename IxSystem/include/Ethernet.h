#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#include "IxSystemExport.h"

#include <vector>
#include <string>

/**
 * @class CNetAddress
 * @brief �����ַ��Ϣ��
 * @note   
 */
class SYSTEM_EXPORT CNetAddress
{
	friend class CNetAdapter;
	friend class CEthernet;
public:
	///���캯��
	CNetAddress();
	///��������
	~CNetAddress();

	///�������캯��
	CNetAddress(const CNetAddress& rParam);

	///��ֵ����
	CNetAddress& operator = (const CNetAddress& rParam);

	///�Ƚ���Ⱥ���
	bool operator == (const CNetAddress& rParam) const;

	///�Ƚϲ��Ⱥ���
	bool operator != (const CNetAddress& rParam) const;

public:

	/**
	 * @fn       std::string GetIpAddressString()
	 * @brief    ����IP��ַ�ַ���
	 * @return   std::string  IP��ַ�ַ���
	*/
	std::string GetIpAddressString() const;

	/**
	 * @fn       std::string GetNetMaskString()
	 * @brief    �������������ַ���
	 * @return   std::string ���������ַ���
	*/
	std::string GetNetMaskString() const;

	/**
	 * @fn       unsigned int GetIpAddressUInt32()
	 * @brief    ����IP��ַ����ֵ
	 * @return   unsigned int  IP��ַ����ֵ
	*/
	unsigned int GetIpAddressUInt32() const;

	/**
	 * @fn       unsigned int GetNetMaskUInt32()
	 * @brief    �������������ַ����ֵ
	 * @return   unsigned int  ������������ֵ
	*/
	unsigned int GetNetMaskUInt32() const;

private:
#ifdef WIN32
	ULONG m_ulContext; ///<Network table entry (NTE)
#elif defined(__linux__) || defined(VXWORKS)
	std::string m_strInterfaceName; ///<Interface Name
#endif
	std::string m_strIpAddress;	///<IP��ַ
	std::string m_strNetMask;	///<��������
};

/**
 * @class CNetAdapter
 * @brief ������Ϣ��
 * @note   
 */
class SYSTEM_EXPORT CNetAdapter
{
	friend class CEthernet;
public:
	///���캯��
	CNetAdapter();

	///��������
	~CNetAdapter();

	///�������캯��
	CNetAdapter(const CNetAdapter& rParam);

	///��ֵ����
	CNetAdapter& operator = (const CNetAdapter& rParam);

public:
	/**
	 * @fn       std::string GetName()
	 * @brief    ������������
	 * @return   std::string  ��������
	*/
	std::string GetName() const;

	/**
	 * @fn       std::string GetDescription()
	 * @brief    ������������
	 * @return   std::string  ��������
	*/
	std::string GetDescription() const;

	/**
	 * @fn       std::string GetMacAddress()
	 * @brief    �������������ַ
	 * @return   std::string  �����ַ
	*/
	std::string GetMacAddress() const;

	/**
	 * @fn       std::vector<CNetAddress> GetNetAddresses()
	 * @brief    ���ظ����������е������ַ��Ϣ
	 * @return   std::vector<CNetAddress>  �����ַ��Ϣ
	*/
	std::vector<CNetAddress> GetNetAddresses() const;

	/**
	 * @fn       std::vector<CNetAddress> GetGatewayAddresses()
	 * @brief    �������ص�ַ��Ϣ
	 * @return   std::vector<CNetAddress>  ���ص�ַ��Ϣ
	*/
	std::vector<CNetAddress> GetGatewayAddresses() const;

	/**
	 * @fn       bool AddNetAddress(const CNetAddress& rNetAddress)
	 * @brief    ��������ַ��Ϣ
	 * @param    const CNetAddress & rNetAddress  �����ַ��Ϣ
	 * @return   bool  �Ƿ���ӳɹ�
	*/
	bool AddNetAddress(const CNetAddress& rNetAddress);

	/**
	 * @fn       bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strIpV4NetMask)
	 * @brief    ���IPV4��ַ��Ϣ
	 * @param    const std::string & strIpV4Address  IP��ַ
	 * @param    const std::string & strIpV4NetMask  ��������
	 * @return   bool  �Ƿ���ӳɹ�
	*/
	bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strIpV4NetMask);

	/**
	 * @fn       bool RemoveNetAddress(const CNetAddress& rNetAddress)
	 * @brief    ɾ�������ַ��Ϣ
	 * @param    const CNetAddress & rNetAddress  �����ַ��Ϣ
	 * @return   bool  �Ƿ�ɾ���ɹ�
	*/
	bool RemoveNetAddress(const CNetAddress& rNetAddress);

	/**
	 * @fn       bool RemoveNetAddress(int nIndex)
	 * @brief    ɾ�������ַ��Ϣ
	 * @param    int nIndex  �����ַ��Ϣ������
	 * @return   bool  �Ƿ�ɾ���ɹ�
	*/
	bool RemoveNetAddress(int nIndex);

	/**
	 * @fn       bool RemoveIpV4Address(const std::string& strIpV4Address)
	 * @brief    ɾ��IPV4��ַ��Ϣ
	 * @param    const std::string & strIpV4Address  IP��ַ
	 * @return   bool  �Ƿ�ɾ���ɹ�
	*/
	bool RemoveIpV4Address(const std::string& strIpV4Address);

	/**
	 * @fn       bool IsHaveIpAddress(const std::string& strIpAddress)
	 * @brief    ���ظ��������Ƿ���ָ����IP��ַ
	 * @param    const std::string & strIpAddress  ָ����IP��ַ
	 * @return   bool  �Ƿ���ָ����IP��ַ
	*/
	bool IsHaveIpAddress(const std::string& strIpAddress);

private:

#ifdef WIN32
	DWORD m_dwAdapterIndex; ///<Adapter���
#elif defined __linux__
	int m_nAdapterIndex; ///<Adapter���
#endif
	std::string m_strName; ///<����
	std::string m_strDescription; ///<����
	std::string m_strMacAddress; ///<MAC��ַ
	std::vector<CNetAddress> m_vecNetAddresses; ///<������ַ�б�
	std::vector<CNetAddress> m_vecGatewayAddresses; ///<���ص�ַ�б�
};

/**
 * @class CEthernet
 * @brief ��̫���ӿ���
 * @note   
 */
class SYSTEM_EXPORT CEthernet
{
public:
	///���캯��
	CEthernet();

	///��������
	~CEthernet();

public:
	/**
	 * @fn       bool GetAllNetAdapterInfo(std::vector<CNetAdapter>& vecNetAdapters)
	 * @brief    ��ȡ����������Ϣ
	 * @param    std::vector<CNetAdapter> & vecNetAdapters  ������Ϣ�б�
	 * @return   bool  �Ƿ��ȡ�ɹ�
	*/
	static bool GetAllNetAdapterInfo(std::vector<CNetAdapter>& vecNetAdapters);

	/**
	 * @fn       bool GetNetAdapterInfo(CNetAdapter& rNetAdapter,int nIndex)
	 * @brief    ��ȡָ����ŵ�������Ϣ
	 * @param    CNetAdapter & rNetAdapter  ������Ϣ
	 * @param    int nIndex  ָ�������
	 * @return   bool  �Ƿ��ȡ�ɹ�
	*/
	static bool GetNetAdapterInfo(CNetAdapter& rNetAdapter,int nIndex = 0);

	/**
	 * @fn       bool GetNetAddresses(std::vector<CNetAddress>& vecNetAddresses,int nIndex)
	 * @brief    ��ȡָ����������������ַ��Ϣ
	 * @param    std::vector<CNetAddress> & vecNetAddresses  �����ַ��Ϣ
	 * @param    int nIndex  ָ����������ţ����С��0�����ȡ���е������������ַ��Ϣ
	 * @return   bool  �Ƿ��ȡ�ɹ�
	*/
	static bool GetNetAddresses(std::vector<CNetAddress>& vecNetAddresses,int nIndex = 0);

	/**
	 * @fn       bool GetIpV4Addresses(std::vector<std::string>& vecIpV4Addresses,int nIndex)
	 * @brief    ��ȡָ�����������IPV4��ַ��Ϣ
	 * @param    std::vector<std::string> & vecIpV4Addresses  IP��ַ�б�
	 * @param    int nIndex  ָ����������ţ����С��0�����ȡ���е�������IPV4��ַ��Ϣ
	 * @return   bool  �Ƿ��ȡ�ɹ�
	*/
	static bool GetIpV4Addresses(std::vector<std::string>& vecIpV4Addresses,int nIndex = 0);

	/**
	 * @fn       bool GetFirstIpV4Address(std::string& strIpAddr,bool bContainLoop)
	 * @brief    ��ȡ��һ����Ч��IP��ַ
	 * @param    std::string & strIpAddr  IP��ַ
	 * @param    bool bContainLoop  �Ƿ����127.0.0.1
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	static bool GetFirstIpV4Address(std::string& strIpAddr,bool bContainLoop = false);

	/**
	 * @fn       bool GetFirstIpV4Address(std::string& strIpAddr,CNetAdapter& rNetAdapter,bool bContainLoop)
	 * @brief    ����IP��ַ��ȡ������Ϣ
	 * @param    std::string & strIpAddr  IP��ַ
	 * @param    CNetAdapter & rNetAdapter  ��IP��ַ������������Ϣ
	 * @return   bool  �ɹ�����true��ʧ�ܷ���false
	*/
	static bool GetNetAdapter(const std::string& strIpAddr,CNetAdapter& rNetAdapter);

	/**
	 * @fn       bool RemoveIpV4Address(const std::string& strIpV4Address,int nIndex)
	 * @brief    ��ָ����ŵ�������ɾ��ָ����IPV4��ַ
	 * @param    const std::string & strIpV4Address  IP��ַ
	 * @param    int nIndex  ָ����������ţ����С��0����ɾ�����������еĸ�IP��ַ
	 * @return   bool  �Ƿ�ɾ���ɹ�
	*/
	static bool RemoveIpV4Address(const std::string& strIpV4Address,int nIndex = 0);
	
	/**
	 * @fn       bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strNetMask,int nIndex)
	 * @brief    ��ָ����ŵ����������IPV4��ַ
	 * @param    const std::string & strIpV4Address  IP��ַ
	 * @param    const std::string & strNetMask  ��������
	 * @param    int nIndex  ָ�����������
	 * @return   bool  �Ƿ�ɾ���ɹ�
	*/
	static bool AddIpV4Address(const std::string& strIpV4Address,const std::string& strNetMask,int nIndex = 0);

	/**
	 * @fn       int GetAdapterNumber()
	 * @brief    ��ȡ����������
	 * @return   int  ����������
	*/
	static int GetAdapterNumber();
private:
	///�Ӷ����������л�ȡ�����ַ
	static std::string GetMacAddressByData(unsigned char* pucData, int nLen);
};

#endif
