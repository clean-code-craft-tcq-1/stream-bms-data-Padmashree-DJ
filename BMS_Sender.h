#ifndef __BMS_SENDER_H
#define __BMS_SENDER_H

typedef struct {
float min;
float max;
}batterydata_tst;

typedef enum
{
	Failure,
	Success
}SuccessType;

typedef enum{
	ToConsole
}Targettype;
typedef enum{
	FileInput,
	RandomGeneration
}InputType;
#define MAX_BATTERY_DATA 40

SuccessType readfromfile(float Temperature[],float SOC[]);
SuccessType printtoconsole(float Temperature[],float SOC[],int arraylength);
SuccessType Read_Input_Data(InputType Source);
SuccessType OutputtoTarget(Targettype Target);
extern float Temperature[MAX_BATTERY_DATA];
extern float SOC[MAX_BATTERY_DATA];


#endif