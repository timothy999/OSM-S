/*
 * Tasks.h
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#ifndef TASKS_H_
#define TASKS_H_

#include <iostream>

class Tasks
{
public:
	Tasks(unsigned short machine, unsigned short lengthOfTime);
	virtual ~Tasks();
	bool isIsDone() const;
	void setIsDone(bool isDone = false);
	unsigned short getLengthOfTime() const;
	unsigned short getMachine() const;
	bool isRunning() const;
	void setRunning(bool running = false);
	unsigned short getStartTime() const;
	void setStartTime(unsigned short startTime);

private:
	unsigned short machine;
	unsigned short lengthOfTime;
	bool isDone = false;
	bool running = false;
	unsigned short startTime = 0;
};

#endif /* TASKS_H_ */
