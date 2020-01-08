#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

// Kuyruk yapısı
typedef struct queue {
 int front, rear;
 int items[QUEUE_SIZE];
}Queue;

// Stack oluşturma
Queue create_queue();

// Doluluk kontrolü
int empty(Queue *);

// Kuyruk degerleri arttırma
int goreceli_arttir(int );

// Kuyruğa eleman ekleme
void insert_queue(Queue *, int );

// Kuyruktan eleman çıkarma
int remove_queue(Queue *);

// Kuyruğu yazdırma
void print_queue(Queue *);

// Kuyruk islem menüsü
void menu_queue(Queue *);

int main(){
 Queue myqueue = create_queue();

  menu_queue(&myqueue);
}

// Stack oluşturma
Queue create_queue() {
 Queue q;

  q.front = q.rear = -1;

  printf("-> Kuyruk olusturuldu. \n\n");
 return q;
}

// Doluluk kontrolü
int empty(Queue *q) {
 if (q->front == q->rear)
  return 1;
 return 0;
}

// Kuyruk degerleri arttırma
int goreceli_arttir(int x) {
 return (x + 1) % QUEUE_SIZE;
}

// Kuyruğa eleman ekleme
void insert_queue(Queue *q, int x) {
 if (q == NULL) {
  printf("Kuyruk mevcut degil.\n");
  
  return;
 }
 q->rear = goreceli_arttir(q->rear);

  if (empty(q)) {
  printf("Kuyruk dolu.\n");
  
  return;
 }
 q->items[q->rear] = x;

  printf("-> %d kuyruga eklendi.\n", x);
}

// Kuyruktan eleman çıkarma
int remove_queue(Queue *q) {
 // Yokluk degeri
 int x = 0;

  if (q == NULL) 
  printf("Kuyruk mevcut degil.\n");
 else if (empty(q)) 
  printf("Kuyrukta veri yok.\n");
 else {
  q->front = goreceli_arttir(q->front);

   int x = q->items[q->front];

   printf("-> %d kuyruktan cikarildi.\n", x);
 }
 return x;
}

// Kuyruğu yazdırma
void print_queue(Queue *q) {
 if (q == NULL) {
  printf("Kuyruk mevcut degil.\n");
  return;
 }
 printf("\nKuyruk verileri: \n");

  if (empty(q) || q->rear == -1) {
  printf("---Kuyruk bos---\n");
 }

  for (int temp = q->front; temp != q->rear; temp) {
  temp = goreceli_arttir(temp);
  printf("%d-", q->items[temp]);
 }
}

// Kuyruk islem menüsü
void menu_queue(Queue *s) {
 while (1) {
  printf("\n*** *** ***\n");
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

     insert_queue(s, x);
    break;
   case 2:
    remove_queue(s);
    break;
   case 3:
    print_queue(s);
    break;
  }
 }

}