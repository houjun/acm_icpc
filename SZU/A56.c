// A56.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *p1,const void *p2){
	return strcmp((char *)p2,(char *)p1);
}

int main()
{
	int times,n,m,l,i,ci,mj;
	char cake[101][31];
	scanf("%d",&times);
	while(times--){
		getchar();
		int samenum=0;
		memset(cake,'0',101*sizeof(cake[0]));
		for (i=0;i<101;i++)
			cake[i][30]='\0';		
		scanf("%d %d",&n,&m);
		scanf("%d",&l);
		for (i=0;i<l;i++){
			scanf("%d %d",&ci,&mj);
			cake[ci-1][mj-1]='1';
		}			
		qsort(cake[0],n,sizeof(cake[0]),cmp);
		for (i=0;i<n-1;i++){
			if(strcmp(cake[i],cake[i+1])==0)
				samenum++;
		}
		printf("%d\n",n-samenum);
		
		
	}
	return 0;
}
