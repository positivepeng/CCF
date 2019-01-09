#include<iostream>
#include<string.h>
using namespace std;
int a[100003];


//出现次数最多，最小 
int main()
{
	int n,t;
	cin >> n;
	int max_times = 0;
	int max_times_num;
	
	memset(a,0,sizeof(a));
	
	for(int i = 0;i < n; i++)
	{
		cin >> t;
		a[t]++;
		if(a[t] > max_times) 
		{
			max_times = a[t];
			max_times_num = t;
		}
		else if(a[t] == max_times && max_times_num > t)
		{
			max_times_num = t;
		}
	}
	cout << max_times_num << endl;
 } 
