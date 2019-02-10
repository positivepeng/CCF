#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int a[1004][1004];
int b[1004];
int m,n,k;

void cal(int times)
{
	int ans[n+1][n+1];
	int u;
	int val;

	for(int i = 1;i <= n; i++)	
	{
		for(int j = 1;j <= n; j++)
		{
			val = 0;
			for(int u = 1;u <= n; u++)
			{
				val ^= a[i][u] & a[u][j];
			}
			ans[i][j] = val;
		}
	}
	
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1;j <= n; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	
	
}



int main(int argc, char const *argv[])
{
	cin >> n;
	string s;
	for(int i = 1;i <= n; i++)
	{
		cin >> s;
		for(int L = 0;L < s.size(); L++)
		{
			a[i][L] = s[L] - '0';
		}
	}
	
	cin >> s;
	for(int L = 0;L < s.size(); L++)
	{
		b[L] = s[L] - '0';
	}	

	

	cin >> m;
	
	for(int i = 0;i < m; i++)
	{
		cin >> k;
		//cal(k);
	}
	
	cal(2);
	
	return 0;
}

