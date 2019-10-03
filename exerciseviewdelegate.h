#ifndef EXERCISEVIEWDELEGATE_H
#define EXERCISEVIEWDELEGATE_H

//Delegate class inherited by ExerciseViewController
class ExerciseViewDelegate
{
public:
    ExerciseViewDelegate();
    virtual ~ExerciseViewDelegate();

protected:

    virtual void muscleButtonOnPress(int buttonId);
    virtual void mainButtinOnPress(bool direction);
    virtual void sliderChanged(int value);

    /* Will be added if needed
    virtual void optionsPressed();
    */
};

#endif // EXERCISEVIEWDELEGATE_H
