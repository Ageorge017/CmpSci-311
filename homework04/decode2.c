#include<stdlib.h>


long decode2(long x, long y, long z){
 //long temp =y; 
 y -= z;
 
 x *= y;
 
 long temp  = y;
 temp  <<= 63;
 temp >>= 63;

 temp ^= x;
 return temp;
}

