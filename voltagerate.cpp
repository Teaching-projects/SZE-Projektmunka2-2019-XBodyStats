#include "voltagerate.h"

VoltageRate::VoltageRate(std::vector<ModelData*>& _data):Algorithm (_data){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 20; j++){
            mins[i][j] = 0;
        }
    }
}

std::string VoltageRate::run(){
    double sum = 0;
    double max;
    bool talalt;
    for(auto d:data){
        double bmi = d->user.weight/pow((d->user.height / 100.0), 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(int time = 0 ; time < d->seconds.size();time++){
                ExerciseSecond* now = d->seconds[time];
                for(int i = 0; i < now->muscles.size(); i++){
                    if(now->muscles[i]->muscle == this->muscle && now->muscles[i]->isSelected == true){
                        int asdasd = now->time/60;
                        mins[0][(int)(now->time / 60)]++;
                        mins[1][(int)(now->time / 60)] += now->muscles[i]->percent;
                        int asdij = mins[0][(int)(now->time/60)];
                        int k;
                        /*for(int j = i-1; j >= 0; j--){
                            if(d->seconds[j]->muscles[i]->muscle == this->muscle && (d->seconds[j]->muscles[i]->isSelected == true || j ==0)){
                                int p = (int)(now->time / 60);
                                mins[1][(int)(now->time / 60)] += now->muscles[i]->percent - d->seconds[j]->muscles[j]->percent;
                            }
                        }*/
                    }
                }
            }
        }
    }
    for(int i = 0; i < 20; i++){
        int mfds = mins[0][i];
        if(mins[0][i] != 0){
            mins[1][i] = mins[1][i] / mins[0][i];
            sum += mins[0][i];
        }
    }
    talalt = false;
    for (int i = 0;i<20;i++) {
        if(mins[0][i]>=sum/6){
            mins[2][i] = 1;
            talalt = true;
        }
    }
    if(false == talalt){
        return "Nincs osszefugges az adott kategoria es izomcsoporton tortent valtoztatasok kozott.";
    }else{
        std::string toreturn = "Az általunk talalt osszefugges(ek) az adott kategoria es a(z) adott izomcsoport kozott:\n";
        for (int i = 0; i < 20; i++) {
            if(mins[2][i] == 1){
                int valami = mins[1][i] - mins[1][i-1];
                toreturn += std::to_string(i) + ". perc\t" + std::to_string((mins[1][i] - mins[1][i-1])) + "%\n";
                //int valami = mins[1][i] - mins[1][i-1];
                int asf;
            }
        }
        std::string s = toreturn;
        std::cout << toreturn;
        return toreturn;
    }
}

VoltageRate::~VoltageRate(){
    FileHandler::getInstance().appendContent(this->run());
}
