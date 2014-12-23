#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200002
bool vis[20][20];
//    freopen("D:/in.txt","r",stdin);
//    freopen("D:/out.txt","w",stdout);
char s[111111];
int par[20];
int init(int n)
{
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        vis[i][i]=1;
    }
}
int find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}
void unite(int u,int v)
{
    par[v]=u;
}
int main()
{
    freopen("D:/in.txt","w",stdout);
    srand((int)time(NULL));
    int t=20;
    int cas=1;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n=rand()%10+1;
        int tmp=((n-1)*n/2-n);
        if(!tmp) tmp++;
        int m=rand()%tmp+n;
        init(n);
        cout<<n<<" "<<m<<endl;
        int NUM=0;
        int i;
        for(i=0;i<m && NUM<500;i++)
        {
            int u=rand()%n+1;
            int v=rand()%n+1;
            int num=0;
            while((find(u)==find(v) || vis[u][v] )&& NUM<500)
            {
                if(num>20)
                {
                    u=rand()%n+1;
                    num++;
                }
                else
                {
                    v=rand()%n+1;
                }
                NUM++;
            }
            unite(u,v);
            vis[u][v]=1,vis[v][u]=1;
            printf("%d %d\n",u,v);
        }
        for(;i<m;i++)
        {
            bool flag=true;
            for(int j=1;j<=n&&flag;j++)
            {
                for(int k=1;k<=n&&flag;k++)
                {
                    if(!vis[j][k])
                    {
                        flag=false;
                        printf("%d %d\n",j,k);
                        vis[j][k]=1;vis[k][j]=1;
                    }
                }
            }
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
