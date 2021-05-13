#include "Ethernet.h"

CNetAddress::CNetAddress()
{

}

CNetAddress::CNetAddress( const CNetAddress& rParam )
{

}
bool CNetAddress::operator!=( const CNetAddress& rParam ) const
{
	return false;
}

bool CNetAddress::operator==( const CNetAddress& rParam ) const
{
	return false;
}

CNetAddress& CNetAddress::operator=( const CNetAddress& rParam )
{
	return *this;
}

CNetAddress::~CNetAddress()
{

}
std::string CNetAddress::GetIpAddressString() const
{
	return "";
}

std::string CNetAddress::GetNetMaskString() const
{
	return "";
}

unsigned int CNetAddress::GetIpAddressUInt32() const
{
	return 0;
}

unsigned int CNetAddress::GetNetMaskUInt32() const
{
	return 0;
}

CNetAdapter::CNetAdapter()
{

}

CNetAdapter::CNetAdapter( const CNetAdapter& rParam )
{

}

std::string CNetAdapter::GetName() const
{
	return "";
}

std::string CNetAdapter::GetDescription() const
{
	return "";
}

std::string CNetAdapter::GetMacAddress() const
{
	return "";
}

std::vector<CNetAddress> CNetAdapter::GetNetAddresses() const
{
	return std::vector<CNetAddress>();
}

std::vector<CNetAddress> CNetAdapter::GetGatewayAddresses() const
{
	return std::vector<CNetAddress>();

}

bool CNetAdapter::AddNetAddress( const CNetAddress& rNetAddress )
{
	return false;
}

bool CNetAdapter::AddIpV4Address( const std::string& strIpV4Address,const std::string& strIpV4NetMask )
{
	return false;
}

bool CNetAdapter::RemoveNetAddress( const CNetAddress& rNetAddress )
{
	return false;

}

bool CNetAdapter::RemoveNetAddress( int nIndex )
{
	return false;
}

bool CNetAdapter::RemoveIpV4Address( const std::string& strIpV4Address )
{
	return false;
}

bool CNetAdapter::IsHaveIpAddress( const std::string& strIpAddress )
{
	return false;
}

CNetAdapter& CNetAdapter::operator=( const CNetAdapter& rParam )
{
	return *this;
}

CNetAdapter::~CNetAdapter()
{

}

CEthernet::CEthernet()
{

}

CEthernet::~CEthernet()
{

}

bool CEthernet::GetAllNetAdapterInfo( std::vector<CNetAdapter>& vecNetAdapters )
{
	return false;
}

bool CEthernet::GetNetAdapterInfo( CNetAdapter& rNetAdapter,int nIndex /*= 0*/ )
{
	return false;
}

bool CEthernet::GetNetAddresses( std::vector<CNetAddress>& vecNetAddresses,int nIndex /*= 0*/ )
{
	return false;
}

bool CEthernet::GetIpV4Addresses( std::vector<std::string>& vecIpV4Addresses,int nIndex /*= 0*/ )
{
	return false;

}

bool CEthernet::GetFirstIpV4Address( std::string& strIpAddr,bool bContainLoop /*= false*/ )
{
	return false;
}

bool CEthernet::GetNetAdapter( const std::string& strIpAddr,CNetAdapter& rNetAdapter )
{
	return false;
}

bool CEthernet::RemoveIpV4Address( const std::string& strIpV4Address,int nIndex /*= 0*/ )
{
	return false;
}

bool CEthernet::AddIpV4Address( const std::string& strIpV4Address,const std::string& strNetMask,int nIndex /*= 0*/ )
{
	return false;

}

int CEthernet::GetAdapterNumber()
{
	return 0;
}

std::string CEthernet::GetMacAddressByData( unsigned char* pucData, int nLen )
{
	return "";
}
