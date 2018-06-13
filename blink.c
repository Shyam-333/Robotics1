#include<avr/io.h>	//This header file contains definitions of the registers
#include <util/delay.h>
main()			//Main part of the code
{
		DDRB = 0xFF;	//Define all pins of Port B as output pins
		while(1)	//Start an infinite while loop
		{
			PORTB = 0b00000001;
			_delay_ms(100);
			PORTB = 0b00000000;
			_delay_ms(100);
		}
}
