#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv){
 char buffer[200];
 int devfile = -1;
 int read_sz = 0;
 devfile = open("/dev/tdd", O_RDONLY);
 if(devfile < 0){
 perror("open");
 exit(-1); 
 }
 read_sz = read(devfile, buffer, 200);
 if(read_sz==0){
 printf("No data available.\n");
 close(devfile);
 return 0;
 }
 printf( "The actual read size is:%d.\n", read_sz );
 printf( "The read content is:%s\n", buffer );
 close(devfile);
 return(0);
} 