/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 7 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Common/MEMORY_MAP.h"
#include "Includes/NVIC_interface.h"
#include "Includes/NVIC_private.h"
#include "../Config/NVIC_config.h"

ES_t NVIC_Init(void){
    SCB->AIRCR = NVIC_Priority_Grouping;
	return ES_OK;
}

ES_t NVIC_EnableInterrupt(u8 Copy_u8InterruptNumber){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8InterruptNumber >=0 && Copy_u8InterruptNumber <=32){
        NVIC_ISER[0] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else if(Copy_u8InterruptNumber >=32 && Copy_u8InterruptNumber <=59){
        Copy_u8InterruptNumber -= 32;
        NVIC_ISER[1] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}

ES_t NVIC_DisableInterrupt(u8 Copy_u8InterruptNumber){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8InterruptNumber >=0 && Copy_u8InterruptNumber <=32){
        NVIC_ICER[0] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else if(Copy_u8InterruptNumber >=32 && Copy_u8InterruptNumber <=59){
        Copy_u8InterruptNumber -= 32;
        NVIC_ICER[1] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}
ES_t NVIC_SetPendingFlag(u8 Copy_u8InterruptNumber){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8InterruptNumber >=0 && Copy_u8InterruptNumber <=32){
        NVIC_ISPR[0] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else if(Copy_u8InterruptNumber >=32 && Copy_u8InterruptNumber <=59){
        Copy_u8InterruptNumber -= 32;
        NVIC_ISPR[1] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}
ES_t NVIC_ClearPendingFlag(u8 Copy_u8InterruptNumber){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8InterruptNumber >=0 && Copy_u8InterruptNumber <=32){
        NVIC_ICPR[0] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else if(Copy_u8InterruptNumber >=32 && Copy_u8InterruptNumber <=59){
        Copy_u8InterruptNumber -= 32;
        NVIC_ICPR[1] = (1<<Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}

ES_t NVIC_GetActiveFlag(u8 Copy_u8InterruptNumber,u8 *Copy_pu8ActiveFlag){
    ES_t Local_enumState = ES_NOK;
    if(Copy_u8InterruptNumber >=0 && Copy_u8InterruptNumber <=32){
        *Copy_pu8ActiveFlag = GET_BIT(NVIC_IABR[0],Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else if(Copy_u8InterruptNumber >=32 && Copy_u8InterruptNumber <=59){
        Copy_u8InterruptNumber -= 32;
        *Copy_pu8ActiveFlag = GET_BIT(NVIC_IABR[1],Copy_u8InterruptNumber);
        Local_enumState = ES_OK;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    return Local_enumState;
}

    //TODO : add conditions for wrong inputs of GROUP and SUB priority
ES_t NVIC_SetIntPriority(s8 Copy_s8InterruptNumber,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority){
    ES_t Local_enumState = ES_NOK;
    u8 Local_u8Priority = Copy_u8SubPriority|Copy_u8GroupPriority<<((NVIC_Priority_Grouping - 0x05FA0300)/256);
    /*  For internal Peripheral */
    //TODO: Test the software priority for internal peripherals
    if(Copy_s8InterruptNumber < 0 && Copy_s8InterruptNumber >=-6){
        if(Copy_s8InterruptNumber == MEMORY_MANAGE || Copy_s8InterruptNumber == BUS_FAULT || Copy_s8InterruptNumber == USAGE_FAULT){
            Copy_s8InterruptNumber += 3;
            SCB->SHPR1 = Local_u8Priority << (8 * Copy_s8InterruptNumber + 4); 
        }
        else if(Copy_s8InterruptNumber == SV_CALL){
            Copy_s8InterruptNumber += 7;
            SCB->SHPR2 = Local_u8Priority << (8 * Copy_s8InterruptNumber + 4); 
        }
        else if(Copy_s8InterruptNumber == SYSTICK || Copy_s8InterruptNumber == PEND_SV){
            Copy_s8InterruptNumber += 8;
            SCB->SHPR3 = Local_u8Priority << (8 * Copy_s8InterruptNumber + 4); 
        }
    }
    /*  For External Peripheral */
    else if(Copy_s8InterruptNumber >= 0 && Copy_s8InterruptNumber <=59){
        NVIC_IPR[Copy_s8InterruptNumber] = Local_u8Priority << 4;
			Local_enumState = ES_OK	;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    SCB->AIRCR = NVIC_Priority_Grouping;
	return Local_enumState;
}