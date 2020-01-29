#include "startvoltage.h"
#include <iostream>
#include <sstream>

StartVoltage::StartVoltage(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data,params){}

std::string StartVoltage::run(){
    //int sum = 0;
    int db = 0;
    //for(;;){} muscle iterálás

    double sum[11];
    double avrg[11];
    for (int i = 0; i < 11; i++) {
        sum[i] = 0;
    }
    for(auto d:data){
        double bmi = d->user.weight/pow((d->user.height/100.0), 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            db++;
            for(int i = 0; i < 11; i++){
                sum[i] += d->seconds[0]->muscles[i]->percent;
            }
        }
    }

    std::string toreturn = "\n\n\n-----------------\nOutput of StartVoltage:\nEbben a kategoriaban az izomcsoportok atlagos kezdo feszultsegszintje: \n";
    std::stringstream ss("");
    ss << toreturn;
    for (int i = 0; i < 11; i++) {
        avrg[i] = sum[i] / db;
        ss << this->format(izomcsoport[i],4) <<'\t' << std::setprecision(4) << avrg[i] << "%\n";
        //toreturn += this->format(izomcsoport[i],4) + '\t' + std::to_string(avrg[i]) + "%\n";

    }
    toreturn = ss.str();
    return toreturn;
}

StartVoltage::~StartVoltage(){
    FileHandler::getInstance().appendContent(this->run());
}
