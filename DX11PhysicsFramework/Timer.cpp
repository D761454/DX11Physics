#include "Timer.h"

Timer::Timer() {
	lastFrame = steady_clock::time_point(steady_clock::now());
}

float Timer::GetDeltaTime() {
	return duration<float>(steady_clock::now() - lastFrame).count();
}

void Timer::Tick() {
	lastFrame = steady_clock::time_point(steady_clock::now());
}