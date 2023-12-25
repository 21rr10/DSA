#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node{
     int data;
     struct node *next;
}*start=NULL;

void insert(int value){
     struct node * newnode;
     newnode=(struct node *)(malloc(sizeof(struct node)));
     newnode->data=value;
     newnode->next=NULL;
     if(start==NULL){
         start=newnode;
         return;
     }
     struct node * temp=start;
     while(temp->next!=NULL){
          temp=temp->next;
     }
     temp->next=newnode;
}

int dequeue(){
      if(start==NULL){
            return -1;
      }
      int x=start->data;
      struct node *temp=start;
     start=start->next;
     free(temp);
     return x;
}


int isEmpty(){
    return (start==NULL);
}



 
 
void bfs(int graph[MAX_NODES][MAX_NODES],int visited[MAX_NODES],int nodes){
       int i,current;

       visited[0]=1;
       insert(0);      
          
    while(!isEmpty()){
      current=dequeue();
      printf("%d ",current);

      for (i = 0; i < nodes; i++)
      {
          if(graph[current][i]==1 && !visited[i]){
               visited[i]=1;
               insert(i);
          }
      }
    }
}









int main(){
      int nodes,edges,i, j;
    int graph[MAX_NODES][MAX_NODES];
    int visited[MAX_NODES] = {0};
    
    // Input the number of nodes and edges
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &nodes, &edges);

    // Initialize the adjacency matrix
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges of the graph
    printf("Enter the edges (format: node1 node2):\n");
    for (i = 0; i < edges; i++) {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;  // Assuming an undirected graph
    }

//     // Input the starting node for BFS
//     printf("Enter the starting node for BFS: ");
//     scanf("%d", &start);

    printf("Breadth-First Traversal starting from node %d: ", start);
    bfs(graph, visited, nodes);




return 0;
} 

void dfs(int graph[MAX_NODES][MAX_NODES],int visited[MAX_NODES],int startNode,int nodes){
     visited[startNode]=1;
     printf("%d ",startNode);
     for (int i = 0; i <nodes ; i++)
     {
           if (!visited[i] && graph[startNode][i] == 1) {
            dfs(graph, visited, i, nodes);
        }
     }
     
}