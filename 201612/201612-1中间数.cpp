#include<iostream>
#include<cstring>
using namespace std;
int a[1005];


bool check(int n)
{
	int less = 0,more = 0;
	for(int i = 1;i < n; i++)
		less += a[i];
	
	for(int j = n+1;j <= 1000; j++)
		more += a[j];
	
	if(less == more && a[n] > 0)
		return true;
	
	return false;
	
}

int main()
{
	int n,t;
	cin >> n;
	memset(a,0,sizeof(a));
	
	for(int i = 0;i < n; i++)
	{
		cin >> t ;
		a[t]++;
	}
	
	for(int i = 1;i <= 1000; i++)
	{
		if(check(i))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
 } 
