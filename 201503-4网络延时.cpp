#include<iostream>
#include<vector> 
#include<queue> 
#include<string.h>

using namespace std;
typedef pair<int,int> P;

vector<vector<int> > v(20004);

int main()
{
	int n,m,t;
	cin >> n >> m;
	for(int i = 2;i <= n; i++)
	{
		cin >> t;
		v[t].push_back(i);
		v[i].push_back(t);
	}
	
	for(int j = n + 1; j <= n + m; j++)
	{
		cin >> t;
		v[t].push_back(j);
		v[j].push_back(t);
	}
	
	//先搜索从1出发能到达的最远的点
	int mark[n+m+1];
	memset(mark,0,sizeof(mark));
	
	queue<P> q;
	q.push(make_pair(1,0));
	
	int deepest_id = 0;
	int max_len = 0;
	
	while(!q.empty())
	{
		P node = q.front();
		q.pop();
		
		int id = node.first;
		int len = node.second;
		
		//cout << "id : " << id << " len  " << len << endl;
		
		mark[id] = 1;
		
		for(int i = 0;i < v[id].size(); i++)
		{
			if(mark[v[id][i]] == 0)
			{
				q.push(make_pair(v[id][i],len+1));
				if(len + 1 > max_len)
				{
					max_len = len + 1;
					deepest_id = v[id][i];
				}
			}
		}
		
	}
	
	//cout << deepest_id << endl;
	
	//从deepest_id再来一次BFS
	memset(mark,0,sizeof(mark));
	
	q.push(make_pair(deepest_id,0));
	
	deepest_id = 0;
	max_len = 0;
	
	while(!q.empty())
	{
		P node = q.front();
		q.pop();
		
		int id = node.first;
		int len = node.second;
		
		//cout << "id : " << id << " len  " << len << endl;
		
		mark[id] = 1;
		
		for(int i = 0;i < v[id].size(); i++)
		{
			if(mark[v[id][i]] == 0)
			{
				q.push(make_pair(v[id][i],len+1));
				if(len + 1 > max_len)
				{
					max_len = len + 1;
					deepest_id = v[id][i];
				}
			}
		}
		
	}
	
	cout << max_len << endl;
	 
	
	
	 
}
