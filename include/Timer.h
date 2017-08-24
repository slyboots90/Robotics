/*
 * Timer.h
 *
 *  Created on: 24 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

using namespace std::chrono;

class Timer {

	struct TimerStruct {
		high_resolution_clock::time_point start;
		high_resolution_clock::time_point finish;
	} * timer;

public:
	Timer();
	virtual ~Timer();
};

#endif /* TIMER_H_ */
