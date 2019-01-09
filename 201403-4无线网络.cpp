#include<iostream>
using namespace std;
typedef long long ll;
ll map[105][105];

ll x[105];
ll y[105];
int tag[105];

int main()
{
	int n,m,k,r,x,y,t;
	cin >> n >> m >> k >> r;
	
	for(int i = 0;i < n + m; i++)
	{
		cin >> x[i] >> y[i];
		if(i < n)
			tag[i] = 1;
		else 
			tag[i] = 2;
	}
	
	for(int i = 0;i < n + m; i++)
	{
		for(int j = 0;j < n + m; j++)
		{
			if(tag[i] == 1 && tag[i] == tag[j])
				map[i][j] = 1;
			else if(tag[i] == 2 && tag[i] == tag[j])
				map[i][j] = 2;
			else if(tag[i] != tag[j])
				map[i][j] = 1;
		}
	}

		
 } 
