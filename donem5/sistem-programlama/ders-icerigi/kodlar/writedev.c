#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv){
 char buffer[100];
 int devfile = -1;
 int req_sz = 100;
 strcpy( buffer, "Hello World!" );
 devfile = open("/dev/tdd", O_WRONLY);
 if(devfile < 0){
 perror("open"); 
 exit(-1);
 }
 if((write(devfile, buffer, req_sz))!=req_sz){
 printf( "Device file Write Error!\n" );
 }
 close(devfile);
 return(0);
} 