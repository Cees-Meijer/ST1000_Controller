#define DELAYTIME 1000
#include <serialib.h>

#pragma pack(1)
typedef struct
{
 unsigned short TxPulse;
 unsigned short TimeOut;
 unsigned short LockOut;
 unsigned short WaitTime;
 unsigned char InitialGain;
 unsigned short GainIncrement;
 unsigned short ScaleNum;
 unsigned short ScaleDenom;
 unsigned short MaxDistance;
 unsigned short ScaleDACNum;
 unsigned short ScaleDACDenom;
 unsigned char RangeUnits;
 unsigned char Checksum;
}ParamsType;
typedef struct{
 unsigned short Range;
 char Reply;
 }EchoRangeType;
#pragma pack()
typedef struct{
 int Time;
 float Angle;
 unsigned short Range;
 float X;
 float Y;
 }EchoDataType;
ParamsType Params;

bool SaveSettings();
char WriteCommand(char*C,int len);
bool ReadSettings();
bool ReadParameters();
bool SendCommand(char m[255],unsigned int len,char Reply);
bool UpdateParams();
bool Step(bool cw);
bool GoLeft();
bool GoRight();
bool EstablishCentre();
bool FindSensorEdge(bool Direction,bool Edge, unsigned short Count);

bool DetectedEdge,HaveLostSteps;
unsigned short Counter,SenseLeft, SenseRight,SenseMiddle,ScanAhead,L0,L1,R0,R1;
float StepAngleDegrees;
char PosSensor;
int Steps,Position;
serialib ScannerPort;
