#include<iostream>
#include<string.h>
#define MAXN 35
using namespace std;

int a[MAXN][MAXN];
int mask[MAXN][MAXN];

int main()
{
	memset(a,0,sizeof(a));
	memset(mask,0,sizeof(mask));
	
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	//––…®√Ë 
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < m - 2; j++)
		{
			if(a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2])
			{
				mask[i][j] = 1;
				mask[i][j+1] = 1;
				mask[i][j+2] = 1;
				
//				int t = j+3;
//				while(t < m && a[i][j] == a[i][t])
//				{
//					mask[i][t] = 1;
//					t++;
//				}
//				j = t;
			}
		}
	}
	
	//¡–…®√Ë 
	for(int j = 0;j < m; j++)
	{
		for(int i = 0;i < n - 2; i++)
		{
			if(a[i][j] == a[i+1][j] && a[i][j] == a[i+2][j])
			{
				mask[i][j] = 1;
				mask[i+1][j] = 1;
				mask[i+2][j] = 1;
				
//				int t = i+3;
//				while(t < n && a[i][j] == a[t][j])
//				{
//					mask[t][j] = 1;
//					t++;
//				}
//				i = t;
			}
		}
	}
	
	
	
	
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < m; j++)
		{
			if(mask[i][j] == 1)
				cout << 0 << " ";
			else
				cout << a[i][j] << " ";
		}
			//cout << mask[i][j] << " ";
		cout << endl;
	}
	
	
}
