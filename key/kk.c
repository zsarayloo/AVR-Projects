#include <mega32.h>
#include <delay.h>
unsigned char i;
//unsigned char but;
unsigned char key;
unsigned char keytable[16]={0xee,0xde,0xce,0xbe,0xed,0xdd,0xcd,0xbd,0xec,0xdc,0xcc,0xbc,0xeb,0xdb,0xcb,0xbb};
char num[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,
0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};



void main (void)

{DDRC=0xff;
i=0;
PORTC=num[i];


  while(1)
{  
   DDRB=0x0F ;//4taye bala khorooji,4ta voroodi
PORTB=0xF0;//etesal moghavemate pullup
   while ((PINB&0xF0)==0xF0); //tashkhis midahad kelid feshorde shode 
   delay_ms(20);
   key=PINB&0x0f;//read column
   DDRB=0xf0;
   PORTB=0x0f;
   key=key|(PINB&0x0f);//read rate
   for(i=0;i<16;i++)
   {
   if (key==keytable[i] ){
   PORTC=num[i];
   delay_ms(1000);  
   }
   }
   
   
 }
}  