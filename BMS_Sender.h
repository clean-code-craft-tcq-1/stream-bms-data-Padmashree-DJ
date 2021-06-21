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
}ResultType;

typedef enum{
	ToConsole
}Targettype;
typedef enum{
	FileInput,
	RandomGeneration
}InputType;

#define MAX_BATTERY_DATA 40
#define RAND_MAX   1.0456

ResultType readfromfile(float Temperature[],float SOC[]);
ResultType printtoconsole(float Temperature[],float SOC[],int arraylength);
ResultType Read_Input_Data(InputType Source);
ResultType OutputtoTarget(Targettype Target);
int random_number(int min_num, int max_num);
ResultType readfromrand(float randarraytemp[],float randarraysoc[]);
extern float Temperature[MAX_BATTERY_DATA];
extern float SOC[MAX_BATTERY_DATA];


#endif