/*
 * LCD.c
 *
 * Created: 05/02/2020 01:01:20 PM
 * Author : jvgoo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "lcdscreen.h"


int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Slow background task after init ISR
Version :    	DMK, Initial code
*******************************************************************/
{
	f_Init();
	f_clearScreen();
	f_DisplayText("Kurwa");
	while(1)
	{
		
	}
	return 1;
}
