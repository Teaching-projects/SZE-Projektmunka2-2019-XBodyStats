#include "generator.h"
#include <cmath>
#include <iostream>

using namespace std;

Generator::Generator()
{
    this->config = Config();
    config.gender = 0;
    config.number = 100;
    config.seconds = 1200;
    config.relationship = vector<Muscle>();
    srand(time(nullptr));
}

int randomNumber(int chance, int lowThreshold = 0){
    int r;

    for(;;){
        r = (rand() % chance) + 1;
        if (r > lowThreshold){
            return r;
        }
    }
}

ExerciseSecond* Generator::beginning(double bmi, int age, bool sex){
    ExerciseSecond* toReturn = new ExerciseSecond;
    double lowerBMI = (bmi > 23) ? (bmi - (bmi - 23)*2) : bmi;

    double bmiPercent = abs(lowerBMI / 23);
    double agePercent;

    if(age <= 30){
        agePercent = 1;
    }else if(age > 30){
        agePercent = 0.95;
    }else {
        agePercent = 0.9;
    }

    double sexPercent = sex ? 0.95 : 1.0;

    double max = 100.0 * bmiPercent * agePercent * sexPercent;

    int muscleStart[Calves];

    for(int i = Quadriceps; i <= Calves; i++){
        Muscle m = static_cast<Muscle>(i);

        int muscleMax = (int)max - randomNumber(7);
        muscleStart[m] = muscleMax;
        MuscleModel* muscle = new MuscleModel;
        muscle->muscle = m;
        muscle->percent = muscleStart[m];
        muscle->chagedWith = nullptr;
        muscle->isSelected = false;
        toReturn->muscles.push_back(muscle);
    }

    toReturn->time = 0;
    toReturn->master.percent = 50;

    return toReturn;
}

vector<ModelData*> Generator::generateModels()
{
    vector<ModelData*> toReturn;


    for(int i=0; i<config.number; i++){
        ModelData* data = new ModelData();
        data->user.sex = (randomNumber(100) <= 50) ? false : true;
        data->user.age = randomNumber(60,18);
        data->user.height = randomNumber(190,155);
        data->user.weight = randomNumber(90,55);
        data->type = Weights;
        data->fileName = i;

        double bmi = data->user.weight / ((double)(data->user.height/100.0) * (double)(data->user.height/100.0));

        data->seconds.push_back(this->beginning(bmi,data->user.age,data->user.sex));

        for(int j = 0;j<config.seconds;j++){

        }

        toReturn.push_back(data);

    }
    return toReturn;
}
