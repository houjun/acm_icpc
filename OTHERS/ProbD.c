#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int search(char * str1, char * str2){

	int i,j;
	int str1len=strlen(str1);
	int str2len=strlen(str2);
	int count=0;
	for(i=0;i<str1len-str2len+1;i++){
		for(j=0;j<str2len;j++)
			if(str2[j]!=str1[i+j]) break;
		if(j==str2len)
			count++;		
	}
	return count;
}


int main()
{		
	char str[1001];
	int m,n,i,j,max,temp;
	scanf("%d %d",&n,&m);
	while(n!=0){
		max=0;
		char tmp[6],resultstr[6],t;
		scanf("%s",str);
		for (i=0;i<n-m+1;i++){
			for (j=0;j<m;j++){
				tmp[j]=str[i+j];
			}
			tmp[j]='\0';
			temp=search(str,tmp);
			if (max<temp||max==temp&&strcmp(resultstr,tmp)>=0){		
				max=temp;
				strcpy(resultstr,tmp);
			}
		}
		printf("%s %d\n",resultstr,max);
		t=getchar();
		scanf("%d %d",&n,&m);
	}
	

	return 0;
}
