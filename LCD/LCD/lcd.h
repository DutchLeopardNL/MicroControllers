/*
 * lcd.h
 *
 * Created: 05/02/2020 01:39:26 PM
 *  Author: jvgoo
 */ 
#ifndef LCD_H_
#define LCD_H_

#define LCD_CMD_8bit_2Lines					0x38
#define LCD_CMD_8bit_1Lines					0x30
#define LCD_CMD_4bit_2Lines					0x28
#define LCD_CMD_4bit_1Lines					0x20
#define LCD_Scroll_1Char_R					0x1E
#define LCD_Scroll_1Char_L					0x18
#define LCD_Move_cursor_Home				0x02
#define LCD_Move_cursor_1L					0x10
#define LCD_Move_cursor_1R					0x14
#define LCD_TurnOn_UnderlineCursor			0x0E
#define LCD_TurnOn_BlinkingBlockCursor		0x0F
#define LCD_Make_cursor_Invisible			0x0C
#define LCD_Blank_Display					0x08
#define LCD_Restore_Display					0x0C
#define LCD_Clear							0x01
#define LCD_Set_Cursor						(addr) (int)(128 + (int)addr)
#define LCD_Set_Pointer						(addr) (int)(64 + (int)addr)

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