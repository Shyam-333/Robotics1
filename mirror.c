#include<avr/io.h>	//Including the header file in order to use input/output registers
void main()
{
	DDRA = 0x00;	// Declaring Port A to be an input port
	DDRB = 0xFF;	 // Declaring Port B to be an output port	
	PORTA = 0xFF;	// Setting the default voltage of Port A HIGH (Pull-up)
	char c;
	while(1)	 //Infinite loop
	{
		c = PINA;		 // Taking input from Port A and storing it in variable c	
		if(c == 0b11111111)		// If input is HIGH 
		     PORTB = 0b00000010;	// Motor will move in one direction 
		if(c == 0b11111110)		// If input is LOW 
		     PORTB = 0b00000001;	//Motor will move in other direction  
	}
}
