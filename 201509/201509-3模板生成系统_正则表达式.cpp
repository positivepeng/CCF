#include <bits/stdc++.h>
using namespace std;

void getKeyValue(string s,string& key,string& value)
{
	int space = s.find(" ");
	key = s.substr(0,space);
	value = s.substr(space+2,s.size()-space-3);
}

string Replace(string s,map<string,string>& mp)
{
	string ans="",target;
	regex double_brace("\\{\\{ (.*?) \\}\\}");
	smatch match_result;
	while(1)
	{
		if(regex_search(s,match_result,double_brace))
		{
			target = match_result[0].str();
			ans += match_result.prefix();
			ans += mp[target.substr(3,target.size()-6)];
			s = match_result.suffix();
		}
		else
		{
			ans += s;
			break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m;
	string temp,s,key,value;
	map<string,string> mp;
	
	cin >> n >> m;
	cin.ignore();
	for(int i = 0;i < n; i++)
	{
		getline(cin,temp);
		s += temp + "\n";
	}
	for(int i = 0;i < m; i++)
	{
		getline(cin,temp);
		getKeyValue(temp,key,value);
		mp[key] = value;
	}
	cout << Replace(s,mp) << endl;
	return 0;
}


