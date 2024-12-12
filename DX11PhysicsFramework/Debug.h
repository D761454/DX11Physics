#pragma once

#include <string>
#include <stdio.h>
#include <windows.h>

class Debug
{
private:

public:
	static int VDebugPrintF(const char* format, va_list args);
	static int DebugPrintF(const char* format, ...);
};

