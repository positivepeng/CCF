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

typedef struct line
{
	int level;
	string tag,attr;
}line;

int debug = 0;

bool isEqual(string s1,string s2) 
{
	if(s1.size() != s2.size())
		return false;
	if(s1[0] == s2[0] && s1[0] == '#')          //id大小写敏感 
	{
		for(int i = 1;i < s1.size(); i++)
		{
			if(s1[i] != s2[i])
				return false;
		}
	}
	else                                       //标签大小写不敏感 
	{
		for(int i = 0;i < s1.size(); i++)
			if(tolower(s1[i]) != tolower(s2[i]))
				return false;
	}
	return true;
}

int getLevel(string s)
{
	int ans = 0;
	while(s[ans] == '.')
		ans++;
	return ans / 2;
}

string getTag(string s)
{
	int dot_end = 0;
	while(s[dot_end] == '.')
		dot_end++;

	int k = s.find(" ",dot_end);
	return s.substr(dot_end,k-dot_end);
}

string getAttr(string s)
{
	int k = s.find("#");
	if(k == -1)
		return "";
	else
		return s.substr(k,s.size()-k);
}

vector<string> parse(string s)
{
	string temp;
	stringstream ss;
	
	ss.str(s);
	vector<string> ans;
	while(!ss.eof())
	{
		ss >> temp;
		ans.push_back(temp);
	}
	return ans;
}

bool match_line(string& s,line& L)
{
	return isEqual(s,L.tag) || isEqual(s,L.attr);
 } 

bool match_ancestor(vector<string> tags,vector<line>& infos,int start,int max_level)
{
	for(int i = start;i >= 0;i--)
	{
		if(infos[i].level < max_level && match_line(tags[tags.size()-1],infos[i]))
		{
			max_level = infos[i].level;
			tags.pop_back();
			if(tags.size() == 0)
				return true;
		}
	}
	return false;
}

vector<int> match(string s,vector<line> infos)
{
	vector<string> tars = parse(s);
	vector<int> ans;
	
	if(tars.size() == 1)
	{
		for(int i = 0;i < infos.size(); i++)
		{
			if(match_line(tars[0],infos[i]))
				ans.push_back(i+1);
		}
		return ans;
	}
	else
	{
		// 多级标签匹配,从末尾开始匹配
		for(int i = 0;i < infos.size(); i++)
		{
			vector<string> temp_tars = tars;
			if(match_line(temp_tars[temp_tars.size()-1],infos[i]))   //匹配成功 
			{
				temp_tars.erase(temp_tars.end()-1);
				if(match_ancestor(temp_tars,infos,i,infos[i].level))   //匹配祖先标签 
					ans.push_back(i+1);
			} 
		}
	}
	
}

int main(int argc, char const *argv[])
{
	int n,m;
	string s;
	vector<string> lines;
	cin >> n >> m;
	cin.ignore();
	
	for(int i = 0;i < n; i++) 
	{
		getline(cin,s);       
		lines.push_back(s);
	}
	
	vector<line> infos(lines.size());
	
	for(int i = 0;i < lines.size(); i++)
	{
		infos[i].level = getLevel(lines[i]);
		infos[i].tag = getTag(lines[i]);
		infos[i].attr = getAttr(lines[i]);
		if(debug == 1)
			cout << infos[i].level << "|" << infos[i].tag <<  "|" << infos[i].attr << endl;	
	}
	
	vector<int> ans;
	for(int i = 0;i < m; i++)
	{
		getline(cin,s);
		
		ans = match(s,infos);
		
		cout << ans.size();
		for(int j = 0;j < ans.size(); j++)
			cout << " " << ans[j];
		cout << endl;
	}
	return 0;
}


