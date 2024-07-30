#include <mega32.h>
#include <stdio.h>
#include <lcd.h>
#include <stdlib.h>
#include <delay.h>
#asm
   .equ_lcd_port=0x15
   #endasm
   int i;
  // char str[10];
   void main()
   {//itoa(i,str);
   lcd_init(16);
   
   for (i=0;i<100;i++)
   {
   lcd_clear();
   lcd_gotoxy(0,0);
  // lcd_puts(str);
   delay_ms(500);
   }
   }
   