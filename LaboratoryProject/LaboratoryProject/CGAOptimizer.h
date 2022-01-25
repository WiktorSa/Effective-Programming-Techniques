#pragma once
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include <random>
#include <vector>

class CGAOptimizer
{
public:
	CGAOptimizer(CMax3SatProblem* pcProblem) { this->pcProblem = pcProblem; pcBestFound = NULL; };
	~CGAOptimizer();
	void vInitialize();
	void vRunIteration();
	CGAIndividual* pcGetBestFound() { return pcBestFound; }

private:
	void vClearPopulation();
	CGAIndividual* pcChooseParent();
	CGAIndividual* pcChooseCandidate();
	void vFindPcBestFound();

	CMax3SatProblem* pcProblem;
	std::mt19937 cRandEngine;
	CGAIndividual* pcBestFound;
	std::vector<CGAIndividual*>  vPopulation;
	static const int iPopulationSize;
};

