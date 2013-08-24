// SZU A57.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
int main()
{
	int times,npp,count,i,j,flag;
	scanf("%d",&times);
	while(times--){
		char seats[10001];
		count=0;
		scanf("%d",&npp);
		npp++;
		scanf("%s",seats);
		for (i=0;i<strlen(seats);i++){
			for(j=i,flag=1;j<npp+i;j++)
				if(seats[j]!='.'){
					flag=0;
					break;
				}
			if(j==npp+i)	count++;
	
		}
		printf("%d\n",count);


	}
	return 0;
}
