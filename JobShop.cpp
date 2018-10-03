/*
 * JobShop.cpp
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#include "JobShop.h"
#include <string>
#include <algorithm>

JobShop::JobShop()
{
	input = {
	{6, 6},
	{2, 1, 0, 3, 1, 6, 3, 7, 5, 3, 4, 6},
	{1, 8, 2, 5, 4, 10, 5, 10, 0, 10, 3, 4},
	{2, 5, 3, 4, 5, 8, 0, 9, 1, 1, 4, 7},
	{1, 5, 0, 5, 2, 5, 3, 3, 4, 8, 5, 9},
	{2, 9, 1, 3, 4, 5, 5, 4, 0, 3, 3, 1},
	{1, 3, 3, 3, 5, 9, 0, 10, 4, 4, 2, 1}
	};
	createMachines(input[0][1]);
	createJobs(input[0][0]);
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

// maakt de machines aan (bool)
void JobShop::createMachines(unsigned short aantal)
{
	for(int i = 0; i < aantal; ++i)
	{
		bool machine = false;
		allMachines.push_back(machine);
	}
}

// maakt de losse jobs aan en stopt ze in een vector
void JobShop::createJobs(unsigned short aantal)
{
	for(int i = 0; i < aantal; ++i)
	{
		Jobs job(input[i+1]);
		allJobs.push_back(job);
	}
}

// nog veranderen naar laagste totale tijd (ipv hoogste wat hij nu weergeeft)
void JobShop::calculateSlackTime()
{
	for (auto& job : allJobs) job.totalTime();
	std::sort(allJobs.begin(), allJobs.end(),
		[](Jobs& lhs, Jobs& rhs) -> bool
	{
		return lhs.getTime() < rhs.getTime();
	});
}

void JobShop::run()
{
	allJobs[0].giveTasks().setIsDone(true);
	Tasks task = allJobs.at(0).giveTasks();
	std::cout << task.getMachine() << std::endl;
	allJobs[0].giveTasks().setIsDone(true);
	task = allJobs.at(0).giveTasks();
	std::cout << task.getMachine() << std::endl;
	/*
	// while ALLE job tijden niet gelijk zijn aan nul
	while(timer < 120)
	{
		calculateSlackTime();
		for(auto& job : allJobs)
		{
			Tasks task = job.giveTasks();
			std::cout << task.getMachine() << std::endl;
			if(job.getTime() != 0)
			{
				if(checkUnusedMachines(task.getMachine()) == false || task.isRunning() == true)
				{
					setMachine(task.getMachine(), task.getLengthOfTime(), job);
				}
				else if(checkUnusedMachines(task.getMachine()) == true && task.isRunning() == false)
				{
					job.setDuration(1);
				}
			}
			//std::cout << job.getDuration() << std::endl;
		}
		std::cout << " " << std::endl;
		timer++;
		// voor alle jobs door de takenlijst lopen en checken op boolean isKlaar
		// starttijd en eindtijd van een taak toevoegen
	}
	*/
}

// returned of de meegegeven machine op het moment gebruikt wordt
bool JobShop::checkUnusedMachines(unsigned short machine)
{
	return allMachines.at(machine);
}

// verander machine van waarde
void JobShop::setMachine(unsigned short nMachine, unsigned short lengthOfTime, Jobs& job)
{

	if(job.giveTasks().isRunning() == false) job.giveTasks().setStartTime(timer);
	job.giveTasks().setRunning(true);
	allMachines.at(nMachine) = true;
	if(timer - lengthOfTime == job.giveTasks().getStartTime())
	{
		job.setDuration(lengthOfTime);
		allMachines.at(nMachine) = false;
		job.giveTasks().setRunning(false);
		job.giveTasks().setIsDone(true);
	}
}



