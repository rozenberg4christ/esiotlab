/*#include<reg51.h>
sbit led = P1^0; 				
void delay();

main()
{
	unsigned int i;
	while(1)
	{
	led=~led; 				
	for(i=0;i<1000;i++)
	delay();				
	}
}

void delay()					
{
	TMOD = 0x01;				
	TH0= 0xFC;  				
	TL0 = 0x66;
	TR0 = 1;   				
	while(TF0 == 0); 			
	TR0 = 0; 				
	TF0 = 0; 				
}*/