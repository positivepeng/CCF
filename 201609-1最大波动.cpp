#include<iostream>
#include<cmath>
using namespace std;
int a[1005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	
	for(int i = 0;i < n-1; i++)
	{
		ans = max(ans,abs(a[i]-a[i+1]));
	}
	cout << ans << endl;
 } 
