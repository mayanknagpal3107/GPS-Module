#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

#include "uart.h"
#include "uart.c"
#include <avr/interrupt.h>
#include "softuart.h"
#include "softuart.c"

char buff[7]="$GPRMC";
//char buf[7]="$GPRMC";
int c=0;
int i=0;
 int buff1[64];


int main()
{
DDRC=0xff;
uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
	//uart_puts("initialized");//uart_putc('f');
	softuart_init();
    sei();


start:
	while(1)
	{
	
		c=uart_getc();
		if(c!=0)
		{
			if(buff[i]==c)			
			{
			
				i++;
				
				if(i==6)
				{
				softuart_puts(buff);
				sbi(PORTC,3);
				goto next;
				
				}
				
				
			}
			
			else
			{
				i=0;
				
			}
		
		}	
	}

next:

	i=0;

	while(1)
	{
		c=uart_getc();
		if(!(c & UART_NO_DATA))
		{
		
			if(c!='$')
			{
			 buff1[i]=c;
			 softuart_puts(buff1);
			 i++;		 
			}		 
		
			else
			{
			sbi(PORTC,2);
			i=0;			
			goto aa;
			
			}
		}	
	}
	
	
aa:	
	softuart_puts("ok");
	while(1);
	{
		 sbi(PORTC,2);
		 softuart_puts("ok");
	
	
	
	}
	
	
	
	
	
	
	
	
	
	
	



}