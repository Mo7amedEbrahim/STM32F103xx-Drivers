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

		GPIO_SetHalfPortMode(GPIO_PORTA_LOW,GPIO_OUTPUT_10MHZ_PP);
		GPIO_SetHalfPortMode(GPIO_PORTB_LOW,GPIO_OUTPUT_2MHZ_PP);

	return 0;
}
