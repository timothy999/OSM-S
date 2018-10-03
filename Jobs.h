/*
 * Jobs.h
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#ifndef JOBS_H_
#define JOBS_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include "Tasks.h"

class Jobs
{
public:
	Jobs(std::vector<unsigned short> job);
	virtual ~Jobs();
	void totalTime();
	unsigned long getTime() const;
	Tasks giveTasks();
	unsigned long getDuration() const;
	void setDuration(unsigned long duration);

private:
	std::vector<Tasks> allTasks;
	unsigned long tTime = 0;
	unsigned long duration;
	unsigned short currentTask = 0;
};

#endif /* JOBS_H_ */
