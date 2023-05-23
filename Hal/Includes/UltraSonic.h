/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 20 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#define US_PORT             GPIO_PORTA
#define TRIGGER_PIN         GPIO_PIN3
#define ECHO_PIN            GPIO_PIN0

void US_Init(void);
u32 GetDistance(void);










#endif