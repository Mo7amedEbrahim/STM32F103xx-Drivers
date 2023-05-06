#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Hal/Includes/SevenSeg.h"

int main(){
	u8 value = 0;
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPA );

		GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_2MHZ_PP);
		GPIO_LockPin(GPIO_PORTA,GPIO_PIN1);
		GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_INPUT_ANALOG);
	
	return 0;
}
