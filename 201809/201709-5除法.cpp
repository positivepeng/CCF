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
typedef long long ll;

const int maxn = 101024;
int n,m;
ll bit[maxn];
int a[maxn];

ll sum(int i)
{
	ll s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i,int x)
{
	while(i <= n)
	{
		bit[i] += x;
		i += i & -i;
	}
}

int main(int argc, char const *argv[])
{
	int l,r,t,k;
	
	cin >> n >> m;
	for(int i = 1;i <= n; i++)
	{
		cin >> a[i];
		add(i,a[i]);
	}
	
	
	for(int i = 0;i < m; i++)
	{
		cin >> t;
		if(t == 1)     //¸ü¸Ä 
		{
			cin >> l >> r >> k;	
			
			if(k == 1)	continue;
			
			for(int j = l;j <= r; j++)
			{
				if(a[j] >= k && a[j] % k == 0)
				{
					add(j,a[j] / k - a[j]);
					a[j] /= k;
				}
			}
		}
		if(t == 2)
		{
			cin >> l >> r;
			cout << sum(r) - sum(l-1) << endl;
		}
	}
	return 0;
}


