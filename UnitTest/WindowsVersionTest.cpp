// Headers for CppUnitTest
#include "CppUnitTest.h"
#include "windows.h"

#include "../CppUnitTestExample/WindowsVersion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(WindowsVersionTest)
	{
	public:
		TEST_METHOD(TestGetVersionExReturnsFalseResultsInUnknownOS)
		{
			struct MockWindowsVersionApi
			{
				static BOOL WINAPI GetVersionEx(_Inout_ LPOSVERSIONINFO lpVersionInfo)
				{
					return FALSE;
				}
			};

			WindowsVersionT<MockWindowsVersionApi> wv;
			WindowsVersionT<MockWindowsVersionApi>::WindowsVersionValue version = wv.GetValue();

			Assert::IsTrue(WindowsVersionT<MockWindowsVersionApi>::Unknown == version);
		}

		TEST_METHOD(TestGetVersionExReturnsVista)
		{
			struct MockWindowsVersionApi
			{
				static BOOL WINAPI GetVersionEx(_Inout_ LPOSVERSIONINFO lpVersionInfo)
				{
					lpVersionInfo->dwMajorVersion = 6;
					lpVersionInfo->dwMinorVersion = 0;
					reinterpret_cast<OSVERSIONINFOEX*>(lpVersionInfo)->wProductType = VER_NT_WORKSTATION;

					return TRUE;
				}
			};

			WindowsVersionT<MockWindowsVersionApi> wv;
			WindowsVersionT<MockWindowsVersionApi>::WindowsVersionValue version = wv.GetValue();

			Assert::IsTrue(WindowsVersionT<MockWindowsVersionApi>::WindowsVista == version);
		}

		TEST_METHOD(TestGetVersionExReturnsWindowsServer2008)
		{
			struct MockWindowsVersionApi
			{
				static BOOL WINAPI GetVersionEx(_Inout_ LPOSVERSIONINFO lpVersionInfo)
				{
					lpVersionInfo->dwMajorVersion = 6;
					lpVersionInfo->dwMinorVersion = 0;
					reinterpret_cast<OSVERSIONINFOEX*>(lpVersionInfo)->wProductType = VER_NT_SERVER;

					return TRUE;
				}
			};

			WindowsVersionT<MockWindowsVersionApi> wv;
			WindowsVersionT<MockWindowsVersionApi>::WindowsVersionValue version = wv.GetValue();

			Assert::IsTrue(WindowsVersionT<MockWindowsVersionApi>::WindowsServer2008 == version);
		}

	};
}