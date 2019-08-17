#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int n,m;
bool used[1005];
int link[1005][1005];

vector<vector<int> > G(1005);

void dfs(int start,int u)
{
	used[u] = 1;
	link[start][u] = link[u][start] = 1;
	for(int i = 0;i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(!used[v])
		{
			dfs(start,v);
		}
	}
} 


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int u,v;
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
	}
	
	
	memset(link,0,sizeof(link));
	
	for(int i = 1;i <= n; i++)
	{
		memset(used,0,sizeof(used));
		dfs(i,i);
	}
	
	int ans = 0;

	for(int i = 1;i <= n; i++)
	{
		int sum = 0;
		for(int j = 1;j <= n; j++)
			sum += link[i][j];
		if(sum == n)
			ans++;
	}
	cout << ans << endl;
	
	
	return 0;
}

