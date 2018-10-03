/*
 * Tasks.cpp
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#include "Tasks.h"

Tasks::Tasks(unsigned short  machine, unsigned short lengthOfTime) :
	machine(machine), lengthOfTime(lengthOfTime)
{

}

Tasks::~Tasks()
{
	// TODO Auto-generated destructor stub
}

bool Tasks::isIsDone() const
{
	return isDone;
}

void Tasks::setIsDone(bool isDone)
{
	this->isDone = isDone;
}

unsigned short Tasks::getLengthOfTime() const
{
	return lengthOfTime;
}

unsigned short Tasks::getMachine() const
{
	return machine;
}

bool Tasks::isRunning() const
{
	return running;
}

void Tasks::setRunning(bool running)
{
	this->running = running;
}

unsigned short Tasks::getStartTime() const
{
	return startTime;
}

void Tasks::setStartTime(unsigned short startTime)
{
	this->startTime = startTime;
}
