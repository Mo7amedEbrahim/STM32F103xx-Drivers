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

/*  AFIO Registers  */
typedef struct{
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR[4];
    volatile u32 MAPR2;
}AFIO_t;

#define AFIO ((AFIO_t *)(0x40010000))

/**********************************************/
/*  NVIC Registers  */
#define NVIC_ISER   ((volatile u32*) 0xE000E100)
#define NVIC_ICER   ((volatile u32*) 0xE000E180)
#define NVIC_ISPR   ((volatile u32*) 0xE000E200)
#define NVIC_ICPR   ((volatile u32*) 0xE000E280)
#define NVIC_IABR   ((volatile u32*) 0xE000E300)
#define NVIC_IPR    ((volatile u8 *) 0xE000E400)

/**********************************************/
typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;

}SCB_Type;

#define SCB ((volatile SCB_Type *) 0xE000ED00 )

/**********************************************/
typedef struct{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;
#define EXTI ((EXTI_t *)(0x40010400))

















#endif