/*#include<reg51.h>
sbit led = P1^0;				// LED connected to 1st pin of port P1
void delay();
void main()
{
	unsigned int i;
	while(1)
	{
	led=~led;				// Toggle LED	
	for(i=0;i<1000;i++)
	delay();				// Call delay
	}
}

void delay()
{
	TMOD = 0x02;				// Mode1 of Timer0
	TH0= 0xA2;				// Initial value loaded to Timer
	TR0 = 1;				// Start Timer
	while(TF0 == 0);			// Polling for flag bit
	TR0 = 0;				// Stop Timer
	TF0 = 0;				// Clear flag
}*/