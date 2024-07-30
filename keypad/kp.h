#include <16F876A.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES HS                    	//High speed Osc (> 4mhz)
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NODEBUG               	//No Debug mode for ICD
#FUSES BROWNOUT              	//Reset when brownout detected
#FUSES LVP                   	//Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOCPD                 	//No EE protection
#FUSES NOWRT                 	//Program memory not write protected

#use delay(clock=20000000)

