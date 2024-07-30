
#pragma used+
sfrb TWBR=0;
sfrb TWSR=1;
sfrb TWAR=2;
sfrb TWDR=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      
sfrb ADCSRA=6;
sfrb ADCSR=6;     
sfrb ADMUX=7;
sfrb ACSR=8;
sfrb UBRRL=9;
sfrb UCSRB=0xa;
sfrb UCSRA=0xb;
sfrb UDR=0xc;
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PINC=0x13;
sfrb DDRC=0x14;
sfrb PORTC=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEARL=0x1e;
sfrb EEARH=0x1f;
sfrw EEAR=0x1e;   
sfrb UBRRH=0x20;
sfrb UCSRC=0X20;
sfrb WDTCR=0x21;
sfrb ASSR=0x22;
sfrb OCR2=0x23;
sfrb TCNT2=0x24;
sfrb TCCR2=0x25;
sfrb ICR1L=0x26;
sfrb ICR1H=0x27;
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1B=0x28;  
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw OCR1A=0x2a;  
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrw TCNT1=0x2c;  
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb SFIOR=0x30;
sfrb OSCCAL=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUCSR=0x34;
sfrb MCUCR=0x35;
sfrb TWCR=0x36;
sfrb SPMCR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GICR=0x3b;
sfrb OCR0=0X3c;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#pragma used+

void delay_us(unsigned int n);
void delay_ms(unsigned int n);

#pragma used-

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
{  
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

