#include <stdio.h>
#include <stdlib.h>
#include "float_i2f.h"

float_bits float_i2f(int i) {

 if( i == 0){
  return 0;
 }
 
 unsigned sign;
 sign = i&0x80000000;

 int absVal;
 if(sign != 0 ){
  absVal= -i ;
 }
 else{
  absVal = i;
 }

 unsigned mantissa;
 int countExp  = 1;
 unsigned exponent;

 mantissa = i & 0x7fffffff;
 while(1){
  if((mantissa & 0x40000000) != 0){
   break;
  }
  mantissa = mantissa<<1;
  countExp++;
 }

 countExp = 31 - countExp;
 exponent = (countExp + 127) << 23;
 mantissa = (mantissa &0x3fffffff) >> 7;

 if((exponent > 23)&& (i>0x01000002)){
  if ((mantissa & 0x00000001) == 1){
   mantissa++;
   }
  }
 //printf("sign = %x, exponent= %x, mantissa = %x ",sign, exponent, mantissa );
 
 return sign |exponent | mantissa ;


}
