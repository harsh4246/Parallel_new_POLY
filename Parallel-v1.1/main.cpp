#include <iostream>
#include "Vehicle.h"
#include "Drone.h"
#include "Obstacle.h"
#include "Target.h"
#include <cstdlib>
#include <ctime>

#include "GeneticAlgorithm.h"

#include "Arena.h"
using namespace std;

void takeManualInput(vector<VehicleData*> &dronesData,vector<VehicleData*> &obstaclesData,vector<VehicleData*> &targetsData){
    int numDrones;
    int numObstacles;
    int numTargets;
    cout<<"Enter numDrones numObstacles numTargets "<<endl;
    cin>>numDrones>>numObstacles>>numTargets;
    for (int i=0;i<numDrones;i++){
        double weight;
        cout<<"Enter weight of drone"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force drone can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity drone can sustain"<<endl;
        cin>>maxVel;

        vector<double> position(3,0);
        cout<<"Enter Drone position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter Drone current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the drone has"<<endl;
        cin>>tolerance;

        dronesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }


    for (int i=0;i<numObstacles;i++){
        double weight;
        cout<<"Enter weight of obstacle"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force obstacle can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity obstacle can sustain"<<endl;
        cin>>maxVel;

        vector<double> position(3,0);
        cout<<"Enter obstacle position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter obstacle current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the obstacle has"<<endl;
        cin>>tolerance;

        obstaclesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }

    for (int i=0;i<numTargets;i++){
        double weight;
        cout<<"Enter weight of target"<<endl;
        cin>>weight;

        int maxForce;
        cout<<"enter the max force target can apply"<<endl;
        cin>>maxForce;

        double maxVel;
        cout<<"Enter the max velocity target can sustain"<<endl;
        cin>>maxVel;

        vector<double> position(3,0);
        cout<<"Enter target position in space separated triads"<<endl;
        cin>>position[0]>>position[1]>>position[2];

        vector<double> velocity(3,0);
        cout<<"Enter target current velocity in space separated triads"<<endl;
        cin>>velocity[0]>>velocity[1]>>velocity[2];

        vector<double> direction(3,0);
        cout<<"Enter the current direction in which velocity is present"<<endl;
        cin>> direction[0]>>direction[1]>>direction[2];

        double tolerance;
        cout<<"Enter the tolerance that the target has"<<endl;
        cin>>tolerance;

        targetsData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }
}

void takeAutoInput(vector<VehicleData*> &dronesData,vector<VehicleData*> &obstaclesData,vector<VehicleData*> &targetsData){
    int numDrones;
    int numObstacles;
    int numTargets;
    cout<<"Enter numDrones numObstacles numTargets "<<endl;
    cin>>numDrones>>numObstacles>>numTargets;

    for (int i=0;i<numDrones;i++){
        double weight=rand()%100;
        cout<<"weight init is "<<weight<<endl;
        int maxForce=rand()%100000 +100000;
        cout<<"maxForce init is "<<maxForce<<endl;
        double maxVel=rand()%1000 +500;
        cout<<"maxvel init is "<<maxVel<<endl;
        vector<double> position(3,0);
        cout<<"pos init is ";
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*5;
            cout<<position[i]<<" ";
        }
        cout<<endl;

        cout<<"vel init is ";
        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
            cout<<velocity[i]<<" ";
        }
        cout<<endl;

        cout<<"dir init is ";
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
            cout<<direction[i]<<" ";
        }
        cout<<endl;

        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        cout<<"tolerance init is "<<tolerance<<endl;
        dronesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));

    }

    cout<<"please provide a max values of coordinates"<<endl;
    vector<double> boundary(3,0);
    for (int i=0;i<3;i++){
        cin>>boundary[i];
    }


    for (int i=0;i<numObstacles;i++){
        double weight=0;
        int maxForce=0;
        double maxVel=0;

        vector<double> position(3,0);
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*boundary[i];
        }

        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
        }
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
        }
        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        obstaclesData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));
    }

    for (int i=0;i<numTargets;i++){
        double weight=0;
        int maxForce=0;
        double maxVel=0;

        vector<double> position(3,0);
        for (int i=0;i<3;i++){
            position[i]=((double)rand()/(double)RAND_MAX)*boundary[i];
        }

        vector<double> velocity(3,0);
        for (int i=0;i<3;i++){
            velocity[i]=0;
        }
        vector<double> direction(3,0);
        for (int i=0;i<3;i++){
            direction[i]=0;
        }
        double tolerance=((double)rand()/(double)RAND_MAX)*2;
        targetsData.push_back(new VehicleData(weight,maxForce,maxVel,tolerance,position,velocity,direction));
    }
}

int main()
{
    srand(time(nullptr));
    vector<VehicleData*> dronesData;
    vector<VehicleData*> obstaclesData;
    vector<VehicleData*> targetsData;
    cout<<"press 'y' and enter if you want to give manual input"<<endl;
    cout<<"press 'n' and enter if you want to allow automatic input"<<endl;
    char x;
    cin>>x;
    if(x=='y'||x=='Y'){
        takeManualInput(dronesData,obstaclesData,targetsData);
    }
    else takeAutoInput(dronesData,obstaclesData,targetsData);

    double frameTime;
    cout<<"please enter the frame time"<<endl;
    cin>>frameTime;

    double duration;
    cout<<"please enter the maxTime/duration"<<endl;
    cin>>duration;
    GeneticAlgorithm instance(10,10,20,dronesData,obstaclesData,targetsData,frameTime,duration);

    for (int i=0;i<instance.bestGenes.size();i++){
        cout<<instance.bestGenes[i].score<<endl;
    }

    return 0;
}
