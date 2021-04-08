#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include "Gene.h"
#include <cstdlib>
#include <algorithm>
#include "Arena.h"

#include "VehicleData.h"

using namespace std;

class Generation
{
    public:
        Generation(vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration, int generationSize);
        virtual ~Generation();

        vector<Gene> droneGenes;
        int generationSize;
        //vector<vector<double>> obstacleGenes; //momentarily discarded as not used
        //vector<vector<double>> targetsGenes;
        double frameTime;
        double duration;

        vector <VehicleData*> dronesData;
        vector <VehicleData*> obstaclesData;
        vector <VehicleData*> targetsData;

        void simulateGeneration();
        void simulateGene(Gene &gene);
        void initGenes(int generationSize);
        vector<double> createRandomGene();
        bool compare(Gene &g1, Gene &g2);
        void evolve();
        void mateGenes();
        void eliminateGenes();
        void regeneratePopulation();
        void bubbleSort();

    protected:

    private:
};

#endif // GENERATION_H
