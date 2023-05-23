#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/NVIC_interface.h"
#include "../Mcal/Includes/EXTI_interface.h"
#include "../Mcal/Includes/AFIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"
#include "../OS_Scheduler/OS_interface.h"
#include "../Hal/Includes/UltraSonic.h"
#include "../Hal/Includes/SevenSeg.h"
#include "../Hal//Includes/LCD.h"



int main(){
	RCC_Init();
	NVIC_Init();
	STK_Init();
	LCD_4BitInitialize();
	US_Init();
	
	
u32 Distance = 0 ;
	while(1){
	LCD_Clear4Bit();
	LCD_GoToXY4Bit(0,0);
	LCD_WriteString4Bit("Distance : ");
	Distance = GetDistance();
	LCD_WriteNumber4Bit(Distance);
	Delay(1000);
	
	}
	return 0;
}