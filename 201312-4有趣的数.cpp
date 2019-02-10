#include<iostream>
using namespace std;


/*
	本题采用动态规划思想，定义状态，寻找递推公式
	由题目描述不难得出数必须由2开头，因此定义子问题：
		前n个数有哪几种状态然后寻找递推公式 
	前n个数可能的状态分别为
	1.只包含2 
	2.包含2.0
	3.包含2.1 -->  题目要求0.1.2.3都必须出现，且0在1前，若前n个包含了1后面无法再插入0，所以状态舍去 
	4.包含2.3 
	5.包含2.0.1 
	6.包含2.0.3 
	7.包含2.1.3  --> 舍去，理由同上 
	8.包含2.0.1.3 
	
	由以上可得出有前n个数有6种可能的状态，分别为：
	S0:只包含2 
	S1:包含2.0 
	S2:包含2.3 
	S3:包含2.0.1 
	S4:包含2.0.3
	S5:包含2.0.1.3
	
	寻找递推公式：
	S0[n] = 1                       只包含2的无论多少位数都只有一种情况 
	S1[n] = S1[n-1] * 2 + S0[n-1]   n位包含2.0可有n-1位只包含2.0的数最后加一个2或者0，也可以由前n-1位只包含2的后面加一个0
	S2[n] = S2[n-1] + S0[n-1]
	S3[n] = S3[n-1] * 2 + S1[n-1]
	S4[n] = S4[n-1] * 2 + S2[n-1] + s1[n-1]
	S5[n] = S5[n-1] * 2 + S4[n-1] + S3[n-1]
	
*/





int main()
{
	long long mod = 1000000007;
	int n;
	cin >> n;
	long long** states = new long long*[n+1];
	for (int i = 0; i <= n; i++)
		states[i] = new long long[6];
	for (int i = 0; i < 6; i++)
		states[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = i - 1;
		states[i][0] = 1;
		states[i][1] = (states[j][0] + states[j][1] * 2) % mod;
		states[i][2] = (states[j][0] + states[j][2]) % mod;
		states[i][3] = (states[j][1] + states[j][3] * 2) % mod;
		states[i][4] = (states[j][1] + states[j][2] + states[j][4] * 2) % mod;
		states[i][5] = (states[j][3] + states[j][4] + states[j][5] * 2) % mod;
	}
	cout << states[n][5] << endl;
	return 0;
}
