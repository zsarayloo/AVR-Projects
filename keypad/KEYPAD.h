key();
column_1();
number_1();
number_2();
number_3();
column_2();
number_4();
number_5();
number_6();
column_3();
number_7();
number_8();
number_9();
column_4();
number_mu();
number_0();
number_P();

/////////////////////////////////////

key(){

output_bit( PIN_A0,1);
output_bit( PIN_A1,0);
output_bit( PIN_A2,0);
output_bit( PIN_A3,0);
column_1();
output_bit( PIN_A0,0);
output_bit( PIN_A1,1);
output_bit( PIN_A2,0);
output_bit( PIN_A3,0);
column_2();
output_bit( PIN_A0,0);
output_bit( PIN_A1,0);
output_bit( PIN_A2,1);
output_bit( PIN_A3,0);
column_3();
output_bit( PIN_A0,0);
output_bit( PIN_A1,0);
output_bit( PIN_A2,0);
output_bit( PIN_A3,1);
column_4();
}



column_1(){

if (input(PIN_A4)==1 ){
                       while(input(PIN_A4)==1);
                       number_1();
                      }
if (input(PIN_A5)==1 ){
                       while(input(PIN_A5)==1);
                       number_2();
                      }
if (input(PIN_C7)==1 ){
                       while(input(PIN_C7)==1);
                       number_3();
                      }

}

number_1(){
printf(read,"1");

}

number_2(){
printf(read,"2");

}

number_3(){

printf(read,"3");
}

column_2(){

if (input(PIN_A4)==1 ){
                       while(input(PIN_A4)==1);
                       number_4();
                      }
if (input(PIN_A5)==1 ){
                       while(input(PIN_A5)==1);
                       number_5();
                      }
if (input(PIN_C7)==1 ){
                       while(input(PIN_C7)==1);
                       number_6();
                      }

}

number_4(){
printf(read,"4");

}

number_5(){
printf(read,"5");

}

number_6(){

printf(read,"6");
}

column_3(){

if (input(PIN_A4)==1 ){
                       while(input(PIN_A4)==1);
                       number_7();
                      }
if (input(PIN_A5)==1 ){
                       while(input(PIN_A5)==1);
                       number_8();
                      }
if (input(PIN_C7)==1 ){
                       while(input(PIN_C7)==1);
                       number_9();
                      }

}

number_7(){
printf(read,"7");

}

number_8(){
printf(read,"8");

}

number_9(){

printf(read,"9");
}

column_4(){

if (input(PIN_A4)==1 ){
                       while(input(PIN_A4)==1);
                       number_mu();
                      }
if (input(PIN_A5)==1 ){
                       while(input(PIN_A5)==1);
                       number_0();
                      }
if (input(PIN_C7)==1 ){
                       while(input(PIN_C7)==1);
                       number_p();
                      }

}

number_mu(){
printf(read,"*");

}

number_0(){
printf(read,"0");

}

number_p(){

printf(read,"#");
com(1);//cls lcd
com(0x80);//first line lcd
}