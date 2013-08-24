// SZU A27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
int main()
{
	int times,num;
	int answer[21]={0,1,2,4,7,13,24,44,81,149,274,504,927,1705,3136,5768,10609,19513,35890,66012,121415};
	scanf("%d",&times);
	while(times--){
		scanf("%d",&num);
		printf("%d",answer[num]);
		if(times)	printf("\n");
		
		
	}
	return 0;
}