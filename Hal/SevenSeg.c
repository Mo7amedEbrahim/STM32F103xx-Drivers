/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 5 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "Includes/SevenSeg.h"



static u8 SevenSegAnode[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

ES_t SevenSeg_Init(GPIO_HALF_PORT_t port){
    ES_t Local_enumState = ES_NOK;
    GPIO_SetHalfPortMode(port, GPIO_OUTPUT_2MHZ_PP);
	GPIO_SetHalfPortValue(port,0xFF);
    Local_enumState = ES_OK;
    return Local_enumState;
}
ES_t SevenSeg_Display(GPIO_HALF_PORT_t port, u8 Copy_u8Number){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8Number <= 9){
        GPIO_SetHalfPortValue(port, SevenSegAnode[Copy_u8Number]);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}