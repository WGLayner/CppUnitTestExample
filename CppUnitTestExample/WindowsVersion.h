#pragma once

#include "stdafx.h"

template<typename W>
class WindowsVersionT
{
public:
	typedef enum
	{
		WindowsVista,
		WindowsServer2008,
		WindowsServer2008R2,
		Windows7,
		WindowsServer2012,
		Windows8,
		Unknown
	} WindowsVersionValue;

	WindowsVersionT()
		: value_(Unknown)
	{
		OSVERSIONINFOEX osvi;
		ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX ));
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX );

		if (FALSE == W::GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&osvi)))
			return;

		if ( 6 == osvi.dwMajorVersion )
		{
			if( 0 == osvi.dwMinorVersion )
			{
				if( VER_NT_WORKSTATION == osvi.wProductType )
					value_ = WindowsVista;
				else 
					value_ = WindowsServer2008;
			}

			if ( 1 == osvi.dwMinorVersion )
			{
				if( VER_NT_WORKSTATION == osvi.wProductType )
					value_ = Windows7;
				else
				value_ = WindowsServer2008R2;
			}

			if ( 2 == osvi.dwMinorVersion )
			{
				if( VER_NT_WORKSTATION == osvi.wProductType )
					value_ = Windows8;
				else
				value_ = WindowsServer2012;
			}
		}
	}

	WindowsVersionValue GetValue() const
	{
		return value_;
	}

private:
	WindowsVersionValue value_;
};

struct WindowsVersionApi
{
	static BOOL WINAPI GetVersionEx(_Inout_ LPOSVERSIONINFO lpVersionInfo)
	{
		return ::GetVersionEx(lpVersionInfo);
	}
};

typedef WindowsVersionT<WindowsVersionApi> WindowsVersion;
