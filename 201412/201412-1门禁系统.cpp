#include<iostream>
#include<string.h>
using namespace std;
int a[1005];
int main()
{
	memset(a,0,sizeof(a));
	int n,t;
	cin >> n;
	
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		cout << ++a[t];
		if(i != n-1) 
			cout << " ";
		else 
			cout << endl;
		
	}
}
