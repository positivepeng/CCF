#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include <iterator>
#include <set>
#include <map>
#define MAXN 300+10
using namespace std;

int dp[MAXN][MAXN][MAXN];
int d1[MAXN],d2[MAXN];
int n; 

void Print()
{
	for(int i = 0;i < n; i++)
		cout << d1[i] << " ";
	cout << endl;
}

int dfs(int i)
{
	if(dp[i][d1[i-2]][d1[i-1]] != -1)
		return dp[i][d1[i-2]][d1[i-1]];
		
	if(i == n-1)
	{
		if(d1[i-1]+d1[i] >= 2*d2[i] && d1[i-1]+d1[i] < 2*(d2[i]+1))
			return 1;
		return 0;
	}
	
	int min_v = max(1,3*d2[i-1]-d1[i-1]-d1[i-2]);
	int max_v = 3*(d2[i-2]+1)-d1[i-1]-d1[i-2];
	
	if(max_v < min_v) 
		return dp[i][d1[i-2]][d1[i-1]] = 0;
	

	for(int vi = min_v;vi < max_v; vi++)
	{
		d1[i] = vi;
		if(dfs(i+1,vi))
			return dp[i][d1[i-2]][d1[i-1]] = 1;	
	}
	
	return dp[i][d1[i-2]][d1[i-1]] = 0;
	
}

void solve()
{
	memset(dp,-1,sizeof(dp));
	for(int v0 = 1;v0 < 2*(d2[0]+1); v0++) 
	{
		d1[0] = v0;
		for(int v1 = max(1,2*d2[0]-v0);v1 < 2*(d2[0]+1)-v0; v1++)
		{
			d1[1] = v1;
			if(dfs(2) == 1)
				return ;
			
		}
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 0;i < n; i++)
		cin >> d2[i];
	
	solve();
	
	for(int i = 0;i < n; i++)
		cout << d1[i] << " ";
	cout << endl;
	return 0;
}


