#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<windows.h>

using namespace std;
int n,m;
vector<string> lines;
string str;
map<string,string> dict;

void getKeyValue(string s,string& key,string& value)
{
	int space = s.find(" ");
	key = s.substr(0,space);
	value = s.substr(space+2,s.size()-space-3);
}


void Replace()
{
	for(int i = 0;i < lines.size(); i++)
	{
		string& s = lines[i];
		int begin = 0;
		
		while(1)
		{
			int left = s.find("{{ ",begin);
			if(left == -1) 
				break;
			
			int right = s.find(" }}",begin);
			string name = s.substr(left+3,right - 1 - (left + 3) + 1);
			
			s = s.replace(left,name.size() + 6,dict[name]);
			
			begin = left + dict[name].size();
		}
	}
}


int main()
{
	cin >> n >> m;
	cin.ignore();
	for(int i = 0;i < n; i++)
	{
		getline(cin,str);
		lines.push_back(str);
	}
		
	string line,key,value;
	for(int i = 0;i < m; i++)
	{
		getline(cin,line);
		getKeyValue(line,key,value);
		dict[key] = value;
	}
	
	Replace();
	
	for(int i = 0;i < lines.size(); i++)
	{
		cout << lines[i] << endl;
	}
	
} 
