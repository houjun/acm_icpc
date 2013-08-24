// SZU F68.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#define MAX 100
int main()
{
	int wrong,round,i,flag,rightl;
	char given[MAX],guess[MAX];
	while(1){
		int alphabet[26]={0};
		rightl=wrong=0;
		flag=1;
		scanf("%d",&round);
		if (round==-1)	break;
		else if(round!=1)	printf("\n");
		printf("Round %d\n",round);
		scanf("%s",given);
		scanf("%s",guess);
		for(i=0;i<strlen(given);i++){
			if(alphabet[given[i]-'a']!=1)	rightl++;
			alphabet[given[i]-'a']=1;
		}
		for(i=0;i<strlen(guess);i++){
			if(alphabet[guess[i]-'a']==0){
				wrong++;
				alphabet[guess[i]-'a']=-1;
			}
			else if(alphabet[guess[i]-'a']==1){
				rightl--;
				alphabet[guess[i]-'a']=2;
			}
			if (rightl==0&&wrong<7){
				printf("You win.");
				break;
			}
		}

		if(wrong>=7){
			printf("You lose.");
			flag=0;
		}
		else if (rightl)
		{
			for(i=0;i<26;i++){
				if(alphabet[i]==1){
					printf("You chickened out.");
					flag=0;
					break;
				}
			}
		}
		if(flag&&rightl)	printf("You win.");
		
	}
	return 0;
}
