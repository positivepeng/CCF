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
#include <ctype.h>
using namespace std;

typedef struct url
{
	string name,format;
	url(string n,string f)
	{
		name = n;
		format = f;
	}
	url(){};
}url;

int n,m;
int debug = 0;
vector<url> urls;

bool isValid(string s)
{
	//保证以斜杠开头。
	//其他合法字符还包括大小写英文字母、阿拉伯数字、减号 -、下划线 _ 和小数点 .
	for(int i = 0;i < s.size(); i++)//如果不是合法的 URL地址返回false 
	   if(s[i]!='/' && s[i]!='.' && s[i]!='-' && s[i]!='_' && !(isalpha(s[i])||isdigit(s[i])))
		return false;
	return true;
}

bool isNum(string s)
{
	for(int i = 0;i < s.size(); i++)
		if(s[i] < '0' || s[i] > '9')
			return false;
	return true;
}

string removeSlash(string s)
{
	string s1 = "",t = " ";
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == '/' && i == s.size()-1)
			s1 += " /";
		else if(s[i] == '/')
			s1 += " ";
		else
		{
			t[0] = s[i];
			s1 += t;
		}
	}
	return s1;
}

bool match(string s0,string st,vector<string>& args)
{
	/*
	以上 3 种参数都必须匹配非空的字符串。
	简便起见，题目规定规则中 <str> 和 <int> 前面一定是斜杠，
	后面要么是斜杠，要么是规则的结束（也就是该参数是规则的最后一部分）。
	而 <path> 的前面一定是斜杠，后面一定是规则的结束。无论是 URL 地址还是规则，
	都不会出现连续的斜杠。
	*/
	s0 = removeSlash(s0);
	st = removeSlash(st);
	
	if(debug == 1)
		cout << s0 << " " << st << endl << endl;
	
	stringstream ss0,sst;
	string t0,tt;
	
	ss0.str(s0);
	sst.str(st);
	
	while(1)
	{
		if(ss0.eof() && sst.eof())
			return true;
		
		if(ss0.eof() || sst.eof())
			return false;
		
		ss0 >> t0;
		
		if(debug == 1)
			cout << "匹配  " << t0 << endl; 
		
		sst >> tt;
		
		if(tt == t0)
			continue;
		else if(tt == "<int>")
		{
			if(isNum(t0))
			{
				args.push_back(to_string(stoi(t0)));
				if(debug == 1)
					cout << "isNum : " << to_string(stoi(t0)) << endl;
			}
			else 
				return false;
		}
		else if(tt == "<str>")
		{	
			if(t0 != "/" && t0.size() != 0)
			{
				args.push_back(t0);
				if(debug == 1)
					cout << "str : " << t0 << endl;
			}
			else
				return false;
		}
		else if(tt == "<path>")
		{
			if(t0 == "/")
				return false;
			
			vector<string> vs;
			vs.push_back(t0);
			while(!ss0.eof())
			{
				ss0 >> t0;
				vs.push_back(t0);
			}
			
			string temp = "";
			for(int i = 0;i < vs.size(); i++)
			{
				if(i == vs.size()-1 && vs[i] == "/")
					temp += "/";
				else
					temp += vs[i] + "/";
			}
			args.push_back(temp.substr(0,temp.size()-1));
		}
		else 	
			return false;
	}
}

int main()
{
	cin >> n >> m;
	string name,format,temp;
	for(int i = 0;i < n; i++)
	{
		cin >> format >> name;
		urls.push_back(url(name,format));
	}
	
	for(int i = 0;i < m; i++)
	{
		cin >> temp;
		int flag = 0;
		 
		for(int j = 0;j < urls.size(); j++)
		{
			vector<string> args;
			if(match(temp,urls[j].format,args))
			{
				flag = 1;
				//cout << "match "  << temp << " " << urls[j].format << endl;
				cout << urls[j].name;
				for(int k = 0;k < args.size(); k++)
					cout << " " << args[k];
				cout << endl;
				break;
			}
		}
		if(flag == 0)
			cout << 404 << endl;
	}
	
}
