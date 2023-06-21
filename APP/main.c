#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/RCC_interface.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/NVIC_interface.h"
#include "../Mcal/Includes/EXTI_interface.h"
#include "../Mcal/Includes/AFIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"
#include "../Mcal/Includes/DMA_interface.h"
#include "../OS_Scheduler/OS_interface.h"
#include "../Hal/Includes/UltraSonic.h"
#include "../Hal/Includes/SevenSeg.h"
#include "../Hal//Includes/LCD.h"
u16 Sum(u8 Num1,u8 Num2,u8 Num3,u8 Num4,u8 Num5,u8 Num6);
__attribute__((naked)) void Change_SP_toPSP(void){
	//Symbolic Names
	__asm volatile (".equ MSP_STACK_START, 0x200006A0");
	__asm volatile (".equ MSP_STACK_END , (MSP_STACK_START - 512)");
	__asm volatile (".equ PSP_STACK_START, MSP_STACK_END");
	//Set PSP
	__asm volatile ("LDR R0, =PSP_STACK_START");
	__asm volatile ("MSR PSP, R0");
	//Set SPSEL
	__asm volatile ("MOV R0, #0x02");
	__asm volatile ("MSR CONTROL, R0");
	//Context Restore
	__asm volatile ("BX LR");
}

int main(){
	volatile int a =5;
	volatile int b = 7;
	RCC_Init();
	STK_Init();
	LCD_4BitInitialize();
	LCD_Clear4Bit();
	LCD_GoToXY4Bit(0,0);
	LCD_WriteString4Bit("Distance : ");
	u16 sum = Sum(5,6,7,8,9,10);
	sum++;
	while(1){

	}
	return 0;
}

u16 Sum(u8 Num1,u8 Num2,u8 Num3,u8 Num4,u8 Num5,u8 Num6){
	u16 sum = 0;
	u8 temp1 = 22,temp2 = 11,temp3 = 55;
	sum = Num1+Num2+Num3+Num4+temp1+temp2+temp3;
	return sum;
}