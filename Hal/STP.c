/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 21 / 6 / 2023                                           */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"
#include "Includes/STP.h"
#include "../Config/STP_config.h"

ES_t STP_Init(void){
    ES_t Local_enuErrorState = ES_NOK;
    //Initialize the GPIO Pins
    GPIO_SetPinDirection(STP_PORT,STP_SERIAL_DATA_PIN,GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinDirection(STP_PORT,STP_SHIFT_CLOCK_PIN,GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinDirection(STP_PORT,STP_STORE_CLOCK_PIN,GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinDirection(STP_PORT,STP_OE_PIN,GPIO_OUTPUT_2MHZ_PP);
    //Initialize the Shift and Store Clocks to LOW
    GPIO_SetPinValue(STP_PORT,STP_SHIFT_CLOCK_PIN,LOW);
    GPIO_SetPinValue(STP_PORT,STP_STORE_CLOCK_PIN,LOW);
    //Initialize the Serial Data Pin to LOW
    GPIO_SetPinValue(STP_PORT,STP_SERIAL_DATA_PIN,LOW);
    //Initialize the OE Pin to LOW
    GPIO_SetPinValue(STP_PORT,STP_OE_PIN,LOW);
    Local_enuErrorState = ES_OK;
    return Local_enuErrorState;
}

ES_t STP_SendData(u8 Copy_u8DataToSend){
    ES_t Local_enuErrorState = ES_NOK;
    s8 Local_s8Counter;
    u8 Local_u8Bit;
    for(Local_s8Counter = 7;Local_s8Counter >= 0 ; Local_s8Counter--){
        //Send the Bits starting from MSB
        Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_s8Counter);
        //Put the bit to Serial Pin
        GPIO_SetPinValue(STP_PORT,STP_SERIAL_DATA_PIN,Local_u8Bit);
        //Send Shift Clock Pulse
        GPIO_SetPinValue(STP_PORT,STP_SHIFT_CLOCK_PIN,HIGH);
        STK_StartBusyWait(1);
        GPIO_SetPinValue(STP_PORT,STP_SHIFT_CLOCK_PIN,LOW);
        STK_StartBusyWait(1);
    }
    //Send Store Clock Pulse
    GPIO_SetPinValue(STP_PORT,STP_STORE_CLOCK_PIN,HIGH);
    STK_StartBusyWait(1);
    GPIO_SetPinValue(STP_PORT,STP_STORE_CLOCK_PIN,LOW);
    STK_StartBusyWait(1);
}