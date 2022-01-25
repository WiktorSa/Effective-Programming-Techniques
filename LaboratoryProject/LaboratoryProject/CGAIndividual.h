#pragma once
#include "CMax3SatProblem.h"
#include <random>
#include <vector>

class CGAIndividual
{
public:
	CGAIndividual(CMax3SatProblem* pcProblem, std::mt19937* cRandEngine);
	CGAIndividual(CGAIndividual& pcOther);
	~CGAIndividual();

	int* piGetResultsAsTable() { return pdGenotype; }
	std::vector<CGAIndividual*>* pcCrossover(CGAIndividual* pcOtherParent, std::mt19937* cRandEngine);
	void vMutation(std::mt19937* cRandEngine);
	double dCalculateFitness(CMax3SatProblem* pcProblem);

private:
	CGAIndividual(int iLengthGenotype);
	int* pdGenotype;
	int iLengthGenotype;
	bool bFitnessCalculated;
	double dFitness;
	static const double dCrossoverChance;
	static const double dChanceTakeGenFromParent1;
	static const double dMutationChance;
};

