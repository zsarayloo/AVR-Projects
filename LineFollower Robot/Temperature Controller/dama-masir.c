#include <mega8.h>
#asm
   .equ __lcd_port=0x18 ;PORTB
#endasm
#include <lcd.h>

#include <delay.h>
#include <stdlib.h>
#include <stdio.h>
#define ADC_VREF_TYPE 0x00
unsigned char i,k;
interrupt[2]void sensor1(void)
{ i++;
}
interrupt[3]void sensor2 (void)
{
k++;
}

unsigned char line;
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
delay_us(10);
ADCSRA|=0x40;
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}
long int adc1, adc2, adc3, adc4;
float adc0;
 unsigned char str[15];
 unsigned char str1[15];

void main(void)
{ DDRD=0x00;
PORTD=0x00;
GICR=0b11000000;
MCUCSR=0b00001111;
#asm("sei")
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x86;
lcd_init(16);
lcd_gotoxy(0,0);
lcd_putsf("temp is:");
lcd_gotoxy(0,1);
lcd_putsf("line is:");
while (1)
      {
       delay_ms(250);
       adc1=read_adc(2);
       delay_ms(250);
       adc2=read_adc(2);
       delay_ms(250);
       adc3=read_adc(2);
       delay_ms(250);
       adc4=read_adc(2);
       adc0=adc1+adc2;
       adc0=adc0+adc3;
       adc0=adc0+adc4;
       adc0=adc0/4;
       adc0=adc0/2.046;
       adc0=adc0+2;
       line=(i+k)/2;
       line=line*12;
       lcd_gotoxy(9,0);
       lcd_putsf(" ");
       itoa(adc0,str);
       lcd_puts(str);
       lcd_gotoxy(9,1);
       itoa(line,str1);
       lcd_putsf(" ");
       lcd_puts(str1);

      };
}
