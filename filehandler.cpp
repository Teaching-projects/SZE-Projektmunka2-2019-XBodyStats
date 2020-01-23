#include "filehandler.h"
using namespace  std;

void FileHandler::appendContent(std::string content)
{
    this->fileContent += content;
}

std::string FileHandler::getExerciseFile()
{

    ifstream f("config.txt");
    ifstream f2("config.txt");

    string number;
    int intNumber;

    f >> number;
    f2 >> intNumber;

    this->exerciseCount = intNumber;

    return number + "exerciseAnalysis";
}

void FileHandler::writeToFile()
{

    ofstream f(this->fileName);
    f << this->fileContent;

    ofstream config("config.txt");
    config << this->exerciseCount;
}


