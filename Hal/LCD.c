/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 22 / 5 / 2023                                           */
/*  Version : V1.0                                                 */
/*******************************************************************/
#include "../Common/BIT_MATH.h"
#include "../Common/STD_TYPES.h"
#include "../Common/MEMORY_MAP.h"
#include "../Common/ERROR_STATUS.h"

#include "Includes/LCD.h"
#include "../Config/LCD_config.h"
#include "../Mcal/Includes/GPIO_interface.h"
#include "../Mcal/Includes/STK_interface.h"
#include "../Mcal/Includes/RCC_interface.h"


static void SendEnablePulse(void);

ES_t LCD_4BitInitialize(void){
 ES_t Local_enuErrorstate = ES_NOK;
 RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPA);
    RCC_EnablePeripheralClock(RCC_APB2, RCC_IOPB);
    // Initialize GPIOs
    GPIO_SetPinMode(LCD_CTRL_PORT, LCD_RS_PIN, GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinMode(LCD_CTRL_PORT, LCD_E_PIN, GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinMode(LCD_DATA_PORT, LCD_D4, GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinMode(LCD_DATA_PORT, LCD_D5, GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinMode(LCD_DATA_PORT, LCD_D6, GPIO_OUTPUT_2MHZ_PP);
    GPIO_SetPinMode(LCD_DATA_PORT, LCD_D7, GPIO_OUTPUT_2MHZ_PP);
    // Initialize LCD
    // Wait for 15ms
    STK_StartBusyWait(15000);
    LCD_WriteCommand4Bit(0x33);
    // Wait for 4.1ms
    STK_StartBusyWait(4100);
    LCD_WriteCommand4Bit(0x32);
    // Wait for 100us
    STK_StartBusyWait(100);
    LCD_WriteCommand4Bit(0x28);
    // Wait for 100us
    STK_StartBusyWait(100);
    LCD_WriteCommand4Bit(0x0C);
    // Wait for 100us
    STK_StartBusyWait(100);
    LCD_WriteCommand4Bit(0x01);
    // Wait for 2ms
    STK_StartBusyWait(2000);
    LCD_WriteCommand4Bit(0x06);
    // Wait for 2ms
    STK_StartBusyWait(2000);
    Local_enuErrorstate = ES_OK;
    return Local_enuErrorstate;
}

ES_t LCD_WriteCommand4Bit(u8 Command){
    ES_t Local_enuErrorstate = ES_NOK;
    // Set RS to LOW (Command)
    GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);

    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4, GET_BIT(Command, 4));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5, GET_BIT(Command, 5));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6, GET_BIT(Command, 6));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7, GET_BIT(Command, 7));
    SendEnablePulse();
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4, GET_BIT(Command, 0));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5, GET_BIT(Command, 1));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6, GET_BIT(Command, 2));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7, GET_BIT(Command, 3));
    SendEnablePulse();
    Local_enuErrorstate = ES_OK;
    return Local_enuErrorstate;
}

ES_t LCD_WriteData4Bit(u8 Data){
    ES_t Local_enuErrorstate = ES_NOK;
    // Set RS to HIGH (Data)
    GPIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);

    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4, GET_BIT(Data, 4));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5, GET_BIT(Data, 5));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6, GET_BIT(Data, 6));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7, GET_BIT(Data, 7));
    SendEnablePulse();
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D4, GET_BIT(Data, 0));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D5, GET_BIT(Data, 1));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D6, GET_BIT(Data, 2));
    GPIO_SetPinValue(LCD_DATA_PORT, LCD_D7, GET_BIT(Data, 3));
    SendEnablePulse();
    Local_enuErrorstate = ES_OK;
    return Local_enuErrorstate;
}

ES_t LCD_WriteString4Bit(char *string){
	ES_t Local_enuErrorstate = ES_NOK;
	u8 i=0;
	while(string[i] != '\0'){
		LCD_WriteData4Bit(string[i]);
		i++;
	}
	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}

	
ES_t LCD_GoToXY4Bit(u8 X_Pos,u8 Y_Pos){
    ES_t Local_enuErrorstate = ES_NOK;
	u8 Address;
	/*	Location at First row	*/
	if(Y_Pos == 0){
		Address = X_Pos;
	}
	/*	Location at second Row	*/
	else if(Y_Pos == 1){
		Address = X_Pos + 0x40;
	}
	LCD_WriteCommand4Bit(128+Address);
	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}

ES_t LCD_WriteNumber4Bit(s32 Number){
    ES_t Local_enuErrorstate = ES_NOK;
	s32 NUM = 1;
	if(Number == 0){
		LCD_WriteData4Bit('0');
	}
	else if(Number < 0){
		LCD_WriteData4Bit('-');
		Number = Number * (-1);
	}
	while(Number){
		NUM = ((NUM * 10) + (Number % 10));
		Number = Number / 10;
	}
	while(NUM != 1){
		LCD_WriteData4Bit((NUM % 10) + 48);
		NUM = (NUM / 10);
	}
	Local_enuErrorstate = ES_OK;
	return Local_enuErrorstate;
}

ES_t LCD_Clear4Bit(void){
    ES_t Local_enuErrorstate = ES_NOK;
    LCD_WriteCommand4Bit(0x01);
    Local_enuErrorstate = ES_OK;
    return Local_enuErrorstate;
}


static void SendEnablePulse(void){
    // Set Enable to HIGH
    GPIO_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, HIGH);
    // Wait for 1ms
    STK_StartBusyWait(1000);
    // Set Enable to LOW
    GPIO_SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, LOW);
    // Wait for 1ms
    STK_StartBusyWait(1000);
}

