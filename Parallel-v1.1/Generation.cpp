#include "Generation.h"

#include <iostream>

using namespace std;

Generation::Generation(vector <VehicleData*> dronesData,vector <VehicleData*> obstaclesData, vector <VehicleData*> targetsData,
                    double frameTime, double duration, int generationSize)
{
    this->targetsData=targetsData;
    this->dronesData=dronesData;
    this->obstaclesData=obstaclesData;
    this->frameTime=frameTime;
    this->duration=duration;
    this->generationSize=generationSize;

    initGenes(generationSize);
}

Generation::~Generation()
{
    //dtor
}

void Generation::initGenes(int generationSize){
    for (int i=0;i<generationSize;i++){
        this->droneGenes.push_back(Gene(createRandomGene()));
    }
}

vector<double> Generation:: createRandomGene(){
    vector<double> randGene(15,0);
    for (int i=0;i<3;i++){
        randGene[i]=(((double) rand()/RAND_MAX)*10);
    }
    for (int i=3;i<15;i++){
        randGene[i]=((double) rand()/RAND_MAX);
    }
    return randGene;
}

void Generation::simulateGeneration(){
    for (int i=0;i<this->droneGenes.size();i++){
        simulateGene(droneGenes[i]); // parallelization point
    }
    //sort(this->droneGenes.begin(),this->droneGenes.end());
    bubbleSort();
}

void Generation:: bubbleSort(){
    for (int i=0;i<this->droneGenes.size();i++){
        for (int j=i;j<this->droneGenes.size()-1;j++){
            if(droneGenes[j].score > droneGenes[j+1].score){
                Gene temp=droneGenes[j];
                droneGenes[j]=droneGenes[j+1];
                droneGenes[j+1]=temp;
            }
        }
    }
}

void Generation::simulateGene(Gene &gene){
    vector<double> dummy;
    Arena arena(gene.gene,dummy,dummy,this->dronesData,this->obstaclesData,this->targetsData,this->frameTime,this->duration);
    arena.simulateArena();
    gene.score=arena.score;
}

bool Generation:: compare(Gene &g1, Gene &g2){
    return true;
}

void Generation::evolve(){
    eliminateGenes();
    mateGenes();
    regeneratePopulation();
}


void Generation:: mateGenes(){

    for (int j=0;j<2;j++){
        vector<double> gene1(15,0);
        vector<double> gene2(15,0);
        for (int i=0;i<15;i++){
            double randomNum1=((double) rand()/RAND_MAX);
            double randomNum2=((double) rand()/RAND_MAX);
            gene1[i]=randomNum1*this->droneGenes[j].gene[i]+(1-randomNum1)*this->droneGenes[j+1].gene[i];
            gene2[i]=randomNum2*this->droneGenes[j].gene[i]+(1-randomNum2)*this->droneGenes[j+1].gene[i];
        }
        this->droneGenes.push_back(Gene(gene1));
        this->droneGenes.push_back(Gene(gene2));
    }
}


void Generation:: eliminateGenes(){

    for (int i=this->droneGenes.size()-1;i>3;i--){
        this->droneGenes.erase(this->droneGenes.begin()+i);
    }
}

void Generation::regeneratePopulation(){
    for (int i=8;i<this->generationSize;i++){
        this->droneGenes.push_back(Gene(createRandomGene()));
    }
}
