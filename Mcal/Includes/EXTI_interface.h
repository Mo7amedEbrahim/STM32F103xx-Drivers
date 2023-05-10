/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 10 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define LINE0       0
#define LINE1       1
#define LINE2       2
#define LINE3       3
#define LINE4       4
#define LINE5       5
#define LINE6       6
#define LINE7       7
#define LINE8       8
#define LINE9       9
#define LINE10      10
#define LINE11      11
#define LINE12      12
#define LINE13      13
#define LINE14      14
#define LINE15      15

#define RISING      0
#define FALLING     1
#define ON_CHANGE   2

ES_t EXTI_Init(u8 Copy_u8Line , u8 Copy_u8Mode);
ES_t EXTI_EnableLine(u8 Copy_u8Line);
ES_t EXTI_DisableLine(u8 Copy_u8Line);
ES_t EXTI_SoftwareTrigger(u8 Copy_u8Line);

/***************************************/
void EXTI0_SetCallBack(void (*Local_FuncPTR)(void));
void EXTI1_SetCallBack(void (*Local_FuncPTR)(void));
void EXTI2_SetCallBack(void (*Local_FuncPTR)(void));
void EXTI3_SetCallBack(void (*Local_FuncPTR)(void));
void EXTI4_SetCallBack(void (*Local_FuncPTR)(void));


#endif