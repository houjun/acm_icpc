// SZU A29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
int main()
{
	char words[81];
	int times,t=1,del,i,temp;
	scanf("%d",&times);
	while(times--){
		scanf("%d %s",&del,words);
		printf("%d ",t);
		temp=strlen(words);
		for (i=0;i<temp;i++){
			if (i!=del-1){
				printf("%c",words[i]);
			}
		}
		printf("\n");
		t++;
	}



	return 0;
}
