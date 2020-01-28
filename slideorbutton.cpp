#include "slideorbutton.h"

SlideOrButton::SlideOrButton(std::vector<ModelData*>& _data):Algorithm (_data){}

std::string SlideOrButton::run(){
    int sliderpercent = 0;
    int buttonpercent = 0;

    for(auto d:data){
        for(auto s:d->seconds){
            for(auto m:s->muscles){
                if(m->chagedWith != nullptr){
                    if(*(m->chagedWith) == Button){
                        buttonpercent++;
                    }if(*(m->chagedWith) == Slider){
                        sliderpercent++;
                    }
                }
            }
        }
    }
    int sum = buttonpercent+sliderpercent;
    return "A valtoztatasok " + std::to_string(int((buttonpercent/sum)*100)) + "%-a tortent gombbal, mig " + std::to_string(int((sliderpercent/sum)*100)) + "%-a csuszkaval.";
}

SlideOrButton::~SlideOrButton(){
    FileHandler::getInstance().appendContent(this->run());
}
