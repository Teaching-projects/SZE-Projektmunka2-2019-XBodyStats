#ifndef ALGORITHMQUEUE_H
#define ALGORITHMQUEUE_H
#include "Algorithm.h"
#include <vector>
#include <iostream>
#include "generator.h"
#include "selectrate.h"
#include "slideorbutton.h"
#include "startenddifferent.h"
#include "startvoltage.h"
#include "voltagerate.h"
#include "masterallrate.h"
#include "masterrate.h"
#include "relationship.h"

using namespace std;

class AlgorithmQueue
{
private:
    vector<Algorithm*> algorithms;
public:
    AlgorithmQueue(vector<ModelData*> testData, AlgorithmParams* params){
        algorithms.push_back(new SelectRate(testData, params));
        algorithms.push_back(new SlideOrButton(testData, params));
        algorithms.push_back(new StartVoltage(testData, params));
        algorithms.push_back(new StartEndDifferent(testData, params));
        algorithms.push_back(new VoltageRate(testData, params));
        algorithms.push_back(new MasterAllRate(testData, params));
        algorithms.push_back(new MasterRate(testData, params));
        algorithms.push_back(new Relationship(testData, params));
    }
    ~AlgorithmQueue(){
        for(auto& x: algorithms){
            delete x;
        }
    }
};

#endif // ALGORITHMQUEUE_H
