#include<iostream>
#include<string>
#include<vector>
using namespace std;

int strict_match;

int main()
{
	int n;
	string tar,tmp1;
	vector<string> ans;
	cin >> tar;

	cin >> strict_match;
	
	
	int ts = tar.size();
	
	if(strict_match == 0)
	{
		for(int i = 0;i < ts; i++)
		{
			if(tar[i] >= 'A' && tar[i] <= 'Z')
				tar[i] = tar[i] - 'A' + 'a';
		}
	}
	
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		cin >> tmp1;
		string tmp = tmp1;
		if(strict_match == 0)
		{
			for(int i = 0;i < tmp.size(); i++)
			{
				if(tmp[i] >= 'A' && tmp[i] <= 'Z')
					tmp[i] = tmp[i] - 'A' + 'a';
			}
		}
		
		for(int j = 0;j <= tmp.size() - ts; j++)
		{
			string sub = tmp.substr(j,ts);
			if(tmp[j] == tar[0] && sub.compare(tar) == 0)
			{
				ans.push_back(tmp1);
				break;
			}
		}
	}
	for(int i = 0;i < ans.size(); i++)
		cout << ans[i] << endl;
}
