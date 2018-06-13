#include<avr/io.h>	// Including the header file in order to use input/output registers
void main()
{
	DDRA = 0x00;	//Input port
	DDRB = 0xFF;	//Output port
	PORTA = 0xFF;	// Setting the default voltage of Port A HIGH (Pull-up) 
	char c;
	while(1)
	{
		c = PINA;
		if(c == 0b11111111)		// If all the sensors input HIGH i.e. no edge detected
			PORTB = 0b00001010;			// Move forward
		else if((c == 0b11111110)||(c == 0b11111011)||(c == 0b11111010))	// if any or both of the Right sensors detect edge
			PORTB = 0b00000010;			// Left Turn:  Right motor- FORWARD , Left motor: STOP
		else if((c == 0b11111101)||(c == 0b11110111)||(c == 0b11110101))	// if any of the Left sensor detects edge or Both of them detects edge
			PORTB = 0b00001000;			// Right Turn:  Right motor-STOP , Left motor-FORWARD
		else if(c == 0b11110011)			// If both back sensors detects edge
			PORTB = 0b00001010;		//Move forward
		else if(c == 0b11111100)			//If both front sensors detects edge
			PORTB = 0b00000110;			// Hard U Turn: Left motor-Backwards, Right motor – Forward
		else
			PORTB = 0b00001111;
	}
}