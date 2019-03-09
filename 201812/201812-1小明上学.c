#include <stdio.h>
#include <string.h>
int main()
{
	int r,y,g,n;
	scanf("%d%d%d",&r,&y,&g);
	scanf("%d",&n);
	
	int i,type,L;
	int ans = 0;
	for(i = 0;i < n; i++)
	{
		scanf("%d%d",&type,&L);
		if(type == 0)
			ans += L;
		if(type == 1)
			ans += L;
		if(type == 2)
			ans += L + r;
	}
	printf("%d\n",ans);
	return 0;
}

