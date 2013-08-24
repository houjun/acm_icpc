// B17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
int main()
{
	int n;
	double r;
	while(1){
		scanf("%d",&n);
		if(n==0)	break;
		else if(n==1)
			printf("1\n");
		else{
			r=((n-1)/2);
			r*=n;
			printf("%.0lf\n",r-1);
		}
	}
	return 0;
}
