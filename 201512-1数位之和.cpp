#include<iostream>
#include<string>
using namespace std;
int main()
{
	int sum  =0;
	string s;
	cin >> s;
	for(int i = 0;i < s.size(); i++)
		sum += s[i] - '0';
	cout << sum << endl;
}
