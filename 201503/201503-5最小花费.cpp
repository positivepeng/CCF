#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#define INF 999999999999999
#define MAX_V 205
using namespace std;

typedef long long ll;
typedef struct node
{
	ll id,min_price,cost;
	node(ll i,ll m,ll c):id(i),min_price(m),cost(c){} 
	node(){}
}node;

ll price[MAX_V],len[MAX_V][MAX_V];
int mark[MAX_V];
ll n,m,start,end;

ll bfs()
{
	ll ans = INF;
	queue<node> q;
	q.push(node(start,price[start],0));
	mark[start] = 1;
	
	while(!q.empty())
	{
		node u = q.front();
		q.pop();
		
		ll id = u.id;
		ll min_p = u.min_price;
		ll curr_cost = u.cost;
		
		for(int i = 1;i <= n; i++)
		{
			if(i == end && len[id][end] != -1)
				ans = min(curr_cost+min_p*len[id][end],ans);
			
			if(mark[i] == 0 && len[id][i] != -1)
			{
				mark[i] = 1;
				q.push(node(i,min(price[i],min_p),curr_cost+min_p*len[id][i]));
			}
		}
	}
	
	return ans;
}

ll cost()
{
	memset(mark,0,sizeof(mark));
	return bfs();
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	ll u,v,e;
	
	for(int i = 1;i <= n; i++)
		cin >> price[i];
	
	memset(len,-1,sizeof(len));
	
	for(int i = 0;i < n-1; i++)
	{
		cin >> u >> v >> e;
		len[u][v] = len[v][u] = e;
	}
	
	for(int i = 0;i < m; i++)
	{
		cin >> start >> end;
		cout << cost() << endl;
	}
	
	return 0;
}

