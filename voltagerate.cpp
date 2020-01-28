#include "voltagerate.h"

VoltageRate::VoltageRate(std::vector<ModelData*>& _data):Algorithm (_data){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 20; j++){
            mins[i][j] = 0;
        }
    }
}

std::string VoltageRate::run(){
    int sum = 0;
    int max;
    bool talalt;
    for(auto d:data){
        int bmi = d->user.weight/pow(d->user.height, 2);
        if((d->user.sex == sex) && (d->user.age <= maxage) && (d->user.age >= minage) && (bmi <= maxbmi) && (bmi >= minbmi)){
            for(auto s: d->seconds){
                for(int i = 0; i < s->muscles.size(); i++){
                    if(s->muscles[i]->muscle == this->muscle && s->muscles[i]->isSelected == true){
                        mins[0][(int)(s->time / 60)]++;
                        for(int j = i; j >= 0; j++){
                            if(s->muscles[i]->muscle == this->muscle && s->muscles[i]->isSelected == true){
                                mins[1][(int)(s->time / 60)] += s->muscles[i]->percent - s->muscles[j]->percent;
                            }
                        }
                    }
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
        return "Nincs osszefugges az adott kategoria es izomcsoporton tortent valtoztatasok kozott.";
    }else{
        std::string toreturn = "Az általunk talalt osszefugges(ek) az adott kategoria es a(z) adott izomcsoport kozott:\n";
        for (int i = 0; i < 20; i++) {
            if(mins[2][i] == 1){
                toreturn += i + ". perc\t" + std::to_string(mins[1][i]) + "%\n";
            }
        }
        return toreturn;
    }
}

VoltageRate::~VoltageRate(){
    FileHandler::getInstance().appendContent(this->run());
}
