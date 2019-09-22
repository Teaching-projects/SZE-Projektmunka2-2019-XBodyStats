#ifndef DATAMINING_H
#define DATAMINING_H
#include "contracts.h"
#include <string>

//Will analyze the data
class DataMining
{
private:
    ModelData* data;
    std::string* result;
public:

    //Requires data from Model
    DataMining(ModelData* modelData):
        data(modelData){}

   std::string *getResult() const;
   void analyzeData();

    ~DataMining();
};

#endif // DATAMINING_H
