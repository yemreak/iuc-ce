#include<stdio.h>
#include<stdlib.h>

#define infinity 9999
#define MAX 5

int G[MAX][MAX], n;
int prims();

int main()
{
 n = MAX;
 int i, j, total_cost;
 printf("\nThe adjacency matrix:\n");

 //random matris uretme
 for (int i = 0; i < n; i++) {
  printf("\t");
  for (int j = 0; j < n; j++) {
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
 total_cost = prims();
 printf("\nTotal cost of spanning tree=%d\n", total_cost);
 return 0;
}

int prims()
{
 int cost[MAX][MAX];
    int u, v, min_distance, distance[MAX];
 int visited[MAX], no_of_edges, i, min_cost, j,from[MAX];;

 //create cost[][] matrix
 for (i = 0; i<MAX; i++)
  for (j = 0; j<MAX; j++)
  {
   if (G[i][j] == 0)
    cost[i][j] = infinity;
   else
    cost[i][j] = G[i][j];
  }

 //initialise visited[],distance[], from[]
 distance[0] = 0;
 visited[0] = 1;

 for (i = 1; i<MAX; i++)
 {
  distance[i] = cost[0][i];
  visited[i] = 0;
        from[i] = 0;
 }
 min_cost = 0;        //cost of spanning tree
 no_of_edges = MAX - 1;        //no. of edges to be added
    printf("\nEdges in spanning tree:\n\n");
 while (no_of_edges>0)
 {
  //find the vertex at minimum distance from the tree
  min_distance = infinity;
  for (i = 1; i<MAX; i++)
   if (visited[i] == 0 && distance[i]<min_distance)
   {
    v = i;
    min_distance = distance[i];
   }
        u = from[v];
  //insert the edge in spanning tree
        printf("%d to %d, distance: %d\n", u,v, distance[v]);
  no_of_edges--;
  visited[v] = 1;

        //updated the distance[], from[] array
  for (i = 1; i<MAX; i++)
   if (visited[i] == 0 && cost[i][v]<distance[i])
   {
    distance[i] = cost[i][v];
                from[i] = v;
   }
  min_cost = min_cost + cost[u][v];
 }

 return(min_cost);
}