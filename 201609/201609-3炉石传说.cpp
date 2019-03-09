#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct hero
{
	int harm,health,islive;
	hero(int h,int hea,int isl)
	{
		harm = h;
		health = hea;
		islive = isl;
	}
	hero()
	{
		islive = 0;
	}
};

int n;
int turn = 0;          //一个为0号玩家 

vector<hero> v0(8);
vector<hero> v1(8); 

int win0 = 0;                   //先手胜 
int win1 = 0;                   //后手胜 

void init()
{
	for(int i = 0;i < 8; i++)
	{
		v0[i].islive = 0;
		v1[i].islive = 0;
	}
}

void call(int pos,int harm,int health)
{
	if(turn == 0)
	{
		//腾出pos处的位置 
		for(int i = 7;i > pos; i--)
			v0[i] = v0[i-1];
		v0[pos] = hero(harm,health,1);
	}
	else
	{
		//腾出pos处的位置 
		for(int i = 7;i > pos; i--)
			v1[i] = v1[i-1];
		v1[pos] = hero(harm,health,1);
	}
}

void attack(int attacker,int defender)
{
	if(turn == 0)      //v0攻击v1 
	{
		v0[attacker].health -= v1[defender].harm;
		v1[defender].health -= v0[attacker].harm;	
		
		if(defender == 0 && v1[defender].health <= 0)     //杀死英雄 
		{
			win0 = 1;
			return ;
		}
		if(v1[defender].health <= 0)                    //守卫者死 
		{
			for(int i = defender;i <= 6; i++)
			{
				v1[i] = v1[i+1];
			}
			v1[7].islive = 0;
		}
		if(v0[attacker].health <= 0)                    //攻击者死 
		{
			for(int i = attacker;i <= 6; i++)
			{
				v0[i] = v0[i+1];
			}
			v0[7].islive = 0;
		}
	}
	else            //v1攻击v0 
	{
		v1[attacker].health -= v0[defender].harm;
		v0[defender].health -= v1[attacker].harm;
		
		if(defender == 0 && v0[defender].health <= 0)     //杀死英雄 
		{
			win1 = 1;
			return ;
		}
		if(v0[defender].health <= 0)                       //守卫者死 
		{
			for(int i = defender;i <= 6; i++)
			{
				v0[i] = v0[i+1];
			}
			v0[7].islive = 0;
		}
		if(v1[attacker].health <= 0)                    //攻击者死 
		{
			for(int i = attacker;i <= 6; i++)
			{
				v1[i] = v1[i+1];
			}
			v1[7].islive = 0;
		}
	}

} 


int main()
{
	cin >> n;
	string s;
	
	init();
	
	//英雄入队
	v0[0] = hero(0,30,1);        //先手 
	v1[0] = hero(0,30,1);        //后手 
	
	for(int i = 0;i < n; i++)
	{
		cin >> s;
		if(s.compare("summon") == 0)
		{
			int pos,harm,health;
			cin >> pos >> harm >> health;
			call(pos,harm,health);
		}
		if(s.compare("attack") == 0)
		{
			int attacker,defender;
			cin >> attacker >> defender;
			attack(attacker,defender);
		}
		if(s.compare("end") == 0)
		{
			turn = 1 - turn;
		}
	}
	
	if(win0 == 0 && win1 == 0) 
		cout << 0 << endl;
	else if(win0 == 1)
		cout << 1 << endl;
	else if(win1 == 1)
		cout << -1 << endl;
		
	cout << v0[0].health << endl;
	
	int cnt0 = 0;
	for(int i = 1;i < 8; i++)
	{
		if(v0[i].islive == 1)
			cnt0++;
	}
	cout << cnt0 << " ";
	for(int i = 1;i < 8; i++)
	{
		if(v0[i].islive == 1)
			cout << v0[i].health << " ";
	}
	cout << endl;
	
	cout << v1[0].health << endl;
	int cnt1 = 0;
	for(int i = 1;i < 8; i++)
	{
		if(v1[i].islive == 1)
			cnt1++;
	}
	cout << cnt1 << " ";
	for(int i = 1;i < 8; i++)
	{
		if(v1[i].islive == 1)
			cout << v1[i].health << " ";
	}
	cout << endl;
	return 0;
} 
