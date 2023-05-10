/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 11 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/MEMORY_MAP.h"
#include "../Common/ERROR_STATUS.h"
#include "Includes/AFIO_interface.h"
#include "Includes/AFIO_private.h"
#include "../Config/AFIO_config.h"


ES_t AFIO_SetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap){
    ES_t Local_enumState = ES_OK;
    u8 Local_u8Index = 0;
    if(Copy_u8Line >= 0 && Copy_u8Line <= 3){
        Local_u8Index = 0;
    }
    else if(Copy_u8Line > 3 && Copy_u8Line <=7){
        Local_u8Index = 1;
        Copy_u8Line -= 4;
    }
    else if(Copy_u8Line > 7 && Copy_u8Line <=11){
        Local_u8Index = 2;
        Copy_u8Line -= 8;
    }
    else if(Copy_u8Line > 11 && Copy_u8Line <=15){
        Local_u8Index = 3;
        Copy_u8Line -= 12;
    }
    else{
        Local_enumState = ES_OUT_OF_RANGE;
    }
    //Mask the 4 bit of EXTx
    AFIO->EXTICR[Local_u8Index] &= ~( (0b1111) << (4 * Copy_u8Line));
    //Select Channel
    AFIO->EXTICR[Local_u8Index] |= ( (Copy_u8PortMap) << (4 * Copy_u8Line));
    return Local_enumState;
}

