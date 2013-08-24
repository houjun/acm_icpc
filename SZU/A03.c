// A03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
long num[250000];

int cmp(const void *a, const void *b)
{
	return *(long *)a - *(long *)b;
}

int main()
{
	int times,time,i;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&time);
		for (i=0;i<time;i++)	scanf("%ld",&num[i]);
		qsort(num,time,sizeof(num[0]),cmp);
		for (i=0;i<time;i++){
			printf("%d",num[i]);
			if(i!=time-1)	printf(" ");
			else	printf("\n");
		}
		
	}
	
	return 0;
}