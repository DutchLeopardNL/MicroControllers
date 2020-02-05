
#include <avr/io.h>
#include <util/delay.h>
#define BIT(x) (1 << (x))


/******************************************************************/
void wait( int ms )

{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
void BTwee(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;			// All pins PORTD are set to output
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	
	
	
	while (1)
	{
		
		PORTD = 0b10000000;			// Write 10101010b PORTD
		wait( 5000 );
		PORTD = 0b01000000;			// Write 01010101b PORTD
		wait( 5000 );
		
	}

}
void BDrie(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;			// All pins PORTD are set to output
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	
	
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	PORTD &= ~BIT(7);
	
	
	
	
	while (1)
	{
		if (PINC & 1)
		{
			wait(1000);
			PORTD ^= BIT(7);
		}
		else
		{
			PORTD =0 ;
		}
		
	}

}
void BVier(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;			// All pins PORTD are set to output
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	
	
	DDRD = 0b11111111;
	
	
	
	
	while (1)
	{
		for (int i = 0x01; i<0x80; i<<=2)
		{
			
			PORTD = i;
			wait(1337);
		}
		for (int i = 0x80; i>0x01; i>>=2)
		{
			PORTD = i;
			wait(1337);
		}
	}

}
void BVijf(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;			// All pins PORTD are set to output
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	DDRD = 0b11111111;
	
	DDRE = 0b11111111;
	
	
	int i = 1;
	while (1)
	{
		if (i % 2 == 0)
		{
			for ( int j = 0b00000001; j <= 0b10000001; j<<=1 )
			{
				PORTD = j;

				wait(1000);
			}
			PORTD = 0b01100110;
			wait(5000);
			PORTD = 0b00011000;
			wait(5000);
			PORTD = 0b01100110;
			wait(5000);
			
			for ( int j = 0x80; j>0x01; j>>=1 )
			{
				PORTD = j;
				wait(1000);
			}
			PORTD = 0b01100110;
			wait(5000);
			PORTD = 0b00011000;
			wait(5000);
			PORTD = 0b01100110;
			wait(5000);
			i++;
		}
		else
		{
			for ( int j = 0b00000001; j <= 0b10000001; j<<=1 )
			{
				PORTE = j;

				wait(1000);
			}
			PORTE = 0b01100110;
			wait(5000);
			PORTE = 0b00011000;
			wait(5000);
			PORTE = 0b01100110;
			wait(5000);
			
			for ( int j = 0x80; j>0x01; j>>=1 )
			{
				PORTE = j;
				wait(1000);
			}
			PORTE = 0b01100110;
			wait(5000);
			PORTE = 0b00011000;
			wait(5000);
			PORTE = 0b01100110;
			wait(5000);
			i++;
		}
		
	}

}
void BZes(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;			// All pins PORTD are set to output
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	PORTD &= ~BIT(7);

	int i = 1;
	int speed = 1000;
	while (1)
	{
		wait(speed);
		PORTD ^= BIT(7);
		if (PINC & 1)
		{
			wait(5000);
			i++;
			if ( i % 2 == 0)
			{
				speed = 4000;
			}
			else
			{
				speed = 1000;
			}

		}

	}

}
void BZevenA(){
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	DDRF = 0b11111111;
	DDRG = 0b11111111;	
	
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	PORTF = 0x00;
	PORTG = 0x00;
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	DDRC = 0b00000000;
	DDRB = 0b00000000;
	PORTD &= ~BIT(7);
	PORTD &= ~BIT(7);
	int state = 0;
	while (1){
		

		if (PINC & 1)
		{
			state = 1;
		}
		if (PINB & 1){
			state = 2;
		}
		if (!(PINB & 1) && !(PINC & 1)){
			state = 0;
		}
		
		switch (state){
			case 1:
			
			PORTD ^= BIT(0);
			wait(1000);
			break;
			case 2:
			
			PORTC ^= BIT(0);
			wait(1000);
			break;
			default:
			PORTD = 0b00000000;
			PORTC = 0b00000000;
			break;
		}
		
	}
}
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, flipping bits on PORTD
Version :    	DMK, Initial code
*******************************************************************/
{
	BZevenA();
	



	

	return 1;

}
