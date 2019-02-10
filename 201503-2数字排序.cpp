#include<iostream>
#include<string.h>
int a[1005];
using namespace std;

bool all_zero()
{
	for(int i = 0;i < 1005; i++)
	{
		if(a[i] != 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	memset(a,0,sizeof(a));
	
	int t;
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		a[t]++;
	}
	
	int most = 0;
	int most_id = 0;
	
	while(!all_zero())
	{
		for(int i = 0;i < 1005; i++)
		{
			if(a[i] > most)
			{
				most = a[i];
				most_id = i;
			}
		}
		cout << most_id << " " << most << endl;
		a[most_id] = 0;
		most = 0;
	}
}
