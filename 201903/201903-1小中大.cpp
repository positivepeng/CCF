#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i = 0;i < n; i++){
		cin >> a[i];
	}
	
	if(n == 0)
		return 0;
	
	if(n == 1){
		cout << a[0] << " " << a[0] << " " << a[0] << endl;
		return 0;
	} 
	
	int maxa = max(a[0], a[n-1]);
	int mina = min(a[0], a[n-1]);
	double mid = 0;
	
	if(n % 2 == 0){
		mid = ((double)a[n/2-1] + (double)a[n/2]) / 2;
	}
	else
		mid = a[n/2];
	
	if((int)(mid*10) % 10 == 0)
		cout << maxa << " " << (int)mid << " " << mina << endl;
	else
		printf("%d %.1lf %d\n",maxa, (double)((int)((mid*10)+0.5))/10, mina);
	
	return 0;
}


