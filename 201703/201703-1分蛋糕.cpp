#include<iostream>
using namespace std;
int a[1005];

int main()
{
	int n,k;
	cin >> n >> k;
	
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
	} 
	
	int ans = 0;
	int need = k;
	
	for(int i = 0;i < n; i++)
	{
		need -= a[i];
		if(need <= 0)
		{
			ans += 1;
			need = k;
		}
	}
	if(need < k)
		cout << ans + 1<< endl;
	else
		cout << ans << endl;
	
 } 
