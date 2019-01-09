#include<iostream>
#include<string.h>
using namespace std;
int a[1004];
int main()
{
	int n,t,ans = 0;
	cin >> n;
	memset(a,0,sizeof(a));
	
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		t = t >= 0 ?  t : -t;
		if(a[t] == 0)
			a[t] = 1;
		else 
			ans++;
	}
	
	cout << ans << endl;
 } 
