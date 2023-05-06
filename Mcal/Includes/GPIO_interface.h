/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 5 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

typedef enum{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC
}GPIO_PORT_t;
typedef enum{
    GPIO_PORTA_LOW,
    GPIO_PORTA_HIGH,
    GPIO_PORTB_LOW,
    GPIO_PORTB_HIGH
}GPIO_HALF_PORT_t;
typedef enum{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}GPIO_LOW_PINS_t;
typedef enum{
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15
}GPIO_HIGH_PINS_t;
typedef enum{
    GPIO_INPUT_ANALOG = 0b0000,
    GPIO_INPUT_FLOATING = 0b0100,
    GPIO_INPUT_PULL_UP_DOWN = 0b1000
}GPIO_INPUT_MODE_t;
typedef enum{
    GPIO_OUTPUT_10MHZ_PP = 0b0001,
    GPIO_OUTPUT_10MHZ_OD = 0b0101,
    GPIO_OUTPUT_10MHZ_AFPP = 0b1001,
    GPIO_OUTPUT_10MHZ_AFOD = 0b1101,
    GPIO_OUTPUT_2MHZ_PP = 0b0010,
    GPIO_OUTPUT_2MHZ_OD = 0b0110,
    GPIO_OUTPUT_2MHZ_AFPP = 0b1010,
    GPIO_OUTPUT_2MHZ_AFOD = 0b1110,
    GPIO_OUTPUT_50MHZ_PP = 0b0011,
    GPIO_OUTPUT_50MHZ_OD = 0b0111,
    GPIO_OUTPUT_50MHZ_AFPP = 0b1011,
    GPIO_OUTPUT_50MHZ_AFOD = 0b1111
}GPIO_OUTPUT_MODE_t;
#define HIGH 1
#define LOW  0


//Main APIs
ES_t GPIO_SetPinMode(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 Copy_u8mode);
//TODO:Edit GPIO_SetPinValue and use BSRR and BRR for better performance and atomicity
    //DONE  5 / 7 / 2023
ES_t GPIO_SetPinValue(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 Copy_u8value);
ES_t GPIO_GetPinValue(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 *Copy_pu8value);
ES_t GPIO_SetHalfPortMode(GPIO_HALF_PORT_t port, u8 Copy_u8mode);
ES_t GPIO_SetHalfPortValue(GPIO_HALF_PORT_t port, u8 Copy_u8value);
//TODO: Edit GPIO_Lock pin as it is not working
ES_t GPIO_LockPin(GPIO_PORT_t port, GPIO_LOW_PINS_t pin);
ES_t GPIO_SetPortMode(GPIO_PORT_t port, u8 Copy_u8mode);



#endif