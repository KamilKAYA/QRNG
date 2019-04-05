/*
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

*/


#include "QRNG.h"

using namespace std;
QRNG myRandomNumbers;


int main(){


start:
    float Limit;
    string readFileName, writeFileName;

    cout<<" Input file name :";
    while(readFileName=="")cin>>readFileName;

    cout<<" Output file name :";
    while(writeFileName=="")cin>>writeFileName;

    cout<<" High logic threshold level (Volt ex. 0.05) :";
    cin>>Limit;

    cout<<" Base number for output file (2,10,16) :";
    int BaseNumber;
    cin>>BaseNumber;

    cout<<" Size of reading byte :";
    unsigned long long int SizeofData;
    cin>>SizeofData;

    //cout<<" Please enter length of bit :";
    unsigned int SizeofBit=8;
    //cin>>SizeofBit;

    cout<<" Scanning step :";
    unsigned int Step;
    cin>>Step;


    /*
    cout<<" Please enter lower limit (float) :";
    cin>>downLimit;
    */

    cout<<" Are you sure the information is correct?(Y/N)";
    char answer = '\0';
    while(answer!='Y'	&&	answer!='N')cin>>answer;
    if(answer=='N')goto start;

    myRandomNumbers.Init(readFileName,writeFileName,Limit,BaseNumber,SizeofData,Step,SizeofBit);

    myRandomNumbers.StartAnalysis();

    myRandomNumbers.close();

    return 0;
}
