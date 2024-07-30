#include "C:\Documents and Settings\4\My Documents\keypad\kp.h"
#include <stdio.h>
#include <string.h>
#include <LCD.h>
#include <KEYPAD.h>




void main()
{

   port_b_pullups(TRUE);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
cls();
while(1){
key();
}

}

