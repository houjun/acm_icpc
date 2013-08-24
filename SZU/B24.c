// SZU B24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times,time,win1,win2;
	char p1[2],p2[2];
	scanf("%d",&times);
	
	while(times--){
		scanf("%d",&time);
		win1=0;
		win2=0;
		while(time--){

			scanf("%s %s",&p1[0],&p2[0]);
			if (p1[0]==p2[0])	continue;
			else if (p1[0]=='R'&&p2[0]=='S'||p1[0]=='S'&&p2[0]=='P'||p1[0]=='P'&&p2[0]=='R')
				win1++;
			else
				win2++;

		}

		if (win1>win2)			printf("Player 1\n");
		else if(win1<win2)		printf("Player 2\n");
		else					printf("TIE\n");


	}
	return 0;
}
