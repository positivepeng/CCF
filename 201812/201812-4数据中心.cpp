#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include <iterator>
#include <set>
#include <map>
using namespace std;
typedef struct edge
{
	int u,v,len;
}edge;

int par[100005];

void init(int n)
{
	for(int i = 0;i <= n; i++)
		par[i] = i;
}

int find(int k)
{
	if(k == par[k])
		return k;
	else
		return par[k] = find(par[k]);
}

bool same(int i,int j)
{
	return find(i) == find(j);
} 

void unite(int i,int j)
{
	i = find(i);
	j = find(j);
	if(i == j)
		return ;
	else	
		par[i] = j;
}

bool cmp(edge& a,edge& b)
{
	return a.len < b.len;
}

int solve(int n,vector<edge>& G)
{
	int ans = 0,cnt = 0;
	init(n);
	int mark[n];
	memset(mark,0,sizeof(mark));
	
	sort(G.begin(),G.end(),cmp);
	
	for(int i = 0;i < G.size(); i++)
	{
		if(!same(G[i].u,G[i].v))
		{
			unite(G[i].v,G[i].u);
			ans = G[i].len;
			if(mark[G[i].u] == 0)
			{
				cnt++;
				mark[G[i].u] = 1;
			}
			if(mark[G[i].v] == 0)
			{
				cnt++;
				mark[G[i].v] = 1;
			}
			if(cnt == n)
				return ans;
		}
	}
	
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m,root; 
	cin >> n >> m;
	vector<edge> G(m);
	cin >> root;
	
	for(int i = 0;i < m; i++)
		cin >> G[i].u >> G[i].v >> G[i].len;
	
	cout << solve(n,G) << endl;
	
	return 0;
}


