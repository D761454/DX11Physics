#include "Debug.h"

int Debug::VDebugPrintF(const char* format, va_list args) {
	const UINT32 MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, args);
	OutputDebugStringA(s_buffer);

	return charsWritten;
}

int Debug::DebugPrintF(const char* format, ...) {
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);
	va_end(argList);

	return charsWritten;
}