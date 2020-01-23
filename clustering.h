#ifndef CLUSTERING_H
#define CLUSTERING_H
#include "Algorithm.h"

class Clustering: public Algorithm
{
public:
    Clustering(ModelData* d)
        :Algorithm(d){
    }

    std::string run(ModelData *data) override{
        return "hello";
    }
    void cleanUp() override{
        this->content = this->run(nullptr);
    }
    ~Clustering(){
        this->cleanUp();
    }
};

#endif // CLUSTERING_H
