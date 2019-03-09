#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define MAX_M 1005
using namespace std;
int m,n,k;

vector<vector<int> > mulMM(vector<vector<int> >& x1,vector<vector<int> >& x2)
{
	vector<vector<int> > ans;
	for(int i = 0;i < m; i++)
	{
		for(int j = 0;j < m; j++)
		{
			int cij = (x1[i][0] & x2[0][j]);
			for(int k = 1;k < m; k++)
				cij = cij ^ (x1[i][k] & x2[k][j]);
			ans[i].push_back(cij);
		}
	}
	return ans;
}

vector<int> mulM1(vector<vector<int> >& x1,vector<int>& x2)
{
	vector<int> ans(m);
	for(int i = 0;i < m; i++)
	{
		int cij = (x1[i][1] & x2[1]);
		for(int k = 1;k < m; k++)
			cij = cij ^ (x1[i][k] & x2[k]);
		
		ans.push_back(cij);
	}
	return ans;
}

vector<vector<int> > quick_pow(vector<vector<int> > x,int k)  // y = x^k
{
	vector<vector<int> > ans(m);
	if(k == 0) 
		return ans;
	ans = x;
	k--;
	
	vector<vector<int> > base = x;

	while(k != 0)
	{
		if(k & 1)
			ans = mulMM(ans,base);
		base = mulMM(base,base);
		k = k >> 1;
	}
	
	return ans;
}

int main() 
{
	char t;
	
	cin >> m;
	
	vector<vector<int> > a(m);
	vector<int> b(m);
	
	for(int i = 0;i < m; i++)
	{
		for(int j = 0;j < m; j++)
		{
			cin >> t;
			a[i].push_back(t-'0');
		}
	}
	
	for(int i = 0;i < m; i++)
	{
		cin >> t;
		b[i] = t-'0';
	}
	
	cin >> n;
	
	for(int i = 0;i < n; i++)
	{
		cin >> k;
		
		vector<vector<int> > ak = quick_pow(a,k);
		vector<int> ans = mulM1(ak,b);
		
		for(int j = 0;j < m; j++)
			cout << ans[j];
		
		cout << endl;
	} 
	
	
	return 0;
}

