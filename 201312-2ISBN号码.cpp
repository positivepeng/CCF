#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	vector<int> nums;
	cin >> s;
	
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] != '-' && i <= 10)
			nums.push_back(s[i] - '0');
	} 
	
	int sum = 0;
	for(int i = 0;i < nums.size(); i++) 
		sum += nums[i] * (i+1);
	
	char right_check = sum % 11 == 10 ? 'X' : '0' + sum % 11; 
	char check = s[s.size()-1];
	
	if(check == right_check)
	{
		cout << "Right" << endl;
	}
	else
	{
		s[12] = right_check;
		cout << s << endl;
	}
	
	
	return 0;
	
	
 } 
