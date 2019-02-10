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

void split(string& line)
{
	//寻找第一个空格
	int i = 0;
	while(line[i] != ' ')  
		i++;
	
	int lineSize = line.size();
	
	string key = line.substr(0,i);
	
	string word = line.substr(i+2,lineSize - i - 3);  //去除引号 
	
	//cout << key << " " << word << endl;
	
	dict[key] = word;
}


void change()
{
	for(int i = 0;i < lines.size(); i++)
	{
		string& s = lines[i];
		//cout << s << endl;
		int begin = 0;
		
		while(1)
		{
			int left = s.find("{{ ",begin);
			if(left == -1) 
				break;
			
			int right = s.find(" }}",begin);
			//cout << "left " << left << " right " << right << " " << right - 1 - (left + 3) + 1 << "     ";
			//cout << s.substr(left+3,right - 1 - (left + 3) + 1) << endl;
			string name = s.substr(left+3,right - 1 - (left + 3) + 1);
			
			s = s.replace(left,name.size() + 6,dict[name]);
			
			//cout << s << endl;
			
			begin = left + dict[name].size();
		}
	}
}


int main()
{
	cin >> n >> m;
	cin.get();
	for(int i = 0;i < n; i++)
	{
		getline(cin,str);
		lines.push_back(str);
		//cout << str << endl;
	}
	
	string key,word,line;
	
	for(int i = 0;i < m; i++)
	{
		getline(cin,line);
		split(line);
		dict[key] = word;
	}
	
	change();
	
	for(int i = 0;i < lines.size(); i++)
	{
		cout << lines[i] << endl;
	}
	
} 
