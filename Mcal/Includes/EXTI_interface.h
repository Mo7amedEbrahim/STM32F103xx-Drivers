/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 10 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

ES_t EXTI_Init(u8 Copy_u8Line , u8 Copy_u8Mode);
ES_t EXTI_EnableLine(u8 Copy_u8Line);
ES_t EXTI_DisableLine(u8 Copy_u8Line);
ES_t EXTI_SoftwareTrigger(u8 Copy_u8Line);









#endif