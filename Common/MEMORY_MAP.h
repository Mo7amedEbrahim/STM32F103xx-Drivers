#ifndef _MEMORY_MAP_H_
#define _MEMORY_MAP_H_
#include "STD_TYPES.h"

/*      RCC Registers   */
typedef struct{
    volatile u32 CR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 APB2RSTR;
    volatile u32 APB1RSTR;
    volatile u32 AHBENR;
    volatile u32 APB2ENR;
    volatile u32 APB1ENR;
    volatile u32 BDCR;
    volatile u32 CSR;
}RCC_t;

#define RCC ((RCC_t *)(0x40021000))
/**********************************************/
/*  GPIO Registers  */
typedef struct{
    volatile u32 CRL;
    volatile u32 CRH;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 BRR;
    volatile u32 LCKR;
}GPIO_t;

#define GPIOA ((GPIO_t *)(0x40010800))
#define GPIOB ((GPIO_t *)(0x40010C00))
#define GPIOC ((GPIO_t *)(0x40011000))

/**********************************************/














#endif