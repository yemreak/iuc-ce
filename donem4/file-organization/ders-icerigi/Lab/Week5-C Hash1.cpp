#include<stdio.h>
#include<stdlib.h>
#define array_size 100 
struct hello { 
	char *name;struct hello *next; 
}; 
int number = 0; 

int hash_function ( const char *str ) {  
	int result = 0;  
	while ( *str ) {    
		result += *str++;  }  
	return result; 
	array_size;
}
/*int hash_function(char *name,int number) { 
	int x = number % array_size; number++; return x;   
}  */
int main() { 
	int l = hash_function("Merhaba");
	//int l = hash_function("Good morning",number);
	printf("%d\n",l); 
}