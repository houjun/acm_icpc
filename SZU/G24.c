#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n),n){
		if (n%2==0)
			printf("%d\n",n*(n-2)/2);
		else
			printf("%d\n",(n-1)*(n-1)/2);
	
	}
	return 0;
}
