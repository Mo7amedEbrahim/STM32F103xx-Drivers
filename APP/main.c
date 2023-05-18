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


int main(){
	u8 i=1;
	u8 value = 1;
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPB );
	
	GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_10MHZ_PP);
	GPIO_LockPin(GPIO_PORTB,GPIO_PIN2);
	GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_10MHZ_OD);

	
	
	while(1){

	}
	return 0;
}

