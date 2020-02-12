/*
 * lcd_screen.c
 *
 * Created: 12/02/2020 12:51:12 PM
 *  Author: jvgoo
 */ 
#include "lcdscreen.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define LCD_E 	3
#define LCD_RS	2
static int lcd_cursor_pos = 0x80;
void f_Init()
{
	
	f_SetCommand(0x03);	
	f_SetCommand(0x03);
	f_SetCommand(0x03);
    f_SetCommand(0x02);
    f_SetCommand(0x28);
    f_SetCommand(0x0f);
    f_SetCommand(0x80);
	
	
	
}
void lcd_write_char(unsigned char byte)

{
	 PORTC = byte & 0xF0;
	 PORTC = PORTC | 0x0C;
	 _delay_ms(1);
	 PORTC = 0x04;
	 PORTC = (byte & 0x0F) << 4;
	 PORTC = PORTC | 0x0C;;
	 _delay_ms(1);
	 PORTC = 0x00;
	
}
void f_DisplayText(char* str)
{
	f_SetCommand(0x80);
	for(int i = 0; i < strlen(str); i)
	{
			lcd_write_char(str[i]);
	}
}
 void f_SetCursor(int a_CursorPosition)
 {
	 lcd_cursor_pos = a_CursorPosition > 16 ? 0xC0 + a_CursorPosition : 0x80 + a_CursorPosition;
 }
 
 void f_clearScreen()
 {
	f_SetCommand(LCD_Clear);	 
 }
 void f_SetCommand(unsigned char byte)

 {
	 PORTC = byte & 0xF0;
	 PORTC = PORTC | 0x08; 
	 _delay_ms(1);
	 PORTC = 0x04;
	 PORTC = (byte & 0x0F) << 4;
	 PORTC = PORTC | 0x08;;
	 _delay_ms(1);
	 PORTC = 0x00;
	
	
	
 }
