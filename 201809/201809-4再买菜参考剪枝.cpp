// �ο�����  https://blog.csdn.net/gl486546/article/details/86077303 
#include <bits/stdc++.h>
using namespace std;

int day2[400], day1[400], n;
bool isfind = 0, visit[400][400][400];

void dfs(int i, int cur, int pre)
{
	if(visit[i][cur][pre]) 
	{
		//cout << "��ǰ״̬ " << i << " " << cur << " " << pre << " �Ѿ��������ˣ�" << endl;
		return;             //��ǰ״̬�Ѿ������������м�֦
	}
		
	visit[i][cur][pre] = 1;
	day1[i] = cur;
	
	if(i == n)
	{
		if((day1[n - 1] + day1[n]) / 2 == day2[n]) 
			isfind = 1;                           //�˶����һ��
		return;
	}
	int next = 3*day2[i] - pre - cur;//�Ե�i�죬�������cur���Լ�����preȷ������ô��һ����3�����
	for(int k = 0; k < 3; ++k){         //0, 1, 2
		if(next + k >= 1 && !isfind){        //ע��next + k����Ϊ������
			dfs(i + 1, next + k, cur);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", day2 + i);
	}
	for(int e = 1; e <= 2*day2[1]; ++e)
	{
		day1[1] = e;              //��һ��ȷ������ô�ڶ���Ҳ��ȷ�������������
		dfs(2, 2*day2[1] - e, day1[1]);
		if(!isfind) 
			dfs(2, 2*day2[1] - e + 1, e);
		else 
			break;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", day1[i]);
	}
	return 0;
}

