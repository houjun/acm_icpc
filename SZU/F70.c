#include <stdio.h>
#include <math.h>
int r[1000001]={0};
int isprime(int n){
	int i,s;
	n=3*n+7;
	s=sqrt(n);
	if(n%2==0||n%3==0||n%5==0||n%7==0)	return 0;
	for (i = 11; i < s+1 ; i+=2){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int cases,n,i,j;
	scanf("%d",&cases);
	for (i = 2; i <= 1000000 ; i++){
		r[i]=r[i-1];
		if(isprime(i))
			r[i]++;		
			
	}
	while(cases--){
		scanf("%d",&n);
		printf("%d\n",r[n]);
	}
	return 0;
}
