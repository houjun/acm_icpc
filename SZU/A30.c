// SZU A30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int times,i;
	double data;
	char type[3];
	scanf("%d",&times);
	for (i=1;i<=times;i++)
	{
		scanf("%lf %s",&data,type);
		if (strcmp(type,"kg")==0)
			printf("%d %.4f lb\n",i,data*2.2046);
		
		if (strcmp(type,"l")==0)
			printf("%d %.4f g\n",i,data*0.2642);

		if (strcmp(type,"lb")==0)
			printf("%d %.4f kg\n",i,data*0.4536);

		if (strcmp(type,"g")==0)
			printf("%d %.4f l\n",i,data*3.7854);

	}
	return 0;
}
