#ifndef STARTENDDIFFERENT_H
#define STARTENDDIFFERENT_H
#include "Algorithm.h"
#include <string>

class StartEndDifferent:public Algorithm
{
public:
    StartEndDifferent(std::vector<ModelData*>& _data);
    std::string run();
private:
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
    Muscle muscle;

    ~StartEndDifferent();
};

#endif // STARTENDDIFFERENT_H
