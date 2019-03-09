//差分约束   https://blog.csdn.next/wl16wzl/article/details/83652703
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 300+10;
const int M = 2000+10;
struct Edge
{
    int to,w,next;
}edge[M];

int tot,first[N];

void addedge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = first[u];
    first[u] = tot++;
}
void init()
{
    tot = 0;
    memset(first,-1,sizeof(first));
}
int dist[N];
bool vis[N];

void spfa(int n)
{
    queue<int> q;
    for(int i=0;i<=n;i++)
    {
        q.push(i);
        vis[i] = true;
        dist[i] = 0;
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = first[u];i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if(dist[v] < dist[u] + edge[i].w)
            {
                dist[v] = dist[u]+edge[i].w;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
        
    init();
    
    //就全部转化为s[x]-s[y]>=z的形式，然后按照差分约束建图 
    addedge(0,2,2*a[1]);
    addedge(2,0,-2*a[1]-1); 
    for(int i = 2;i < n; i++)
    {
        addedge(i-2,i+1,3*a[i]);
        addedge(i+1,i-2,-3*a[i]-2);
    }
    addedge(n-2,n,2*a[n]);
    addedge(n,n-2,-2*a[n]-1);
    
    //S(i) - S(i-1) = a[i] >= 1
    for(int i=1;i<=n;i++)
        addedge(i-1,i,1);
    
    spfa(n);
    
    for(int i=1;i<=n;i++)
        a[i]=dist[i]-dist[i-1];

    for(int i=1;i<n;i++)
        printf("%d ",a[i]);

    printf("%d\n",a[n]);
    return 0;
}

