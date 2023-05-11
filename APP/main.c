#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/NVIC_interface.h"
#include "../Mcal/Includes/EXTI_interface.h"
#include "../Mcal/Includes/AFIO_interface.h"

void JustTest0(void);
void JustTest1(void);
void JustTest2(void);
void JustTest3(void);
void JustTest4(void);

int main(){
	u8 value = 0;
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPA );
	//Set Priorities
	NVIC_SetIntPriority(NVIC_EXTI0,0,0);
	NVIC_SetIntPriority(NVIC_EXTI1,1,0);
	NVIC_SetIntPriority(NVIC_EXTI2,0,0);
	NVIC_SetIntPriority(NVIC_EXTI3,0,0);
	NVIC_SetIntPriority(NVIC_EXTI4,0,0);
	//Enable NVIC For EXTI 0->4
	NVIC_EnableInterrupt(NVIC_EXTI0);
	NVIC_EnableInterrupt(NVIC_EXTI1);
	NVIC_EnableInterrupt(NVIC_EXTI2);
	NVIC_EnableInterrupt(NVIC_EXTI3);
	NVIC_EnableInterrupt(NVIC_EXTI4);
	//Set AFIO Channel
	AFIO_SetEXTIConfig(LINE0 , EXTI_PA);
	AFIO_SetEXTIConfig(LINE1 , EXTI_PB);
	AFIO_SetEXTIConfig(LINE2 , EXTI_PC);
	AFIO_SetEXTIConfig(LINE3 , EXTI_PA);
	AFIO_SetEXTIConfig(LINE4 , EXTI_PC);


	//Set CallBackFunctions
	EXTI0_SetCallBack(&JustTest0);
	EXTI1_SetCallBack(&JustTest1);
	EXTI2_SetCallBack(&JustTest2);
	EXTI3_SetCallBack(&JustTest3);
	EXTI4_SetCallBack(&JustTest4);
		// Set Pending Flags
	NVIC_SetPendingFlag(NVIC_EXTI1);

	while(1);

	return 0;
}
void JustTest0(void){
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_2MHZ_PP);
}
void JustTest1(void){
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_2MHZ_PP);
	NVIC_SetPendingFlag(NVIC_EXTI0);
}
void JustTest2(void){
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_2MHZ_PP);
}
void JustTest3(void){
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_2MHZ_PP);
}
void JustTest4(void){
	GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT_2MHZ_PP);
}