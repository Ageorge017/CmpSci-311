#include <stdio.h>
#include <stdlib.h>

void good_echo(){
  char buf[8];
  char *p;
  int i;
  while(1){ //reuse buffer for bigger strings  
    p =  fgets(buf, 8, stdin);

    if ( p == NULL){
   // printf("inside if\n");
      break;
    }

    fputs(buf, stdout);

   for(i = 0; i< 7; i++){
     if(buf[i] == '\n'){
       return;
     }
   }
  }
 }
int main(){
  good_echo();
  //printf("back in main\n");
  return 0;
}
