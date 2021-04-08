#ifndef EPOCH_H
#define EPOCH_H
#include "VehicleData.h"
#include "Generation.h"

#include <vector>

using namespace std;
class Epoch
{
    public:
        Epoch(int epochLen,vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration, int generationSize);
        virtual ~Epoch();
        vector<double> dummy;
        Gene bestGene;
        int epochLen;
        int generationSize;

        void simulateEpoch();

    protected:

    private:
};

#endif // EPOCH_H
