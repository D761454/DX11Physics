#pragma once

#include <string>
#include <stdio.h>
#include <windows.h>

class Debug
{
private:
	static int VDebugPrintF(const char* format, va_list args);
public:
	static int DebugPrintF(const char* format, ...);
};

