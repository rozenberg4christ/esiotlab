/*#include<reg51.h>
void main()
{
	TMOD = 0x20;
	TH1 = 0xFD; // Baud rate = 9600
	SCON = 0x50;
	TR1 = 1;
	while(1)
	{
		SBUF='A';
		while(TI==0);
		TI=0;
	}
}*/