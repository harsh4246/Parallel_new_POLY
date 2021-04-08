#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#include <vector>
#include "Gene.h"
#include "Epoch.h"
#include "VehicleData.h"

class GeneticAlgorithm
{
    public:
        GeneticAlgorithm(int noOfEpoch, int epochLen, int generationSize,vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration);
        virtual ~GeneticAlgorithm();

        vector<Gene> bestGenes;

    protected:

    private:
};

#endif // GENETICALGORITHM_H
