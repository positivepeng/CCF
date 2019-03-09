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
#define INF 999999999
using namespace std;

typedef struct path
{
	int type;
	int len;
	int to;
	path();
	path(int ty,int to_id,int Len)
	{
		type = ty;
		to = to_id;
		len = Len;
	}
}path;

typedef struct node
{
	int id;
	int narrow_len;
	int energy_cost;
	node(){}
	node(int i,int nlen,int ec)
	{
		id = i;
		narrow_len = nlen;
		energy_cost = ec;
	}
}node;

vector<vector<path> > G(503);
int min_energy[503];
int n,m;

void solve()
{
	fill(min_energy,min_energy+503,INF);
	min_energy[1] = 0;
	
	queue<node> q;
	q.push(node(1,0,0));

	while(!q.empty())
	{
		node u = q.front();
		q.pop();

		int id = u.id;
		int narrow_len = u.narrow_len;
		int energy_cost = u.energy_cost;
		
		cout << "id " << id << " narrow len " << narrow_len << " energy_cost " << energy_cost << endl;
		
		for(int i = 0;i < G[id].size(); i++)
		{
			int type = G[id][i].type;
			int v = G[id][i].to;
			int len = G[id][i].len;
			cout << v << " links " << id << endl;
			if(type == WIDE)
			{
				int total_energy_cost = energy_cost + len + narrow_len * narrow_len;
				if(total_energy_cost < min_energy[v])
				{
					q.push(node(v,0,total_energy_cost));
					min_energy[v] = total_energy_cost;
					cout << id << " to " << v << " updated to " << min_energy[v] << endl;
				}
			}
			if(type == NARROW)
			{
				int total_narrow_len = narrow_len + len;
				int total_energy_cost = energy_cost + total_narrow_len * total_narrow_len;
				if(total_energy_cost < min_energy[v])
				{
					q.push(node(v,total_narrow_len,energy_cost));
					min_energy[v] = total_energy_cost;
					cout << id << " to " << v << " updated to " << min_energy[v] << endl;
				} 
			}
		}
		
		
	}
	
	for(int i = 1;i <= n; i++)
		cout << " i " << i << " min_energy " << min_energy[n] << endl;
	
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int t,u,v,len;
	
	for(int i = 0;i < m; i++)
	{
		cin >> t >> u >> v >> len;
		G[u].push_back(path(t,v,len));
		G[v].push_back(path(t,u,len));
	}
	
	solve();
	
	return 0;
}

