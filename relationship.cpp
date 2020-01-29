#include "relationship.h"

Relationship::Relationship(std::vector<ModelData*>& _data):Algorithm (_data){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            this->muscrerelation[i][j] = 0;
        }
    }
}

std::string Relationship::run(){
    for(auto dat: data){
        for(auto sec1: dat->seconds){
            for(auto musc1: sec1->muscles){
                if(musc1->isSelected == true){
                    for(auto musc2: sec1->muscles){
                        if(musc1 != musc2){
                            if(musc2->isSelected == true){
                                muscrerelation[musc1->muscle][musc2->muscle]++;
                            }
                        }
                    }
                    for(auto sec2: dat->seconds){
                        if(sec1 != sec2){
                            if((((sec1->time + 10) >= sec2->time) && (sec1->time <= sec2->time)) || (((sec1->time - 10) <= sec2->time) && (sec1->time >= sec2->time))){
                                for(auto musc2: sec2->muscles){
                                    if(musc1 != musc2){
                                        if(musc2->isSelected == true){
                                            muscrerelation[musc1->muscle][musc2->muscle]++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            this->muscrerelation[i][j] /= 2;
        }
    }
    std::string toreturn="Az altalunk felmert edzesek alapjan ezen izomcsoportok intenzitasat modositjak egyszerre:\n";
    std::string izomcsoport[11]={"Quadriceps", "Hamstring", "Glutes", "Abs", "LowerBack", "Back", "Trapezius", "Pectoral", "Arms", "Shoulders", "Calves"};
    int sum;
    for(int i = 0; i < 11; i++){
        sum = 0;
        for(int j = 0; j < 11; j++){
            if(i != j){
                sum += muscrerelation[i][j];
             }
        }
        for(int j = 0; j < 11; j++){
            if(i != j){
                if(muscrerelation[i][j] >= sum / 6){
                    std::string afdasfasf= izomcsoport[i] + " - " + izomcsoport[j];
                    toreturn += izomcsoport[i] + " - " + izomcsoport[j] + '\n';
                }
            }
        }
    }
    return toreturn;
}

Relationship::~Relationship(){
    FileHandler::getInstance().appendContent(this->run());
}
