// SZU B89.cpp : Defines the entry point for the console application.
//Ð§ÂÊÌ«µÍ!

#include "stdafx.h"

#include <stdio.h>

int main()
{
	int times,i,j,t,n;
	long sum;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&n);
		sum=0;
		i=j=t=100;
		for (i=1;i<j;i++)
		{
			for (j=i;j<t;j++)
			{
				t=n-i-j;
				if (i!=j&&j!=t)			sum+=6;
				else if (i==j||j==t)	sum+=3;					
			}

			}
		if (n%3==0)	sum-=2;
		if (n<3)	sum=0;
		printf("%ld\n",sum);

	}
	return 0;
}

int right()
{
	int t;
	long n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		if(n<=2)
			printf("0\n");
		else
			printf("%ld\n",((n-1)*(n-2))/2);
	}
	return 0;
}