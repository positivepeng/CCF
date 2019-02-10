#include<iostream>
using namespace std;


int tax(int n)
{
	if(n <= 3500)    return 0;
	
	int A = n - 3500;
	
	int pay = 0;
	
	if(A > 80000)
	{
		pay += (A - 80000) * 0.45 ;
		pay += 250 * 35;
		pay += 2000 * 3;
		pay += 260 * 25;
		pay += 450 * 2;
		pay += 300 * 1;
		pay += 15 * 3;
	}
	else if(A > 55000)
	{
		pay += (A - 55000) * 0.35 ;
		pay += 2000 * 3;
		pay += 260 * 25;
		pay += 450 * 2;
		pay += 300 * 1;
		pay += 15 * 3;
	}
	else if(A > 35000)
	{
		pay += (A - 35000) * 0.3 ;
		pay += 260 * 25;
		pay += 450 * 2;
		pay += 300 * 1;
		pay += 15 * 3;
	}
	else if(A > 9000)
	{
		pay += (A - 9000) * 0.25 ;
		pay += 450 * 2;
		pay += 300 * 1;
		pay += 15 * 3;
	}
	else if(A > 4500)
	{
		pay += (A - 4500) * 0.2 ;
		pay += 300 * 1;
		pay += 15 * 3;
	}
	else if(A > 1500)
	{
		pay += (A - 1500) * 0.1;
		pay += 15 * 3; 
	}
	else
	{
		pay += A  * 0.03;
	}
	
	return pay;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 100;i <= 1000000; i+=100)
	{
		if(i - tax(i) == n)
		{
			cout << i << endl;
			return 0;
		}
	 } 
}
