#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#define MAXN 55
#define UP     3
#define DOWN   2
#define LEFT   1
#define RIGHT  0
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m,x0,y0,xn,yn;
char a[MAXN][MAXN];
int mark[MAXN][MAXN];
int mark2[MAXN][MAXN];

typedef pair<int,int> P;

inline bool isvalid(int x,int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#' && mark[x][y] == 0;
}

void bfs(int x,int y)
{
	queue<P> q;
	q.push(make_pair(x,y));
	int cx,cy,nx,ny;
	
	while(!q.empty())
	{
		P v = q.front();
		q.pop();
		
		cx = v.first;
		cy = v.second;
		
		//cout << "cx :" << cx << "cy : " << cy << endl;
		
		mark[cx][cy] = 1;

		if(a[cx][cy] == 'S' || a[cx][cy] == '+' || a[cx][cy] == 'T')
		{
			for(int i = 0;i < 4; i++)
			{
				nx = cx + dx[i];
				ny = cy + dy[i];
				if(isvalid(nx,ny))
				{
					q.push(make_pair(nx,ny));
					//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
				}
			}
		}
		else if(a[cx][cy] == '-')
		{
			for(int i = 0;i < 2; i++)
			{
				nx = cx + dx[i];
				ny = cy + dy[i];
				if(isvalid(nx,ny))
				{
					q.push(make_pair(nx,ny));
					//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
				}
			}
		}
		else if(a[cx][cy] == '|')
		{
			for(int i = 2;i < 4; i++)
			{
				nx = cx + dx[i];
				ny = cy + dy[i];
				if(isvalid(nx,ny))
				{
					q.push(make_pair(nx,ny));
					//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
				}
			}
		}
		else if(a[cx][cy] == '.')
		{
			nx = cx + 1;
			ny = cy ;
			if(isvalid(nx,ny))
			{
				q.push(make_pair(nx,ny));
				//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
			}
		}
	}
}

void dfs(int cx,int cy)
{		
	int nx,ny;
	mark[cx][cy] = 1;

	if(a[cx][cy] == 'S' || a[cx][cy] == '+' || a[cx][cy] == 'T')
	{
		for(int i = 0;i < 4; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(isvalid(nx,ny))
			{
				dfs(nx,ny);
				//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
			}
		}
	}
	else if(a[cx][cy] == '-')
	{
		for(int i = 0;i < 2; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(isvalid(nx,ny))
			{
				dfs(nx,ny);
				//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
			}
		}
	}
	else if(a[cx][cy] == '|')
	{
		for(int i = 2;i < 4; i++)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(isvalid(nx,ny))
			{
				dfs(nx,ny);
				//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
			}
		}
	}
	else if(a[cx][cy] == '.')
	{
		nx = cx + 1;
		ny = cy ;
		if(isvalid(nx,ny))
		{
			dfs(nx,ny);
			//printf("in %c (%d,%d) push (%d,%d)\n",a[cx][cy],cx,cy,nx,ny);
		}
	}
}


int main()
{

	cin >> n >> m;

	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < m; j++)
		{
			cin >> a[i][j] ;
			if(a[i][j] == 'S') 
			{
				x0 = i;
				y0 = j;
			}
			if(a[i][j] == 'T')
			{
				xn = i;
				yn = j;
			}
		}
	}
	
	memset(mark,0,sizeof(mark));
	dfs(x0,y0);
	
//	for(int i = 0;i < n; i++)
//	{
//		for(int j = 0;j < m; j++)
//			cout << mark[i][j] << " ";
//		cout << endl;
//	}
	
	memcpy(mark2,mark,sizeof(mark));
	int ans = 0;
	
	if(mark2[xn][yn] == 1)            //S 能到的点 
	{
		for(int i = 0;i < n; i++)
		{
			for(int j = 0;j < m; j++)
			{
				if(mark2[i][j] == 1)
				{	
					memset(mark,0,sizeof(mark));
					dfs(i,j);
					
					if(mark[xn][yn] == 0)        //不能到T 
						ans++; 
				}
			}
		}
		cout << ans << endl; 
	}
	else
		cout << "I'm stuck!" << endl;
}
