#include<iostream>
using namespace std;


/*
	������ö�̬�滮˼�룬����״̬��Ѱ�ҵ��ƹ�ʽ
	����Ŀ�������ѵó���������2��ͷ����˶��������⣺
		ǰn�������ļ���״̬Ȼ��Ѱ�ҵ��ƹ�ʽ 
	ǰn�������ܵ�״̬�ֱ�Ϊ
	1.ֻ����2 
	2.����2.0
	3.����2.1 -->  ��ĿҪ��0.1.2.3��������֣���0��1ǰ����ǰn��������1�����޷��ٲ���0������״̬��ȥ 
	4.����2.3 
	5.����2.0.1 
	6.����2.0.3 
	7.����2.1.3  --> ��ȥ������ͬ�� 
	8.����2.0.1.3 
	
	�����Ͽɵó���ǰn������6�ֿ��ܵ�״̬���ֱ�Ϊ��
	S0:ֻ����2 
	S1:����2.0 
	S2:����2.3 
	S3:����2.0.1 
	S4:����2.0.3
	S5:����2.0.1.3
	
	Ѱ�ҵ��ƹ�ʽ��
	S0[n] = 1                       ֻ����2�����۶���λ����ֻ��һ����� 
	S1[n] = S1[n-1] * 2 + S0[n-1]   nλ����2.0����n-1λֻ����2.0��������һ��2����0��Ҳ������ǰn-1λֻ����2�ĺ����һ��0
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
