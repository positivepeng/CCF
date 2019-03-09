#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int total = 0;
	int curr = 0;
	int cnt = 0;
	while(cin >> t)
	{
		cnt ++;
		
		if(t == 0) 
			break;
		if(t == 1)
		{
			total += 1;
			curr = 1;
		}
		if(t == 2)
		{
			if(cnt == 1 || curr == 1)
				curr = 2;
			else
				curr += 2;
			total += curr;
		}
	}
	
	cout << total << endl; 
	
	
	return 0;
}

