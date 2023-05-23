/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 11 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Common/MEMORY_MAP.h"
#include "Includes/STK_interface.h"
#include "Includes/STK_private.h"
#include "../Config/STK_config.h"

void (*STK_pfCallBack)(void) = NULL;
u8 STK_ModeOfInterval = STK_MULTI_INTERVAL;
ES_t STK_Init(void){
    ES_t Local_enumState = ES_NOK;
    //Select Clock Source
#if STK_CLK_SOURCE == STK_AHB
    SET_BIT(SYSTICK->CTRL,2);
#elif STK_CLK_SOURCE == STK_AHB_BY_8
    CLR_BIT(SYSTICK->CTRL,2);
#endif
    //Disable SYS Tick Interrupt
    CLR_BIT(SYSTICK->CTRL,1);
    //Stop Sys Tick;
    CLR_BIT(SYSTICK->CTRL,0);
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_StartBusyWait(u32 Copy_u32Tics){
    ES_t Local_enumState = ES_NOK;
    //Load ticks to LOAD Register
    SYSTICK->LOAD = Copy_u32Tics;
    //Start timer
    SET_BIT(SYSTICK->CTRL,0);
    //Wait untill underflow
    while(!GET_BIT(SYSTICK->CTRL,16));
    //Stop timer
    CLR_BIT(SYSTICK->CTRL,0);
    SYSTICK->LOAD = 0;
    SYSTICK->VAL = 0;
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_StartIntervalSingle(u32 Copy_u32Tics, void(*Copy_pf)(void) ){
    ES_t Local_enumState = ES_NOK;
    SYSTICK->LOAD = Copy_u32Tics;
    STK_pfCallBack = Copy_pf;
    SET_BIT(SYSTICK->CTRL,1);
    STK_ModeOfInterval = STK_SINGLE_INTERVAL;
    SET_BIT(SYSTICK->CTRL,0);
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t STK_StartIntervalPeriodic(u32 Copy_u32Tics, void(*Copy_pf)(void) ){
    ES_t Local_enumState = ES_NOK;
    SYSTICK->LOAD = Copy_u32Tics;
    STK_pfCallBack = Copy_pf;
    SET_BIT(SYSTICK->CTRL,1);
    STK_ModeOfInterval = STK_MULTI_INTERVAL;
    SET_BIT(SYSTICK->CTRL,0);
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_StopInterval(void){
    ES_t Local_enumState = ES_NOK;
    //Disable SYS Tick Interrupt
    CLR_BIT(SYSTICK->CTRL,1);
    //Stop timer
    CLR_BIT(SYSTICK->CTRL,0);
    SYSTICK->LOAD = 0;
    SYSTICK->VAL = 0;
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_GetElapsedTime(u32 *Copy_pu32Ticks){
    ES_t Local_enumState = ES_NOK;
    *Copy_pu32Ticks = SYSTICK->LOAD - SYSTICK->VAL ;
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t STK_GetRemainingTime(u32 *Copy_pu32Ticks){
    ES_t Local_enumState = ES_NOK;
    *Copy_pu32Ticks = SYSTICK->VAL ;
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_ReadFlag(u8 *Copy_pu8Flag){
    ES_t Local_enumState = ES_NOK;
    *Copy_pu8Flag = GET_BIT(SYSTICK->CTRL,16);
    Local_enumState = ES_OK;
    return Local_enumState;
}

ES_t STK_SetCallBack(void (*Local_FuncPTR)(void)){
    ES_t Local_enumState = ES_NOK;
    if(Local_FuncPTR == NULL){
        Local_enumState = ES_NULL_POINTER;
    }
    else{
        STK_pfCallBack = Local_FuncPTR ;
        Local_enumState = ES_OK;
    }
    return Local_enumState;
}

ES_t Delay(u32 Copy_u32TimeInMilliSeconds){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u32TimeInMilliSeconds <= 16777){
        STK_StartBusyWait(Copy_u32TimeInMilliSeconds * 1000);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}

void SysTick_Handler(void){
    if(STK_pfCallBack == NULL){
        //Do Nothing
    }
    else{
        if(STK_ModeOfInterval == STK_SINGLE_INTERVAL){
            //Disable SYS Tick Interrupt
            CLR_BIT(SYSTICK->CTRL,1);
            //Stop timer
            CLR_BIT(SYSTICK->CTRL,0);
            SYSTICK->LOAD = 0;
            SYSTICK->VAL = 0;
        }
        STK_pfCallBack();
        //Clear Flag
        GET_BIT(SYSTICK->CTRL,16);
    }
}