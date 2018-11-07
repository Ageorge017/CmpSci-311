#include "csapp.h"

int main(int argc, char **argv) 
{
  int n, fd;
  rio_t rio;
  char buf[MAXLINE];
  
 if (argc ==2){
   fd = Open(argv[1], O_RDONLY, 0); //opens file descriptor table for file given in the second arguement
  while ((n = Rio_readn(fd,buf, MAXBUF))> 0){ //loop to read each byte in file
   Rio_writen(STDOUT_FILENO, buf, n);
  }
  exit(0);
 }
  Rio_readinitb(&rio, STDIN_FILENO);
  while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) 
    Rio_writen(STDOUT_FILENO, buf, n);

  return 0;
}



