#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/NVIC_interface.h"
#include "../Hal/Includes/SevenSeg.h"

int main(){
	u8 value = 0;
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPA );

	NVIC_SetIntPriority(NVIC_EXTI0,1,2,GROUP5);

	return 0;
}
