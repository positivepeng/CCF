#include <stdio.h>
#include <string.h>
#define R 1
#define Y 2
#define G 3
typedef long long ll;



ll cal_stop_time(ll r,ll g,ll y,ll type,ll time_cost,ll L)
{
	time_cost = time_cost % (r + g + y);
	//printf("in function  : %lld",time_cost);
	while(1)
	{
		if(type == R)
		{
			if(L - time_cost >= 0)  
			{
				//printf("最后一个是红灯 : %lld %lld %lld \n",L,time_cost,L - time_cost);
				return L - time_cost;
			}
			else 
			{
				//printf("%lld时红变绿\n",time_cost);
				type = G;
				time_cost = time_cost - L;
				L = g;
			}
		}
		
		if(type == G)
		{
			if(L - time_cost >= 0)
				return 0;
			else
			{
				type = Y;
				time_cost = time_cost - L; 
				L = y;
			}
		}
		
		if(type == Y)
		{
			if(L - time_cost >= 0)
				return L - time_cost + r;
			else
			{
				type = R;
				time_cost = time_cost - L;
				//printf(" timecost L : %lld %lld\n",time_cost ,L);
				L = r;
			}
		}
	}
}

int main()
{	
	ll r,y,g,n;
	scanf("%lld%lld%lld",&r,&y,&g);
	scanf("%lld",&n);
	
	ll type,L;
	ll curr = 0;
	ll i = 0;
	for(i = 0;i < n; i++)
	{
		scanf("%lld%lld",&type,&L);
		if(type == 0)	          //直接通过 
		{
			//printf("type == 0\n");
			curr += L;
		}
		else
		{
			ll stop_time = cal_stop_time(r,g,y,type,curr,L);
			curr += stop_time;
			//printf("*********%lld  %lld *********\n",i,curr);
		}
	}
	printf("%lld\n",curr);
	return 0;
}

