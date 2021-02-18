#include <iostream>
#include "serverTCP.h"
using namespace std;

int main()
{
    serverTCP *TCPs = new serverTCP();
    int test = TCPs->createSocket(502);
    cout << test << endl;
    cout << "Hello world!" << endl;
    system("PAUSE");
    return 0;
}
