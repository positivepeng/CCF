#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#define INF 99999999
using namespace std;
typedef long long ll;

struct node
{
	int to;
	int len;
	node(int t,int L)
	{
		to = t;
		len = L;
	}
	node(){}
	
};

vector<vector<node> > G(10005);
int price[10005];
node par[10005];
int d[10005];
bool used[10005];
int n,m;

void dijkstra(int s)
{
	fill(d,d+n+1,INF);
	fill(used,used+n+1,false);
	d[s] = 0;
	
	while(true)
	{
		int v = -1;
		for(int u = 1;u <= n; u++)
		{
			if(!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}
		
		if(v == -1)   break;
		//cout << "v " << v << endl;
		used[v] = true;
		
		for(int i = 0;i < G[v].size(); i++)
		{
			int u = G[v][i].to;
			if(d[v] + G[v][i].len < d[u])
			{
				d[u] = d[v] + G[v][i].len;
				par[u].to = v;
				par[u].len = G[v][i].len;
				//cout << "par " << u << " " << v << endl;
			}
		}
	}
}

ll cost(int u,int v)
{
	dijkstra(u); 
	
	stack<int> sk;
	stack<int> lens;
	ll ans = 0;
	
	while(par[v].to != u) 
	{
		//cout << "v : " << v << endl;
		sk.push(v);
		v = par[v].to;
		lens.push(par[v].len);
	}
	sk.push(v);
	lens.push(par[v].len);
	
	int curr_min = INF;
	
	while(!sk.empty())
	{
		//cout << sk.top() << " " ;
		ans += min(curr_min,price[sk.top()]) * lens.top();
		if(sk.top() < curr_min)
			curr_min = sk.top();
		sk.pop();
		lens.pop();
	}
	//cout << endl;
	return ans;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int u,v,e;
	
	for(int i = 1;i <= n; i++)
		cin >> price[i];
	
	for(int i = 0;i < n-1; i++)
	{
		cin >> u >> v >> e;
		G[u].push_back(node(v,e));
		G[v].push_back(node(u,e));
	}
	
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v;
		cout << cost(u,v) << endl;
	}
	
	return 0;
}

