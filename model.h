#ifndef MODEL_H
#define MODEL_H
#include "contracts.h"

// Manages connection with database
class Model
{
private:
    ModelData* data;
public:
    Model();

    //TODO implement database
    ModelData* getData() const;

    ~Model();
};

#endif // MODEL_H
