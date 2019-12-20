#include <iostream>
#include <time.h>

#define MAX_M 10
#define MAX_N 100

int M[MAX_M][MAX_M];
int M_MARK[MAX_M][MAX_M];
int front = 0;
int tail = 0;

struct Node{
    int x;
    int y;
};

int direct[4][2] = {0,-1, 0, 1, -1, 0, 1, 0};

Node Queue[MAX_N];

void push(Node n)
{
    std::cout <<"tail" << tail<<std::endl;
    Queue[tail++] = n;
}

Node pop()
{
    return Queue[front++];
}

bool isEmpty()
{
    if(front == tail)
        return true;
    return false;
}

int bfs(Node n)
{
    int count = 1;
    push(n);
    M_MARK[n.x][n.y] = true;
    while(!isEmpty())
    {
        n = pop();
        int x = n.x;
        int y = n.y;
        for(int i = 0; i<4; ++i)
        {
            n.x = x + direct[i][0];
            n.y = y + direct[i][1];
            if(n.x >= 0 && n.x<MAX_M && n.y >= 0 && n.y < MAX_M)
                if(M[n.x][n.y] == 1 && M_MARK[n.x][n.y] == false)
                {
                    count++;
                    push(n);
                    M_MARK[n.x][n.y] = true;
                }
        }
    }
    return count;
}

int main()
{
    srand(time(0));
    for(int i = 0; i<MAX_M; ++i)
    for(int j = 0; j<MAX_M; ++j)
    {
        M_MARK[i][j] = false;
        M[i][j] = rand()%2;
    }
    for(int i = 0; i<MAX_M; ++i)
    {
        for(int j = 0; j<MAX_M; ++j)
            std::cout <<M[i][j]<< " ";
        std::cout <<std::endl;
    }

    Node n;
    for(int i=0; i<MAX_M; ++i)
    for(int j=0; j<MAX_M; ++j)
    {
        if(M_MARK[i][j] || M[i][j] == 0)
            continue;
        n.x =i;
        n.y =j;

        std::cout << bfs(n) << std::endl;
    }
    
    return 0;
}