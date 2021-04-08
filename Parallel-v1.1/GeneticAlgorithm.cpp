#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int noOfEpoch, int epochLen, int generationSize,vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration)
{
    for (int i=0;i<noOfEpoch;i++){
        Epoch epoch(epochLen,dronesData,obstaclesData,targetsData,frameTime,duration,generationSize);
        this->bestGenes.push_back(epoch.bestGene);
    }
}

GeneticAlgorithm::~GeneticAlgorithm()
{
    //dtor
}
