#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <iterator>
#include <string.h>
using namespace std;
void ForwardDFS(bool sCanReach[55][55],int r,int c,char arr[55][55],int x,int y)
{
	if (sCanReach[x][y] || arr[x][y]=='#')
		return;
	sCanReach[x][y] = true;
	bool up = 0,right = 0,down = 0,left = 0;
	switch(arr[x][y])
	{
		case '.':
		{
			down = true;
			break;
		}
		
		case '|':
		{
			up = true;
			down = true;
			break;
		}
		
		case '-':
		{
			left = true;
			right = true;
			break;
		}
		
		case '+':
		case 'S':
		case 'T':
		{
			up = true;
			down = true;
			left = true;
			right = true;
			break;
		}
		
	}
	if(up && x-1 >= 0)
		ForwardDFS(sCanReach,r,c,arr,x-1,y);
	if (down && x+1 <= r-1)
		ForwardDFS(sCanReach,r,c,arr,x+1,y);
	if (left && y-1 >= 0)
		ForwardDFS(sCanReach,r,c,arr,x,y-1);
	if (right && y+1 <= c-1)
		ForwardDFS(sCanReach,r,c,arr,x,y+1);
}
//从终点出发，反向DFS
void ReverseDFS(char map[55][55],//输入矩阵
                bool sign[55][55],//返回标记结果图，true表示可以到达这个点，false表示不能到达
                int Row,int Col,//矩阵规模
                int curR, int curC,//当前点
                int preR, int preC)//上一个点
{
	//若 当前点已走过 或 当前点是障碍物，停止递归
	if (sign[curR][curC] || map[curR][curC] == '#')
		{
			return ;
		}
	//从下面来的，可以返回去，其他方向来的无法原路返回
	if (map[curR][curC] == '.' && preR == curR+1 && preC == curC)
		{
			sign[curR][curC] = true;
		}
	//从左右来的可以返回去
	else if (map[curR][curC] == '-' && preR == curR)
		{
			sign[curR][curC] = true;
		}
	//必须从上下来
	else if (map[curR][curC] == '|' && preC == curC)
		{
			sign[curR][curC] = true;
		}
	//可随便返回
	else if (map[curR][curC] == 'S' || map[curR][curC] == '+' || map[curR][curC] == 'T')
		{
			sign[curR][curC] = true;
		}
	//不可达，返回
	if (sign[curR][curC] == false)
		{
			return ;
		}
	//上
	if (curR-1 >= 0)
		{
			ReverseDFS(map,sign,Row,Col,curR-1,curC,curR,curC);
		}
	//下
	if (curR+1 < Row)
		{
			ReverseDFS(map,sign,Row,Col,curR+1,curC,curR,curC);
		}
	//左
	if (curC-1 >= 0)
		{
			ReverseDFS(map,sign,Row,Col,curR,curC-1,curR,curC);
		}
	//右
	if (curC+1 < Col)
		{
			ReverseDFS(map,sign,Row,Col,curR,curC+1,curR,curC);
		}
}
int main(void)
{
	char arr[55][55];
	memset(arr,0,55*55);
	int r,c;
	cin>>r>>c;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			cin>>arr[i][j];
	 
	bool sCanReach[55][55],dCanReach[55][55];//分别为S能到哪些点，哪些点能到T
	
	memset(sCanReach,0,55*55);
	memset(dCanReach,0,55*55);
	
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			{
				if (arr[i][j]=='S')
					ForwardDFS(sCanReach,r,c,arr,i,j);
			}
	
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
		{
			if (arr[i][j]=='T')
				{
					if (!sCanReach[i][j])
					{
						cout<<"I'm stuck!";
						return 0;
					}
					ReverseDFS(arr,dCanReach,r,c,i,j,i,j);
				}
		}
	
	int num=0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
		{
			if (sCanReach[i][j] && !dCanReach[i][j])//&&arr[i][j]!='S'&&arr[i][j]!='T'
			{ 
				cout << i << "  " << j << endl;
				num++;
			} 
		}
	cout<<num;
	return 0;
}
