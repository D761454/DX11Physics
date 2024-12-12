#pragma once

#include <vector>

template <typename T, size_t size>
class CircularBuffer
{
	vector<T> data;
	unsigned int lastEntryPos;

	CircularBuffer() : data(size), lastEntryPos(0) {};

	// https://stackoverflow.com/questions/22612680/whats-a-good-data-structure-for-a-24hr-minute-by-minute-boolean-record

	void RecordEntry(T in) {
		data[lastEntryPos] = in;
		lastEntryPos = (lastEntryPos + 1) % data.size(); // when at max, go back to start
	}
};

