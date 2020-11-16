#include <stdio.h>
#include <stdlib.h>

int a[13][13];
int c[13];
int q[13];
int rear=0;
int front=0;
int state[13];
int MAX=13;

void b(int h,int u)
{
    a[h][u]=1;
    a[u][h]=1;
}

void in_qu(int v)
{
    if(rear==MAX-1)
        printf("Queue overflow\n");
    else
    {
        if(front==0)
            front=1;
        rear+=1;
        q[rear]=v;
    }
}

int isEmpty()
{
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}

int del()
{
    int deleted;
    if(front==0||front>rear)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    else
    {
        deleted=q[front];
        front++;
        return deleted;
    }
}

void dfs(int k)
{
    printf("%i ",k);
    c[k]=1;
    for(int y=0;y<13;y++)
    {
        if(y==k)
            continue;
        if(a[k][y]==1)
        {
            if(c[y]==1)
                continue;
            dfs(y);
        }
    }
}

void bfs(int ve)
{
    int i;
    in_qu(ve);
    state[ve]=2;
    while(!isEmpty())
    {
        ve=del();
        state[ve]=3;
        printf("%i ",ve);
        for(i=0;i<13;i++)
        {
            if(a[ve][i]==1&&state[i]==1)
            {
                in_qu(i);
                state[i]=2;
            }
        }
    }
}

void main()
{
    q[0]=0;
    int br,de;

    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            a[i][j]=0;
        }
    }

    b(1,2);
    b(1,4);
    b(2,3);
    b(2,4);
    b(2,6);
    b(4,5);
    b(4,7);
    b(5,7);
    b(6,3);
    b(6,8);
    b(6,9);
    b(7,10);
    b(7,11);
    b(8,9);
    b(9,10);
    b(9,12);
    b(10,12);

    for(int i=0;i<13;i++)
        c[i]=0;

    printf("Enter the starting vertex for Depth First Search\n");
    scanf("%i",&de);
    printf("\nDepth First Search:\n");
    dfs(de);
    printf("\n");

    for(int kk=0;kk<13;kk++)
      state[kk]=1;

    printf("\nEnter the starting vertex for Breadth First Search\n");
    scanf("%i",&br);
    printf("\nBreadth First Search:\n");
    bfs(br);
    printf("\n");
}
/*#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1, c[13];;

void bfs(int v)
{
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r)
{
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}
void dfs(int k)
{
    printf("%i ",k);
    c[k]=1;
    for(int y=0;y<13;y++)
    {
        if(y==k)
            continue;
        if(a[k][y]==1)
        {
            if(c[y]==1)
                continue;
            dfs(y);
        }
    }
}
void b(int h,int u)
{
    a[h][u]=1;
    a[u][h]=1;
}
void main() {
 int v,de;
 n=12;
 for(i=1; i <= n; i++) {
 q[i] = 0;
 visited[i] = 0;
 }

 for(int i=0;i<13;i++)
    {
    for(int j=0;j<13;j++)
    {
        a[i][j]=0;
    }
    }
    b(1,2);b(1,4);b(4,5);
    b(6,3);b(2,4);b(2,3);b(2,6);
    b(5,7);b(6,8);b(6,9);b(4,7);
    b(9,10);b(7,11);b(7,10);
    b(8,9);b(9,12);b(10,12);
 for(int i=0;i<13;i++)
    c[i]=0;
 printf("Enter the starting vertex for DFS\n");
 scanf("%i",&de);
 printf("\nDFS:\n");
 dfs(de);

 printf("\n");
 printf("\nEnter the starting vertex for BFS\n");
 scanf("%d", &v);
 printf("\nBFS:\n");
 bfs(v);
 for(i=0; i <= n; i++) {
 if(visited[i])
 printf("%d\t", q[i]);
 }
}*/
