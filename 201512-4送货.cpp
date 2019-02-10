#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
using namespace std;

int n,m;
int degree[10003];
bool path[10003][10003];
int par[10003];

stack<int> points;
vector<set<int> > G(10003);

void init()
{
	for(int i = 1;i <= n; i++)
		par[i] = i;
}

int find(int k)
{
	if(par[k] == k)
		return k;
	return par[k] = find(par[k]);
}

bool link()
{	
	int cnt = 0; 
	for(int i = 1;i <= n; i++)
	{
		//cout << "par[i] " << i << " " << par[i] << " " ;
		if(find(i) == i)
			cnt++;
	}
	//cout << " cnt " << cnt << endl;
	return cnt == 1;
}





bool has_euler()
{
	int cnt = 0;
	for(int i = 1;i <= n; i++)
	{
		if(degree[i] % 2 == 1)
			cnt++;
	}
	
	return cnt == 0 || cnt == 2;
}






int last_id;

void dfs(int u)
{
	for(set<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		int v = *it;
		if(!path[u][v])
		{
			path[u][v] = path[v][u] = true;
			//cout << u << " " ;
			//last_id = v;
			dfs(v);
			points.push(v);
		}
	}
	
}


void print_path()
{
	memset(path,0,sizeof(path));
	dfs(1);
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int u,v;
	
	init();
	memset(degree,0,sizeof(degree));
	
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v;
		par[max(u,v)] = min(u,v);
		G[u].insert(v);
		G[v].insert(u);
		degree[u]++;
		degree[v]++;
	}
	

	
	if(!has_euler() || !link())
	{
		cout << -1 << endl;
		return 0;
	}
	
	print_path();
	cout << 1 << " ";
	while(!points.empty())
	{
		cout << points.top() << " ";
		points.pop();
	}
	cout << endl;
	
	return 0;
}

