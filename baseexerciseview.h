#ifndef BASEEXERCISEVIEW_H
#define BASEEXERCISEVIEW_H
#include "contracts.h"
#include "exerciseviewdelegate.h"

//AbstractClass implemented by ExerciseView
class BaseExerciseView
{
private:
    //ExerciseViewDelegate* delegate;

public:
    BaseExerciseView(){}

    virtual void display(ViewContent& viewContent) = 0;
    virtual ~BaseExerciseView(){}
};

#endif // BASEEXERCISEVIEW_H
