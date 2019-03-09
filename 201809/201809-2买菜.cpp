#include <bits/stdc++.h>
using namespace std;

int a[1000000];

int main(int argc, char const *argv[])
{
	int n; 
	cin >> n;
	memset(a,0,sizeof(a));
	int u,v;
	for(int i = 0;i < n; i++)
	{
		cin >> u >> v;
		for(int j = u;j < v; j++)
			a[j] = 1;
	}
	int ans = 0;
	for(int i = 0;i < n; i++)
	{
		cin >> u >> v;
		for(int j = u;j < v; j++)
		{
			if(a[j] == 1) 
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}


