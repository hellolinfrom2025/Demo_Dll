#pragma once
#include <windows.h>
#include <string>
#include <assert.h>
class CLibrary
{
public:
	CLibrary(const wchar_t* name)
	{
		m_handle = LoadLibrary(name);
		DWORD errNumber= GetLastError(); 
		assert(m_handle);
		if (!m_handle) 
		{
			if (errNumber==126)
				throw std::runtime_error(std::string("Could not find library depending:"));
			throw std::runtime_error(std::string("Could not find library file:"));
		}
	}

	~CLibrary()
	{
		FreeLibrary(m_handle);
	}

	void* GetProc(const char* name)
	{
		void* proc = ::GetProcAddress(m_handle, name);
		assert(proc);
		return proc;
	}

private:
	HMODULE m_handle;
};

