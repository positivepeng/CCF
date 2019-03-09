#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int a[27];
int reached[27];
string args[27];

int main()
{
	string str;
	cin>>str;
	for(int i = 0; i < str.length(); i++)
	{
		if(i+1 < str.length() && str[i+1] == ':') 
		{
			a[str[i]-'a'] = 2;
			i++;
	
		else
		{
			a[str[i]-'a'] = 1;
		}
	}
	int n;
	cin >> n;
	getchar();
	for(int i=0; i<n; i++)
	{
		getline(cin,str);
		stringstream stream(str);
		string commandName;
		stream >> commandName;
		string cmd;
		while(stream >> cmd)
		{
			//命令格式不规范 
			if(cmd.length() != 2)break;
			if(cmd[0]=='-' && cmd[1] >= 'a' && cmd[1] <= 'z') {}
			else break;
			
			int index = cmd[1]-'a';
			if(a[cmd[1]-'a'] == 2)
			{
				string as;
				if(stream>>as)
				{
					reached[index] = 1+i;    //省的标记了
					args[index]=as;
				}
				else break;
			}
			else if(a[cmd[1]-'a'] == 1)
			{
				reached[index] = 1+i;     //省的标记了
			}
			else
				break;
		}

		cout << "Case " << i+1 << ":";
		for(int j=0; j<26; j++)
		{
			if(reached[j] == i+1)
			{
				if(args[j] != "")
					cout << " -" << (char)(j+'a') << " " << args[j];
				else
					cout << " -" << (char)(j+'a');
			}
		}
		cout << endl;
	}
	return 0;
}

