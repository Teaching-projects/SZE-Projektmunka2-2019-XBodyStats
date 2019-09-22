#include "datamining.h"

DataMining::~DataMining()
{
    delete data;
    delete result;
}

std::string* DataMining::getResult() const
{
    return result;
}

void DataMining::analyzeData()
{
    //TODO
}
