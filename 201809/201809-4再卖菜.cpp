#include <bits/stdc++.h> 
using namespace std;

int d1[305],d2[305];
int n; 

// 第i天的价格设为value是否可能 
bool isValid(int i,int value)
{
	d1[i] = value;
	if(i == n) 
	{
		return d1[n-1] + d1[n] >= 2 * d2[n] && d1[n-1] + d1[n] < 2 * (d2[n] + 1);
	}
	else if(i == 1)
	{
		for(int v = 2*d2[1]-d1[1];v < 2*(d2[1]+1)-d1[1]; v++)
		{
			if(v >= 1 && isValid(2,v))
				return true;
		}
	}
	else
	{
		for(int v = 3*d2[i]-d1[i-1]-d1[i];v< 3*(d2[i]+1)-d1[i-1]-d1[i]; v++)
			if(v >= 1 && isValid(i+1,v))
				return true;
	}
	return false;
}

void solve()
{
	for(int v = 1;v < 2*(d2[1]+1); v++)
	{
		if(isValid(1,v))
			break;
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 1;i <= n; i++)
		scanf("%d",&d2[i]);

	solve();
	
	for(int i = 1;i <= n; i++)
		printf("%d ",d1[i]);
	
	cout << endl;
	return 0;
}


