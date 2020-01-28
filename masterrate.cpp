#include "masterrate.h"

MasterRate::MasterRate(std::vector<ModelData*>& _data):Algorithm (_data){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 20; j++){
            mins[i][j] = 0;
        }
    }
}

std::string MasterRate::run(){
    int sum = 0;
    bool talalt;
    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(int i = 0; i < d->seconds.size(); i++){
                if(d->seconds[i]->master != nullptr){
                    int korabbi;
                    for(int j = i; j >= 0; j--){
                        if(d->seconds[j]->master != nullptr){
                            int korabbi = d->seconds[j]->master->percent;
                        }
                    }
                    mins[0][(int)(d->seconds[i]->time / 60)]++;
                    mins[1][(int)(d->seconds[i]->time / 60)] += d->seconds[i]->master->percent - korabbi;
                }
            }
        }
    }
    for(int i = 0; i < 20; i++){
        if(mins[0][i] != 0){
            mins[1][i] = mins[1][i] / mins[0][i];
            sum += mins[0][i];
        }
    }
    talalt = false;
    for (int i = 0;i<20;i++) {
        if(mins[0][i]>=sum/4){
            mins[2][i] = 1;
            talalt = true;
        }
    }
    if(false == talalt){
        return "Nincs osszefugges az adott kategoria es master gomb hasznalata kozott.";
    }else{
        std::string toreturn = "Az általunk talalt osszefugges(ek) az adott kategoria es a master gomb hasznalata kozott:\n";
        for (int i = 0; i < 20; i++) {
            if(mins[2][i] == 1){
                toreturn += i + ". perc\t" + std::to_string(mins[1][i]) + "%\n";
            }
        }
        return toreturn;
    }
}

MasterRate::~MasterRate(){
    FileHandler::getInstance().appendContent(this->run());
}
