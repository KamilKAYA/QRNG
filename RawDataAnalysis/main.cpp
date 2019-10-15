#include <iostream>
#include "filecontrol.h"

using namespace std;

static FILECONTROL QRNG;

int main()
{

    QRNG.open({"x","y"});
    cout << "Hello World!" << endl;
    return 0;
}
