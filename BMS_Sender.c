#include<stdio.h>
#include<math.h>
#include "BMS_Sender.h"

float Temperature[MAX_BATTERY_DATA]={};
float SOC[MAX_BATTERY_DATA]={};
int g_arraylength=0;
	
SuccessType OutputtoTarget(Targettype Target)
{	

	SuccessType Status = Failure;
	Status=(*Targetoutput[Target])(Temperature,SOC,g_arraylength);
	return Status;
}
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
FILE * file=fopen( "test.txt" , "r");
if (file) {
   for(int loop_ctr=0;fscanf(file, "%f\t\t%f\n", &TemperatureVal,&SOCVal)!=EOF;loop_ctr++)
	{
      lengthOfFile=lengthOfFile+1;
	  Temperature[loop_ctr]=TemperatureVal;
	  SOC[loop_ctr]=SOCVal;
	}
   int g_arraylength= lengthOfFile;
	Status= Success;
	}
	fclose(file);
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
