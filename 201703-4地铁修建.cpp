#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 9999999
#define max(a,b) ((a > b) ? (a) : (b))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,vector<int>> POINT;

const int maxn = 100005;
vector<vector<P> > G(maxn);
bool used[maxn];
int n,m;

int min_index(vector<int> &v)
{
	int min_value = 99999999;
	int min_i = -1;
	for(int i = 0;i < v.size(); i++)
	{
		if(v[i] < min_value)
		{
			min_value = v[i];
			min_i = i;
		}
	}
	return min_i;
}

int bfs()
{
	queue<POINT> q;
	vector<int> v0(6,0);
	q.push(make_pair(1,v0));
	
	while(!q.empty())
	{
		
	}
	
}

int main()
{
	cin >> n >> m;
	int u,v,len;
	
	
	for(int i = 0;i < m; i++)
	{
		cin >> u >> v >> len;
		G[u].push_back(make_pair(v,len));
		G[v].push_back(make_pair(u,len));
	}
	
	cout << bfs() << endl;
	
}
