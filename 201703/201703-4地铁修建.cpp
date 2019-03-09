#include<iostream>
#include<vector> 
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef struct edge
{
	int u,v,len;
	edge(int u,int v,int len)
	{
		u = u;v = v;len = len;
	}
	edge(){}
}edge;

int n,m;
int  par[100004];
vector<edge> edges;
	
void init()
{
	for(int i = 1;i <= n; i++)
		par[i] = i;
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

bool cmp(edge e1,edge e2)
{
	return e1.len < e2.len;
}


void solve()
{
	//扩边法求最小生成树 
	sort(edges.begin(),edges.end(),cmp);
	
	init();
	for(int i = 0;i < m; i++)
	{
		edge e = edges[i];
		//cout << e.u << " " << e.v << endl;
		unite(e.u,e.v);
		if(same(1,n))
		{
			cout << e.len << endl;  
			return ;
		}
	}
}

int main()
{
	cin >> n >> m;
	int u,v,len;
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v >> len; 
		edge tmp;
		tmp.u = u;
		tmp.v = v;
		tmp.len = len;
		edges.push_back(tmp);
	}
	
	solve();
}
/*
#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Edge
{
public:
	int a,b;
	int time;
};

bool cmd(Edge e1,Edge e2){
	return e1.time<e2.time;
}

int n,m;
vector<Edge> eds;
int p[100010];

int find(int x)
{
	if(p[x] == x)
		return x;
	else
	{
		int y=find(p[x]);
		p[x] = y; 
		return y;
	}
}
void union_p(int x,int y) 
{
	if(x==y)
	{
		return;
	}
	p[x] = y;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		Edge e;
		scanf("%d%d%d",&e.a,&e.b,&e.time);
		eds.push_back(e);
	}
	sort(eds.begin(),eds.end(),cmd);
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	for(int i=0;i<m;i++){
		Edge e=eds[i];
		union_p(find(e.a),find(e.b));
		if(find(1)==find(n)){
			cout<<e.time<<endl;
			break;
		}
	}
	
	return 0;
}
*/ 
