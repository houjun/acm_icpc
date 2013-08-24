#include <stdio.h>
 
int main()
{
	long long a,b,l;
	int up,day,times;
	day=0;
	scanf("%d",&times);
	while (times--)
	{
		scanf("%lld%lld%lld",&a,&b,&l);
 
		if (a<=b&&a<=l)
		{
			day=-1;
		}
		else if(a>l)
		{
			day=1;
		}
		else
		{
			up=a-b;
		    day=(int)((l-a)/up)+2;
		}
		printf("%d\n",day);
	}
	return 0;
}