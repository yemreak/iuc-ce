// yigittan kuyruga eleman tasima
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

//yigit yapisi
struct stack
{
 int arr[MAXSIZE];    //yigittaki elemanlar dizisi
 int top;             //yigita en son eklenmis elemanin indeksini tutuyor
};

//kuyruk yapisindaki dugum
struct qnode {
 int data;
 struct qnode *next;   //bir sonraki dugume isaretci
};


//kuyruk fonksiyon bildirimleri
void displayQueue();
void insertQueue(int);
int isEmpty();

//yigit fonksiyon bildirimleri
void push(struct stack *, int);
int pop(struct stack *);
void displayStack(struct stack *);

//kuyruk olusturma, ilk deger atama
struct qnode *front = NULL;  //kuyrugun basi
struct qnode *rear = NULL;   //kuyrugun sonu

int main()
{
    //yigit olusturma, ilk deger atama
    struct stack mystack;
    mystack.top = -1;   //baslangic degeri
    
 int selection,tmp;
 while (1)
 {
  printf("*** *** ***\n");
  printf("      1    -->    Yigita  Eleman  Ekle           \n");
  printf("      2    -->    Elemani Kuyruga Tasi           \n");
  printf("      3    -->    Yigiti  Goruntule              \n");
  printf("      4    -->    Kuyrugu Goruntule              \n");
  printf("      5    -->    EXIT           \n");
  printf("*** *** ***\n");

  printf("Seciminizi girin: ");
  scanf("%d", &selection);
  
  switch (selection) {
  case 1:
   tmp = 0;
   printf("Eklenecek eleman:");
   scanf("%d", &tmp);
   push(&mystack, tmp);
   break;
  case 2:
   tmp = pop(&mystack);
   if (tmp == -1)//stack bos
                //detay icin pop fonskyionunun hangi durumda -1 dondugune bakin
    printf("Yigitta eleman olmadigindan kuyruga eklenemiyor!\n");
   else
    insertQueue(tmp);
   break;
  case 3:
   displayStack(&mystack);
   break;
  case 4:
   displayQueue();
   break;
  case 5:
   return 0;
  }
 }
 return 0;
}

//FONKSIYONLAR
//kuyruk fonksiyonlari
void displayQueue() {
 struct qnode *ptr = front;

 if (isEmpty() == 1)//listede eleman yok
  return;

 //else kismi
    printf("\n *** QUEUE *** \n");
 printf("[ ");
 while (ptr != NULL) {
  printf("%d ", ptr->data);
  ptr = ptr->next;
 }
 printf(" ]\n");

}

void insertQueue(int data) {
 //bellekte yer tutma
    struct qnode *ptr = (struct qnode*) malloc(sizeof(struct qnode));
 if (ptr == NULL) {
  printf("Bellekte yeterli alan yok !\n");
  return;
 }
    //node olusturma
 ptr->data = data;
 ptr->next = NULL;

    //node u kuyruga ekleme
 if (front == NULL) //ilk qnode
  front = rear = ptr;
 else {
  rear->next = ptr;
  rear = ptr;
 }
}

int isEmpty() {
 if (front == NULL) {
  printf("Kuyrukta hic eleman yok !\n");
  return 1;
 }
 else
  return 0;
}

//////////////////////*** *** ***//////////////////////

//yigit fonksiyonlari
void push(struct stack *p, int x) {
 if (p->top == MAXSIZE - 1) {   //stack dolu mu kontrolu
  printf("Stack tamamen dolu, eleman eklenemiyor\n");
  return;
 }
 else {  //stackte yer var, eleman eklenebilir
  (p->top)++;  //indeksi guncelle
  p->arr[p->top] = x;    //elemani yazdi
 }
 return;
}
int pop(struct stack *p) {
 int tmp;
 if (p->top == -1) {
  printf("Stack bos\n");
  return -1;
 }
 else {  //stackte elemean var
  tmp = p->arr[p->top];     //stackte en âˆšÂºstteki eleman
  printf("'%d' stackten cikarildi\n", tmp);
  p->arr[p->top] = 0;
  (p->top)--;
 }
 return(tmp);
}

void displayStack(struct stack *p) //stack deki elemanlari ekrana basan fonksiyon
{
 int i;
 if (p->top == -1)
 {
  printf("Stackte goruntulenecek eleman yok !\n");
  return;
 }
 else
 {
  printf("\n *** STACK *** \n");
  for (i = p->top; i >= 0; i--)
   printf("%d\n", p->arr[i]);
 }
 printf("\n");
}