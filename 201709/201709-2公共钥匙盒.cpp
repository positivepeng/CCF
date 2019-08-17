#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define GET 0
#define RETURN 1
using namespace std;

struct action
{
	int type;
	int num;
	int time;
	action(int t,int n,int e)
	{
		type = t;
		num = n;
		time = e;
	}
	action(){}
	
};

vector<action>  actions;
int a[10005];
int m,n;

void init()
{
	for(int i = 1;i <= n; i++)
		a[i] = i;
}

bool cmp(action &a,action& b)
{
	if(a.time == b.time)
	{
		if(a.type == RETURN && b.type == RETURN)
			return a.num < b.num;
		if(a.type == RETURN)
			return true;
		if(b.type == RETURN)
			return false;
	}
	return a.time < b.time;
}

void get_key(int num)
{
	for(int i = 1;i <= n; i++)
	{
		if(a[i] == num)
			a[i] = -1;
	}
}

void return_key(int num)
{
	for(int i = 1;i <= n; i++)
	{
		if(a[i] == -1)
		{
			a[i] = num;
			return ;
		}
	}
}


int main(int argc, char const *argv[])
{
	cin >> n >> m;
	int num,take_time,last;
	for(int i = 0;i < m; i++)	 
	{
		cin >> num >> take_time >> last;
		actions.push_back(action(GET,num,take_time));
		actions.push_back(action(RETURN,num,take_time+last));
	}
	
	init();
	
	sort(actions.begin(),actions.end(),cmp);
	
//	for(int i = 0;i < actions.size(); i++)
//	{
//		cout << actions[i].type << " " << actions[i].num << " " << actions[i].time << endl;
//	}
	
	for(int i = 0;i < actions.size(); i++)
	{
		if(actions[i].type == GET)
			get_key(actions[i].num);
		
		if(actions[i].type == RETURN)
			return_key(actions[i].num);
	}
	
	for(int i = 1;i <= n; i++)
	{
		cout << a[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}

