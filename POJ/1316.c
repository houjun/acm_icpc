#include <stdio.h>
#define MAX 10000
int a[MAX]={0};
int d(int n){
	int t=n;
	while(n){
		t+=n%10;
		n/=10;
	}
	return t;
}
int main()
{

	int i,t;
	a[2]=1;
	for (i = 2; i < MAX ; i++){
		t=d(i);
		if(t<MAX)
		a[t]=1;
	}
	for (i = 1; i < MAX ; i++){
		if(a[i]==0)
			printf("%d\n",i);
	}
	return 0;
}
