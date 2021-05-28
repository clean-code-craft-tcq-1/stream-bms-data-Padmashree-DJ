#include<stdio.h>
#include<math.h>

float Temperature[MAX_BATTERY_DATA]={};
float SOC[MAX_BATTERY_DATA]={};

SuccessType OutputtoTarget(Targettype Target)
{
	int* arraylength;
	int array_a=0;
	arraylength=&array_a;
	SuccessType Status = Failure;
	Status=(*Targetoutput[Target])(Temperature,SOC,*arraylength);
	return Status;
}
SuccessType Read_Input_Data(InputType Source)
{
	SuccessType FileReadSuccess= Failure;
	FileReadSuccess=(*ReadBatteryData[Source])(Temperature,SOC,arraylength);
	return FileReadSuccess;
}

SuccessType readfromfile(float Temperature[],float SOC[],int* arraylength)
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
   *arraylength=lengthOfFile;
   
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
