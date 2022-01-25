#include "CGAOptimizer.h"

const int CGAOptimizer::iPopulationSize = 200;

// CMax3SatProblem will be erased in main
// pcBestFound is in vPopulation
CGAOptimizer::~CGAOptimizer()
{
	vClearPopulation();
	if (pcBestFound != NULL) {
		delete pcBestFound;
	}
}

void CGAOptimizer::vClearPopulation()
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		delete vPopulation.at(i);
	}
	vPopulation.clear();
}

void CGAOptimizer::vInitialize()
{
	for (int i = 0; i < iPopulationSize; i++)
	{
		CGAIndividual* pcIndividual = new CGAIndividual(pcProblem, &cRandEngine);
		vPopulation.push_back(pcIndividual);

		if (i == 0) {
			pcBestFound = new CGAIndividual(*pcIndividual);
		}
	}
}

void CGAOptimizer::vRunIteration()
{
	std::vector<CGAIndividual*>  vNewPopulation;
	while (vNewPopulation.size() < vPopulation.size())
	{
		CGAIndividual* pcParent1 = pcChooseParent();
		CGAIndividual* pcParent2 = pcChooseParent();
		std::vector<CGAIndividual*>* vChilren = pcParent1->pcCrossover(pcParent2, &cRandEngine);
		CGAIndividual* pcChild1 = vChilren->at(0);
		CGAIndividual* pcChild2 = vChilren->at(1);
		pcChild1->vMutation(&cRandEngine);
		pcChild2->vMutation(&cRandEngine);
		vNewPopulation.push_back(pcChild1);
		vNewPopulation.push_back(pcChild2);
		// We don't delete pointers in vChildren because they are now allocated in vNewPopulation
		vChilren->clear();
		delete vChilren;
	}
	
	vClearPopulation();
	vPopulation = vNewPopulation;
	vFindPcBestFound();
}

CGAIndividual* CGAOptimizer::pcChooseParent()
{
	CGAIndividual* pcCandidate1 = pcChooseCandidate();
	CGAIndividual* pcCandidate2 = pcChooseCandidate();
	return pcCandidate1->dCalculateFitness(pcProblem) > pcCandidate2->dCalculateFitness(pcProblem) ? pcCandidate1 : pcCandidate2;
}

CGAIndividual* CGAOptimizer::pcChooseCandidate()
{
	int iChosenCandidate = 0;
	// Avoid error with iChosenCandidate = 0
	while (iChosenCandidate == 0)
	{
		iChosenCandidate = cRandEngine();
	}

	return vPopulation.at(iChosenCandidate % vPopulation.size());
}

void CGAOptimizer::vFindPcBestFound()
{
	for (int i = 0; i < vPopulation.size(); i++)
	{
		if (vPopulation.at(i)->dCalculateFitness(pcProblem) > pcBestFound->dCalculateFitness(pcProblem)) {
			// Because we work with pointers we cannot use = operator 
			// (We could implement it but it could cause a lot of problems later)
			delete pcBestFound;
			pcBestFound = new CGAIndividual(*vPopulation.at(i));
		}
	}
}
