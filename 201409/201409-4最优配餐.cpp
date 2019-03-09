#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;

const int maxn = 1005;

struct node
{
	int x,y,len;
	node(int x1,int y1,int len1):x(x1),y(y1),len(len1){}
};

int n,m,k,d;
int mark[maxn][maxn];
int order[maxn][maxn];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<node> q; 



ll bfs(int buynum)
{
	ll ans = 0;
	int x,y,len,nx,ny;
	
	while(!q.empty())
	{
		node v = q.front();
		q.pop();
		//cout << "x : " << x << " y : " << y << " len : " << len << endl;
		x = v.x;
		y = v.y;
		len = v.len;
		
		for(int i = 0;i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && mark[nx][ny] == 0)
			{
				if(order[nx][ny] > 0)
				{
					ans += order[nx][ny] * (len + 1);
					//cout << "接单" << x << " " << y << " len: " << len + 1 << endl;
					//cout << order[x][y]
					mark[nx][ny] = 1;
					if(--buynum == 0)
						return ans;
				}
				mark[nx][ny] = 1;
				q.push(node(nx,ny,len+1));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k >> d;
	int x,y,num,buynum = 0;
	
	memset(order,0,sizeof(order));
	memset(mark,0,sizeof(mark));
	
	for(int i = 0;i < m; i++)          //读入店家 
	{
		cin >> x >> y;
		q.push(node(x,y,0));
		mark[x][y] = 1;
	}
	
	for(int i = 0;i < k; i++)
	{
		cin >> x >> y >> num;
		if(order[x][y] == 0)
			buynum++;
		order[x][y] += num;
	}
	
	for(int i = 0;i < d; i++)
	{
		cin >> x >> y;
		mark[x][y] = 1;
	}
	
	ll ans = bfs(buynum);
	
	cout << ans << endl;
} 
