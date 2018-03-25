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


/*int in()
{

int c,i=0;
int count=0;

	

}*/
void main()
{
    DDRD=0XFF;
    DDRC=0XFF;
	char buf[7]="$GPRMC";
	int c,j,i=0;
	int time[11];
	int lat[11];
	int dr[2];
	int dp[2];
	int lon[11];
	int SPEED[5];
	int DEG[5];
	int DATE[7];
	int gp[8];
	int data[64];
	int count=0;
	init();
	_delay_ms(1000);
	         
		
 
	while(1)
	{   
	    start:;
	    
		c=uart_getc();
		//if(c!=0)
		if(!(c& UART_NO_DATA))
		{
			///softuart_putchar(c);
			
			if(buf[i]==c)
			{
				//softuart_putchar(c);
				count++;
				i++;
				//PORTC=255;
				if(count==6){
					softuart_puts(buf);
					//softuart_putchar('c');
					sbi(PORTC,3);
					//while(1);
					goto sd;
				}
			}
			else{
				i=0;
				count=0;
			}
		}
	}
	        sd:
			
		while(1)
	    {
			i=0;
			c=uart_getc();
			if(!(c& UART_NO_DATA))
			{
				//softuart_putchar(c);
				if(c!='$')
				{
					data[i]=c;
					softuart_putchar(data[i]);
					i++;
				}
				else{
					softuart_puts("$");
					sbi(PORTC,2);
					//goto star;
					goto start;
					//while(1);
				}
				
				
			}
		
			//PORTC=0X01;
			//goto star;
		}
	/*	 star:;
		 
		 
		 
		 while(1);
		 
			 //for(int j=0;j<=20;j++){
				//softuart_putchar(data[j]);
				//}
			
			    i=1;
				if(data[11]=='V')
				{
				   softuart_puts("okk");
				   for(i=1;i<=10;i++)
					time[i]=data[i];
					softuart_puts(time);
					goto sta;
				}
                    if(data[18]=='V')
					{
						softuart_puts("ok");
					}
					if(data[19]=='V')
					{
						softuart_puts("okp");
					}	
				else{
					goto  start;
				}
	
				
		   
         
			sta:;
			while(1)
			{
			    i=1;
				int j=15;
				if(data[14]==',')
				{
				   for(i=1;i<10;i++)
				   {
						lat[i]=data[j];
						j++;
					}	
						softuart_puts(lat);
						
				}	goto st;
			}	
             
                st:;
				while(1)
				{
					i=0;
					if(data[24]==',')
					{
						dr[i]=data[25];
					}	
						softuart_puts(dr);
						goto tt;
				}
				
				tt:;
				while(1)
				{
					i=1;
				    j=27;
					if(data[26]==',')
					{
						for(i=1;i<=10;i++)
						{
							lon[i]=data[j];
							j++;
						}	
						softuart_puts(lon);
					}	
					goto ts;	                                                                                  
					
				}	
                 
				 ts:;
				while(1)
				{
					i=0;
					j=38;
					if(data[37]==',')
						dp[i]=data[38];
						
						softuart_puts(dr);
						goto aa;
				}
				
				aa:;
				while(1)
				{
					i=1;
				    j=40;
					if(data[39]==',')
					{
						for(i=1;i<=4;i++)
						{
							SPEED[i]=data[j];
							j++;
						}	
						softuart_puts(SPEED);
						
					}
					goto bb;
				}
				
				bb:;
				while(1)
				{
					i=1;
				    j=45;
					if(data[44]==',')
					{
						for(i=1;i<=4;i++)
						{
							DEG[i]=data[j];
							j++;
						}	
						softuart_puts(DEG);
						
					}
					goto cc;
				}
				
				cc:;
				while(1)
				{
					i=1;
				    j=50;
					if(data[49]==',')
					{
						for(i=1;i<=6;i++)
						{
							DATE[i]=data[j];
							j++;
						}	
						softuart_puts(DATE);
						
					}
					goto dd;
				}
				
				dd:;
				while(1)
				{
				    i=1;
					j=57;
					
					if(data[56]==',')
					{
					  for(i=1;i<=6;i++)
						{
							gp[i]=data[j];
							j++;
						}	
						softuart_puts(gp);
						
					}
					goto start;
				}*/	
				
			
			
			
			
		
	
}	
