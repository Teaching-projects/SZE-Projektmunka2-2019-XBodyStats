#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H
#include "Algorithm.h"
#include <cmath>
#include <string>

class Relationship : public Algorithm
{
public:
    Relationship(std::vector<ModelData*>& _data);
    std::string run();
    int muscrerelation[11][11];
    ~Relationship();
};

#endif // RELATIONSHIP_H
