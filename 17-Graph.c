#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 13

int adj[SIZE][SIZE], q[SIZE], rear=0, front=0;
bool visited[SIZE];

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void enqueue(int element)
{
    if(rear == SIZE-1)
        printf("Queue overflow\n");
    else
    {
        if(front == 0)
            front=1;
        rear++;
        q[rear] = element;
    }
}

int isQEmpty()
{
    if(front==0 || front>rear)
        return 1;
    else
        return 0;
}

int dequeue()
{
    int deleted;
    if(front==0 || front>rear)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    else
    {
        deleted = q[front];
        front++;
        return deleted;
    }
}

void DFS(int src)
{
    visited[src] = true;
    printf("%d ", src);
    
    for(int i=0; i<SIZE; i++)
    {
        if(adj[src][i]==1 && !visited[i])
            DFS(i);
    }
}

void BFS(int src)
{
    visited[src] = true;
    enqueue(src);

    while(!isQEmpty())
    {
        src = dequeue();
        printf("%d ", src);

        for(int i=0;i<SIZE;i++)
        {
            if(adj[src][i]==1 && !visited[i])
            {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

void main()
{
    int src;

    addEdge(1,2);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(2,4);
    addEdge(2,6);
    addEdge(4,5);
    addEdge(4,7);
    addEdge(5,7);
    addEdge(6,3);
    addEdge(6,8);
    addEdge(6,9);
    addEdge(7,10);
    addEdge(7,11);
    addEdge(8,9);
    addEdge(9,10);
    addEdge(9,12);
    addEdge(10,12);

    for(int i=0; i<SIZE; i++)
        visited[i] = false;

    printf("Enter the starting vertex for Depth First Search\n");
    scanf("%d", &src);
    printf("\nDepth First Search:\n");
    DFS(src);
    printf("\n");

    for(int i=0; i<SIZE; i++)
        visited[i] = false;

    printf("\nEnter the starting vertex for Breadth First Search\n");
    scanf("%d", &src);
    printf("\nBreadth First Search:\n");
    BFS(src);
    printf("\n");
}