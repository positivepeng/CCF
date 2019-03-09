#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 105;
char a[maxn][maxn];
int mark[maxn][maxn];
int m,n,q;
int x1,y1,x2,y2;
int x,y,c;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void init()
{
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < m; j++)
		{
			a[i][j] = '.';
		}
	}
}

inline bool valid(int x,int y)
{
	//向右为x坐标增大的方向，向上为y坐标增大的方向
	return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '-' && a[x][y] != '|' && a[x][y] != '+';
}

void drawline(int x1,int y1,int x2,int y2)
{
	int xs = min(x1,x2);
	int ys = min(y1,y2);
	int xe = max(x1,x2);
	int ye = max(y1,y2);
	
	if(x1 == x2)
	{
		for(int i = ys;i <= ye; i++)
		{
			if(a[x1][i] == '|')
				a[x1][i] = '+';
			else if(a[x1][i] != '+')
				a[x1][i] = '-';
		}
	}
	
	if(y1 == y2)
	{
		for(int i = xs;i <= xe; i++)
		{
			if(a[i][y1] == '-')
				a[i][y1] = '+';
			else if(a[i][y1] != '+')
				a[i][y1] = '|';
		}
	}
}

void dfs(int x,int y,char c)
{
	int nx,ny;
	a[x][y] = c;
	mark[x][y] = 1;
	//cout << "fill " << x << " " << y << endl;
	for(int i = 0;i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if(valid(nx,ny) && mark[nx][ny] == 0)
		{
		//	cout << "x,y " << x << " " << y << " push " << nx << " " << ny << endl;
			dfs(nx,ny,c);
		}
			
	}
}

void fill(int x,int y,char c)
{
	memset(mark,0,sizeof(mark));
	
	dfs(x,y,c);
}
int main()
{	
	cin >> m >> n >> q;
	
	init();
	
	char fillc;
	
	for(int i = 0;i < q; i++)
	{
		cin >> c;
		if(c == 0)	
		{
			cin >> y1 >> x1 >> y2 >> x2;
			drawline(x1,y1,x2,y2);
		}
		if(c == 1)
		{
			cin >> y >> x >> fillc;
			fill(x,y,fillc);
		}
//		for(int i = n-1;i >= 0; i--)
//		{
//			for(int j = 0;j < m; j++)
//				cout << a[i][j] << " ";
//			cout << endl;
//		}
	}
	
	for(int i = n-1;i >= 0; i--)
	{
		for(int j = 0;j < m; j++)
			cout << a[i][j];
		cout << endl;
	}
	
		
 } 
