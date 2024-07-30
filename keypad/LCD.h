//**************************DEFINE**********************
#define    rs   PIN_C0
#define    rw   PIN_C1
#define    en   PIN_C2
//*******************DEFINE FUNCTION********************
com(int8);// WRITE COMMAND TO LCD//
read(int8);//WRITE AND READ TO LCD//
cls();//CLEAN SCREEN DISPLAY//
bin(int8);
//*
//*
//*
//*
//*
//*******************COMMAND********************

com(int8 a){
delay_ms(1);
OUTPUT_B( a);
output_low(RS);
output_low(rw);
output_high(en);
delay_cycles(1);
output_low(en);

}

//******************READ********************
read(int8 ch){
delay_ms(1);
OUTPUT_B(ch);
output_high(RS);
output_low(rw);
output_high(en);
delay_cycles(1);
output_low(en);
}
//**************CLEAN SCREEN****************
cls(){
int8 g[6]={0x0f,0x38,0x01,0x02,0x80,0x0C},i;
for(i=0;i<6;i++){
delay_ms(6);
com(g[i]);
}}
//******************************************
//*****************binary ascii**************
bin(int8 ci){
int8 ba2[9],i;
          for(i=1;i<=8;i++){
              ba2[i]=ci%2;
              ci/=2;
                          }
          for(i=8;i>0;i--){
              ba2[i]+=48;
              read(ba2[i]);
                }
}
