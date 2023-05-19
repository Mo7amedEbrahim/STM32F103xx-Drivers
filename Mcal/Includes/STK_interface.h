/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 11 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_


ES_t STK_Init(void);    //Done
ES_t STK_StartBusyWait(u32 Copy_u32Tics);
ES_t STK_StartIntervalSingle(u32 Copy_u32Tics, void(*Copy_pf)(void) );
ES_t STK_StartIntervalPeriodic(u32 Copy_u32Tics, void(*Copy_pf)(void) );
ES_t STK_StopInterval(void);
ES_t STK_GetElapsedTime(u32 *Copy_pu32Ticks);
ES_t STK_GetRemainingTime(u32 *Copy_pu32Ticks);
ES_t STK_ReadFlag(u8 *Copy_pu8Flag);
ES_t STK_SetCallBack(void (*Local_FuncPTR)(void));
ES_t Delay(u32 Copy_u32TimeInMilliSeconds);








#endif