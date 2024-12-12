#include "Debug.h"

void Debug::Print(int in) {
	char sz[1024] = { 0 };
	sprintf_s(sz, "Debug Output: ", in);
	OutputDebugStringA(sz);
}