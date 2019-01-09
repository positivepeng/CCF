#include<iostream>
#include<queue>
using namespace std;
int a[55][55];

int main()
{
	int m,n;
	int si,sj; 
	cin >> m >> n;
	for(int i = 0;i < m; i++)
	{
		for(int j = 0;j < n; j++)
			cin >> a[i][j];
		if(a[i][j] == 'S')
		{
			si = i;
			sj = j;
		}
	}
	
	int ans = bfs(si,sj);
 } 
