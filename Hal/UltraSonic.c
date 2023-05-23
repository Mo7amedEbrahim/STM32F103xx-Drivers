/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 20 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/ERROR_STATUS.h"
#include "../Common/MEMORY_MAP.h"
#include "Includes/UltraSonic.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"


void US_Init(void){
    GPIO_SetPinMode(US_PORT,TRIGGER_PIN,GPIO_OUTPUT_10MHZ_PP);
    GPIO_SetPinMode(US_PORT,ECHO_PIN,GPIO_INPUT_PULL_UP_DOWN);
    GPIO_SetPinValue(US_PORT,ECHO_PIN,LOW);
}

u32 GetDistance(void) {
    u8 echoState = LOW;
    
    // Send 10us pulse to trigger
    GPIO_SetPinValue(US_PORT, TRIGGER_PIN, HIGH);
    STK_StartBusyWait(10);
    GPIO_SetPinValue(US_PORT, TRIGGER_PIN, LOW);
    
    // Wait for echo
    while (echoState == LOW) {
        GPIO_GetPinValue(US_PORT, ECHO_PIN, &echoState);
    }
    
    // Start timer
    SYSTICK->LOAD = 0xFFFFFF;  // Set maximum value for long interval
    SYSTICK->VAL = 0;  // Clear current value
    SET_BIT(SYSTICK->CTRL, 0);  // Enable timer
    
    // Wait for echo to end
    while (echoState == HIGH) {
        GPIO_GetPinValue(US_PORT, ECHO_PIN, &echoState);
    }
    
    // Stop timer
    CLR_BIT(SYSTICK->CTRL, 0);  // Disable timer
    
    // Calculate distance
    u32 elapsedTime = 0xFFFFFF - SYSTICK->VAL;
    u32 distance = (elapsedTime * 343) / 20000;
    // Reset timer
    SYSTICK->VAL = 0;
    
    return distance;
}
