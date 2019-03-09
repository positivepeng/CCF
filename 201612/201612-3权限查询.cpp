#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

set<string> perms;
map<string,int> max_level;           //�еȼ�������ߵȼ���û�о���-1
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
	����ϵͳ���û�����ɫ��Ȩ�޵�������Ϣ����ĳ�����Ҫ�ش��������û���Ȩ�޵Ĳ�ѯ��
	��ѯ�ɷ�Ϊ���¼��ࣺ
�������ֵȼ�Ȩ�޵Ĳ�ѯ��
		���Ȩ�ޱ����ǲ��ֵȼ��ģ����ѯʱ��ָ���ȼ��������Ƿ���и�Ȩ�ޣ�
�����ֵȼ�Ȩ�޵Ĵ��ȼ���ѯ��
		���Ȩ�ޱ���ֵȼ�����ѯҲ���ȼ����򷵻��Ƿ���и���ĸõȼ�Ȩ�ޣ�
�����ֵȼ�Ȩ�޵Ĳ����ȼ���ѯ��
		���Ȩ�ޱ���ֵȼ�����ѯ�����ȼ����򷵻ؾ��и���Ȩ�޵ĵȼ�����������и�����κεȼ�Ȩ�ޣ��򷵻ء��񡱡�
	*/
	cin >> num_of_query;
	string people_name,s;
	for(int i = 0;i < num_of_query; i++)
	{
		cin >> people_name >> s;
		
		//�����Ƿ��еȼ� 
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
		
		//��Ȩ���еȼ� 
		if(max_level[perm_name] != -1)
		{
			//δָ���ȼ� 
			if(plevel == -1) 
			{
				if(peoples[people_name].count(perm_name) == 1) 
					cout << peoples[people_name][perm_name] << endl;
				else
					cout << "false" << endl;
			}
			else   //ָ���ȼ� 
			{
				if(peoples[people_name].count(perm_name) == 1 && 
					peoples[people_name][perm_name] >= plevel)
					cout << "true" << endl;
				else
					cout << "false" << endl;
			}
		}
		//��Ȩ���޵ȼ�
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
