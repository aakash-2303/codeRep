#include<bits/stdc++.h>
using namespace std;

int tos = 0,stk[20];

void push(int x)
{
    stk[++tos] = x;
}

void pop()
{
    tos--;
}

int main()
{
    int n,i,j,visit[20],k,cnode,exist = 0,c = 0,flg[20],a[20][20];
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
    stk[0] = 0;
    cnode = 0;
    visit[0] = 0;
    k = 1;
    c++;

    while(c < n)
    {
        for(i=0;i<n;i++)
        {
            if(a[cnode][i] == 1 && flg[i] == 0)
            {
                flg[i] = 1;
                cnode = i;
                push(cnode);
                visit[k] = i;
                k++;
                c++;
                exist = 1;
                break;
            }
        }
        if(exist == 0)
        {
            pop();
        cnode = tos;
        }
        else
            exist = 0;
    }

    for(i=0;i<n;i++)
        cout<<visit[i]<<"\t";
}
