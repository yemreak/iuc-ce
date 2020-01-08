#include <stdio.h>
#include <stdlib.h>

// Bağlı liste yapısı
typedef struct linkedlist {
 int value;
 struct linkedlist *next;
}Llnode;

// Bağlı listeyi oluşturma
Llnode *create_ll(int);

// Bağlı liste sonuna eleman ekleme
void push_ll(Llnode *, int);

// Bağlı listeye eleman ekleme
void insert_ll(Llnode *, int);

// Bağlı listede aranan elemanı silme
Llnode *delete_ll(Llnode *, int);

// Bağlı listeyi gösterme
void print_ll(Llnode *);

// Bagli listeyi ters çevirme 
Llnode *reverse_ll(Llnode *);

// Bağlı liste arayüzü
void menu_ll(Llnode *);

int main(){
 // Linked list
 Llnode *ll = create_ll(5);
 menu_ll(ll);
}

// Bağlı listeyi oluşturma
Llnode *create_ll(int x) {
 Llnode *ll = (Llnode *)malloc(sizeof(Llnode));
 ll->next = NULL;
 ll->value = x;

  printf("-> Bagli liste olusturuldu. \n");
 return ll;
}

// Bağlı liste sonuna eleman ekleme
void push_ll(Llnode *ll, int x) {
 if (ll == NULL) {
  printf("Bagli liste mevcut degil.\n");
  return;
 }
 for (ll; ll->next != NULL; ll = ll->next);

  Llnode *newll = (Llnode*) malloc(sizeof(Llnode));

  newll->next = ll->next; // Yani NULL
 newll->value = x;
 ll->next = newll;

  printf("-> Listeye %d eklendi\n", x);
}

// Bağlı listeye eleman ekleme
void insert_ll(Llnode *ll, int x) {
 if (ll == NULL) {
  printf("Bagli liste mevcut degil.\n");
  return;
 }
 Llnode *newll = (Llnode*) malloc(sizeof(Llnode));
 
 newll->next = ll->next;
 newll->value = x;
 ll->next = newll;

  printf("-> Listeye %d eklendi\n", x);
}

// Bağlı listede aranan elemanı silme
Llnode *delete_ll(Llnode *ll, int x) {
 if (ll == NULL) {
  printf("Bagli liste mevcut degil\n");
  return ll;
 }
 Llnode *s = ll->next;

  int i = 1;

  if (ll->value == x) {
  printf("-> [%d] elemani, bagli listede %d. sirada. Eleman silindi\n", x, i);

   free(ll);

   return s;
 }
 i++;

  if (s == NULL) {
  printf("-> Aranan eleman bulunamadi. \n");
  return ll;
 }
 Llnode *head = ll;

  while (s->value != x) { 
   i++;
   ll = ll->next;
   s = s->next;

    if (s == NULL) {
    printf("-> Aranan eleman bulunamadi. \n");
    return head;
   }
  
 }
 printf("-> [%d] elemani, bagli listede %d. sirada. Eleman silindi\n", x, i);

  ll->next = s->next;
 free(s);

  return head;
}

// Bağlı listeyi gösterme
void print_ll(Llnode *ll) {
 if (ll == NULL) {
  printf("--- Bagli liste bos ---\n");
  return;
 }
 printf("Bagli lise elemanları: \n");

  while (ll != NULL) {
  printf("[%d]-", ll->value);

   ll = ll->next;
 }
}

// Bagli listeyi ters çevirme 
Llnode *reverse_ll(Llnode *ll) {
 if (ll == NULL)
  return ll;

  Llnode *s = ll->next;
 Llnode *p = s->next;

  ll->next = NULL;

  while (s != NULL) {
  s->next = ll;
  ll = s;
  s = p;

   if(p != NULL)
   p = p->next;
 }
 return ll;
}

// Bağlı liste arayüzü
void menu_ll(Llnode *ll) {
 while (1) {
  printf("\n*** *** ***\n");
  printf("      1    -->    SONA EKLE       \n");
  printf("      2    -->    YANINA EKLE (2.SIRA)  \n");
  printf("      3    -->    CIKAR           \n");
  printf("      4    -->    GOSTER          \n");
  printf("      5    -->    TERSINI AL      \n");
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

     push_ll(ll, x);
    break;
   case 2:
    printf("Eklenecek veri: ");
    scanf("%d", &x);

     insert_ll(ll, x);
    break;
   case 3:
    printf("Silinmesini istediginiz degeri giriniz:\t");
    scanf("%d", &x);

     ll = delete_ll(ll, x);
    break;
   case 4:
    print_ll(ll);
    break;
   case 5:
    ll = reverse_ll(ll);
    break;
  }
 }

}