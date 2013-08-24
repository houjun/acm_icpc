// B21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
int num[100];
int cmp(const void *a, const void *b){
	return(*(int *)a-*(int *)b);
}
int main()
{
	int n,m,i;
	while(scanf("%d %d",&n,&m),m!=0){
		int t=0;
		for (i = 0; i < n ; i++){
			scanf("%d",&num[i]);
		}
		qsort(num,n,sizeof(num[0]),cmp);
		for (i = 0; i < n ; i++){
			if(i%m==0){
				if(t!=0)	printf(" ");
				printf("%d",num[i]);
				t=1;
			}
		}
		printf("\n");
	}
	return 0;
}
