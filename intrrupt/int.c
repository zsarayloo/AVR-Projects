#include <mega32.h>
#include <delay.h>
char num[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,
0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned char i;
unsigned char kbd_get(void);
void kbd_init(void);
void kbd_init()
{   
DDRC=0xf0;
PORTC=0x0f;
}



unsigned char kbd_get()
{
unsigned char kbd_in;
unsigned char kbd_num;
//scanning first row. 

PORTC=0xef;
delay_us(10);
kbd_in=PINC & 0x0f;
if(kbd_in!=0x0f)
{
 switch(kbd_in)
 {
  case 0x0e:kbd_num=7;goto exit_fcn;break;
  case 0x0d:kbd_num=4;goto exit_fcn;break;
  case 0x0b:kbd_num=1;goto exit_fcn;break;
  case 0x07:kbd_num=10;goto exit_fcn;break;
 }
   
}
//scanning second row.
PORTC=0xdf;
delay_us(10);
kbd_in=PINC & 0x0f;
if(kbd_in!=0x0f)
{
 switch(kbd_in)
 {
  case 0x0e:kbd_num=8;goto exit_fcn;break;
  case 0x0d:kbd_num=5;goto exit_fcn;break;
  case 0x0b:kbd_num=2;goto exit_fcn;break;
  case 0x07:kbd_num=0;goto exit_fcn;break;
 }  
}
//scanning third row.
PORTC=0xbf;
delay_us(10);
kbd_in=PINC & 0x0f;
if(kbd_in!=0x0f)
{
 switch(kbd_in)
 {
  case 0x0e:kbd_num=9;goto exit_fcn;break;
  case 0x0d:kbd_num=6;goto exit_fcn;break;
  case 0x0b:kbd_num=3;goto exit_fcn;break;
  case 0x07:kbd_num=11;goto exit_fcn;break;
 }  
}
//scanning fourth row.
PORTC=0x7f;
delay_us(10);
kbd_in=PINC & 0x0f;
if(kbd_in!=0x0f)
{
 switch(kbd_in)
 {
  case 0x0e:kbd_num=12;goto exit_fcn;break;
  case 0x0d:kbd_num=13;goto exit_fcn;break;
  case 0x0b:kbd_num=14;goto exit_fcn;break;
  case 0x07:kbd_num=15;goto exit_fcn;break;
 }  
}
kbd_num=0;
exit_fcn: 
kbd_init();
return(kbd_num);
} 
interrupt [19] void key_seg (void)
{  //PORTA=num[12];
PORTA=num[kbd_get()] ;
delay_ms(1000);


}
void main()
{    DDRD=0x00;
PORTD=0xff;
DDRA=0xff;
PORTA=0x00;
DDRC=0xf0;
PORTC=0x0f;
DDRB=0x00;
PORTB=0x00;
GICR=0b00100000;
MCUCSR=0b00000000;
i=0;
#asm("sei")
while(1)
{
PORTA=num[13];
delay_ms(20);
i=  PIND.0 +(PIND.1*2)+(PIND.2*4)+(PIND.3*8) ;
PORTA=num[i] | 0x80;
delay_ms(20);
}
}

