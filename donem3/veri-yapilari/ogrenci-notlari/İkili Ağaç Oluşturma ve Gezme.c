//ikili agac olusturma ve gezme
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

//agac olusturma
struct node * root=NULL;

struct node * createnode(int x)
{
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return(p);
}

void setleft(struct node * p, int x)
{
    if (p == NULL)
        printf(" void insertion \n");
    else if (p->left != NULL)   //solda node zaten var
        printf(" invalid insertion \n");
    else
        p->left = createnode(x);
}

void setright(struct node * p, int x)
{
    if (p == NULL)
        printf(" void insertion \n");
    else if (p->right != NULL)  //sagda node zaten var
        printf(" invalid insertion \n");
    else
        p->right = createnode(x);
}

void pretrav(struct node * ptr)
{
    if (ptr == NULL){
        return;
    }
        printf("%d\n", ptr->info);
        pretrav(ptr->left);
        pretrav(ptr->right);
 }

void intrav(struct node * ptr)
{
    if (ptr == NULL){
        return;
    }
        intrav(ptr->left);
        printf("%d\n", ptr->info);
        intrav(ptr->right);
}

void posttrav(struct node * ptr)
 {
    if (ptr == NULL){
        return;
    }
        posttrav(ptr->left);
        posttrav(ptr->right);
        printf("%d\n", ptr->info);
}


int main()
{
    struct node * p, *q;
    int selection,x;
    
    while (1)
    {   printf ("\n*** *** ***\n");
        printf ("      1    -->    eleman ekle           \n");
        printf ("      2    -->    display preorder      \n");
        printf ("      3    -->    display inoder        \n");
        printf ("      4    -->    display postorder     \n");
        printf ("      5    -->    EXIT                  \n");
        printf ("*** *** ***\n");
        
        printf ("SeÃ§iminizi girin: ");
        scanf    ("%d", &selection);
        switch (selection){
            case 1:
                printf("Eklemek istediginiz sayiyi giriniz:");
                scanf("%d", &x);
                
                if(root==NULL) //agacta eleman yok
                    {
                        printf("Agac olusturuldu, ilk eleman ekleniyor !\n");
                        root=createnode(x);
                    }
                else //agacta onceden eleman vardi
                {
                    p = q = root;
                    
                        while ((x != p->info) && q != NULL) {
                            p = q;
                            if (x < p->info)
                                q = p->left;
                            else
                                q = p->right;
                        }
                    
                        if (x == (p->info)) //daha once ayni eleman eklenmis
                            printf("duplicate \n");
                        else if (x<(p->info)) //sola ekleme
                            setleft(p, x);
                        else //saga ekleme
                            setright(p, x);
                }
                break;
            case 2:
                if (root == NULL){
                    printf("agacta goruntulenecek eleman yok");
                    break;
                }
                pretrav(root);
                break;
            case 3:
                if (root == NULL){
                    printf("agacta goruntulenecek eleman yok");
                    break;
                }
                intrav(root);
                break;
            case 4:
                if (root == NULL){
                    printf("agacta goruntulenecek eleman yok");
                    break;
                }
                posttrav(root);
                break;
            case 5:
                return 0;
        }
    }
    

    return 0;
}