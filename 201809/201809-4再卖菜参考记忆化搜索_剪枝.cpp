//���仯����+��֦  https://blog.csdn.net/wl16wzl/article/details/83652703
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 300+10;
int a[N],up[N],down[N];    //����ڶ���˼ۣ��Լ���һ����ھӲ˼۵ĺ͵����ޣ�����
int n;
int b[N];           //�����һ��˼�
int dp[N][N][N];    //��ʼΪ-1
int dfs(int d)
{
	if(dp[d][b[d-1]][b[d-2]] != -1) 
		return dp[d][b[d-1]][b[d-2]];     //���仯
	if(d == n)
	{
		if(b[n-1]+b[n-2] >= down[n-1] && b[n-1]+b[n-2] <= up[n-1])     //�����һ��
			return 1;
		return 0;
	}
	int l = down[d-1]-b[d-1]-b[d-2],r = up[d-1]-b[d-1]-b[d-2]; //����ǰ�����˼���������˼۷�Χ
	if(l < 1) l=1;     //����Ϊ1
	if(r < l) 
		return dp[d][b[d-1]][b[d-2]] = 0; //��֦
	for(int i=l; i<=r; i++)
	{
		b[d] = i;
		if(dfs(d+1)) 
			return dp[d][b[d-1]][b[d-2]] = 1; //����
	}
	return dp[d][b[d-1]][b[d-2]] = 0; //������
}
int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	//Ԥ����������
	up[0] = a[0]*2+1;
	down[0] = a[0]*2;
	up[n-1] = a[n-1]*2+1;
	down[n-1] = a[n-1]*2;
	for(int i=1; i<n-1; i++)
	{
		up[i]=a[i]*3+2;
		down[i]=a[i]*3;
	}
	memset(dp,-1,sizeof(dp));
	bool flag=false;
	for(int i=1; !flag&&i<up[0]; i++)     //ö��ǰ���������������
		for(int j=1; j<up[1]-i; j++)
		{
			if(i+j < down[0]) 
				continue;
			b[0]=i;
			b[1]=j;
			if(dfs(2)==1) //����
			{
				flag=true;
				break;
			}
		}

	for(int i=0; i<n-1; i++)
		printf("%d ",b[i]);
	
	printf("%d\n",b[n-1]);
	
	return 0;
}

