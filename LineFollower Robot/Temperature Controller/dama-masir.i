
#pragma used+
sfrb TWBR=0;
sfrb TWSR=1;
sfrb TWAR=2;
sfrb TWDR=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      
sfrb ADCSRA=6;
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
sfrw ICR1=0x26;   
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

#asm
   .equ __lcd_port=0x18 ;PORTB
#endasm

#pragma used+

void _lcd_ready(void);
void _lcd_write_data(unsigned char data);

void lcd_write_byte(unsigned char addr, unsigned char data);

unsigned char lcd_read_byte(unsigned char addr);

void lcd_gotoxy(unsigned char x, unsigned char y);

void lcd_clear(void);
void lcd_putchar(char c);

void lcd_puts(char *str);

void lcd_putsf(char flash *str);

unsigned char lcd_init(unsigned char lcd_columns);

void lcd_control (unsigned char control);

#pragma used-
#pragma library lcd.lib

#pragma used+

void delay_us(unsigned int n);
void delay_ms(unsigned int n);

#pragma used-

#pragma used+

unsigned char cabs(signed char x);
unsigned int abs(int x);
unsigned long labs(long x);
float fabs(float x);
int atoi(char *str);
long int atol(char *str);
float atof(char *str);
void itoa(int n,char *str);
void ltoa(long int n,char *str);
void ftoa(float n,unsigned char decimals,char *str);
void ftoe(float n,unsigned char decimals,char *str);
void srand(int seed);
int rand(void);
void *malloc(unsigned int size);
void *calloc(unsigned int num, unsigned int size);
void *realloc(void *ptr, unsigned int size); 
void free(void *ptr);

#pragma used-
#pragma library stdlib.lib

typedef char *va_list;

#pragma used+

char getchar(void);
void putchar(char c);
void puts(char *str);
void putsf(char flash *str);
int printf(char flash *fmtstr,...);
int sprintf(char *str, char flash *fmtstr,...);
int vprintf(char flash * fmtstr, va_list argptr);
int vsprintf(char *str, char flash * fmtstr, va_list argptr);

char *gets(char *str,unsigned int len);
int snprintf(char *str, unsigned int size, char flash *fmtstr,...);
int vsnprintf(char *str, unsigned int size, char flash * fmtstr, va_list argptr);

int scanf(char flash *fmtstr,...);
int sscanf(char *str, char flash *fmtstr,...);

#pragma used-

#pragma library stdio.lib

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
ADMUX=adc_input | (0x00 & 0xff);
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
ADMUX=0x00 & 0xff;
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
