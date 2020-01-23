#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>

class FileHandler
{
private:
    FileHandler() {
        this->setup();
    }
    ~FileHandler(){
    }
    std::string fileContent;
    std::string fileName;
    int exerciseCount;
    std::string getExerciseFile();
public:

    void setup(){
        this->fileContent = "";
        this->fileName = this->getExerciseFile();
    }

    static FileHandler& getInstance()
    {
        static FileHandler instance; // Guaranteed to be destroyed.
                               // Instantiated on first use.
        return instance;
    }
    void appendContent(std::string content); //algorithm should call this upon colmpleting;
    void writeToFile();
};

#endif // FILEHANDLER_H
