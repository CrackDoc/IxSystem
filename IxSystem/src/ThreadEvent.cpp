#include "ThreadEvent.h"

CThreadEvent::CThreadEvent()
{

}

CThreadEvent::~CThreadEvent()
{

}

bool CThreadEvent::Signal()
{
	return m_hHandle.Signal();
}

bool CThreadEvent::Wait( int nMilliseconds /*= -1*/ )
{
	return m_hHandle.Wait(nMilliseconds);
}

bool CThreadEvent::Reset()
{
	return m_hHandle.Reset();
}

void CThreadEvent::TravelEvents( IThreadEventVisitor &rVistor )
{
	rVistor.AppendEvent(this);
}

ThreadEventHandle& CThreadEvent::GetHandle()
{
	return m_hHandle;
}

