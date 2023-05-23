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
#include "../Hal/Includes/SevenSeg.h"
#include "../Hal//Includes/LCD.h"

void Test (void){
	LCD_GoToXY4Bit(0,0);
	LCD_WriteString4Bit("Mohammed");
	Delay(1000);
	LCD_WriteString4Bit(" Gafar");
}

int main(){
	RCC_Init();
	NVIC_Init();
	LCD_4BitInitialize();
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_PULL_UP_DOWN);
	GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH);
	EXTI0_SetCallBack(&Test);
	EXTI_Init(LINE0,ON_CHANGE);
	NVIC_EnableInterrupt(NVIC_EXTI0);
	
	LCD_GoToXY4Bit(5,1);
	LCD_WriteNumber4Bit(55555555);
	
	
	
	
	u8 i = 0;
	while(1){
	
	}
	return 0;
}