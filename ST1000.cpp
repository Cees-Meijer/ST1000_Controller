#include <iostream>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <unistd.h> //For Sleep
#include <ST1000.h>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int fd;
    if(wiringPiSetup() < 0)return 1;
    if((ScannerPort = serialOpen("/dev/ttyUSB0",9600)) < 0)return 1;
    printf("serial test start ...\n");

    serialPrintf(ScannerPort,"Hello World!!!\n");
    usleep(1000000);
    Params.Checksum=0;
    Params.GainIncrement=1;
    Params.InitialGain=20;
    Params.LockOut = 10;
    SaveSettings();
    ReadSettings();
    return 0;
}

bool SaveSettings()
{
    FILE* file;
    int bytes_written;

    file = fopen("parameters.cfg", "wb");
    if (!file)
        return -1;
         printf("Size of params %d ",sizeof(Params) );
    bytes_written = fwrite(&Params,1,sizeof(Params),file);
    fclose(file);
    printf(" %d Bytes written",bytes_written );
    if(bytes_written==0){return FALSE;}
    return TRUE;
}

bool ReadSettings()
{

char Reply;
char Command[10];
Command[0]='V';
Reply=WriteCommand(Command,1);
Command[0]='H';
Reply=WriteCommand(Command,1);
Command[0]='=';Command[1]=0;Command[2]=0; // Set motor delay to 0
Reply=WriteCommand(Command,3);
Command[0]='X';
Reply=WriteCommand(Command,1);
Command[0]='K';
Reply=WriteCommand(Command,1);
Command[0]='E';Command[1]=0xD2;
Reply=WriteCommand(Command,2);
Command[0]='T';Command[1]=0x3;Command[2]=0x0;Command[3]=0x0;Command[4]=0x0;Command[5]=0x0;Command[6]=0x81;Command[7]=0x14;Command[8]=0x98;
Reply=WriteCommand(Command,9);
}

char WriteCommand(char*C,int len)
{
char Reply=0;
for (int i=0;i<len;i++){
serialPutchar(ScannerPort,(unsigned char)C[i]);
}

sleep(1);
if(serialDataAvail(ScannerPort)>0){Reply= (char)serialGetchar(ScannerPort);}
return Reply;
}
