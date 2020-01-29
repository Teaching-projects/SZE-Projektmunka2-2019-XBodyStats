#include "slideorbutton.h"
#include <sstream>

SlideOrButton::SlideOrButton(std::vector<ModelData*>& _data, AlgorithmParams* params):Algorithm (_data,params){}

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
    double sum = buttonpercent+sliderpercent;
    std::string s;
    double button = (double)((buttonpercent/sum)*100.0);
    double slider = (double)((sliderpercent/sum)*100.0);
    std::stringstream ss("");
    ss << "\n\n\n-----------------\nOutput of SlideOrButton:\nA valtoztatasok " << std::setprecision(4) << button << "%-a tortent gombbal, mig " << std::setprecision(4) << slider << "%-a csuszkaval.";

    s =  "A valtoztatasok " + std::to_string(double((buttonpercent/sum)*100.0)) + "%-a tortent gombbal, mig " + std::to_string(double((sliderpercent/sum)*100.0)) + "%-a csuszkaval.";
    //return "\n\n\n-----------------\nOutput of SlideOrButton:\nA valtoztatasok " + std::to_string(int((buttonpercent/sum)*100)) + "%-a tortent gombbal, mig " + std::to_string(int((sliderpercent/sum)*100)) + "%-a csuszkaval.";
    s = ss.str();
    return s;
}

SlideOrButton::~SlideOrButton(){
    FileHandler::getInstance().appendContent(this->run());
}
