#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

typedef long long ll;

int n,m; 
ll G[2][MAXN][MAXN];      
bool inque[MAXN];
ll dis[2][MAXN];         

const ll inf = 1e18;
const int narrow = 1;
const int wide = 0;

void spfa(int start,int n)
{ 
	for(int i = 1;i <= n; i++)
	{
		dis[narrow][i] = dis[wide][i] = inf;
		inque[i] = false;
	}
	
	queue<int> q;
	q.push(start);
	
	dis[narrow][start] = 0;
	dis[wide][start] = 0;
	inque[start] = true;    // id为start的点入队列 
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		inque[u] = false;        //id为u的点出队列 
		
		for(int i = 1;i <= n; i++)
		{
			ll v = G[wide][u][i];
			if(dis[wide][i] > dis[wide][u] +  v)     //大路接着大路 
			{
				dis[wide][i] = dis[wide][u] + v;
				if(!inque[i])
				{
					q.push(i);
					inque[i] = true;
				}
			}
			if(dis[wide][i] > dis[narrow][u] + v)    //大路接小路 
			{
				dis[wide][i] = dis[narrow][u] + v;
				if(!inque[i])
				{
					q.push(i);
					inque[i] = true;
				}
			}
			if(G[narrow][u][i] != inf)              //能通过小路连接u,i,,,小路接小路 
			{
				v = G[narrow][u][i] * G[narrow][u][i];
				if(dis[narrow][i] > dis[wide][u] + v)
				{
					dis[narrow][i] = dis[wide][u] + v;
					if(!inque[i])
					{
						q.push(i);
						inque[i] = true;
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	
	//初始化 没有联通的边 
	for(int i = 0;i <= n; i++)	
		for(int j = 0;j <= n; j++)
			G[narrow][i][j] = G[wide][i][j] = inf;
	
	ll type,u,v,len;
	for(int i = 0;i < m; i++) 
	{
		cin >> type >> u >> v >> len;
		if(G[type][u][v] > len)                   //这里卡  10分 ！！！！！ 
			G[type][u][v] = G[type][v][u] = len;
	}
	
	//先用floyd算法计算i,j间小路距离
	for(int i = 1;i <= n; i++) 
	{
		for(int j = i+1;j <= n; j++)
		{
			for(int k = 1;k <= n; k++)
			{
				if(i == k || k == j)   continue;
				if(G[narrow][i][j] > G[narrow][i][k] + G[narrow][k][j])
					G[narrow][i][j] = G[narrow][j][i] = G[narrow][i][k] + G[narrow][k][j];
			}
		}
	}
	
	// spfa 求距离 
	spfa(1,n);
	
	cout << min(dis[narrow][n],dis[wide][n]) << endl;
	
	return 0;
}


