#include <stdio.h>
 
int main()
{
	int times,a,b,c;
	scanf("%d",&times);
	while (times--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",(a*b+b*c+a*c)*2);
	}
	return 0;
}