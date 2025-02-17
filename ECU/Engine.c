#include "Engine.h"
extern int gear_state; // 0: P, 1: N, 2: R, 3: D
extern int accel_val; // 0, 1, 2, 3
extern int break_val; // 0, 1, 2, 3
extern int wink_state; // 0: None, 1: Left, 2: right, 3: Warning
extern int current_speed;
extern int RPM;

void accelActuator()
{
	RPM = RPM+20;
	if(RPM>240)
	{
		RPM = 240;
	}

	switch(gear_state)
	{
		case 0:
		case 1:
			printf("Gear:%d \t[Error] Error Message \n", gear_state);
			break;
		case 2:
		case 3:

			if(current_speed + (accel_val) > MAX_SPEED)
				current_speed = MAX_SPEED;
			else
				current_speed += accel_val; 
			break;
	}
}

void breakActuator()
{
	RPM = RPM-30;
	if(RPM<0)
	{
		RPM = 0;
	}

	switch(gear_state)
	{
		case 0:
		case 1:
			break;
		case 2:
		case 3:
			if(current_speed - (2*break_val) < 0)
				current_speed = 0;
			else
				current_speed -= 2 * break_val; 
			break;
	}
}

void nonActuator()
{
	RPM = RPM-10;
	if(RPM<0)
	{
		RPM = 0;
	}

	switch(gear_state)
	{
		case 0:
		case 1:
			break;
		case 2:
		case 3:
			if(current_speed - 2 < 0)
				current_speed = 0;
			else
				current_speed -= 2; 
			break;
	}
}
