#ifndef QRNG_H
#define QRNG_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <dirent.h>
#include <fstream>

class QRNG{
    private:
        float Threshold;
        std::string readingFileName;
        std::string writingFileName;
        std::ofstream exportFile;
        std::ofstream exportFileRaw;
        std::ifstream importFile;
        unsigned long long int line;
        float timeData, voltage;
        bool complate;
        int Base;
        unsigned int Step;
        unsigned int BitLength;
        unsigned long SizeOfData;
        unsigned int sizeOfBitOne;
        unsigned int sizeOfBitZero;
    public:
        QRNG();
        ~QRNG();
        void Init(std::string,std::string,float,int,unsigned long long int,unsigned int,unsigned int);
        uint8_t StartAnalysis();
        void close();
};

#endif // QRNG_H
