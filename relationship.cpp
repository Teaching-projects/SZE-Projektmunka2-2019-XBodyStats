#include "relationship.h"
#include <sstream>

Relationship::Relationship(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data, params){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            this->muscrerelation[i][j] = 0;
        }
    }
}

std::string Relationship::run(){

    int osszes[11];

    for(auto dat: data){
        for(auto sec1: dat->seconds){
            for(auto musc1: sec1->muscles){
                if(musc1->isSelected == true){
                    osszes[musc1->muscle]++;
                    for(auto musc2: sec1->muscles){
                        if(musc1 != musc2){
                            if(musc2->isSelected == true){
                               std::string safsd = izomcsoport[musc1->muscle] + " - " + izomcsoport[musc2->muscle];
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
                                            std::string sadaf = izomcsoport[musc1->muscle] + " - " + izomcsoport[musc2->muscle];
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
    std::stringstream ss("");
    ss << "\n\n\n-----------------\nOutput of Relationship:\n\nAz altalunk felmert edzesek alapjan ezen izomcsoportok intenzitasat modositjak egyszerre:\n\n";
    int sum;
    for(int i = 0; i < 11; i++){
        sum = 0;
        for(int j = 0; j < 11; j++){
            if(i != j){
                sum += muscrerelation[i][j];
             }
        }
        if (sum > 0){
            int k = 0;
        }
        for(int j = i; j < 11; j++){
            if(i != j && sum > 5){
                if(muscrerelation[i][j] >= sum / 6){

                    //ss << (izomcsoport[i] + izomcsoport[j]);
                    ss << (this->format(izomcsoport[i],4) + izomcsoport[j])w << " " << std::setprecision(4) << (sum/(double)osszes[i])*100.0 << "%" <<  '\n';
                }
            }
        }
    }
    return ss.str();
}

int allOccurance(int matrix[11][11], int muscle){
    int all=0;
    for(int i =0; i< 11;i++){
        if (i == muscle){
            for(int j =0;j<11;j++){
                all += matrix[i][j];
            }
        }

    }
    return all;
}

Relationship::~Relationship(){
    FileHandler::getInstance().appendContent(this->run());
}
