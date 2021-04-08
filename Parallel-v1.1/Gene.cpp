#include "Gene.h"

Gene::Gene(vector<double> gene)
{
    this->gene=gene;
    this->score=-1;
}

Gene::~Gene()
{
    //dtor
}

bool Gene:: operator < (const Gene& gene){
         this->score<gene.score;
      }
