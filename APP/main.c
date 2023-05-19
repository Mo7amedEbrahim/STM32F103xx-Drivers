#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/NVIC_interface.h"
#include "../Mcal/Includes/EXTI_interface.h"
#include "../Mcal/Includes/AFIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"

#include "../Hal/Includes/SevenSeg.h"


void test(void){
	static u8 count = 0;
	count++;
	if (count == 1){
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,LOW);
	}
	else if(count == 2){
		GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH);
		count = 0;
	}
}

int main(){
	u8 i=1;
	u8 value = 1;
	/*	Initializing Clocks	*/
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPA );
	STK_Init();
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_2MHZ_PP);
	GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH);
	STK_StartIntervalPeriodic(1000000,&test);
	while(1){

	}
	return 0;
}
