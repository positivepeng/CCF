#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include <iterator>
#include <set>
#include <map>
using namespace std;

typedef struct json
{
	map<string,string> value;
	map<string,json*> next;
}json;

int debug = 0;

string removeSlash(string s)
{
	vector<char> s_ans;
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == '\\')
			s_ans.push_back(s[++i]);
		else
			s_ans.push_back(s[i]);
	}
	string ans(s_ans.begin(),s_ans.end());
	return ans;
}

string removeChar(string s,char start_char,char end_char)
{
	if(s.find(start_char) == -1)
		return s;
	string ans;
	int L = 0;
	int R = s.size()-1;
	while(s[L] != start_char)
		L++;
	while(s[R] != end_char)
		R--;
	
	return s.substr(0,L) + s.substr(L+1,R-L-1) + s.substr(R+1,s.size()-1-R);
}
json* parse(string s)
{
	if(debug == 1)
		cout << "parsing " << s << endl << endl;
	
	json* ans = new json;
	
	if(s.size() == 0)
		return ans;
	
	stringstream ss;
	ss.clear();
	ss.str(s);
	
	string k,v,temp;
	string next_level;
	
	while(1)
	{
		ss >> k >> v;
		if(ss.fail()) 	break;
		if(debug == 1)
			cout << "read k v [" << k << "|" << v << "]" << endl;
		
		//去除转义 
		if(k.find('\\') != -1)
			k = removeSlash(k);
		//去除左右两端的引号 
		k = removeChar(k,'"','"');
		
		if(v == "{")
		{
			next_level = "";
			int num_left_brace = 0;
			while(1)
			{
				ss >> temp;
				if(temp == "}" && num_left_brace == 0) 
					break;
				else if(temp == "{")
					num_left_brace += 1;
				else if(temp == "}")
					num_left_brace -= 1;
				next_level += " " + temp;
			}
			
			ans->next[k] = parse(next_level);
			if(debug == 1)
				cout << "next_level return " << k << endl;	
		}
		else
		{
			if(v.find('\\') != -1)
				v = removeSlash(v);

			v = removeChar(v,'"','"');
			
			ans->value[k] = v;
		}
	}
	
	return ans;
		
}


int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	cin.ignore();
	
	string lines = "",line,all = "";
	for(int i = 0;i < n; i++) 
	{
		getline(cin,line);
		lines += line;
	}
	
	// 大括号两边加空格 
	for(int i = 0;i < lines.size(); i++)
	{
		string t = " ";
		t[0] = lines[i];
		if(lines[i] == '{' || lines[i] == '}')
			all += " " + t + " ";
		else 
			all += t;
	}
	
	//去除字符串中的,: 
	for(int i =  0;i < all.size(); i++)
	{
		if(all[i] == ',' || all[i] == ':')
			all[i] = ' ';
	}
	
	//去除最外层的大括号 
	if(all.find("{") != -1)
		all = removeChar(all,'{','}');
	 
	json* final = parse(all);
	
	if(debug == 2)
	{
		//final = final->next["test"];
		for(map<string,string>::iterator it = final->value.begin(); it != final->value.end(); it++)
			cout << (*it).first << " " << (*it).second << endl;
	}
	
	string temp,s;
	for(int i = 0;i < m; i++) 
	{
		json* root = final;
		cin >> s;
		for(int i = 0;i < s.size(); i++)
		{
			if(s[i] == '.')
				s[i] = ' ';
		}
		
		stringstream ss;
		ss.str(s);
		
		while(1)
		{
			ss >> temp;
			//cout << temp << endl;
			if(ss.fail())  break;
			
			if(root->value.count(temp) == 1)
			{
				cout << "STRING " << root->value[temp] << endl;
				break;
			}
			else if(root->next.count(temp) == 1)
			{
				string vtemp;
				if(ss.eof())  
				{
					cout << "OBJECT" << endl;
					break;
				}
				else
				{ 
					ss << vtemp;
					root = root->next[temp];
				}
			}
			else 
			{
				cout << "NOTEXIST" << endl;
				break;
			}
		}
	}
	return 0;
}



