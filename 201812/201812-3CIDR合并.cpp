#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include <iterator>
#include <set>
#include <list>
#include <map>
using namespace std;

typedef struct ip
{
	int d[32],len; 
	ip(vector<int> v)
	{
		if(v.size() != 5)
			cout << "ERROR SIZE != 5" << endl;
		for(int i = 0;i < 4; i++)
		{
			if(v[i] == 0)
			{
				for(int k = (i+1)*8;k >= i*8; k--) 
					d[k] = 0;
			}
			else
			{
				//t 表示到 d[i*8]到d[(i+1)*8]
				for(int k = (i+1)*8-1;k >= i*8; k--) 
				{
					d[k] = v[i] & 1;
					v[i] >>= 1;
				}
			}
		}
		len = v[4];
	}
	ip()
	{
		for(int i = 0;i < 32; i++) 
			d[i] = 0;
		len = 0;
	}
}ip;

int debug = 0;

ip stdip(string s)
{	
	int dot_count = 0,slash_count = 0;
	
	for(int i = 0;i < s.size(); i++)
	{
		if(s[i] == '.')
		{ 
			dot_count++;
			s[i] = ' ';
		} 
		if(s[i] == '/')
		{
			slash_count++;
			s[i] = ' ';
		}
	}
	
	if(dot_count == 3 && slash_count == 1)       //标准型 
	{
		stringstream ss;
		ss.str(s);
		
		int i = 0,temp;
		vector<int> v;
		while(i < 4)
		{
			ss >> temp;
			v.push_back(temp);
			i++;
		}
		ss >> temp;
		v.push_back(temp);
		return ip(v);
	}
	
	else if(dot_count < 3 && slash_count == 1)        //省略后缀型
	{
		stringstream ss;
		ss.str(s);
		
		int temp;
		vector<int> v;
		while(1)
		{
			ss >> temp;
			if(ss.eof())
			{
				while(v.size() < 4)
					v.push_back(0);
				v.push_back(temp);
				break;
			}
			else
				v.push_back(temp);
		}
		return ip(v);
	}
	else if(slash_count == 0)        //省略长度型 
	{
		stringstream ss;
		ss.str(s);
		
		int temp;
		vector<int> v;
		while(1)
		{
			ss >> temp; 
			v.push_back(temp);
			if(ss.eof())
				break;
		}
		int k = v.size();
		while(v.size() < 4)
			v.push_back(0);
		v.push_back(8*k);
		return ip(v);
	}
}

bool cmp(ip& ip1,ip& ip2)
{
	for(int i = 0;i < 32; i++)
	{
		if(ip1.d[i] < ip2.d[i])
			return true;
		else if(ip1.d[i] == ip2.d[i])
			continue;
		else
			return false;
	}
	return ip1.len < ip2.len;
}

bool a_include_b(ip& a,ip& b)
{
	for(int i = 0;i < a.len; i++)
	{
		if(a.d[i] != b.d[i])
			return false;
	}
	return true;
}

vector<ip> unite(vector<ip> ips) 
{
	vector<ip> ans;
	ip curr_ip = ips[0];
	
	for(int i = 1;i < ips.size(); i++)
	{
		if(a_include_b(curr_ip,ips[i]))
			continue;
		else
		{
			ans.push_back(curr_ip);
			curr_ip = ips[i];
		}
	}
	ans.push_back(curr_ip);
	return ans;
}

bool a_b_union(ip& a,ip& b) 
{
	if(a.len != b.len)
		return false;
	for(int i = 0;i < a.len-1; i++)
	{
		if(a.d[i] != b.d[i])
			return false;
	}
	return a.d[a.len-1] != b.d[a.len-1];
}

list<ip> marge_same_level(vector<ip> ips)
{
	list<ip> ipAddress;
	for(int i = 0;i < ips.size(); i++)	
		ipAddress.push_back(ips[i]);
	
	auto i = ipAddress.begin(),j = ipAddress.begin();
    for(++j;j!=ipAddress.end();)
	{
        if(a_b_union(*i,*j))
		{
            j=ipAddress.erase(j);
            --(*i).len;
            if(i!=ipAddress.begin())
			{
                --i;
                --j;
        	}
        }
		else
		{
            ++i;
            ++j;
        }
    }
    return ipAddress;
}

void printIp(ip &p)
{
	if(debug == 1)
	{
		for(int i = 1;i <= 32; i++) 
		{
			cout << p.d[i-1];	
			if(i % 8 == 0 && i != 32)
				cout << ".";
		}
		cout << "/" << p.len << endl;
	}
	if(debug == 0)
	{
		for(int i = 0;i < 4; i++)
		{
			int s = i*8,e = (i+1)*8-1,base = 1,t = 0;
			while(e >= s)
			{
				t += base * p.d[e];
				base *= 2;
				e--;
			}
			cout << t;
			if(i != 3)
				cout << ".";
		}
		cout << "/" << p.len << endl;
	}

} 

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s;
	
	vector<ip> ips(n);
	
	for(int i = 0;i < n; i++) 
	{
		cin >> s;
		ips[i] = stdip(s);
	}
	
	sort(ips.begin(),ips.end(),cmp);
	
	if(debug == 1)
	{
		cout << endl;
		for(int i = 0;i < ips.size(); i++)
			printIp(ips[i]);
		cout << endl;
	}
	
	ips = unite(ips);
	
	if(debug == 2)
	{
		for(int i = 0;i < ips.size(); i++)
			printIp(ips[i]);
	}
	
	if(debug == 1)
	{
		cout << endl;
		for(int i = 0;i < ips.size(); i++)
			printIp(ips[i]);
		cout << endl;
	}
	
	list<ip> list_ips = marge_same_level(ips);
	
	for(auto it = list_ips.begin(); it != list_ips.end(); it++)
	{
		ip p = (*it);
		for(int i = 0;i < 4; i++)
		{
			int s = i*8,e = (i+1)*8-1,base = 1,t = 0;
			while(e >= s)
			{
				t += base * p.d[e];
				base *= 2;
				e--;
			}
			cout << t;
			if(i != 3)
				cout << ".";
		}
		cout << "/" << p.len << endl;
	}
//	if(debug == 1)
//	{
//		cout << endl;
//		for(int i = 0;i < ips.size(); i++)
//			printIp(ips[i]);
//		cout << endl;
//	}
	
	return 0;
}


