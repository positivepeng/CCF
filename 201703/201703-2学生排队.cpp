#include<iostream>
using namespace std;

int a[1005];
int n;

void init(int n)
{
	for(int i = 1;i <= n; i++)
		a[i] = i;
}

int find(int num)
{
	for(int i = 1;i <= n; i++)
	{
		if(a[i] == num)
			return i;
	}
}

int swap2(int pos,int shift)
{
	if(shift > 0)
	{
		for(int i = pos;i < pos + shift; i++)
			swap(a[i],a[i+1]);
	}
	else if(shift < 0)
	{
		for(int i = pos;i > pos + shift; i--)
		{
			swap(a[i],a[i-1]);
		}
	}
}

int main()
{
	int m,num,shift;
	cin >> n >> m;
	init(n);
	for(int i = 0;i < m; i++)
	{
		cin >> num >> shift;
		int pos = find(num);
		swap2(pos,shift);
	}
	for(int j = 1;j <= n; j++)
		cout << a[j] << " ";
	cout << endl;
}
