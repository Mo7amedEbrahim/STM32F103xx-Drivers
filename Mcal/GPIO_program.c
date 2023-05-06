/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 5 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
/*  Lib Includes    */
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Common/MEMORY_MAP.h"
/*  Module Includes */
#include "Includes/GPIO_interface.h"
#include "Includes/GPIO_private.h"
#include "../Config/GPIO_config.h"

/*  Function definitions  */
ES_t GPIO_SetPinMode(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 Copy_u8mode){
    ES_t Local_enumState = ES_NOK;
    switch(port){
        case GPIO_PORTA:
            if(pin <= 7 && pin >= 0){
                //Low pins
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOA->CRL |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else if(pin > 7 && pin <=15){
                //High Pins
                pin = pin-8;
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOA->CRH |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
        break;
        case GPIO_PORTB:
            if(pin <= 7 && pin >= 0){
                //Low pins
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOB->CRL |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else if(pin > 7 && pin <=15){
                //High Pins
                pin = pin-8;
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOB->CRH |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
        break;
        case GPIO_PORTC:
            if(pin <= 7 && pin >= 0){
                //Low pins
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOC->CRL |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else if(pin > 7 && pin <=15){
                //High Pins
                pin = pin-8;
                //Mask CNF and MODE Bits
                GPIOA->CRL &= ~(0b1111 << (pin * 4));
                //Choose Mode
                GPIOC->CRH |= Copy_u8mode << (pin * 4);
                Local_enumState = ES_OK;
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
        break;
        default:
            Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}

ES_t GPIO_SetPinValue(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 Copy_u8value){
    ES_t Local_enumState = ES_NOK;
    switch(port){
        case GPIO_PORTA:
        if(pin >=0 && pin <=15){
            if(Copy_u8value == HIGH){
                GPIOA->BSRR = (1 << pin);
            }
            else if(Copy_u8value == LOW){
                GPIOA->BRR = (1 << pin);
            }
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        case GPIO_PORTB:
        if(pin >=0 && pin <=15){
            if(Copy_u8value == HIGH){
                GPIOB->BSRR = (1 << pin);
            }
            else if(Copy_u8value == LOW){
                GPIOB->BRR = (1 << pin);
            }
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        case GPIO_PORTC:
        if(pin >=0 && pin <=15){
            if(Copy_u8value == HIGH){
                GPIOC->BSRR = (1 << pin);
            }
            else if(Copy_u8value == LOW){
                GPIOC->BRR = (1 << pin);
            }
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        default:
        Local_enumState = ES_OUT_OF_RANGE;
        break;
    }
    return Local_enumState;
}

ES_t GPIO_GetPinValue(GPIO_PORT_t port, GPIO_LOW_PINS_t pin, u8 *Copy_pu8value){
    ES_t Local_enumState = ES_NOK;
    switch(port){
        case GPIO_PORTA:
        if(pin >=0 && pin <=15){
            *Copy_pu8value = GET_BIT(GPIOA->IDR,pin);
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        case GPIO_PORTB:
        if(pin >=0 && pin <=15){
            *Copy_pu8value = GET_BIT(GPIOB->IDR,pin);
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        case GPIO_PORTC:
        if(pin >=0 && pin <=15){
            *Copy_pu8value = GET_BIT(GPIOC->IDR,pin);
            Local_enumState = ES_OK;
        }
        else{
            Local_enumState = ES_OUT_OF_RANGE;
        }
        break;
        default :
            Local_enumState = ES_OUT_OF_RANGE;
        break;
    }
    return Local_enumState;
}

ES_t GPIO_SetHalfPortMode(GPIO_HALF_PORT_t port, u8 Copy_u8mode){
    ES_t Local_enumState = ES_NOK;
    u8 Local_u8Counter = 0;
    switch(port){
        case GPIO_PORTA_LOW:
        GPIOA->CRL = (Copy_u8mode * 0x11111111);
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTA_HIGH:
        GPIOA->CRH = (Copy_u8mode * 0x11111111);
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTB_LOW:
        GPIOB->CRL = (Copy_u8mode * 0x11111111);
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTB_HIGH:
        GPIOB->CRH = (Copy_u8mode * 0x11111111);
        Local_enumState = ES_OK;
        break;
        default:
        Local_enumState = ES_OUT_OF_RANGE;
        break;
    }
    return Local_enumState;
}
ES_t GPIO_SetHalfPortValue(GPIO_HALF_PORT_t port, u8 Copy_u8value){
    ES_t Local_enumState = ES_NOK;
    u8 Local_u8Counter = 0;
    switch(port){
        case GPIO_PORTA_LOW:
        GPIOA->ODR |= Copy_u8value & 0x00FF;
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTA_HIGH:
        GPIOA->ODR = (Copy_u8value << 8) & 0xFF00;
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTB_LOW:
        GPIOB->ODR = Copy_u8value & 0x00FF;
        Local_enumState = ES_OK;
        break;
        case GPIO_PORTB_HIGH:
        GPIOB->ODR = (Copy_u8value << 8) & 0xFF00;
        Local_enumState = ES_OK;
        break;
        default:
        Local_enumState = ES_OUT_OF_RANGE;
        break;
    }
    return Local_enumState;
}


ES_t GPIO_LockPin(GPIO_PORT_t port, GPIO_LOW_PINS_t pin){
    ES_t Local_enumState = ES_NOK;
    switch(port){
        case GPIO_PORTA:
            if(pin >= 0 && pin <= 15){
                SET_BIT(GPIOA->LCKR, pin);
                CLR_BIT(GPIOA->LCKR, pin);
                SET_BIT(GPIOA->LCKR, pin);
                if(GET_BIT(GPIOA->LCKR, pin)){
                    SET_BIT(GPIOA->LCKR, 16);
                    if(GET_BIT(GPIOA->LCKR, 16)){
                        Local_enumState = ES_OK;
                    }
                }
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
            break;
        case GPIO_PORTB:
            if(pin >= 0 && pin <= 15){
                SET_BIT(GPIOB->LCKR, pin);
                CLR_BIT(GPIOB->LCKR, pin);
                SET_BIT(GPIOB->LCKR, pin);
                if(GET_BIT(GPIOB->LCKR, pin)){
                    SET_BIT(GPIOB->LCKR, 16);
                    if(GET_BIT(GPIOB->LCKR, 16)){
                        Local_enumState = ES_OK;
                    }
                }
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
            break;
        case GPIO_PORTC:
            if(pin >= 0 && pin <= 15){
                SET_BIT(GPIOC->LCKR, pin);
                CLR_BIT(GPIOC->LCKR, pin);
                SET_BIT(GPIOC->LCKR, pin);
                if(GET_BIT(GPIOC->LCKR, pin)){
                    SET_BIT(GPIOC->LCKR, 16);
                    if(GET_BIT(GPIOC->LCKR, 16)){
                        Local_enumState = ES_OK;
                    }
                }
            }
            else{
                Local_enumState = ES_OUT_OF_RANGE;
            }
            break;
        default:
            Local_enumState = ES_OUT_OF_RANGE;
            break;
    }
    return Local_enumState;
}
