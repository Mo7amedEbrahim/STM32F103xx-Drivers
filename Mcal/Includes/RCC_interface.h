/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 4 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
// RCC Bus IDs
typedef enum{
    RCC_AHB = 0,
    RCC_APB1 = 1,
    RCC_APB2 = 2
} BusID_t;

// peripheral IDs
// RCC_AHB
typedef enum{
    RCC_DMA1 = 0,
    RCC_DMA2 = 1,
    RCC_SRAM = 2,
    RCC_FLITF = 4,
    RCC_CRC = 6,
    RCC_FSMC = 8,
    RCC_SDIO = 10
}AHB_PeripheralID_t;

// RCC_APB2
typedef enum{
    RCC_AFIO = 0,
    RCC_IOPA = 2,
    RCC_IOPB = 3,
    RCC_IOPC = 4,
    RCC_IOPD = 5,
    RCC_IOPE = 6,
    RCC_IOPF = 7,
    RCC_IOPG = 8,
    RCC_ADC1 = 9,
    RCC_ADC2 = 10,
    RCC_TIM1 = 11,
    RCC_SPI1 = 12,
    RCC_TIM8 = 13,
    RCC_USART1 = 14,
    RCC_ADC3 = 15,
    RCC_TIM9 = 19,
    RCC_TIM10 = 20,
    RCC_TIM11 = 21
}APB2_PeripheralID_t;

// RCC_APB1
typedef enum{
    RCC_TIM2 = 0,
    RCC_TIM3 = 1,
    RCC_TIM4 = 2,
    RCC_TIM5 = 3,
    RCC_TIM6 = 4,
    RCC_TIM7 = 5,
    RCC_TIM12 = 6,
    RCC_TIM13 = 7,
    RCC_TIM14 = 8,
    RCC_WWDG = 11,
    RCC_SPI2 = 14,
    RCC_SPI3 = 15,
    RCC_USART2 = 17,
    RCC_USART3 = 18,
    RCC_USART4 = 19,
    RCC_USART5 = 20,
    RCC_I2C1 = 21,
    RCC_I2C2 = 22,
    RCC_USB = 23,
    RCC_CAN = 25,
    RCC_BKP = 27,
    RCC_PWR = 28,
    RCC_DAC = 29
}APB1_PeripheralID_t;

ES_t RCC_Init( void );

ES_t RCC_EnablePeripheralClock( u8 Copy_u8BusID, u8 Copy_u8PeripheralID );

ES_t RCC_DisablePeripheralClock( u8 Copy_u8BusID, u8 Copy_u8PeripheralID );







#endif