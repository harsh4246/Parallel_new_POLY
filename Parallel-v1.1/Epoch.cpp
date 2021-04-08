#include "Epoch.h"

Epoch::Epoch(int epochLen,vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration, int generationSize):bestGene(dummy)
{
//    this->bestGene(dummy);
    this->epochLen=epochLen;
    this->generationSize=generationSize;

    Generation generation(dronesData,obstaclesData,targetsData,frameTime,duration,generationSize);
    for (int i=0;i<this->epochLen;i++){
        generation.simulateGeneration();
        generation.evolve();
    }
    this->bestGene=generation.droneGenes[0];
}

Epoch::~Epoch()
{
    //dtor
}

void Epoch:: simulateEpoch(){

}
