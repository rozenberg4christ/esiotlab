#include<reg51.h>

void main()
{
	unsigned char t; // Declare here first else results error in Keil
	TMOD = 0x20;
	TH1 = 0xFD; // Baud rate = 9600
	SCON = 0x50;
	TR1 = 1;
	
	while(1)
	{
		while(RI==0);
		t = SBUF;
		P1 = t;
		RI = 0;
	}
}