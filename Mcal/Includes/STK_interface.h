/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 11 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_


ES_t STK_Init(void);
ES_t STK_Start(u32 Copy_u32PreloadValue);
ES_t STK_ReadFlag(u8 *Copy_pu8Flag);
ES_t STK_SetCallBack(void (*Local_FuncPTR)(void));
ES_t Delay(u32 Copy_u32TimeInMilliSeconds);








#endif