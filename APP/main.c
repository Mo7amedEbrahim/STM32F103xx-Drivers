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

DMA_Config_t Config = {
	.DMA_Channel = DMA_CHANNEL_7,
	.DMA_Direction = DMA_DIR_MEM_TO_MEM,
	.DMA_MemSize = DMA_MEMSIZE_8BITS,
	.DMA_MINC = DMA_MINC_ENABLE,
	.DMA_Mode = DMA_MODE_NORMAL,
	.DMA_PerSize = DMA_PERSIZE_8BITS,
	.DMA_PINC = DMA_PINC_ENABLE,
};
u8 sourceData[3] = {5,2,3};
u8 destinationData[3] = {0};

int main(){
	RCC_Init();
	RCC_EnablePeripheralClock(RCC_AHB,RCC_DMA1);
	NVIC_Init();
	LCD_4BitInitialize();
	DMA_VidSetConfiguration(&Config);
	
	//DMA_VidSetCallBack(&Test,DMA_CHANNEL_7);
	NVIC_EnableInterrupt(NVIC_DMA1_Channel7);
	
	STK_Init();
	

	DMA_VidStartSynch(DMA_CHANNEL_7,(u32 *)sourceData, (u32 *)destinationData, 3);
	LCD_Clear4Bit();
	LCD_WriteNumber4Bit(destinationData[0]);
	LCD_WriteString4Bit("  ");
	LCD_WriteNumber4Bit(destinationData[1]);
	LCD_WriteString4Bit("  ");
	LCD_WriteNumber4Bit(destinationData[2]);
	LCD_WriteString4Bit("  ");

	while(1){

	}
	return 0;
}