#include<iostream>
#include<cmath>
#include<cstring>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll a[7][1005];

int main()
{
	int n,m;
	cin >> n >> m;
	memset(a,0,sizeof(a));
	
	if(n * m % 3 != 0 || m == 1)   cout << 0 << endl;      //Ãæ»ýÊØºã
	
	for(int i = 2;i <= n; i++)
	{
		a[2][i] = i % 3 == 0 ? pow(2,i/3) : 0;
		a[3][i] = i % 2 == 0 ? pow(2,i/2) : 0;
		a[4][i] = a[2][i] * a[2][i];
		a[5][i] = a[2][i] * a[3][i];
		a[6][i] = a[2][i] * a[2][i] * a[2][i] + a[3][i] * a[3][i];
	}
	
	
	cout << a[m][n] << endl;
	
	
	
	return 0;
}
