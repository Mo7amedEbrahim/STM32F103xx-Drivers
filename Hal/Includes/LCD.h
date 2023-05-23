/*******************************************************************/
/*  Author : Mohammed Gaafar                                       */
/*  Date : 22 / 5 / 2023                                           */
/*  Version : V1.0                                                 */
/*******************************************************************/
#ifndef _LCD_H_
#define _LCD_H_



ES_t LCD_4BitInitialize(void);

ES_t LCD_WriteCommand4Bit(u8 Command);

ES_t LCD_WriteData4Bit(u8 Data);

ES_t LCD_WriteString4Bit(char *string);
	
ES_t LCD_GoToXY4Bit(u8 X_Pos,u8 Y_Pos);

ES_t LCD_WriteNumber4Bit(s32 Number);





#endif