#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

set<string> perms;
map<string,int> max_level;           //有等级就是最高等级，没有就是-1
map<string,map<string,int> > roles;
map<string,map<string,int> > peoples;

int num_of_auth;
int num_of_role;
int num_of_people;
int num_of_query;
int debug = 4;

void print_map(map<string,int> m)
{
	for(map<string,int>::iterator it = m.begin(); it != m.end(); it++)
			cout << (*it).first << " " << (*it).second << " ";
	cout << endl;
}


void read_level()
{
	cin >> num_of_auth;
	string s;
	for(int i = 0;i < num_of_auth; i++)
	{
		cin >> s;
		int k = s.find(":");
		if(k == -1)
			max_level[s] = -1;
		else
			max_level[s.substr(0,k)] = s[s.size()-1]-'0';
	}
	if(debug <= 1)
	{
		cout << "max_level " << endl;
		print_map(max_level);
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
		
		if(debug <= 2)
		{
			cout << "ROLE NAME : " << role_name << endl;
			print_map(tmp);
		}
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
				if(it->second != -1)
					tmp[it->first] = max(tmp[it->first],it->second);
				else
					tmp[it->first] = -1;
			}
		}
		peoples[people_name] = tmp;
		
		if(debug <= 3)
		{
			cout << "PEOPLE NAME : " << people_name << endl;
			print_map(tmp);
		}
	}
}

void query()
{
	/*
	给出系统中用户、角色和权限的描述信息，你的程序需要回答多个关于用户和权限的查询。
	查询可分为以下几类：
　　不分等级权限的查询：
		如果权限本身是不分等级的，则查询时不指定等级，返回是否具有该权限；
　　分等级权限的带等级查询：
		如果权限本身分等级，查询也带等级，则返回是否具有该类的该等级权限；
　　分等级权限的不带等级查询：
		如果权限本身分等级，查询不带等级，则返回具有该类权限的等级；如果不具有该类的任何等级权限，则返回“否”。
	*/
	cin >> num_of_query;
	string people_name,s;
	for(int i = 0;i < num_of_query; i++)
	{
		cin >> people_name >> s;
		
		//区分是否有等级 
		int colon_pos = s.find(":"),plevel;
		string perm_name;
		if(colon_pos != -1)
		{
			perm_name = s.substr(0,colon_pos);
			plevel = s[s.size()-1]-'0';
		}
		else
		{
			perm_name = s;
			plevel = -1;
		}
		
		//该权限有等级 
		if(max_level[perm_name] != -1)
		{
			//未指定等级 
			if(plevel == -1) 
			{
				if(peoples[people_name].count(perm_name) == 1) 
					cout << peoples[people_name][perm_name] << endl;
				else
					cout << "false" << endl;
			}
			else   //指定等级 
			{
				if(peoples[people_name].count(perm_name) == 1 && 
					peoples[people_name][perm_name] >= plevel)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			}
		}
		//该权限无等级
		else
		{
			if(peoples[people_name].count(perm_name) == 1)
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
	}
}

int main()
{
	read_level();
	read_role();
	read_people();
	query();
	return 0;
}
