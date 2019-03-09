#include<iostream>
#include<algorithm>
#define MAXE 100005
#define MAXV 1005
typedef long long ll;
using namespace std;

struct edge
{
	int u,v;
	ll cost;
};

edge es[MAXE];
int par[MAXV];
int V,E;

bool cmp(edge& e1,edge& e2)
{
	return e1.cost < e2.cost;
}

//并查集操作
void init_union_find(int n) 
{
	for(int i = 0;i <= n; i++)
	{
		par[i] = i;
	}
}

int find(int k)
{
	if(par[k] == k)    
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
	if(i == j)   return ;
	else par[i] = j;
} 

int kruskal()
{
	sort(es,es+E,cmp);
	init_union_find(V);
	ll res = 0;
	
	for(int i = 0;i < E; i++)
	{
		edge e = es[i];
		if(!same(e.u,e.v))
		{
			unite(e.u,e.v);
			res += e.cost;
		}
	}
	
	return res;
}

int main()
{
	cin >> V >> E;
	for(int i = 0;i < E; i++)
	{
		cin >> es[i].u >> es[i].v >> es[i].cost;
	}
	
	cout << kruskal() << endl;
}




