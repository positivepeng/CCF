#include<iostream>
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
	for(int j = 1;j < n-1; j++)
	{
		if((a[j] > a[j-1] && a[j] > a[j+1]) || (a[j] < a[j-1] && a[j] < a[j+1]))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
