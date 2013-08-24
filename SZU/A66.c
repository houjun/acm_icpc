// SZU A66.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times,a,b,i,t;
	scanf("%d",&times);
	while(times--){
		int num[10]={0};
		scanf("%d %d",&a,&b);
		if(a>b){
			t=a;
			a=b;
			b=t;
		}
		for (i=a;i<=b;i++){
			t=i;
			while(t){
				num[t%10]++;
				t/=10;
			}
		}
		for (i=0;i<10;i++)
		printf("%d %d\n",i,num[i]);
		if(times)	printf("\n");
	}
	return 0;
}
