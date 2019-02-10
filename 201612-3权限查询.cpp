#include<iostream>
#include<map>
#include<vector>
#niclude<set>
using namespace std;

struct perm
{
	string name;
	int level;
	perm(){}
	perm(string n,int L)
	{
		name = n;
		L = level;
	}
};

const int maxn = 105;

set<string> perms;
map<string,int> max_level;           //有等级就是最高等级，没有就是-1
map<string,map<string,int> > roles;
map<string,map<string,int> > peoples;

int num_of_auth;
int num_of_role;
int num_of_people;
int num_of_query;

void read_level()
{
	cin >> num_of_auth;
	string s;
	for(int i = 0;i < num_of_auth; i++)
	{
		cin >> s;
		int k = s.find(":");
		if(k == -1)
		{
			perms.
			max_level[s] = -1;
		}
		else
		{
			max_level[s.substr(0,k)] = s[s.size()-1]-'0';
		}
	}
}

void read_role()
{
	cin >> num_of_role;
	string role_name;
	int cnt;
	for(int i = 0;i < num_of_role; i++)
	{
		cin >> role_name;
		cin >> cnt;
		map<string,int> tmp;
		for(int j = 0;j < cnt; j++)
		{
			string s;
			cin >> s;
			int k = s.find(":");
			if(k == -1)
				tmp[s] = -1;
			else
				tmp[s.substr(0,k)] = max(tmp[s.substr(0,k)],s[s.size()-1]-'0');
		}
		roles[role_name] = tmp;
	}
}

void read_people()
{
	cin >> num_of_people;
	
	string people_name,role_name;
	int cnt = 0;
	
	for(int i = 0;i < num_of_people; i++)
	{
		cin >> people_name >> cnt;
		map<string,int> tmp;
		for(int j = 0;j < cnt; j++)
		{
			cin >> role_name;
			for(map<string,int>::iterator it = roles[role_name].begin() ; it != roles[role_name].end(); it++)
			{
				tmp[it->first] = max(tmp[it->first],it->second);
			}
		}
		peoples[people_name] = tmp;
	}
}

void query()
{
	cin >> num_of_query;
	string name,s;
	for(int i = 0;i < num_of_query; i++)
	{
		cin >> people_name >> s;
		int k = s.find(":"),plevel;
		string p;
		if(k != -1)
		{
			p = s.substr(0,k);
			plevel = s[s.size()-1]-'0';
		}
		else
		{
			p = s;
			plevel = -1;
		}
		
		if() 
		if(max_level[p] == -1)    //是没有等级的命令
		{
		} 
		
		
	}
}

int main()
{
	int n;
	
}
