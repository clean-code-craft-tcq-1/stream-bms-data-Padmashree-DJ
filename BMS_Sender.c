#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "BMS_Sender.h"

float Temperature[MAX_BATTERY_DATA]={};
float SOC[MAX_BATTERY_DATA]={};
int g_arraylength=0;

SuccessType (*ReadBatteryData[])(float Temperature[],float SOC[])={readfromfile,readfromrand};	
SuccessType(*Targetoutput[])(float Temperature[],float SOC[],int arraylength)={printtoconsole};
	

SuccessType Read_Input_Data(InputType Source)
{
	SuccessType FileReadSuccess= Failure;
	FileReadSuccess=(*ReadBatteryData[Source])(Temperature,SOC);
	return FileReadSuccess;
}

SuccessType readfromfile(float Temperature[],float SOC[])
{
float TemperatureVal,SOCVal;
int lengthOfFile=0;
SuccessType Status= Failure;
FILE * file=fopen( "BatteryData.txt" , "r");
if (file) {
   for(int loop_ctr=0;fscanf(file, "%f\t\t%f\n", &TemperatureVal,&SOCVal)!=EOF;loop_ctr++)
	{
      lengthOfFile=lengthOfFile+1;
	  Temperature[loop_ctr]=TemperatureVal;
	  SOC[loop_ctr]=SOCVal;
	}
    g_arraylength= lengthOfFile;
	Status= Success;
	}
	fclose(file);
	return Status;
}

SuccessType readfromrand(float randarraytemp[],float randarraysoc[])
{
	for(int loop=0;loop<21;loop++)
	{
		float RandTemp=random_number(1,40);
		RandTemp=RAND_MAX*RandTemp;
		randarraytemp[loop]=RandTemp;
		
		float RandSOC=random_number(20,80);
		RandSOC=RAND_MAX*RandSOC;
		randarraysoc[loop]=RandSOC;
		g_arraylength=20;
	}
	return Success;
}

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

SuccessType OutputtoTarget(Targettype Target)
{	

	SuccessType Status = Failure;
	Status=(*Targetoutput[Target])(Temperature,SOC,g_arraylength);
	return Status;
}

SuccessType printtoconsole(float Temperature[],float SOC[],int arraylength)
{

for(int loop=0;loop<arraylength;loop++)
{
	printf("Temp value is %f and SOC value is %f\n",Temperature[loop],SOC[loop]);
}
return Success;
}
