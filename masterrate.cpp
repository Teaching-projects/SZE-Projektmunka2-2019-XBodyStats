#include "masterrate.h"
#include <iostream>

MasterRate::MasterRate(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data,params){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 20; j++){
            mins[i][j] = 0;
        }
    }
}

std::string MasterRate::run(){
    double sum = 0;
    bool talalt;
    for(auto d:data){
        double bmi = d->user.weight/pow(d->user.height/100.0, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(int i = 1; i < d->seconds.size(); i++){
                if(d->seconds[i]->master != nullptr){
                    /*double korabbi = 0.0;
                    for(int j = i-1; j >= 0; j--){
                        if(d->seconds[j]->master != nullptr){
                            korabbi = d->seconds[j]->master->percent;
                            break;
                        }
                    }*/
                    auto minute = (int)(d->seconds[i]->time / 60);
                    mins[0][(int)(d->seconds[i]->time / 60)]++;
                    auto minsa = mins[0][minute];
                    auto asdas =  d->seconds[i]->master->percent;
                    mins[1][(int)(d->seconds[i]->time / 60)] += d->seconds[i]->master->percent;
                }
            }
        }
    }


    for(int i = 0; i < 20; i++){
        if(mins[0][i] > 0){
            int safsdfa = mins[1][i];
            mins[1][i] = mins[1][i] / (double)mins[0][i];
            /*if(i > 0){
                mins[1][i] = mins[1][i] - mins[1][i-1];
            }*/
            int percossz = mins[0][i];
            sum += mins[0][i];
        }
    }
    talalt = false;
    for (int i = 0;i<20;i++) {
        if(mins[0][i] >= sum/6){
            auto vmi = mins[0][i];
            auto vmiaa = mins;
            mins[2][i] = 1;
            talalt = true;
        }
    }
    if(false == talalt){
        return "\n\n\n-----------------\nOutput of MasterRate:\nNincs osszefugges az adott kategoria es master gomb hasznalata kozott.";
    }else{
        std::string toreturn = "Az általunk talalt osszefugges(ek) az adott kategoria es a master gomb hasznalatanak merteke kozott:\n";
        for (int i = 0; i < 20; i++) {
            if(mins[2][i] == 1){
                auto asdminuszegy = mins[1][i-1];
                auto asd = mins[1][i] - asdminuszegy;
                toreturn += std::to_string(i) + ". perc\t" + std::to_string(mins[1][i] - mins[1][i-1]) + "%\n";
            }
        }
        std::string s =  "\n\n\n-----------------\nOutput of MasterRate:\n" + toreturn;
        //std::cout << s;
        return s;
    }
}

MasterRate::~MasterRate(){
    FileHandler::getInstance().appendContent(this->run());
}
