// C01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
long ipow(int n,int t){
	long r=1;
	while(t--){
		r=r*3;
		if(r>20090411)
			r%=20090411;
	}
	return r;
}
int main()
{
	int times,n;
	long result;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&n);
		result=1;
		if(n==1){
			printf("1\n");
			continue;
		}
		if(n%3==0){
			result=ipow(3,n/3);
		}
		else if(n%3==1)
			result=ipow(3,(n-1)/3-1)*4;
		else
			result=ipow(3,(n-2)/3)*2;
		if(result>20090411)
			result%=20090411;

		printf("%ld\n",result);
	}	
	
	return 0;
}
