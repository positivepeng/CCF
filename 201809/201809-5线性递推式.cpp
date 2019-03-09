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
#include <list>
#define Q 998244353
using namespace std;
typedef unsigned long long ull;

ull k[100005];
ull m,L,R;
	
void solve() 
{
	list<ull> v;
	v.push_back(1);
	for(ull i = 1;i <= R; i++)
	{
		ull ai = 0,index = 1;
		for(auto it = v.begin(); it != v.end(); it++)
			ai = (ai + k[index++] * (*it)) % Q;
		if(i >= L)
			cout << ai << endl;
		v.push_front(ai);
		if(v.size() > m)
			v.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	cin >> m >> L >> R;
	
	for(ull i = 1;i <= m; i++)
		cin >> k[i];

	solve();
		
	return 0;
}


