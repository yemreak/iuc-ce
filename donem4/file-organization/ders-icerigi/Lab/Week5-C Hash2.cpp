#include<stdio.h>
#include<stdlib.h>
#define array_size 20 

int M = 10; 

int hash_function(char ch[], int M) {
   
   int i, sum=0;
   for (i=0; i < array_size; i++)
     sum += ch[i];
   return sum % M;
   //return sum;
}

int main() { 
	int l = hash_function("File Organization",M);
	printf("%d\n",l); 
}
