/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 11 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

typedef enum{
    EXTI_PA = 0b0000,
    EXTI_PB = 0b0001,
    EXTI_PC = 0b0010
}AFIO_EXTI_t;



ES_t AFIO_SetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap);









#endif