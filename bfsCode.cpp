#include<bits/stdc++.h>
using namespace std;

int q[20],rear,front;

void enq(int x)
{
    q[++rear] = x;
}

void deq()
{
    front++;
}

int main()
{
    int n,flg[20],i,j,a[20][20],cnode,visit[20],c = 0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        flg[i] = 0;
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    flg[0] = 1;
    q[0] = 0;
    front = 0;
    rear = 0;
    cnode = 0;
    visit[0] = 0;
    c++;
    while(c < n)
    {
        for(i=0;i<n;i++)
        {
            if(a[cnode][i] == 1 && flg[i] == 0)
            {
                enq(i);
                visit[c] = i;
        c++;
                flg[i] = 1;
            }
        }
        deq();
        cnode = q[front];
    }
    for(i=0;i<n;i++)
        cout<<visit[i]<<"\t";
}
