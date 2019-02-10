#include<iostream>
using namespace std;
int a[1005];
int main()
{
	int n;
	cin >> n;
	
	for(int i = 0;i < n; i++)
		cin >> a[i];
	
	int ans = 1;
	int cur = a[0];
	for(int i = 1;i < n; i++)
	{
		if(a[i] != cur)
		{
			cur = a[i];
			ans++;
		}
	}
	cout << ans << endl;
}
