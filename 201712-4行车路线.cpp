#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define WIDE 0
#define NARROW 1
using namespace std;

struct path
{
	int type;
	int len;
	int to;
	path(int t,int to,int L)
	{
		type = t;
		to = to;
		len = L;
	}
	path();
};

struct node
{
	int id;
	int narrow_len;
	int fatigue;
	node(int id,int nlen,int fat)
	{
		id = id;
		narrow_len = nlen;
		fatigue = fat;
	}
	node(){}
};

vector<vector<path> > G(503);
int mark[503];
int n,m;

int bfs()
{
	memset(mark,0,sizeof(mark));
	queue<node> q;
	q.push(node(1,0,0));
	
	int ans = INT_MAX;
	
	
	while(!q.empty())
	{
		node u = q.front();
		q.pop();
		
		int id = u.id;
		int narrow_len = u.narrow_len;
		int fat = u.fatigue;
		
		mark[id] = 1;
		
		for(int i = 0;i < G[id].size(); i++)
		{
			int v = G[id].to;
			if(mark[v] == 0 && v == n)        //µ½´ïÖÕµã 
			{
				ans = min(ans , fat + narrow_len*narrow_len);
				
			}
		}
		
		
	}
	
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int t,u,v,len;
	for(int i = 0;i < m; i++)
	{
		cin >> t >> u >> v >> len;
		G[u].push_back(path(t,v,len));
	}
	
	bfs();
	
	return 0;
}

