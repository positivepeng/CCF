#include<iostream>
#include<string> 
#include<vector>
#include<cmath>
#include<map>
#include<cstdio>
#include<set>
#define BUY 0
#define SELL 1
#define CANCEL 2
using namespace std;
typedef long long ll;

struct line
{
	int type;
	int price;
	int amount;
	int valid;
	line(int t,int p,int a,int v) : type(t),price(p),amount(a),valid(v){}
};

vector<line> a;
set<int> ps;
map<int,int> times;

ll deal_amount(double price)
{
	ll buy_amount = 0;
	ll sell_amount = 0;
	for(int i = 0;i < a.size(); i++)
	{
		if(a[i].valid == 1 && a[i].type != CANCEL)
		{
			if(a[i].type == BUY && a[i].price >= price)
				buy_amount += a[i].amount;
				
			if(a[i].type == SELL && a[i].price <= price)
				sell_amount += a[i].amount;
		}
	}
	return min(buy_amount,sell_amount);
}

void solve()
{
	ll deal = 0;
	double deal_p = 0;
	
	for(set<int>::iterator it = ps.begin();it != ps.end(); it++)
	{
		int price = *it;
		ll amount = deal_amount(price);
		if(amount >= deal)
		{	
			deal = amount;
			deal_p = (double)price / 100;
		}
	}
	
	printf("%.2lf",(double)deal_p);
	cout << " " << deal << endl;
}


int main()
{
	string s;
	double price;
	int amount;

	while(cin >> s)
	{
//		if(s.compare("stop") == 0)
//			break;
		if(s.compare("cancel") == 0)
		{
			int num;
			cin >> num;
			a.push_back(line(CANCEL,-1,-1,0));
			a[num-1].valid = 0;
			if(times[a[num-1].price] > 1)
				times[a[num-1].price] -= 1;
			else if(times[a[num-1].price] == 1)
			{
				times[a[num-1].price] = 0;
				ps.erase(a[num-1].price);
			}
		} 
		
		if(s.compare("buy") == 0)
		{
			cin >> price >> amount ;
			ps.insert(price*100);
			times[price*100] += 1;
			a.push_back(line(BUY,price*100,amount,1));
		}
		
		if(s.compare("sell") == 0)
		{
			cin >> price >> amount ;
			ps.insert(price*100);
			times[price*100] += 1;
			a.push_back(line(SELL,price*100,amount,1));
		}
	}
	
//	for(int i = 0;i < a.size(); i++) 
//	{
//		cout << a[i].type << " " << a[i].valid << endl;
//	}
	
	solve();
	//cout << solve() << endl;;
 } 
