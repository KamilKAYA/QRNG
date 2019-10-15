#include <iostream>
#include "filecontrol.h"
#include <string.h>
#include "postprocessing.h"

using namespace std;

static FILECONTROL readCSV;
static FILECONTROL saveDAT;


int main()
{
    string readingfile;
    string readingpath;

    string writingfile;
    string writingpath;

    cout<<" Ozyegin University, Department of EEE"<<endl;
    cout<<" Please write file path where program will read : ";
    cin>>readingpath;
    cout<<" Please write file name where program will read : ";
    cin>>readingfile;
    cout<<" Please write file path where program will write : ";
    cin>>writingpath;
    cout<<" Please write file name where program will write : ";
    cin>>writingfile;

    readCSV.open({readingpath,readingfile});
    saveDAT.save({writingpath,writingfile});

    for(int i=0; i<1000000; i++){
        string readline=readCSV.read();
        readline=readCSV.removeBefore(readline,',');
        double rawData=readCSV.strToDouble(readline);
        saveDAT.write(rawData);



    }
    return 0;
}
