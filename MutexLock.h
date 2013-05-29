//////////////////////////////////////////////////////////////////////// 
// Lock.h: interface for the Lock class.
//
/*
How to use

Declare as: CLock myMutex;

call: mutex.lock();
call: mutex.unlock();

Use mutex in area's where the same data may be modified at the same time by 2 seperate processors
	*Note: 2 threads can modify data that was declared within the thread because they are unique
		   to each thread. 
		   ONLY data that was declared and accessed by all (eg singleton data) needs the mutex's 
		   because its the same data being accessed by the whole program/solution.

*You will generally have a lot of small areas with mutexs in them eg:

void InboundDataProcessor::clearMarineLinkData() <--This is called by many
{
	mutex.lock();
	while (marineLinkData.IsEmpty() == false)
	{
		mliStruct * entry = marineLinkData.GetHead();
		delete entry;
		marineLinkData.RemoveHead();
	}

	totalDevices = 0;
	mutex.unlock();
}

*/

#if !defined(Lock_H)
#define Lock_H

#include <windows.h>
#include <string>
using namespace std;

/////////////////////////////////////////////////
// Lock
class CLock
{
public:
	HANDLE		m_hMutex;			// used to lock/unlock object access
	bool		m_attached;			// shows attached to existing lock


	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	CLock( string & lockName ) :
		m_hMutex(NULL),
		m_attached(false)
	{
		createLock(lockName);
	}


	CLock() :
		m_hMutex(NULL),
		m_attached(false)
	{
		createLock();
	}


	CLock( HANDLE hMutex ) :
		m_hMutex(NULL),
		m_attached(false)
	{
		if ( hMutex != NULL )
		{
			m_hMutex  = hMutex;
			m_attached = true;
		}
	}


	virtual ~CLock()
	{
		destroyLock();
	}


	/////////////////////////////////////////////////////////////
	// access object fxns

	bool lock	()
	{
		if ( m_hMutex == NULL )
			return false;

		WaitForSingleObject( m_hMutex, INFINITE );

		return true;
	}


	void unlock ()
	{
		ReleaseMutex(m_hMutex);
	}

	bool createLock ( string & lockName )
	{
		// return object mutex
		m_hMutex = ::CreateMutex( NULL, false, lockName.c_str() );
		if ( m_hMutex == 0 )
			return false;

		return true;
	}

	bool createLock ()
	{
		// return object mutex
		m_hMutex = ::CreateMutex( NULL, false, 0 );
		if ( m_hMutex == 0 )
			return false;

		return true;
	}

	static bool createLock ( HANDLE & hMutex )
	{
		// return object mutex
		hMutex = ::CreateMutex( NULL, false, 0 );
		if ( hMutex == 0 )
			return false;

		return true;
	}


	void destroyLock ()
	{
		if ( !m_attached )
		{
			if ( m_hMutex != NULL )
			{
				::CloseHandle( m_hMutex );
			}
		}

		m_attached = false;
		m_hMutex   = NULL;
	}

};
#endif
