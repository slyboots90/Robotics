/*
 * Timer.cpp
 *
 *  Created on: 24 aug. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/Timer.h"
#include <iostream>


Timer::Timer() : timer( new TimerStruct ) {
	timer->start = high_resolution_clock::now();
}

Timer::~Timer() {
	timer->finish = high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(timer->finish - timer->start).count() << " ns\n";
	delete timer;
}

