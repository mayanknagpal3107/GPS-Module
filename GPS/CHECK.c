#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

#include "uart.h"
#include "uart.c"
#include <avr/interrupt.h>
#include "softuart.h"
#include "softuart.c"


void init()
{
//long char d,p;
	//int caller;
	DDRC=0XFF;
	//PORTC=255;
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
	//uart_puts("initialized");//uart_putc('f');
	softuart_init();
    sei();
    //softuart_turn_rx_on();
	
	//_delay_ms(100);
	softuart_puts("initialized");
}


void main()
{
 init();
 int c;
	while(1)
	{   
	    
	    	softuart_putchar('o');
			_delay_ms(1000);
		/*c=uart_getc();
		if(c!=0)
		{
			if(c=='a')
			{
			sbi(PORTC,3);
			softuart_putchar('o');
			softuart_putchar('k');
			softuart_putchar(c);
			}
			
			
			
		}*/
	}
	       
	
}