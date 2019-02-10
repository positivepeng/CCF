#include<iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

int mark[150];
string arg[150];

vector<string> splitCommand(string s)
{
	vector<string> ans;	
	if(s.size() == 0)   return ans;
	
	int curr = 0;
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			ans.push_back(s.substr(curr,i-curr));
			curr = i + 1;
		}
	}
	ans.push_back(s.substr(curr,s.size() - curr));
	return ans;
}


bool isCmd(string s)
{
	if(s.size() < 2)  return false;
	if(s[0] == '-' && s[1] >= 'a' && s[1] <= 'z' && s.size() == 2)   return true;
	return false;
}

int main()
{
	string line,command;
	int n;
	
	cin >> line;
	memset(mark,-1,sizeof(mark));
	//标记是否需要参数 
	
	for(int i = 0;i < line.size(); i++) 
	{
		if(i + 1 < line.size() && line[i+1] == ':')	
			mark[line[i]] = 1;   //需要参数
		else
			mark[line[i]] = 0; 
	}
	
	cin >> n;
	vector<string> cs;
	for(int i = 1;i <= n; i++)
	{
		if(i == 1) cin.get();
		getline(cin,command);
	
		cs = splitCommand(command);
		
		for(int j = 0;j < 150; j++)		arg[j] = " ";
		
		for(int j = 1;j < cs.size(); j++)
		{
			string s1 = cs[j];
			string s2 = j < cs.size() - 1 ? cs[j+1] : "";
			if(isCmd(s1))
			{
				if(!isCmd(s2) && s2 != "" && mark[s1[1]] == 1)
				{
					arg[s1[1]] = s2;
					j++;
				}
				else if(mark[s1[1]] == 0)
				{
					arg[s1[1]] = "NOARG";
				}
				else 
					break;
			}
			else 
				break;
		}

		
		cout << "Case " << i << ":";
		if(cs.size() >= 1 && cs[0][0] == '-')     //+10分，命令不以-开头 
		{
			cout << endl;
			continue;
		} 
		for(char j = 'a';j<= 'z'; j++)
		{
			if(arg[j].compare(" ") != 0)
			{
				cout << " " << "-" << j;
				if(mark[j] == 1)
					cout << " " << arg[j];
			}
		}
		cout << endl;
		
	}
	
	
	
}
