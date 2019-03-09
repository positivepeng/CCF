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
//���յ����������DFS
void ReverseDFS(char map[55][55],//�������
                bool sign[55][55],//���ر�ǽ��ͼ��true��ʾ���Ե�������㣬false��ʾ���ܵ���
                int Row,int Col,//�����ģ
                int curR, int curC,//��ǰ��
                int preR, int preC)//��һ����
{
	//�� ��ǰ�����߹� �� ��ǰ�����ϰ��ֹͣ�ݹ�
	if (sign[curR][curC] || map[curR][curC] == '#')
		{
			return ;
		}
	//���������ģ����Է���ȥ���������������޷�ԭ·����
	if (map[curR][curC] == '.' && preR == curR+1 && preC == curC)
		{
			sign[curR][curC] = true;
		}
	//���������Ŀ��Է���ȥ
	else if (map[curR][curC] == '-' && preR == curR)
		{
			sign[curR][curC] = true;
		}
	//�����������
	else if (map[curR][curC] == '|' && preC == curC)
		{
			sign[curR][curC] = true;
		}
	//����㷵��
	else if (map[curR][curC] == 'S' || map[curR][curC] == '+' || map[curR][curC] == 'T')
		{
			sign[curR][curC] = true;
		}
	//���ɴ����
	if (sign[curR][curC] == false)
		{
			return ;
		}
	//��
	if (curR-1 >= 0)
		{
			ReverseDFS(map,sign,Row,Col,curR-1,curC,curR,curC);
		}
	//��
	if (curR+1 < Row)
		{
			ReverseDFS(map,sign,Row,Col,curR+1,curC,curR,curC);
		}
	//��
	if (curC-1 >= 0)
		{
			ReverseDFS(map,sign,Row,Col,curR,curC-1,curR,curC);
		}
	//��
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
	 
	bool sCanReach[55][55],dCanReach[55][55];//�ֱ�ΪS�ܵ���Щ�㣬��Щ���ܵ�T
	
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
