/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 5 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef SEVENSEG_H_
#define SEVENSEG_H_


ES_t SevenSeg_Init(GPIO_HALF_PORT_t port);
ES_t SevenSeg_Display(GPIO_HALF_PORT_t port, u8 Copy_u8Number);




#endif /* SEVENSEG_H_ */