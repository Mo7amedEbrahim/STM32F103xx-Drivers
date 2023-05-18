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

ES_t STK_Init(void){
    ES_t Local_enumState = ES_NOK;
    //Select Clock Source
#if STK_CLK_SOURCE == STK_AHB
    SET_BIT(SYSTICK->CTRL,2);
#elif STK_CLK_SOURCE == STK_AHB_BY_8
    CLR_BIT(SYSTICK->CTRL,2);
#endif
    //Enable SYS Tick Interrupt
    SET_BIT(SYSTICK->CTRL,1);
    //Stop Sys Tick;
    CLR_BIT(SYSTICK->CTRL,0);
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t STK_Start(u32 Copy_u32PreloadValue){
    ES_t Local_enumState = ES_NOK;
    //Set the Preload Value
    SYSTICK->LOAD = Copy_u32PreloadValue - 1;
    //Clear VAL register
    SYSTICK->VAL = 0;
    //Start the timer
    SET_BIT(SYSTICK->CTRL,0);
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
        STK_Start(Copy_u32TimeInMilliSeconds * 1000);
        while(GET_BIT(SYSTICK->CTRL,16) == 0);
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
        STK_pfCallBack();
        //Clear Flag
        GET_BIT(SYSTICK->CTRL,16);
    }
}