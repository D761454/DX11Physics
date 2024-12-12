#pragma once

#include <chrono>
#include "CircularBuffer.h"

using namespace std::chrono;

class Timer
{
public:
	Timer();

	float GetActualDeltaTime();
	void Tick();

private:
	steady_clock::time_point lastFrame;

	
};

