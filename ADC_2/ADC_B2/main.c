#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void adcInit(void);
void wait(int ms);

int main(void)
{
	DDRD = 0b01111111;
	PORTC = 0xFF;
	
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	adcInit();
	
	while (1)
	{
		if (PINC & 0x80)
		{
			PORTB = ADCL;
			PORTA = ADCH;
			wait(100);
		}
		else
		{
			PORTB = 0x00;
			PORTA = 0x00;
			wait(100);
		}
	}
	return 1;
}

void wait(int ms)
{
	for (int tms = 0; tms < ms; tms++)
	{
		_delay_ms(1);
	}
}

void adcInit(void)
{
	ADMUX = 0b01100001;
	ADCSRA = 0b11100110;
}