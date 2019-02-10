#include<iostream>
#include<vector>
#include<cstring>
#define MAXN 10005
#define INF 9999999
using namespace std;

typedef long long ll;
struct edge
{
	int to,len,change;
	edge(int t,int L,int c)
	{
		to = t;
		len = L;
		change = c;
	}
	edge()
	{
		to = len = -1;
		change = 0;
	}
};

vector<edge> G[MAXN];
int d[MAXN];
bool used[MAXN];
int addLen[MAXN];
int V,E;

ll dijkstra(int s)
{
	fill(d,d+V+1,INF);
	fill(addLen,addLen+V+1,INF);
	fill(used,used+V+1,false);
	d[s] = 0;
	ll ans = 0;
	
	while(true)
	{
		int v = -1;
		
		for(int u = 1;u <= V; u++)
		{
			if(!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}
		
		if(v == -1)
			break;
		
		used[v] = true;
		 
		//cout << "v " << v << endl;
		
		for(int i = 0;i < G[v].size(); i++)          //用当前最短的v去更新其他的 
		{
			int id = G[v][i].to;
			int Len = G[v][i].len;
			
			if(d[id] >= d[v] + Len)
			{
				d[id] = d[v] + Len;
				//G[v][i].change = 1;
				addLen[id] = min(Len,addLen[id]);
			}
		}
	}
	
	for(int i = 1;i <= V; i++)
	{
		//cout << addLen[i] << " ";
		if(addLen[i] != INF)
			ans += addLen[i];
	}
	//cout << endl;
	

//	for(int i = 1;i <= V; i++)
//	{
//		for(int j = 0;j < G[i].size(); j++)
//		{
//			if(G[i][j].change == 1)
//				ans += G[i][j].len;
//		}
//	}
	return ans;
}



int main()
{

	int u,v,len;
	cin >> V >> E;
	for(int i = 0;i < E; i++)
	{
		cin >> u >> v >> len;
		G[u].push_back(edge(v,len,0));
		G[v].push_back(edge(u,len,0));
	}
	
	cout << dijkstra(1) << endl;
	
}
