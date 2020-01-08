//
//  liste implementasyonu
//  Created by Nurefsan Sertbas on 11/10/2017.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;  //listenin basi
struct node *last = NULL;  //listenin sonu

void displayList();
void insertNode(int);
void deleteNode(int);
void searchNode(int);
int isEmpty();


int main ()
{   int selection;
    while (1)
    {   printf ("*** *** ***\n");
        printf ("      1    -->    insert         \n");
        printf ("      2    -->    remove         \n");
        printf ("      3    -->    display        \n");
        printf ("      4    -->    search        \n");
        printf ("      5    -->    EXIT           \n");
        printf ("*** *** ***\n");
        int x,flag;
        printf ("SeÃ§iminizi girin: ");
        scanf    ("%d", &selection);
        switch (selection){
            case 1:
                printf("Eklemek istediginiz sayiyi giriniz:");
                scanf("%d", &x);
                insertNode(x);
                break;
            case 2:
                flag=isEmpty();
                if(flag!=1){ //listede eleman varsa
                printf("Silmek istediginiz elemani giriniz:");
                scanf("%d", &x);
                deleteNode(x);}
                break;
            case 3:
                displayList();
                break;
            case 4:
                flag=isEmpty();
                if(flag!=1){ //listede eleman varsa
                    printf("Aramak istediginiz sayiyi giriniz:");
                    scanf("%d", &x);
                    searchNode(x);}
                break;
            case 5:
                return 0;
        }
}
    return 0;
}

//fonskiyonlar
void displayList() {
    struct node *ptr = head;
    
    if(isEmpty()==1)//listede eleman yok
        return;
    
    //else kismi
    printf("\n[ ");
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf(" ]\n");

}

void insertNode(int data) {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Bellekte yeterli alan yok !\n");
        return;
    }
    ptr->data = data;
    ptr->next=NULL;
    
    if(head==NULL) //ilk node
        head=last=ptr;
    else{
        last->next=ptr;
        last=ptr;
    }
}

void deleteNode(int x) {
    if(head==NULL)
    {printf("Listede hic eleman yok !\n");
        return;}
    else{
        struct node *p;
        struct node *previous=head;
        for(p=head;p!=NULL;p=p->next) //listeyi geziyoruz
        {   if(p->data==x) //eleman bulundu
            {
                
                //case1:ilk eleman silinmek isteniyor
                if(p==head)
                {   head=head->next;
                    free(p);
                    printf("%d basariyla listeden silindi\n",x);
                    return;
                }
                //case2:son eleman silinmek isteniyor
                if(p==last){
                    previous->next=p->next; //p->next=NULL zaten
                    last=previous;
                    free(p);
                    printf("%d basariyla listeden silindi\n",x);
                    return;
                }
                //case3:aradan eleman silinmek isteniyor
                previous->next=p->next;
                free(p);
                printf("%d basariyla listeden silindi\n",x);
                return;                
            }
            previous=p;
        }
        
        //for bitti ama hala return etmedi yani eleman bulunamadi
        printf("Aranan eleman listede bulunamadi\n");
        return;
    }
}

void searchNode(int x) {
    int counter=0;
    struct node* ptr = head;
    
    if(isEmpty()==1)//listede eleman yok
        return;
    
    counter=1;
    while(ptr->data != x) {
        if(ptr->next == NULL) { //son node a geldi hala bulamadi
           printf("Listede aranan eleman yok\n");
            return;}
        else {
            ptr = ptr->next;
            counter=counter+1;
        }
    }
    printf("Aranan eleman listede %d. sirada\n",counter);
}

int isEmpty(){
    if(head==NULL){
        printf("Listede hic eleman yok !\n");
        return 1;}
    else
        return 0;
}