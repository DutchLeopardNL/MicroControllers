/*
 * lcd.c
 *
 * Created: 05/02/2020 01:39:08 PM
 *  Author: jvgoo
 */ 
#include <lcd.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LCD_E 	3
#define LCD_RS	2

static void lcd_strobe_lcd_e(void)

{
	PORTC |= (1<<LCD_E);	
	_delay_ms(1);			
	PORTC &= ~(1<<LCD_E);  
	_delay_ms(1);			
}

static void lcd_write_data(unsigned char byte)

{
	PORTC = byte;
	PORTC |= (1<<LCD_RS);
	lcd_strobe_lcd_e();


	PORTC = (byte<<4);
	PORTC |= (1<<LCD_RS);
	lcd_strobe_lcd_e();
}


void f_DisplayText(char* a_Text){
	for(;*a_Text; a_Text++){
		lcd_write_data(*a_Text);
	}
}

void f_SetCommand(unsigned char a_Instruction){
	PORTC = byte;
	PORTC &= ~(1<<LCD_RS);
	lcd_strobe_lcd_e();

	// Second nibble
	PORTC = (byte<<4);
	PORTC &= ~(1<<LCD_RS);
	lcd_strobe_lcd_e();
}

void f_SetCursor(int a_CursorPosition){
	
}

void f_Init(){
	DDRC = 0xFF;
	PORTC = 0x00;

	// Step 2 (table 12)
	PORTC = 0x20;	// function set
	lcd_strobe_lcd_e();

	// Step 3 (table 12)
	PORTC = 0x20;   // function set
	lcd_strobe_lcd_e();
	PORTC = 0x80;
	lcd_strobe_lcd_e();

	// Step 4 (table 12)
	PORTC = 0x00;   // Display on/off control
	lcd_strobe_lcd_e();
	PORTC = 0xF0;
	lcd_strobe_lcd_e();

	// Step 4 (table 12)
	PORTC = 0x00;   // Entry mode set
	lcd_strobe_lcd_e();
	PORTC = 0x60;
	lcd_strobe_lcd_e();
}
const struct LCD_t LCD = {
	.f_Init = f_Init,
	.f_DisplayText = f_DisplayText,
	.f_SetCommand = f_SetCommand,
	.f_SetCursor = f_SetCommand
};