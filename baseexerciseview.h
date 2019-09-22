#ifndef BASEEXERCISEVIEW_H
#define BASEEXERCISEVIEW_H
#include "contracts.h"


//AbstractClass implemented by ExerciseView
class BaseExerciseView
{
public:
    BaseExerciseView();

    virtual void display(ViewContent& viewContent) = 0;
    virtual ~BaseExerciseView();
};

#endif // BASEEXERCISEVIEW_H
