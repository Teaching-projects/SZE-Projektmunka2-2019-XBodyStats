#include "selectrate.h"

SelectRate::SelectRate(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string SelectRate::run(){
    int selectdb;
    int osszdb = 0;
    int selectuse = 0;
    for (auto d: data) {
        osszdb += d->seconds.size();
        for(auto min: d->seconds){
            selectdb = 0;
            for(int i = 0; i < min->muscles.size() && selectdb <= 1; i++){
                if(min->muscles[i]->isSelected == true){
                    selectdb++;
                }
            }
            if(selectdb > 1){
                selectuse++;
            }
        }
    }
    return "Az edzesek soran a valtoztatasok " + std::to_string(selectuse/osszdb) + "%-a tortent select gombbal(" + std::to_string(selectuse) + " db)";

}

SelectRate::~SelectRate(){
    FileHandler::getInstance().appendContent(this->run());
}
