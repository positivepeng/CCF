#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int a[1005];
int n,k;

void init(int n)
{
	for(int i =  0;i < n; i++)
		a[i] = i;
}

int main(int argc, char const *argv[])
{
	int out = 0;
	int num = 0;
	int id = 0;
	cin >> n >> k;
	init(n);
	
	while(out != n-1)
	{
		if(a[id] != -1)
		{
			num++;
			if(num % k == 0 || num % 10 == k)
			{
				a[id] = -1;
				out++;
			}
		}
		id = (id + 1) % n;
	}
	
	for(int i = 0;i < n; i++)
	{
		if(a[i] != -1)
		{
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}

