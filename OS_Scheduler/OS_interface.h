/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 21 / 5 / 2023                                           */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

typedef enum{
    TASK_RESUMED,
    TASK_SUSPENDED,
}TASK_STATE_t;
typedef struct{
    u16 Periodicity;
    void (*TaskHandler)(void);
    TASK_STATE_t TaskState;
    u16 FirstDelay;
}TASK_TCB_t;


void RTOS_Start(void);
void RTOS_CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay);
void RTOS_SuspendTask(u8 Copy_u8Priority);
void RTOS_ResumeTask(u8 Copy_u8Priority);





#endif