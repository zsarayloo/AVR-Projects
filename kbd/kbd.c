#include <mega32.h>
#include <delay.h>
unsigned char a;
unsigned char i;
unsigned char j;
unsigned char c;



void main (void)

{DDRC=0xff;
PORTC=0x00;
DDRB=0x0F ;
PORTB=0xF0;
  while(1)
{
 do
   {
   delay_ms (1000);
   PORTC=PINB;
    
   }
   while ((PINB&0xFF)==0xF0);
   i=0;
   do
   {
     if(i==0){PORTB=0x0e;} 
     if(i==1){PORTB=0x0d;}
     if(i==2){PORTB=0x0b;}
     if(i==3){PORTB=0x07;}
     a=PINB;
     if ((PINB&0xff)==0xF0){i++;}
     }
     while ((PINB&0xff)==0xF0);
     PORTB=0x00;
     switch(PINB&0xff){
     case 0xe0:j=0;break;
     case 0xd0:j=1;break;
     case 0xb0:j=2;break;
     default:  j=3;
     }
     if(i==0)
     {switch(j)
     {case 0:c=0x3f;break;
      case 1:c=0x06;break;
      case 2:c=0x5b;break;
      default :c=0x00 ;
      }}
      if (i==1)
      {switch (j)
      {case 0:c=0x4f;break;
       case 1:c=0x66;break;
       case 2:c=0x6d;break;
       default :c=0x00;  
       }}
       if(i==2)
       {switch(j)
       {case 0:c=0x7d;break;
        case 1:c=0x07;break;
        case 2 :c=0x7f;break;
        default : c=0x00 ;
        }}
        if(i==3)
        {switch(j)
        {case 0:c=0x6f;break;
        case 1:c=0x77;break;
        case 2:c=0x7c;break;
        default :c=0x00;
        }}
        PORTC=c;
        } 
        };
       