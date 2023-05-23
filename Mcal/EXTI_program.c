/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 10 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/MEMORY_MAP.h"
#include "../Common/ERROR_STATUS.h"
#include "Includes/EXTI_interface.h"
#include "Includes/EXTI_private.h"
#include "../Config/EXTI_config.h"

// Callback functions Pointers
void (*EXTI0_pfCallBack)(void) = NULL;
void (*EXTI1_pfCallBack)(void) = NULL;
void (*EXTI2_pfCallBack)(void) = NULL;
void (*EXTI3_pfCallBack)(void) = NULL;
void (*EXTI4_pfCallBack)(void) = NULL;

ES_t EXTI_Init(u8 Copy_u8Line , u8 Copy_u8Mode){
    ES_t Local_enumState = ES_OK;
    switch(Copy_u8Mode){
        case RISING: SET_BIT(EXTI->RTSR,Copy_u8Line);       break;
        case FALLING: SET_BIT(EXTI->FTSR,Copy_u8Line);      break;
        case ON_CHANGE: SET_BIT(EXTI->RTSR,Copy_u8Line);    SET_BIT(EXTI->FTSR,Copy_u8Line);  break;
        default: Local_enumState = ES_OUT_OF_RANGE;         break;
    }
    SET_BIT(EXTI->IMR, Copy_u8Line);
    return Local_enumState;
}
ES_t EXTI_EnableLine(u8 Copy_u8Line){
    ES_t Local_enumState = ES_NOK;
    SET_BIT(EXTI->IMR, Copy_u8Line);
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t EXTI_DisableLine(u8 Copy_u8Line){
ES_t Local_enumState = ES_NOK;
    CLR_BIT(EXTI->IMR, Copy_u8Line);
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t EXTI_SoftwareTrigger(u8 Copy_u8Line){
    ES_t Local_enumState = ES_NOK;
    SET_BIT(EXTI->SWIER, Copy_u8Line);
    Local_enumState = ES_OK;
    return Local_enumState;
}


void EXTI0_SetCallBack(void (*Local_FuncPTR)(void)){
    EXTI0_pfCallBack = Local_FuncPTR;
}


void EXTI0_IRQHandler(void){
    EXTI0_pfCallBack();
    SET_BIT(EXTI->PR,0);
}

void EXTI1_SetCallBack(void (*Local_FuncPTR)(void)){
    EXTI1_pfCallBack = Local_FuncPTR;
}


void EXTI1_IRQHandler(void){
    EXTI1_pfCallBack();
    SET_BIT(EXTI->PR,1);
}

void EXTI2_SetCallBack(void (*Local_FuncPTR)(void)){
    EXTI2_pfCallBack = Local_FuncPTR;
}


void EXTI2_IRQHandler(void){
    EXTI2_pfCallBack();
    SET_BIT(EXTI->PR,2);
}

void EXTI3_SetCallBack(void (*Local_FuncPTR)(void)){
    EXTI3_pfCallBack = Local_FuncPTR;
}


void EXTI3_IRQHandler(void){
    EXTI3_pfCallBack();
    SET_BIT(EXTI->PR,3);
}

void EXTI4_SetCallBack(void (*Local_FuncPTR)(void)){
    EXTI4_pfCallBack = Local_FuncPTR;
}


void EXTI4_IRQHandler(void){
    EXTI4_pfCallBack();
    SET_BIT(EXTI->PR,4);
}