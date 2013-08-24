// SZU B06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int convert(char word){
	if (word>='0'&&word<='9')		return (word-'0');
	else if(word>='A'&&word<='Z')	return (word-'A'+10);
	else							return (word-'a'+36);
}

int main()
{
	int sum;
	int i,j;
	char word[1001];

	while(1){
		sum=0;
		scanf("%s",word);
		if(strcmp(word,"end")==0)	break;
		j=strlen(word);
		for (i=0;i<j;i++){
			sum+=convert(word[i]);
		}
		if(sum%61==0)	printf("yes\n");
		else			printf("no\n");
	}	
	return 0;
}
