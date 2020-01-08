#include<stdlib.h>
#include <stdio.h>
#define infinity 9999
#define MAX 5

int G[MAX][MAX];

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[MAX];
}edgelist;

edgelist alledges;
edgelist spanningTree;
int edgecounter=0;//graftaki edge sayisi,baslangicta 0
int ctr=0; //spanning tree deki edge sayisi, baslangicta 0

//fonksiyon bildirimleri
void kruskal(void);
void combine(int belongs[],int c1,int c2);
void sortEdges(void);
int print(void);

int main()
{
    //random matris uretme
    int total_cost,i,j;
    printf("\nThe adjacency matrix:\n");
    for (i = 0; i < MAX; i++) {
        printf("\t");
        for (j = 0; j < MAX; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else if (i > j)
                G[i][j] = G[j][i];
            else {
                G[i][j] = rand() % 10;
            }
            printf("%d\t ", G[i][j]);
        }
        printf("\n");
    }
    
    kruskal();
    printf("\nEdges in spanning tree:\n");
    total_cost=print();
    printf("\nTotal cost of spanning tree=%d\n", total_cost);
    return 0;
}


void kruskal(void)
{
    int belongs[MAX],i,j,cno1,cno2;


    
    //sirasiyle grafi gezip edgeleri listeye ekliyoruz
    for(i=1;i<MAX;i++){
        for(j=0;j<=i;j++)
        {  if(G[i][j]!=0)
            {   //alledges listesinin n. elemani olarak ekliyor
                alledges.data[edgecounter].u=i;
                alledges.data[edgecounter].v=j;
                alledges.data[edgecounter].w=G[i][j];
                edgecounter=edgecounter+1;
                //listedeki edge sayisini 1 arrtirarak guncelledi
            }
        }
    }
    
    printf("\nAll Edges\n");
    for(i=0;i<edgecounter;i++)
    {
        printf("%d-%d, cost:%d\n",alledges.data[i].u,alledges.data[i].v,alledges.data[i].w);
    }
    //bu noktada alledges graftaki tum edgeleri tutuyor
    sortEdges();
    //listedeki edgeler kucukten buyuge dogru(weight degerlerine gore) siralandi
    
    //nodelari ekledik, simdi edgeleri ekleyecegz
    for(i=0;i<MAX;i++)
        belongs[i]=i;
    
    
    printf("\nSorted Edges\n");
    for(i=0;i<edgecounter;i++)
    {
        printf("%d-%d, cost:%d\n",alledges.data[i].u,alledges.data[i].v,alledges.data[i].w);
    }
    
    //spanning tree yi olusturmaya basliyoruz, baslangicta hic edge yok ctr=0 di
    
    for(i=0;i<edgecounter;i++)
    {    //alledges.data[i] ile kucukten buyuge sirali haldeki edgelerden birini aldi
        cno1=belongs[alledges.data[i].u];  //source
        cno2=belongs[alledges.data[i].v];  //destination
        
        if(cno1!=cno2) //cycle olusup olusmadigi kontrolu
        {   //baslangici ile bitisi ayni degilse cycle olusmaz (cno1!=cno2)
            spanningTree.data[ctr]=alledges.data[i]; //ilgili edge i spanning tree ye ekledi
            ctr=ctr+1; //spanning treedeki edge sayisini tutan sayaci guncelledi
            combine(belongs,cno1,cno2); //dugumle edge i birbirine bagladi
        }
    }
}


void combine(int belongs[],int c1,int c2)
{
    for(int i=0;i<MAX;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}

void sortEdges(void)
{   //graftaki tum edge(linkleri) weight degerlerine gore
    // kucukten buyuge siralama
    int i,j;
    edge temp;
    
    for(i=1;i<edgecounter;i++)
        for(j=0;j<edgecounter-1;j++)
            if(alledges.data[j].w > alledges.data[j+1].w)
            {   //Swap islemi
                temp=alledges.data[j];
                alledges.data[j]=alledges.data[j+1];
                alledges.data[j+1]=temp;
            }
}

int print(void)
{
    int i,cost=0;
    for(i=0;i<ctr;i++)
    {   printf("%d-%d, cost:%d\n",spanningTree.data[i].u,spanningTree.data[i].v,spanningTree.data[i].w);
        //spanning treedeki edgelerin source-destination ve weightlerini ekrana basma
        cost=cost+spanningTree.data[i].w; //ilgili linkin weight'ini cost olarak toplama ekle
    }
    return cost;
}