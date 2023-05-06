/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 4 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
/*  Libraries Includes  */
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Common/MEMORY_MAP.h"
/*  RCC Includes    */
#include "Includes/RCC_interface.h"
#include "../Config/RCC_config.h"
#include "Includes/RCC_private.h"


ES_t RCC_Init( void ){
    ES_t Local_EnumErrorStatus = ES_NOK;
    u32 Local_u32Timeout = 0;
#if RCC_CLOCK_TYPE  == RCC_HSE_CRYSTAL
    //Select HSE as system clock
    SET_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);
    //Enable HSE Clock
    SET_BIT(RCC->CR,16);
    //Wait until HSE is ready
    while( !GET_BIT(RCC->CR,17) && Local_u32Timeout < 100000 ){
        Local_u32Timeout++;
    }
    if(Local_u32Timeout == 100000){
        return ES_NOK;
    }
    Local_EnumErrorStatus = ES_OK;
#elif RCC_CLOCK_TYPE == RCC_HSI
    //Select HSI as system clock
    CLR_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);
    //Enable HSI Clock
    SET_BIT(RCC->CR,0);
    //Wait until HSI is ready
    while( !GET_BIT(RCC->CR,1) && Local_u32Timeout < 100000 ){
        Local_u32Timeout++;
    }
    if(Local_u32Timeout == 100000){
        return ES_NOK;
    }
    Local_EnumErrorStatus = ES_OK;
#elif RCC_CLOCK_TYPE == RCC_PLL
    //Select PLL as system clock
    CLR_BIT(RCC->CFGR,0);
    SET_BIT(RCC->CFGR,1);
    //Select multiplication factor
    #if ((PLL_MUL_FACTOR >= PLL_NO_CLK_FACTOR) && (PLL_MUL_FACTOR <= PLL_MUL_16))
        //Mask 4 bits of PLLCFGR multiply factor
        RCC->CFGR &= ~(0b1111 << 18);
        RCC->CFGR |= PLL_MUL_FACTOR << 18;
    #else
        #error "Wrong PLL multiplication factor"
    #endif
    //Select PLL Source
    #if PLL_SOURCE == RCC_PLL_HSI_DIV_2
        //Select HSI/2 as PLL source
        CLR_BIT(RCC->CFGR,16);
    #elif PLL_SOURCE == RCC_PLL_HSE
        //Enable HSE Clock
        SET_BIT(RCC->CR,16);
        //select HSE as PLL source
        SET_BIT(RCC->CFGR,16);
        //Select HSE Not Divided as PLL source
        CLR_BIT(RCC->CFGR,17);
    #elif PLL_SOURCE == RCC_PLL_HSE_DIV_2
        //Enable HSE Clock
        SET_BIT(RCC->CR,16);
        //select HSE as PLL source
        SET_BIT(RCC->CFGR,16);
        //Select HSE Divided by 2 as PLL source
        SET_BIT(RCC->CFGR,17);
    #else
        #error "Wrong PLL Source"
    #endif
    //Enable PLL Clock
    SET_BIT(RCC->CR,24);
    //Wait until PLL is ready
    while( !GET_BIT(RCC->CR,25) && Local_u32Timeout < 100000 ){
        Local_u32Timeout++;
    }
    if(Local_u32Timeout == 100000){
        return ES_NOK;
    }
    Local_EnumErrorStatus = ES_OK;
#elif RCC_CLOCK_TYPE == RCC_HSE_BYPASS
    /* HSE Clock Disabled */
	CLR_BIT( RCC->CR   , 16 );
    /* HSEBYPASS Clock Enable */
	SET_BIT( RCC->CR , 18 );
    //Select HSE as system clock
    SET_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);
    //Enable HSE Clock
    SET_BIT(RCC->CR,16);
    //Wait until HSE is ready
    while( !GET_BIT(RCC->CR,17) && Local_u32Timeout < 100000 ){
        Local_u32Timeout++;
    }
    if(Local_u32Timeout == 100000){
        return ES_NOK;
    }
    Local_EnumErrorStatus = ES_OK;
    #else
        #error "Wrong Clock Type"
#endif
    //Select Clock Security System
    #if RCC_SECURITY_SYSTEM == RCC_CSS_ENABLE
        SET_BIT(RCC->CR,19);
    #elif RCC_SECURITY_SYSTEM == RCC_CSS_DISABLE
        CLR_BIT(RCC->CR,19);
    #else
        #error "Wrong Clock Security System State"
    #endif
    return Local_EnumErrorStatus;
}

ES_t RCC_EnablePeripheralClock( u8 Copy_u8BusID, u8 Copy_u8PeripheralID ){
    ES_t Local_EnumErrorStatus = ES_NOK;
    if( Copy_u8PeripheralID <= 31 ){
        switch( Copy_u8BusID ){
            case RCC_AHB:
                SET_BIT( RCC->AHBENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            case RCC_APB1:
                SET_BIT( RCC->APB1ENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            case RCC_APB2:
                SET_BIT( RCC->APB2ENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            default:
                Local_EnumErrorStatus = ES_NOK;
                break;
        }
    }
    else{
        Local_EnumErrorStatus = ES_NOK;
    }
    return Local_EnumErrorStatus;
}

ES_t RCC_DisablePeripheralClock( u8 Copy_u8BusID, u8 Copy_u8PeripheralID ){
    ES_t Local_EnumErrorStatus = ES_NOK;
    if( Copy_u8PeripheralID <= 31 ){
        switch( Copy_u8BusID ){
            case RCC_AHB:
                CLR_BIT( RCC->AHBENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            case RCC_APB1:
                CLR_BIT( RCC->APB1ENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            case RCC_APB2:
                CLR_BIT( RCC->APB2ENR , Copy_u8PeripheralID );
                Local_EnumErrorStatus = ES_OK;
                break;
            default:
                Local_EnumErrorStatus = ES_NOK;
                break;
        }
    }
    else{
        Local_EnumErrorStatus = ES_NOK;
    }
    return Local_EnumErrorStatus;
}