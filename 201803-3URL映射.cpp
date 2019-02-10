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
typedef pair<string,string> P;
int valid[300];
int n,m;

template<typename Out>
void split(const  string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}


void init()
{
	memset(valid,0,sizeof(valid));
	for(int i = 0;i <= 9; i++)
		valid['0'+i] = 1;
	for(char c = 'a';c <= 'z'; c++)
		valid[c] = 1;
	for(char c = 'A';c <= 'Z'; c++)
		valid[c] = 1;
	valid['/'] = valid['-'] = valid['_'] = valid['.'] = 1;
}

bool isValid(string s)
{
	for(int i = 0;i < s.size(); i++)
	{
		if(valid[s[i]] == 0)
			return false;
	}
	return true;
}

bool isNum(string s)
{
	for(int i = 0;i < s.size(); i++)
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return false;
	}
	return true;
}

bool match(string s,P role)
{
	string tar = role.first;
	string name = role.second;
	
	s = s.substr(1,s.size()-1);
	tar = tar.substr(1,tar.size()-1);
	
	vector<string> s_splits = split(s,'/');
	vector<string> tar_splits = split(tar,'/');
	
//	cout << "source " << endl;
//	for(int i = 0;i < s_splits.size(); i++)
//		cout << s_splits[i] << " " << s_splits[i].size() << endl;
//	
//	cout << "tar " << endl;
//	for(int i = 0;i < tar_splits.size(); i++)
//		cout << tar_splits[i] << " " << tar_splits[i].size() << endl;
	if(s_splits.size() != tar_splits.size())	
		return false;
	
	vector<string> ans;
	vector<string> output;
	int match_all = 0;
	
	for(int i = 0;i < s_splits.size(); i++)
	{
		if(s_splits[i].compare(tar_splits[i]) == 0)
			continue;
		else if(tar_splits[i].compare("<int>") == 0)
		{
			if(isNum(s_splits[i]))
			{
				output.push_back(s_splits[i]);
				match_all = 1;
			}
			else
			{
				match_all = 0;
				break;
			}		
		} 
		else if(tar_splits[i].compare("<str>") == 0)
		{
			output.push_back(s_splits[i]);
			match_all = 1;
		}
		else if(tar_splits[i].compare("<path>") == 0)
		{
			string temp = "";
			for(i;i < s_splits.size(); i++)
			{
				if(i != s_splits.size()-1)
					temp = temp + s_splits[i] + "/";
				else
					temp = temp + s_splits[i];
			}
			output.push_back(temp);
			match_all = 1;
		}
	}
	if(match_all == 1)
	{
		cout << name << " ";
		for(int i = 0;i < output.size(); i++)
		{
			cout << output[i] << " ";
		} 
	}
		
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	vector<P> names;
	string s1,s2;
	for(int i = 0;i < n; i++)
	{
		cin >> s1 >> s2;
		names.push_back(make_pair(s1,s2));
	}
	
	init();
	
	for(int i = 0;i < m; i++)
	{
		cin >> s1;
		cout << s1 << endl;
		int flag = 0;
		if(!isValid(s1))
			cout << 404 << endl;
		else
		{
			for(int j = 0;j < names.size(); j++)
			{
				if(match(s1,names[j]))
				{
					flag = 1;
					continue;
				}
			}
		}
		if(flag == 0)
			cout << 404 << endl;
	}
	
	return 0;
}

