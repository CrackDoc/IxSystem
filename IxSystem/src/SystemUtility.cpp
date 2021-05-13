#include "SystemUtility.h"


#if defined WIN32
int gettimeofday(struct timeval* tp, void* tz)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm. tm_isdst= -1;
	clock = mktime(&tm);
	tp->tv_sec = (long)clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return 0;
} 
void usleep(int64_t usec)
{
	HANDLE timer;
	LARGE_INTEGER interval;
	interval.QuadPart = -(10 * usec);

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &interval, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}

#endif
timespec ConvertMilliSeconds( int nMilliseconds )
{
	struct timeval tv;
	#if defined WIN32
	gettimeofday(&tv,NULL);
	#elif defined __linux__
	#endif
	struct timespec ts;
	uint64_t nsec = uint64_t(tv.tv_usec) * 1000 + uint64_t(nMilliseconds)*1000*1000;
	ts.tv_sec = tv.tv_sec + (nsec/1000000000LL);
	ts.tv_nsec = nsec%1000000000LL;

	return ts;
}
u_int64 ConvertTimevalSeconds(timeval* tp)
{
	uint64_t nsec = uint64_t(tp->tv_usec) * 1000 + tp->tv_sec;
	return nsec;
}

u_int64 ConvertTimevalMilliSeconds(timeval* tp)
{
	uint64_t millisec = uint64_t(tp->tv_usec)/1000 + (uint64_t)tp->tv_sec*1000;
	return millisec;
}

u_int64 ConvertTimevalUsSeconds(timeval* tp)
{
	uint64_t usec = uint64_t(tp->tv_usec) + (uint64_t)tp->tv_sec*1000*1000;
	return usec;
}

u_int64 GetCurrentTimeUsSeconds()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);

	return ConvertTimevalUsSeconds(&tv);
}

u_int64 GetCurrentTimeMsSeconds()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);

	return ConvertTimevalMilliSeconds(&tv);
}
u_int64 GetCurrentTimeSeconds()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);

	return ConvertTimevalSeconds(&tv);
}

