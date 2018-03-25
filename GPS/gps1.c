#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>

#include "uart.h"
#include "uart.c"
#include "softuart.h"
#include "softuart.c"
#include <avr/interrupt.h>


void CHECK_FOR_DATA()
{
unsigned char c;
softuart_puts("data");
sbi(PORTC,3);
	while(c!='$')
	{
		c=uart_getc();
		softuart_putchar(c);
		//softuart_puts("\t");
	}

sbi(PORTC,2);
	while(c!='G')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}

	

	while(c!='P')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}
	while(c!='R')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}
	while(c!='M')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}
	while(c!='C')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}
	while(c != ',')
	{
	c=uart_getc();
	softuart_putchar(c);
	//softuart_puts("\n");
	}
     
	c='\0';
	sbi(PORTC,2);
	

}


void main()
{
   
DDRC=0x0f;
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	softuart_init();
	sei();
	softuart_puts("initialized");
	softuart_puts("\n");
	
	PORTC=0x00;
	

	int i=0,z=0;
	unsigned char c=0,a=0;
	

 //  _delay_ms(2000);
//	PORTC=0x00;
	
	
	char str[3]={0},str2[3],str3;
   
while(1)
   	
{


 cbi(PORTC,0);
	
	c = uart_getc();

		if(c=='$')
		{
		
		cbi(PORTC,2);
		CHECK_FOR_DATA();
		
		
		
		}
		
		
		
	
	_delay_ms(10);
	
	
	
	
}


/*next:	
        while(c!='$')
		{
		c=uart_getc();	
		    
			str[i]=c;
			i++;
		}
         i=0;

		if(str[11]=='A')
		{		
		
		softuart_puts("ok");
				
		}
		
		else
		{
		
		softuart_puts("no data");
		goto begin;
		
		
		}
		
		
		
	
	/*softuart_puts("comp");
	
	
		while(c!='V')
		{
		c=uart_getc();
		//softuart_putchar(c);
		//softuart_puts("\n");
		}
			
		i=0;
		
		while(c!='$')
		{
			
			 c=uart_getc();

			//if(!(c&UART_NO_DATA))
			// {
				// sbi(PORTC,2);
					str[i]=c;
					  i++;
				softuart_putchar(c);
 	  
			//}		  
		}
		//softuart_puts(str);
		softuart_puts("\n");
		z=0;
		/*while(c!='E')
		{
			
			 c=uart_getc();

			//if(!(c&UART_NO_DATA))
			// {
				// sbi(PORTC,2);
					str2[z]=c;
					  z++;  	  
			//}		  
		}
		
		softuart_puts(str2);
		softuart_puts("\t");
		
		
		_delay_ms(100);
		 
		//_delay_ms(200);*/

		

}