// A61.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
 
int main()
{
	int times;
	long a,b,t,i,sum;
	
	scanf("%d",&times);
	while(times--){
		scanf("%d %d",&a,&b);
		if (a>b)
		{	t=a;
		a=b;
		b=t;
		}
		sum=0;
		for (i=a;i<=b;i++)
			sum+=i;
		printf("%ld\n",sum);
	}
	return 0;
}