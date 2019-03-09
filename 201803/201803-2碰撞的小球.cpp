#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define LEFT -1
#define RIGHT 1
using namespace std;

typedef struct ball
{
	int pos;
	int direction;
}ball;

int main(int argc, char const *argv[])
{
	int right,n,t;

	cin >> n >> right >> t;
	ball balls[n];
		
	for(int i = 0;i < n; i++)
	{
		cin >> balls[i].pos;
		if(balls[i].pos == right)
			balls[i].direction = LEFT;
		balls[i].direction = RIGHT;
	}
	
	int mark[1005];
	
	
	while(t > 0)
	{
		for(int i = 0;i < n; i++)
			balls[i].pos += balls[i].direction;
		
		for(int i = 0;i < n; i++)
		{
			if(balls[i].pos == 0)
				balls[i].direction = RIGHT;
			if(balls[i].pos == right)
				balls[i].direction = LEFT;
		}
		
		
		memset(mark,-1,sizeof(mark));
		for(int i = 0;i < n; i++)
		{
			if(mark[balls[i].pos] == -1)
				mark[balls[i].pos] = i;
			else
				swap(balls[i],balls[mark[balls[i].pos]]);
		}
		
		
		
//		for(int i = 0;i < n; i++)
//		{
//			cout << balls[i].pos << " ";
//		}
//		cout << endl;
		t--;
	}
	
	for(int i = 0;i < n; i++)
	{
		cout << balls[i].pos << " ";
	}
	
	return 0;
}

