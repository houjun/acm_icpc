#include <stdio.h>
 
 
int main()
{
	int times,n,t1,above;
	float totweigh,aveweigh;
	scanf("%d",&times);
	int num[100000];
	while (times--)
	{
		totweigh=0;
		scanf("%d",&n);
		for(t1=0;t1<n;t1++)
		{
			scanf("%d",&num[t1]);
			totweigh+=num[t1];
 
		}
		aveweigh=totweigh/n;
		above=0;
		for (t1=0;t1<n;t1++)
		{
			if (num[t1]>aveweigh)
			{
				above++;
			}
 
		}
		printf("%d\n",above);
 
	}
	return 0;
}