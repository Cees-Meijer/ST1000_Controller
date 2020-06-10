#pragma option push -a1
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
#pragma pop
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
int ScannerPort;