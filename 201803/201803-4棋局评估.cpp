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
int a[5][5];
int size = 3;

bool win(int k)
{
	for(int i = 1;i <= size; i++)
	{
		if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] == k)    
			return true;
		if(a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[1][i] == k)
			return true;
	}
	
	if(a[1][1] == a[2][2] && a[1][1] == a[3][3] && a[1][1] == k)
		return true;
	
	if(a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[2][2] == k)
		return true;
	
	return false;
}

int dfs(int k)
{
	int empty = 0;
	for(int i = 1;i <= 3; i++) 
	{
		for(int j = 1;j <= 3; j++)
			if(a[i][j] == 0) 
				empty += 1;
	}
	
	if(k == 1 && win(2))
		return -empty-1;
	if(k == 2 && win(1))
		return empty+1;
	if(empty == 0)
		return 0;
	
	int alice = -1000000,bob = 10000000;
	for(int i = 1;i <= 3; i++)
	{
		for(int j = 1;j <= 3; j++)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = k;
				if(k == 1) 
					alice = max(alice,dfs(2));
				if(k == 2)
					bob = min(bob,dfs(1));
				a[i][j] = 0;
			}
		}
	}
	
	if(k == 1)
		return alice;
	
	if(k == 2)
		return bob;
}

int main(int argc, char const *argv[])
{	
	int n;
	cin >> n;
	while(n--)
	{
		for(int i = 1;i <= size; i++)
			for(int j = 1;j <= size; j++)
				cin >> a[i][j];
	
		cout << dfs(1) << endl;
	}
	
	
	return 0;
}

