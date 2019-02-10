#include<iostream>
using namespace std;
int a[105];
int unused[25];           //每行剩余的位置 
int pos[25][10];
const int n = 20;
const int m = 5;

void init()
{
	for(int i = 0;i < n; i++)        //0-19行 1-5列 
	{
		for(int j = 1;j <= m; j++)
		{
			pos[i][j] = 5 * i + j;
			//cout << pos[i][j] << " ";
		}
		unused[i] = m; 
		//cout << endl;
	}
}


void solve(int num)
{
	int i;
	for(i = 0;i < n; i++)
	{
		if(unused[i] >= num)
		{
			for(int j = 1;j <=m; j++)
			{
				if(pos[i][j] > 0)
				{
					cout << pos[i][j] << " ";
					unused[i] -= 1;
					pos[i][j] = -1;
					num--;
					if(num == 0)
					{
						cout << endl;
						return ;		
					}
					
				}
			}
		}
	}
	
	if(i == n)
	{
		for(int i = 0;i < n; i++)
		{
			for(int j = 1;j <= m; j++)
			{
				if(pos[i][j] > 0)
				{
					cout << pos[i][j] << " ";
					unused[i] -= 1;
					pos[i][j] = -1;
					num--;
					if(num == 0)
					{
						cout << endl;
						return ;
					}
				}
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0;i < N; i++)
		cin >> a[i];
	
	init();
	
	for(int i = 0;i < N; i++)
		solve(a[i]);
}
