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
	inque[start] = true;    // idΪstart�ĵ������ 
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		
		inque[u] = false;        //idΪu�ĵ������ 
		
		for(int i = 1;i <= n; i++)
		{
			ll v = G[wide][u][i];
			if(dis[wide][i] > dis[wide][u] +  v)     //��·���Ŵ�· 
			{
				dis[wide][i] = dis[wide][u] + v;
				if(!inque[i])
				{
					q.push(i);
					inque[i] = true;
				}
			}
			if(dis[wide][i] > dis[narrow][u] + v)    //��·��С· 
			{
				dis[wide][i] = dis[narrow][u] + v;
				if(!inque[i])
				{
					q.push(i);
					inque[i] = true;
				}
			}
			if(G[narrow][u][i] != inf)              //��ͨ��С·����u,i,,,С·��С· 
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
	
	//��ʼ�� û����ͨ�ı� 
	for(int i = 0;i <= n; i++)	
		for(int j = 0;j <= n; j++)
			G[narrow][i][j] = G[wide][i][j] = inf;
	
	ll type,u,v,len;
	for(int i = 0;i < m; i++) 
	{
		cin >> type >> u >> v >> len;
		if(G[type][u][v] > len)                   //���￨  10�� ���������� 
			G[type][u][v] = G[type][v][u] = len;
	}
	
	//����floyd�㷨����i,j��С·����
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
	
	// spfa ����� 
	spfa(1,n);
	
	cout << min(dis[narrow][n],dis[wide][n]) << endl;
	
	return 0;
}


