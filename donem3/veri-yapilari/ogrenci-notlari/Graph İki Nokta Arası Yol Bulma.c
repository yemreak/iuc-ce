#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define true 1
#define false 0

void findPath(int from, int to);
void printPath(void);

int graph[N][N];
int path[N];
int visited[N];
int indeks = 0;

int  main()
{
    srand((unsigned int)time(NULL));
    int from, to;
    printf(" %dx%d lik graf uretildi\n\n",N,N);
    
    //random komsuluk matrÄ±sÄ± uretÄ±mÄ±
    for (int i = 0; i < N; i++){
        printf("\t");
        for (int j = 0; j < N; j++) {
            graph[i][j] = rand() % 2;
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Baslangic dugumu [0,%d]: ", N - 1);
    scanf("%d", &from);
    
    printf("BÄ±tÄ±s dugumu[0,%d]: ", N - 1);
    scanf("%d", &to);
    
    // baslangicta tum dugumler unvisited
    memset(visited, 0, sizeof(visited)); 
    
    printf("\n[%d-%d] arasi tum yollar:\n",from,to);
    findPath(from, to);
    return 0;
    
}
void findPath(int from, int to)
{
    visited[from] = true;
    path[indeks] = from;
    indeks++;
    
    if (from == to)
        printPath();
    else{
        int i;
        for (i = 0; i < N; i++){
            if (visited[i] == false && graph[from][i]==true)
                findPath(i, to);
            }
    }
    visited[from] = false;
    indeks--; 
}

void printPath()
{
    int i;
    for (i = 0; i < indeks; i++)
        printf("%d ", path[i]);
    printf("\n");
}