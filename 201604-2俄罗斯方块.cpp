#include<iostream>
#include<cstring>
using namespace std;
int a[20][20];
int s[5][5];
int n = 15,m = 10;

	
bool collision(int line,int left)             //×óÉÏ½ÇÎ»£¨line£¬left£© 
{
	for(int i = line;i <= line + 3; i++)         
	{
		for(int j = left;j <= left + 3; j++)
		{
			if(a[i][j] == s[i - line + 1][j - left + 1] && a[i][j] == 1)
				return 1;
		}
	}
	return 0;
}

void change(int line,int left)
{
	for(int i = line;i <= line + 3; i++)         
	{
		for(int j = left;j <= left + 3; j++)
		{
			a[i][j] += s[i - line + 1][j - left + 1];
		}
	}
}

int main()
{
	for(int i = 0;i < 20; i++)
	{
		for(int j = 0;j < 20; j++)
			a[i][j] = 1;
	}
	
	
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	memset(s,0,sizeof(s));
	
	for(int i = 1;i <= 4; i++)
	{
		for(int j = 1;j <= 4; j++)
		{
			cin >> s[i][j];
		}
	}
	
	int left;
	cin >> left;
	
	int i;
	for(i = 1;i <= n ; i++)         //ÐÐºÅ 
	{
		if(!collision(i,left) && collision(i+1,left))
		{
			change(i,left);
			break;
		} 
	}
	
	
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
}
