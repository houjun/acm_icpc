#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct DATA{
	int t;
	int x;
}DATA;
DATA T[1005];
int cmp(const void *a,const void *b)
{
	return( (*(DATA*)a).t<= (*(DATA*)b).t?1:-1 );
}
 
int main()
{
	while (1)
	{
		int n,i,j;
		int f=0,flag=0;
 
		scanf("%d",&n);
		if (n==0) break;
 
		for(i=0;i<n;i++)
			scanf("%d",&T[i].x);
		for(i=0;i<n;i++)
			scanf("%d",&T[i].t);
 
		qsort(T,n,sizeof(T[0]),cmp);
 
 
		for (i=0;i<n;i++)
		{
			if (f<0)
			{
				flag=1;
				break;
			}
			else if ((T[0].t-f) <= T[i].t)
			{
				f += T[i].x;
			}
			else// if ((T[0].t-f) > T[i].t)				//T[0].t-f > T[i].t)
			{
				f = T[0].t-T[i].t + T[i].x;
			}
		}
 
		if (T[0].t-f>=0 && flag==0)
			printf("%d\n",T[0].t-f);
		else
			printf("impossible\n");
 
	}
	return 0;
}