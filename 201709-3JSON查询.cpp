#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef struct json
{
	map<string,string> keys;
	set<string> keys_set;
	map<string,json*> next; 
	set<string> next_set;
}json;

int n,m;
int debug = 0;

string removeSlash(string &s)
{
	vector<char> s_ans;
	
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == '\\')
		{
			s_ans.push_back(s[++i]);
		}
		else
			s_ans.push_back(s[i]);
	}
	
	string ans(s_ans.begin(),s_ans.end());
	
	return ans;
}

string getKey(string& line)
{
	int end = line.find(":");
	string key = line.substr(1,end-2);
	return key;
}

void getKeyValue(string& line,string &key,string &value)
{
	int colon = line.find(":");
	int start = colon + 3;
	int end = line[line.size()-1] == ',' ? line.size()-3 : line.size()-2;
	
	string tKey = line.substr(1,colon-2);
	string tValue = line.substr(start,end-start+1);
	key = removeSlash(tKey);
	value = removeSlash(tValue);
	
	
	if(debug == 1)
	{
		cout << "input : " << line << endl;
		cout << "key: " << key << " value: " << value << endl;
	}
}

json* construct(vector<string>& lines)
{	
	json* root = new json;
	
	if(debug == 1)
	{
		cout << "current level" << endl;
		for(int i = 0;i < lines.size(); i++)
		{
			cout << lines[i] << endl;
		}
		cout << "*******************************" << endl;
	}
	
	for(int i = 1;i < lines.size()-1; i++)
	{
		if(debug == 1)
			cout << "analysis " << lines[i] << endl;
		
		if(lines[i][lines[i].size()-1] == '{' && lines.size() != 1)      //下一层开始 
		{
			string key = getKey(lines[i]);
			
			root->next_set.insert(key);
			
			vector<string> temp;
			if(debug == 1)
				cout << "next level: " << key << endl;
			
			temp.push_back("{");
			int j = i + 1;
			for(;j < lines.size()-1; j++)
			{
				if(lines[j].find("}") == -1)
				{
					temp.push_back(lines[j]);
				}
				else
					break;
			}
			temp.push_back("}");
			i = j;
			root->next[key] = construct(temp);
		}
		else
		{
			string key,value;
			getKeyValue(lines[i],key,value);
			root->keys_set.insert(key);
			root->keys[key] = value;
		}
	}
	
	return root;
}

void analysis(string s,json *root)
{
	vector<string> names;
	int curr = 0;
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == '.')
		{
			names.push_back(s.substr(curr,i-curr));
			curr = i+1;
		}
	}
	names.push_back(s.substr(curr,s.size()-curr));
	
	if(debug == 1)
	{
		for(int i = 0;i < names.size(); i++)
			cout << names[i] << " ";
		cout << endl;
	}
	
	if(names.size() == 1)
	{
		if(root->keys_set.count(names[0]) != 0)
			cout << "STRING " << root->keys[names[0]] << endl;
		else if(root->next_set.count(names[0]) != 0)
			cout << "OBJECT" << endl;
		else
			cout << "NOTEXIST"  << endl;
		return ;
	}
	
	for(int i = 0;i < names.size(); i++)
	{
		if(root->keys_set.count(names[i]) == 0 && root->next_set.count(names[i]) == 0)
		{
			cout << "NOTEXIST" << endl;
			return ;
		}
		else if(root->next_set.count(names[i]) != 0)
		{
			if(i == names.size()-1)
			{
				cout << "OBJECT" << endl;
				return ;
			}
			else
			{
				root = root->next[names[i]];
			}
		}
		else if(root->keys_set.count(names[i]) != 0 && i == names.size()-1)
		{
			cout << "STRING " << root->keys[names[i]] << endl;
			return ;
		}
	}
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	string s;
	vector<string> lines;
	
	cin.ignore();
	for(int i = 0;i < n; i++)
	{
		getline(cin,s);
		lines.push_back(s);
	}
	
	json *root = construct(lines);
	
	vector<string> check;
	for(int i = 0;i < m; i++)
	{
		getline(cin,s);
		check.push_back(s);
	}
	
	
	for(int i = 0;i < check.size(); i++)
	{
		string s = check[i];
		analysis(s,root);
	}
	
	return 0;
}

