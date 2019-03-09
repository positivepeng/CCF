#include<iostream>
#include<vector>
using namespace std;
int a[505][505];
int n;


void solve()
{
	vector<vector<int> > v;   //每个元素是一条对角线 
	int x = 0,y = 0;
	for(x = 0;x < n; x++)
	{
		vector<int> v1;
		int tx = x,ty = y;
		int sum = tx + ty;
		v1.push_back(a[tx][ty]);
		while(tx > 0)
		{
			v1.push_back(a[--tx][++ty]);
		}
		v.push_back(v1);
	}
	
	x = n-1;
	for(y = 1;y < n; y++)
	{
		vector<int> v1;
		int tx = x;
		int ty = y;
		v1.push_back(a[tx][ty]);
		int sum = tx + ty;
		while(ty < n-1)
		{
			v1.push_back(a[--tx][++ty]);
		}
		v.push_back(v1);
	}
	
//	for(int i =0;i < v.size(); i++)
//	{
//		for(int j = 0;j < v[i].size(); j++)
//		{
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i = 0;i < v.size(); i++)
	{
		if(i % 2 == 0)
		{
			for(int j = 0;j < v[i].size(); j++)
			{
				if(i == 0 && j == 0)
					cout << v[i][j];
				else 
					cout << " " << v[i][j];
			}
				
		}
		else if(i % 2 == 1)
		{
			for(int j = v[i].size() - 1;j >= 0; j--)
				cout << " " << v[i][j];
		}
	}
	
	cout << endl;
	 
}


int main()
{
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		for(int j = 0;j < n; j++)
		{
			cin >> a[i][j];
			//cout << a[i][j] << " ";
		}
	}
	
	solve();
	
 } 
