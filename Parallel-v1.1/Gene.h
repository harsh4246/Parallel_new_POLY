#ifndef GENE_H
#define GENE_H

#include <vector>

using namespace std;

class Gene
{
    public:
        Gene(vector<double> gene);
        virtual ~Gene();

        vector<double> gene;
        double score;

        bool operator < (const Gene& gene);
    protected:

    private:
};

#endif // GENE_H
