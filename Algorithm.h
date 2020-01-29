#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <filehandler.h>
#include <iomanip>
#include "contracts.h"
#include<vector>

struct AlgorithmParams{
    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;
};

class Algorithm{
private:

public:
    Algorithm(std::vector<ModelData*>& _data, AlgorithmParams* params = nullptr)
        :data(_data), params(params)
    {
        content = "";
        if (params){
            minage = params->minage;
            maxage = params->maxage;
            sex = params->sex;
            minbmi = params->minbmi;
            maxbmi = params->maxbmi;
        }else{
            minage = 30;
            maxage = 55;
            sex = 0;
            minbmi = 18;
            maxbmi = 25;
        }
    }

    int minage;
    int maxage;
    bool sex;
    int minbmi;
    int maxbmi;

    std::string content;
    std::vector<ModelData*> data;
    AlgorithmParams* params;
    virtual std::string run() = 0;
    //virtual void cleanUp() =0;
    //body is always this->content = this->run();

    std::string izomcsoport[11]={"Quadriceps", "Hamstring", "Glutes", "Abs", "LowerBack", "Back", "Trapezius", "Pectoral", "Arms", "Shoulders", "Calves"};

    std::string format(std::string name, int distance){
       int max = 10;
       int spacerNumber = max - name.length() + distance;
       std::string toReturn = name;
       for(int i=0;i<spacerNumber;i++){
           toReturn += " ";
       }
       return toReturn;
    }

    virtual ~Algorithm(){
    }
};

#endif // ALGORITHM_H

