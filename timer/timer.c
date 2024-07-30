#include <mega32.h>
#define xtal 8000000
void main(void)
{
PORTB=0x00;
DDRB=0x08;
TCCR0=0x7A;
TCNT0=0x06;
OCR0=0xe6;
while (1);
}