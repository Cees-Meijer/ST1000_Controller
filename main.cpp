#include <iostream>
#include <wiringPi.h>
#include <unistd.h> //For Sleep
#include <ST_Sonar.h>

using namespace std;
    ST_Sonar ST;
int main()
{

    if((ST.ScannerPort.openDevice("/dev/ttyUSB0",9600)) !=1)return 1;
    printf("serial test start ...\n");

    ST.Params.InitialGain = 50;//0-255
    ST.Params.GainIncrement = 60; //0-255
    ST.Params.LockOut= 60;// Lockout time in 1.96uS [0-65535]
    ST.Params.ScaleDenom=11184 ;
    ST.Params.RangeUnits=1;         // 0=cm, 1= mm units
    ST.Params.MaxDistance = 5000; //Max distance in range units
    ST.Params.TimeOut=ST.Params.MaxDistance;

    //SaveSettings();
    //ReadSettings();
    ST.ReadParameters();
    printf("Get Centre\r\n");
    ST.EstablishCentre();
    ST.SetStepSize(ST.STEP_HALF);
    ST.Scan(100,50);
    return 0;
}
