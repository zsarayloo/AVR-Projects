#include <mega32.h>
void main ()
{   
     DDRB=0xFF;
     portb=ox00;
     DDRA=0x00;
     PORTA=0x00;
     ADMUX =0xe1;
     ADCSRA=0x86;
     SFIOR=0;
     while(1)
     {      
        ADCSRA.6=1;   
        while (!(ADCSRA.4));
        ADCSRA.4=1;
        PORTB=ADCH;     
      };
      }
     