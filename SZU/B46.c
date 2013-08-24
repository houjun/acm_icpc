// B46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX 103
char fib[485][MAX];
void add(char *pa,char *pb,char *result){
	int i;
	for (i=MAX-2;i>=0;i--){
		result[i]+=pa[i]-'0'+pb[i]-'0';
		if (result[i]>'9'){						 /*判断是否该进位*/
			result[i]-=10;
			result[i-1]++;						 /*进位*/
		}
	}
}
void init(){
	int i;
	memset(fib,'0',485*103*sizeof(fib[0][0]));
	fib[0][MAX-2]='1';
	fib[1][MAX-2]='2';
	for (i = 0; i < 485 ; i++){
		fib[i][MAX-1]='\0';
	}
	for (i = 2; i < 485 ; i++){
		add(fib[i-1],fib[i-2],fib[i]);
	}
}
int main()
{
	int i,result,l1,l2;
	char s1[MAX],s2[MAX],t[MAX];
	init();
	while(scanf("%s %s",&s1,&s2),strcmp(s2,"0")!=0){
		result=0;
		l1=strlen(s1);
		l2=strlen(s2);
		strcpy(t,s1);
		memset(s1,'0',MAX*sizeof(s1[0]));
		strcpy(s1+MAX-l1-1,t);

		strcpy(t,s2);
		memset(s2,'0',MAX*sizeof(s2[0]));
		strcpy(s2+MAX-l2-1,t);

		for (i = 0; i < 485 ; i++){
			if(strcmp(s1,fib[i])<=0)
				break;
		}
		for (; i < 485 ; i++){
			if(strcmp(s2,fib[i])>=0)
				result++;
			else
				break;
		}
		if(strcmp(s2,fib[i])==0)
			result++;
		printf("%d\n",result);
	}
	return 0;
}
