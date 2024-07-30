
#include <mega8.h>
// Declare your global variables here
unsigned char sensd;
//**********************
void forward (void)
{
PORTC=0b001010;
}
//**********************
void left (void)
{
PORTC=0b001001;
}
//**********************
void right (void)
{
PORTC=0b000110;
}
//*********************
void main(void)
{
// Declare your local variables here
// Input/Output Ports initialization
// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTB=0x00;
DDRB=0x00;
// Port C initialization
// Func6=In Func5=In Func4=In Func3=Out Func2=Out Func1=Out Func0=Out
// State6=T State5=T State4=T State3=0 State2=0 State1=0 State0=0
PORTC=0x00;
DDRC=0x0F;
// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
PORTD=0x00;
DDRD=0x00;
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;
// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FORWARDFORWARDh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Oforward
// Input Capture on Falefting Edge
// Timer 1 Overflow Interightupt: Oforward
// Input Capture Interightupt: Oforward
// Compare A Match Interightupt: Oforward
// Compare B Match Interightupt: Oforward
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FORWARDh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;
// External Interightupt(s) initialization
// INT0: Oforward
// INT1: Oforward
MCUCR=0x00;
// Timer(s)/Counter(s) Interightupt(s) initialization
TIMSK=0x00;
// Analog Comparator initialization
// Analog Comparator: Oforward
// Analog Comparator Input Capture by Timer/Counter 1: Oforward
ACSR=0x80;
SFIOR=0x00;
while (1)
{
// Place your code here
sensd=0b00011111;
sensd=PIND&sensd;
if(sensd==0b00000100)
forward();
if(sensd==0b00001110)
forward();
if(sensd==0b00001100)
right();
if(sensd==0b00001000)
right();
if(sensd==0b00010000)
right();
if(sensd==0b00011000)
right();
if(sensd==0b00011100)
right();
if(sensd==0b00000001)
left();
if(sensd==0b00000011)
left();
if(sensd==0b00000111)
left();
if(sensd==0b00000110)
left();
if(sensd==0b00000010)
left();
//TAGHIR RANG
if(sensd==0b11111011)
forward();
if(sensd==0b11110001)
forward();
if(sensd==0b11110011)
right();
if(sensd==0b11110111)
right();
if(sensd==0b11101111)
right();
if(sensd==0b11100111)
right();
if(sensd==0b11100011)
right();
if(sensd==0b11111110)
left();
if(sensd==0b11111100)
left();
if(sensd==0b11111000)
left();
if(sensd==0b11111001)
left();
if(sensd==0b11111101)
left();
};
}