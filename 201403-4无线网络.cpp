#include<iostream>
#include<queue> 
#include<vector>
#include<string.h>
typedef long long ll;
using namespace std;


struct node
{
	int id;
	int length;
	int left_nodes;
	node(int id_,int length_,int left_nodes_) 
	{
		id = id_;
		length = length_;
		left_nodes = left_nodes_;
	}
};


ll n,m,k,r;
ll r2;
typedef pair<ll,ll> P;
bool canLink[205][205];
int mark[205];
vector<P> points;

inline bool dis_less_r(P& p1,P& p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + 
			(p1.second - p2.second) * (p1.second - p2.second) <= r2;
}

int solve()
{
	queue<node> q;
	memset(mark,0,sizeof(mark));
	q.push(node(0,0,k));
	mark[0] = 1;
	
	while(!q.empty())
	{
		
		node v = q.front();
		q.pop();

//		cout << "v.id : " << v.id << endl;
//		cout << "v.length : " << v.length << endl;
//		cout << "v.left_nodes : " << v.left_nodes << endl;

		int id = v.id;

		for(int i = 0;i < n + m; i++)
		{
			if(canLink[i][id] && mark[i] == 0)
			{
				if(i >= n && v.left_nodes >= 1)
				{
					q.push(node(i,v.length+1,v.left_nodes-1));
					mark[i] = 1;
					if(i == 1)
						return v.length + 1;
				}
				else
				{
					q.push(node(i,v.length+1,v.left_nodes));
					mark[i] = 1;
					if(i == 1)
						return v.length + 1;
				}
			}
		}
		
	}
	
}


int main()
{
	cin >> n >> m >> k >> r;
	r2 = r * r;
	
	ll x,y;
	
	for(int i = 0;i < n + m; i++)	
	{
		cin >> x >> y;
		points.push_back(make_pair(x,y));
	}
	
	memset(canLink,0,sizeof(canLink));
	
	for(int i = 0;i < points.size(); i++)
	{
		for(int j = 0;j < points.size(); j++)
		{
			if(i == j)  canLink[i][j] = false;
			else canLink[i][j] = dis_less_r(points[i],points[j]);
			//cout << canLink[i][j];
		}
	}
	
	cout << solve() - 1 << endl;
	
}

