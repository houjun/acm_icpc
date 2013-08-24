// SZU A50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times,percentage,count;
	double fpc,t;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&percentage);
		if(percentage>=50){
			printf("0\n");
			continue;
		}
		fpc=1-percentage/100.0;
		for (count=0,t=fpc;1.0-fpc<0.5;count++)
		{
			fpc*=t;
		}
		printf("%d\n",count);



	}
	return 0;
}
