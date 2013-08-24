// SZU B97.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int sq(int n){
	int sum=0;
	while(n){
		sum+=(n%10)*(n%10);
		n/=10;
	}
	return sum;
}
int main()
{
	int n=1,t,times=1;
	while(n){
		scanf("%d",&n);
		if (n==0)	break;
		t=sq(n);
		while(t>20)
			t=sq(t);
				
		if (t==1||t==7||t==10||t==13||t==19)
			printf("Set %d has a cycle length of 1.\n",times);

		else	printf("Set %d has a cycle length of 8.\n",times);
		times++;

	}

	return 0;
}
