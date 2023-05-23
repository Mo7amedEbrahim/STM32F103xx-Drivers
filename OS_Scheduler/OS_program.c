/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 20 / 5 / 2023                                            */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/STD_TYPES.h"
#include "../Common/BIT_MATH.h"
#include "../Common/ERROR_STATUS.h"
#include "../Mcal/Includes/STK_interface.h"
#include "OS_interface.h"
#include "../Config/OS_config.h"

static void Schedular( void ) ;

static TASK_TCB_t SYS_TASKS[TASK_NUMBER] = { { 0 } };
void RTOS_Start(void){
    STK_Init();
    STK_StartIntervalPeriodic(TICK_TIME,&Schedular);
}

void RTOS_CreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay){
    if(SYS_TASKS[Copy_u8Priority].TaskHandler == NULL){
        SYS_TASKS[Copy_u8Priority].TaskHandler = Copy_pvTaskFunc;
        SYS_TASKS[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
        SYS_TASKS[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
        SYS_TASKS[Copy_u8Priority].TaskState = TASK_RESUMED;
    }
    else{
        //  NOTHING
    }
}

void RTOS_SuspendTask(u8 Copy_u8Priority){
    SYS_TASKS[Copy_u8Priority].TaskState = TASK_SUSPENDED;
}

void RTOS_ResumeTask(u8 Copy_u8Priority){
    SYS_TASKS[Copy_u8Priority].TaskState = TASK_RESUMED;
}


static void Schedular( void ){

	u8 LOC_u8TaskCounter;

	for( LOC_u8TaskCounter = 0 ; LOC_u8TaskCounter < TASK_NUMBER ; LOC_u8TaskCounter++ ){

		if( ( SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler != NULL ) && ( SYS_TASKS[ LOC_u8TaskCounter ].TaskState == TASK_RESUMED ) ){

			if( SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay == 0 ){

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay = SYS_TASKS[ LOC_u8TaskCounter ].Periodicity - 1 ;
				SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler();

			}
			else{

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay--;

			}

		}
		else{

			/* Do No Thing */

		}

	}

}