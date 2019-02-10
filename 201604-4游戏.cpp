#include<iostream>
#include<queue>
#include<cstring>
#define inf 999999
using namespace std;
const int maxn = 105;
const int maxtime = 10000;
bool used[maxn][maxn][maxtime];
int dan_start[maxn][maxn];
int dan_end[maxn][maxn];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,t,nx,ny;

struct node
{
	int x,y,time;
	node(int x1,int y1,int time1)
	{
		x = x1;
		y = y1;
		time = time1;
	}
};

inline bool inside(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs()
{
	queue<node> q;
	q.push(node(1,1,0));
	used[1][1][0] = 1;
	
	while(!q.empty()) 
	{
		node u = q.front();
		q.pop();
		//cout << "u.x " << u.x << " " << u.y << " " << u.time << endl;
		for(int i = 0;i < 4; i++)
		{
			nx = u.x + dx[i];
			ny = u.y + dy[i];
			if(inside(nx,ny) && used[nx][ny][u.time+1] != 1 &&
					 !(u.time + 1 >= dan_start[nx][ny] && u.time + 1 <= dan_end[nx][ny]))
			{
				used[nx][ny][u.time+1] = 1;
				if(nx == n && ny == m)
					return u.time+1;
				q.push(node(nx,ny,u.time+1));
			}
		}
	}
}


int main()
{
	//memset(dan_start,-1,sizeof(dan_start));
	memset(dan_end,-1,sizeof(dan_end));

	memset(used,0,sizeof(used));
	
	int x,y,s,e;
	cin >> n >> m >> t;
	for(int i = 0;i < t; i++)
	{
		cin >> x >> y >> s >> e; 
		dan_start[x][y] = s;
		dan_end[x][y] = e;
	}
	
	cout << bfs() << endl;
	
	
	
} 
