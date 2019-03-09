#include <bits/stdc++.h>
using namespace std;

const int maxn = 400;
int n;
int day1[maxn],day2[maxn];
bool visit[maxn][maxn][maxn];
bool isfind = false;

void dfs(int i,int curr,int pre)
{
	if(visit[i][curr][pre])
		return ;
	
	visit[i][curr][pre] = 1;
	day1[i] = curr;
	
	if(i == n)
	{
		if((curr + pre) / 2 == day2[n])
		{
			isfind = true;
			return ;
		}
	}
	else
	{
		int next = day2[i]*3 - curr - pre;
		for(int k = 0;k < 3; k++)
		{
			if(next+k >= 1 && !isfind)
				dfs(i+1,next+k,curr);
				
		}
	}
	
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 1;i <= n; i++)
		cin >> day2[i];
	
	memset(visit,0,sizeof(visit));
	
	for(int v1 = 1;v1 < 2*day2[1]; v1++)
	{
		day1[1] = v1;			
		dfs(2,2*day2[1]-v1,day1[1]);
		if(!isfind)
			dfs(2,2*day2[1]-v1+1,day1[1]);
		else
			break;
	}
	for(int i = 1;i <= n; i++)	
		cout << day1[i] << " ";
	cout << endl;
	
	return 0;
}


