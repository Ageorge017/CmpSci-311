#include <stdio.h>
#include "test_endian.h"
// this function returns 1 if the store function
// actually stores value in little endian order.
// otherwise returns 0.
int is_little_endian(void (*store)(int*,int)) {

  int x;

  unsigned char *byte_ptr = (unsigned char*)(&x);
 
  store(&x,0x12345678);









	 



int count;
for( count = 0; count<4; count++){
switch(count){
	case 0 :
		if(*(byte_ptr+count) != 0x78){
		return 0;}
		continue;
	case 1 :
		if(*(byte_ptr+count) != 0x56){
		return 0;}
		continue;
	case 2:
		if(*(byte_ptr+count) != 0x34){
		return 0;}
		continue;
	//	break;
	case 3:
		if(*(byte_ptr+count) != 0x12){
		return 0;}
		continue;
	//	break;	
	default:
		return 1;	
}}
 return 1 ;
}
