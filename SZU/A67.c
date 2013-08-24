// SZU A67.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
int main()
{
	int times;
	scanf("%d",&times);
	while(times--){
		int n,t,i;
		scanf("%d",&n);
		t=n*n;
		for(i=1;i<=t;i++){
			printf("%d",i);
			if(i%n!=0)	printf(" ");
			else		printf("\n");
		}
	if(times)	printf("\n");

	}
	return 0;
}
