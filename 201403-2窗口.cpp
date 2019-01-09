#include<iostream>
using namespace std;
typedef struct 
{
	int x1,x2,y1,y2;
	int level;
}window;

bool isInWindow(window win,int x,int y)
{
	int x1 = win.x1,x2 = win.x2,y1 = win.y1,y2 = win.y2;
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

int findFocus(window wins[12],int x,int y,int n)
{
	int curr_level = -1;
	int curr_win_id = -1;
	for(int i = 1;i <= n; i++)
	{
		if(isInWindow(wins[i],x,y) && wins[i].level > curr_level)
		{
			curr_level = wins[i].level;
			curr_win_id = i;
		}
	}
	return curr_win_id;
}

int main()
{
	int n,m;
	int x1,x2,y1,y2,x,y;
	
	window windows[12];
	cin >> n >> m;
	int max_level = n;
	
	//nÎª×î¶¥²ã 
	for(int i = 1;i <= n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		windows[i].x1 = x1;
		windows[i].x2 = x2;
		windows[i].y1 = y1;
		windows[i].y2 = y2;
		windows[i].level = i;
	}
	
	for(int i = 0;i < m; i++) 
	{
		cin >> x >> y;
		int focus_id = findFocus(windows,x,y,n);
		if(focus_id != -1)
		{
			cout << focus_id << endl;
			windows[focus_id].level = ++max_level;
		}
		else
			cout << "IGNORED" << endl;
	}

	return 0;
 } 
