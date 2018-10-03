/*
 * JobShop.h
 *
 *  Created on: 22 sep. 2018
 *      Author: andre
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <iostream>
#include <vector>
#include "Jobs.h"

class JobShop
{
public:
	JobShop();
	virtual ~JobShop();
	void createJobs(unsigned short aantal);
	void createMachines(unsigned short aantal);
	void calculateSlackTime();
	void run();
	bool checkUnusedMachines(unsigned short machine);
	void setMachine(unsigned short machine, unsigned short lengthOfTime, Jobs& job);
private:
	std::vector< std::vector<unsigned short> > input;
	std::vector<Jobs> allJobs;
	std::vector<bool> allMachines;
	unsigned long long timer = 0;
};

#endif /* JOBSHOP_H_ */
