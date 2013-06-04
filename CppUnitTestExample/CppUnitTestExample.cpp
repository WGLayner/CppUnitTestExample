// CppUnitTestExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WindowsVersion.h"

int _tmain(int argc, _TCHAR* argv[])
{
	WindowsVersion wv;

	WindowsVersion::WindowsVersionValue version = wv.GetValue();

	switch(version)
	{
		case WindowsVersion::WindowsVista:
			std::cout << "Windows Vista" << std::endl;
			break;

		case WindowsVersion::WindowsServer2008:
			std::cout << "Windows Server 2008" << std::endl;
			break;

		case WindowsVersion::Windows7:
			std::cout << "Windows 7" << std::endl;
			break;

		case WindowsVersion::WindowsServer2008R2:
			std::cout << "Windows Server 2008 R2" << std::endl;
			break;

		case WindowsVersion::Windows8:
			std::cout << "Windows 8" << std::endl;
			break;

		case WindowsVersion::WindowsServer2012:
			std::cout << "Windows Server 2012" << std::endl;
			break;

		case WindowsVersion::Unknown:
		default:
			std::cout << "Unknown" << std::endl;
			break;
	}

	return 0;
}

