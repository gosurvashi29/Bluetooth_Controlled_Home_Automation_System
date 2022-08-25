#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define BR 9600UL
#define PS ((F_CPU/(16*BR))-1)







void usart_init()
{
	UCSRB =(1<<RXEN) | (1<<TXEN);
	UCSRC =(1<<URSEL) | (1<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);
	UBRRL=PS;
	UBRRH=(PS>>8);
}

void usart_tx(unsigned char data)
{
	while((UCSRA & 0x20)==0);
	UDR=data;
}
void usart_txstring(char *str)
{
	int i=0;
	while (str[i]!='\0')
	{
		usart_tx(str[i]);
		_delay_ms(100);
		i++;
		
	}
}

unsigned int usart_rx()
{
	while((UCSRA & 0x80)==0);
	return UDR;
}

int main()
{
	usart_init();
	DDRB=0XFF;
	int i=0;
	int j=0;
	int k=0;
	int l=0;
	while(1)
	{
		char c= usart_rx();
		 if((c=='F') && (i==0))
		{
			//PORTB=0b00000100;	
			PORTB= (PORTB)|(0b00000100);
			
		}
          if((c=='F') && (i==1))
       	{
	        //PORTB=0b00000100;
	       	PORTB= (PORTB)& (0b11111011);
	       
		   }	
		 if((c=='B') && (j==0))
		{
			PORTB=(PORTB)|(0b00001000);
			
		}
		
		if((c=='B') && (j==1))
		{
			
			PORTB=(PORTB)&(0b11110111);
		}

        /*if ((PINC ==0b00000001) && (k==0))
        { 
			PORTB=(PORTB)|(0b00000001);
			k=1;
        }
		
		
		if((PINC ==0b00000001) && (k==1))
		{
			
			PORTB=(PORTB)&(0b11111110);
			k=0;
		}

		if((PINC ==0b00000010) && (l==0))
		{
			PORTB=(PORTB)|(0b00000010);
			l=1;
		}
		
		if((PINC ==0b00000010) && (l==1))
		{
			PORTB=(PORTB)&(0b11111101); 
			l=0;
		}*/
		if((c=='R') && (k==0))
		{
			PORTB=(PORTB)|(0b00000001);
		}
		
		if((c=='R') && (k==1))
		{
			
			PORTB=(PORTB)&(0b11111110);
		}

		if((c=='L') && (l==0))
		{
			PORTB=(PORTB)|(0b00000010);
		}
		
		if((c=='L') && (l==1))
		{
			PORTB=(PORTB)&(0b11111101);
		}
		if(c=='S')
		{
			PORTB=0b00000000;
		}
	
		if ( c== 'q')
		 {
			if (i==0)
			{
				i=1;
			}
			else if (i==1)
			{
				i=0;
			}
		}
		if ( c== 'y')
		{
		
			if (j==0)
			{
				j=1;
			}
			else if (j==1)
			{
				j=0;
			}
			
		}			
		if (c == 'z')
			{
			
			if (k==0)
			{
				k=1;
			}
			else if (k==1)
			{
				k=0;
			}
			
			}	
			if (c=='t')
			{
			
								
			 if (l==0)
			 {
				 l=1;
			 }
			 else if (l==1)
			 {
				 l=0;
			 }
			}			 
			 
		 }

		   }		
