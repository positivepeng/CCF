#include<iostream>
#include<string.h>
using namespace std;
int a[10004];

int main()
{
	int n,t;
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		a[t] = 1;
	}
	
	int cnt = 0;
	
	for(int i = 0;i < 10003; i++)
	{
		if(a[i] == 1 && a[i+1] == 1)
			cnt++;
	}
	
	cout << cnt << endl;
 } 
