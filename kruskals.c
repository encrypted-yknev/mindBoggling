#include <stdio.h>
#include <stdlib.h>

int parent[100];
int rank[100];

struct adjListNode  {
    int data;
    int value;
    struct adjListNode *next;
};

struct adjList  {
    struct adjListNode *head;
};

struct edge     {
    int src;
    int dest;
    int weight;
};

struct graph    {
    int v;
    struct adjList *array;
};
struct adjListNode *createNode(int dest,int weight)    {
    struct adjListNode *node=(struct adjListNode *)malloc(sizeof(struct adjListNode));
    node->data=dest;
    node->value=weight;
    node->next=NULL;
    return node;
}
struct graph * createGraph(int v)   {
    struct graph *g = (struct graph *)malloc(v * sizeof(struct graph));
    g->v=v;
    g->array = (struct adjList *)malloc(v * sizeof(struct adjList));
    int i;
    for(i=0; i<v; i++)
        g->array[i].head=NULL;
    
    return g;
}

struct edge addEdge(int s,int d,int w)  {
    struct edge e;
    e.src=s;
    e.dest=d;
    e.weight=w;
    
    return e;
}

void printGraph(struct graph *g,int v)    {
    int i;
    for(i=0; i<v;i++)   {
        struct adjListNode *ptr=g->array[i].head;
        printf("Adcacency list for vertex %d \n",i);
        while(ptr)  {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
/*
void dfsUtil(struct graph *g,int i,int visited[])   {
    printf("%d ",i);
    visited[i]=1;
    struct adjListNode *ptr = g->array[i].head;
    while(ptr)  {
        if(visited[ptr->data]==0)
            dfsUtil(g,ptr->data,visited);
        else
            ptr=ptr->next;
    }
}
void dfs(struct graph * g,int v)  {
    int visited[v];
    int i;
    for(i=0; i<v; i++)  
        visited[i]=0;
    int t=0;
    for(i=0; i<v; i++)  {
        if(visited[i]==0)   {
            dfsUtil(g,i,visited,&t);
        }
    }
}
*/
int findSet(int x,int y)    {
    if(x == y)
        return x;
    else    {
        int root = findSet(y,parent[y]);
        parent[x]=root;
        return root;
    }
}

void unionEdge(int p1,int p2)    {
    if(rank[p1] < rank[p2])
        parent[p1]=p2;
    else if(rank[p2] < rank[p1])
        parent[p2]=p1;
    else    {
        parent[p1]=p2;
        rank[p2]+=1;
    }
}

int partition(struct edge e[],int i,int j)    {
    int x=e[j].weight;
    int p = i-1,q=i;
    struct edge temp;
    while(q < j)    {
        if(e[q].weight <= x)    {
            p+=1;
            temp=e[p];
            e[p]=e[q];
            e[q]=temp;
        }
        q+=1;
    }
    temp=e[p+1];
    e[p+1]=e[j];
    e[j]=temp;
    return p+1;
}
void quicksort(struct edge e[],int start,int end) {
    if(start < end) {
        int index = partition(e,start,end);
        quicksort(e,start,index-1);
        quicksort(e,index+1,end);
    }
}
int Kruskals(struct edge edgeList[],int size)   {
    
    int i,len=0,totWt=0;
    struct edge finalEdge[size];
    for(i=0; i<size; i++)   {
        struct edge e = edgeList[i];
        int p1 = findSet(e.src,parent[e.src]);
        int p2 = findSet(e.dest,parent[e.dest]);
        if(p1 != p2)    {
            unionEdge(p1,p2);
            finalEdge[len++]=e;
        }
    }
    for(i=0; i<len; i++)    
        totWt+=finalEdge[i].weight;
    
    return totWt;
}
int main() {
    int i,v=9,edge=14,k=0;
	struct edge edgeList[edge];
	struct edge e;
	e = addEdge(0, 1, 4);
    edgeList[k++]=e;
    e = addEdge(0, 7, 8);
    edgeList[k++]=e;
    e = addEdge(1, 2, 8);
    edgeList[k++]=e;
    e = addEdge(1, 7, 11);
    edgeList[k++]=e;
    e = addEdge(2, 3, 7);
    edgeList[k++]=e;
    e = addEdge(2, 8, 2);
    edgeList[k++]=e;
    e = addEdge(2, 5, 4);
    edgeList[k++]=e;
    e = addEdge(7, 8, 7);
    edgeList[k++]=e;
    e = addEdge(7, 6, 1);
    edgeList[k++]=e;
    e = addEdge(8, 6, 6);
    edgeList[k++]=e;
    e = addEdge(6, 5, 2);
    edgeList[k++]=e;
    e = addEdge(3, 5, 14);
    edgeList[k++]=e;
    e = addEdge(3, 4, 9);
    edgeList[k++]=e;
    e = addEdge(4, 5, 10);
    edgeList[k++]=e;
    for(i=0; i<v; i++)  {
        parent[i]=i;
        rank[i]=0;
    }
    
    quicksort(edgeList,0,edge);
    //printGraph(graph,v);
    //dfs(graph,v);
    
    int minWeight = Kruskals(edgeList,edge);
    printf("%d",minWeight);
	return 0;
}

