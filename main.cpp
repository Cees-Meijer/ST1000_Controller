#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h> //For Sleep


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int fd;
    if(wiringPiSetup() < 0)return 1;
    if((fd = serialOpen("/dev/ttyUSB0",9600)) < 0)return 1;
    printf("serial test start ...\n");
    while(TRUE)
    {
    serialPrintf(fd,"Hello World!!!\n");
    usleep(1000000);
    }
    return 0;
}
