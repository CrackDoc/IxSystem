#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_
/**
@file SystemExport.h
@author crack
@brief 不同操作系统的配置
*/
#if !defined(WIN32) && !defined(__linux__)
#	ifndef VXWORKS
#		define VXWORKS
#	endif
#endif

#ifdef WIN32 
#	undef UNICODE
#	include <winsock2.h>
	
	typedef signed __int64 int64_t;
	typedef unsigned __int64 uint64_t;

#	ifdef _MSC_VER
#		pragma warning (disable:4251)
#		pragma warning (disable:4275)
#		if defined(_MSC_VER) && _MSC_VER==1200//vc6.0
#			pragma warning (disable:4311)
#			pragma warning (disable:4786)
#			pragma warning (disable:4005)
#		elif defined(_MSC_VER) && _MSC_VER==1310//vc7.1
#			pragma warning (disable:4311)
#		elif defined(_MSC_VER) && _MSC_VER>=1400//vc8.0以后版本
#			pragma warning (disable:4311)
#			pragma warning (disable:4996)
#		endif
#	endif
#endif

#ifdef __linux__
#	include <inttypes.h>
#	include <sys/types.h>
#endif

#ifdef VXWORKS
	typedef long long int64_t;
	typedef unsigned long long uint64_t;
#endif

#endif
