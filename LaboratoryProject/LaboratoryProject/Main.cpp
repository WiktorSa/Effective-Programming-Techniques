#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"
#include "Timer.h"
#include <exception>
#include <iostream>

using namespace TimeCounters;

#define dMAX_TIME 20 * 60

void vRunExperiment(CMax3SatProblem* pc_problem)
{
	CTimeCounter c_time_counter;
	double d_time_passed;
	CGAOptimizer c_optimizer(pc_problem);

	c_time_counter.vSetStartNow();
	c_optimizer.vInitialize();
	c_time_counter.bGetTimePassed(&d_time_passed);

	c_optimizer.vRunIteration();
	double dScore = c_optimizer.pcGetBestFound()->dCalculateFitness(pc_problem);
	std::cout << dScore << std::endl;

	while (d_time_passed <= dMAX_TIME)
	{
		c_optimizer.vRunIteration();
		dScore = c_optimizer.pcGetBestFound()->dCalculateFitness(pc_problem);
		std::cout << dScore << std::endl;

		c_time_counter.bGetTimePassed(&d_time_passed);
	}
}


int main(int iArgCount, char** ppcArgValues)
{
	try
	{
		CMax3SatProblem  c_problem;

		if (c_problem.bLoad("C:/Users/User/Desktop/LaboratoryProject/max3sat/50/m3s_50_0.txt") == true) {
			vRunExperiment(&c_problem);
		}

		return 0;
	}

	catch (std::exception& c_exception)
	{
		std::cout << c_exception.what() << std::endl;
		return -1;
	}
}
