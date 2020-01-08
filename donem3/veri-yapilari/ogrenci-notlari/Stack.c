#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// Stack Yapısı
typedef struct stack {
 int top;
 int items[STACK_SIZE];
}Stack;


// Stack oluşturma
Stack create_stack();

// Stack'e eleman ekleme
void push_stack(Stack *, int);

// Stack'ten eleman çıkarma
int pop_stack(Stack *);


// Stack'i yazdırma
void print_stack(Stack *s);

// Stack arayüzü
void menu_stack(Stack *);

int main() {
 // Stack
 Stack mystack = create_stack();

  menu_stack(&mystack);
}

// Stack oluşturma
Stack create_stack() {
 Stack s;

  s.top = -1;

  printf("-> Stack olusturuldu. \n\n");
 return s;
}

// Stack'e eleman ekleme
void push_stack(Stack *s, int x) {
 if (s == NULL) 
  printf("Stack yok !\n");
 else if (s->top == STACK_SIZE - 1) 
  printf("Stack dolu\n");
 else {
  s->items[++(s->top)] = x;
  printf("-> %d eklendi.\n", x);
 }
}

// Stack'ten eleman çıkarma
int pop_stack(Stack *s) {
 int x = 0;

  if (s == NULL)
  printf("Stack mevcut degil !\n");
 else if (s->top == -1)
  printf("Stack bos !\n");
 else {
  x = s->items[(s->top)--];
  printf("-> %d stackten cikarildi\n", x);
 }
 return x;
}

// Stack'i yazdırma
void print_stack(Stack *s) {
 printf("\nStack verileri: \n");
 
 if (s == NULL) {
  printf("--- Stack mevcut degil ! ---\n");
  
  return;
 }
 if(s->top == -1)
  printf("--- Stack bos ---\n");

  for(int temp = s->top; temp >= 0; temp--)
  printf("%d. veri: %d\n", temp + 1 , s->items[temp]);
}

// Stack arayüzü
void menu_stack(Stack *s) {
 while (1) {
  printf("*** *** ***\n");
  printf("      1    -->    EKLE               \n");
  printf("      2    -->    CIKAR               \n");
  printf("      3    -->    GOSTER               \n");
  printf("      0    -->    CIKIS           \n");
  printf("*** *** ***\n");

   int x;

   scanf("%d", &x);

   switch (x) {
   case 0:
    return;
   case 1:
    printf("Eklenecek veri: ");
    scanf("%d", &x);

     push_stack(s, x);
    break;
   case 2:
    pop_stack(s);
    break;
   case 3:
    print_stack(s);
    break;
  }
 }
}