/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 4 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

//RCC PLL Multiplication Factor
/*******************************************************************/

#define PLL_MUL_NO_CLK_FACTOR   0b0000
#define PLL_MUL_2               0b0000
#define PLL_MUL_3               0b0001
#define PLL_MUL_4               0b0010
#define PLL_MUL_5               0b0011
#define PLL_MUL_6               0b0100
#define PLL_MUL_7               0b0101
#define PLL_MUL_8               0b0110
#define PLL_MUL_9               0b0111
#define PLL_MUL_10              0b1000
#define PLL_MUL_11              0b1001
#define PLL_MUL_12              0b1010
#define PLL_MUL_13              0b1011
#define PLL_MUL_14              0b1100
#define PLL_MUL_15              0b1101
#define PLL_MUL_16              0b1110
/*******************************************************************/


/*******************************************************************/
// RCC Clock Types
#define RCC_HSE_CRYSTAL     0
#define RCC_HSI             1
#define RCC_PLL             2
#define RCC_HSE_BYPASS      3
/*******************************************************************/
// RCC PLL Clock Source
#define RCC_PLL_HSI_DIV_2   0
#define RCC_PLL_HSE_DIV_2   1
#define RCC_PLL_HSE         2
/*******************************************************************/
//Clock Security System
#define RCC_CSS_ENABLE      0
#define RCC_CSS_DISABLE     1
/*******************************************************************/







#endif