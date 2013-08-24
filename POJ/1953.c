#include <stdio.h>
int main()
{
	int times,a,i,t=0;
	int fib[45]={2,3};
	for (i = 2; i < 45 ; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	scanf("%d",&times);
	while(times--){
		t++;
		scanf("%d",&a);
		printf("Scenario #%d:\n%d\n\n",t,fib[a-1]);
	}
	return 0;
}
