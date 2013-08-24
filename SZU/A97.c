// SZU A97.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
int main()
{
	float a,t;
	int n,times=0;
	while(1){
		times++;
		scanf("%f %d %f",&a,&n,&t);
		if(n==0)	break;
		float distance,mph;
		distance=(float)(3.141592*a*n/63360.0);
		mph=(float)(distance/t*3600.0);
		printf("Trip #%d: %0.2f %0.2f\n",times,distance,mph);

	}
	return 0;
}
