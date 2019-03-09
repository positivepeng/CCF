#include<iostream>
#include<cmath>
using namespace std;
int a[1005];
int main()
{
	int n;
	int ans = 9999999;
	cin >> n;
	for(int i = 0;i < n; i++)
		cin >> a[i];
	
	for(int i = 0;i < n; i++)
	{
		for(int j = i+1;j < n; j++)
		{
			if(abs(a[i] - a[j]) < ans)
			{
				ans = abs(a[i] - a[j]);
			}
		} 
	}
	cout << ans << endl;
	
 } 
