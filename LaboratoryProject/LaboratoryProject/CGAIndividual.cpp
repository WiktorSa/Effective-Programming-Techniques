#include "CGAIndividual.h"

const double CGAIndividual::dCrossoverChance = 0.3;
const double CGAIndividual::dChanceTakeGenFromParent1 = 0.5;
const double CGAIndividual::dMutationChance = 0.2;

CGAIndividual::CGAIndividual(CMax3SatProblem* pcProblem, std::mt19937* cRandEngine)
{
	this->iLengthGenotype = pcProblem->iGetNumberVariables();
	pdGenotype = new int[iLengthGenotype];
	std::uniform_int_distribution<> dis(0, 1);
	for (int i = 0; i < iLengthGenotype; i++)
	{
		pdGenotype[i] = dis(*cRandEngine);
	}
	bFitnessCalculated = false;
	dFitness = 0.0;
}

CGAIndividual::CGAIndividual(CGAIndividual& pcOther)
{
	iLengthGenotype = pcOther.iLengthGenotype;
	pdGenotype = new int[iLengthGenotype];
	for (int i = 0; i < iLengthGenotype; i++)
	{
		pdGenotype[i] = pcOther.pdGenotype[i];
	}
	bFitnessCalculated = false;
	dFitness = 0.0;
}

CGAIndividual::CGAIndividual(int iLengthGenotype)
{
	this->iLengthGenotype = iLengthGenotype;
	pdGenotype = new int[iLengthGenotype];
	bFitnessCalculated = false;
	dFitness = 0.0;
}

// Will never be null cause we don't use any move semantics etc.
CGAIndividual::~CGAIndividual()
{
	delete pdGenotype;
}

// Vector is only used because it's hard to easily return two values
std::vector<CGAIndividual*>* CGAIndividual::pcCrossover(CGAIndividual* pcOtherParent, std::mt19937* cRandEngine)
{
	std::vector<CGAIndividual*>* vChildren = new std::vector<CGAIndividual*>;
	if (double((*cRandEngine)()) / double((*cRandEngine).max()) <= dCrossoverChance) {
		CGAIndividual* child1 = new CGAIndividual(iLengthGenotype);
		CGAIndividual* child2 = new CGAIndividual(iLengthGenotype);

		for (int i = 0; i < iLengthGenotype; i++)
		{
			if (double((*cRandEngine)()) / double((*cRandEngine).max()) <= dChanceTakeGenFromParent1) {
				child1->pdGenotype[i] = this->pdGenotype[i];
				child2->pdGenotype[i] = pcOtherParent->pdGenotype[i];
			}

			else {
				child2->pdGenotype[i] = this->pdGenotype[i];
				child1->pdGenotype[i] = pcOtherParent->pdGenotype[i];
			}
		}

		vChildren->push_back(child1);
		vChildren->push_back(child2);
		return vChildren;
		
	}

	else {
		vChildren->push_back(new CGAIndividual(*this));
		vChildren->push_back(new CGAIndividual(*pcOtherParent));
		return vChildren;
	}
}

void CGAIndividual::vMutation(std::mt19937* cRandEngine)
{
	for (int i = 0; i < iLengthGenotype; i++)
	{
		if (double((*cRandEngine)()) / double((*cRandEngine).max()) <= dMutationChance) {
			pdGenotype[i] = (pdGenotype[i] + 1) % 2;
		}
	}
}

// The pcProblem won't change
double CGAIndividual::dCalculateFitness(CMax3SatProblem* pcProblem)
{ 
	if (!bFitnessCalculated) {
		dFitness = pcProblem->dCompute(pdGenotype);
		bFitnessCalculated = true;
	}

	return dFitness;
}
