/*
 * Jobs.cpp
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#include "Jobs.h"

Jobs::Jobs(std::vector<unsigned short> job)
{
	for(std::vector<unsigned short>::iterator i = job.begin(); i != job.end(); i++)
	{
		unsigned short x = *i;
		unsigned short y = *(++i);
		Tasks task(x, y);
		allTasks.push_back(task);
	}
}

Jobs::~Jobs()
{
	// TODO Auto-generated destructor stub
}

void Jobs::totalTime()
{
	tTime = 0;
	for(const auto& task: allTasks)
	{
		if(task.isIsDone() == false) tTime += task.getLengthOfTime();
	}
}

unsigned long Jobs::getTime() const
{
	return tTime;
}

// returned de tasks die nog gedaan moeten worden
Tasks Jobs::giveTasks()
{
	if(allTasks.at(currentTask).isIsDone() == true)
	{
		++currentTask;
	}
	return allTasks.at(currentTask);
}

unsigned long Jobs::getDuration() const
{
	return duration;
}

void Jobs::setDuration(unsigned long duration)
{
	this->duration += duration;
}

