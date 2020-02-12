/*
 * lcd.h
 *
 * Created: 05/02/2020 01:39:26 PM
 *  Author: jvgoo
 */ 
#ifndef LCD_H_
#define LCD_H_



struct LCD_t
{
	void (*f_Init)();
	void (*f_DisplayText)	(char* a_Text);
	void (*f_SetCursor)		(int a_CursorPosition);
	void (*f_SetCommand)	(unsigned char a_Instruction);
	
	};
	
static void f_Init();
static void f_DisplayText(char* a_Text);
static void f_SetCursor(int a_CursorPosition);
static void f_SetCommand(unsigned char a_Instruction);

endif /* LCD_H_ */








#endif