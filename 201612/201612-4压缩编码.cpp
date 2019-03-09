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

using namespace std;
const int maxn = 1005;
int a[maxn],sum[maxn],dp[maxn][maxn];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < n; j++)
			dp[i][j] = 0x7fffffff;
	}
	
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
		sum[i] = (i == 0) ? a[i] : sum[i-1] + a[i];
		dp[i][i] = 0;
	}
	
	
	for(int k = 1;k < n; k++)
	{
		for(int i = 0,j;i + k < n; i++)
		{
			j = i + k;
			int su = sum[j] - sum[i-1];
			for(int u = i;u < j; u++)
				dp[i][j] = min(dp[i][j],dp[i][u]+dp[u+1][j]+su);
		}
	}
	
	cout << dp[0][n-1] << endl;
	
	return 0;
}


