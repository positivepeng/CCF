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
int  degree[10003];
bool path[10003][10003];
bool mark[10003];
stack<int> points;
vector<set<int> > G(10003);

bool link()
{	
	memset(mark,0,sizeof(mark));
	int cnt = 0;
	queue<int> q;
	q.push(1);
	mark[1] = 1;
	cnt++;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		
		for(set<int>::iterator it = G[v].begin(); it != G[v].end(); it++)
		{
			int k = *it;
			if(mark[k] == 0)
			{			
				q.push(k);	
				mark[k] = 1;
				cnt++;
			}
		}
	}
	return cnt == n;
}

bool has_euler()
{
	int cnt = 0,flag = 0;
	for(int i = 1;i <= n; i++)
	{
		if(degree[i] % 2 == 1)
		{
			cnt++;
			if(i == 1)
				flag = 1;
		}
	}
	
	return cnt == 0 || (flag == 1 && cnt == 2);
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
	
	memset(degree,0,sizeof(degree));
	for(int i = 0;i < 10003; i++)
	{
		for(int j = 0;j < 10003; j++)
		{
			path[i][j] = false;
		}
	}
	
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v;
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

