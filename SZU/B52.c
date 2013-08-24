#include "stdafx.h"


/*
ID: neil.li2
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <string.h>

char origin[11][11],cmp[11][11],trans[11][11],origincpy[11][11];
int length;

void trans1(char a[11][11],char b[11][11]){
	int i,j;
	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			a[j][length-i-1]=b[i][j];	
}
void trans2(char a[11][11],char b[11][11]){
	int i,j;
	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			a[length-i-1][length-j-1]=b[i][j];	
}
void trans3(char a[11][11],char b[11][11]){
	int i,j;
	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			a[length-j-1][i]=b[i][j];	
}
void trans4(char a[11][11],char b[11][11]){
	int i,j;
	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			a[i][length-j-1]=b[i][j];	
}
int test(char a[11][11],char b[11][11]){
	int i,j,flag;
	flag=1;
	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			if(a[i][j]!=b[i][j]){
				flag=0;
				return 0;
			}
	return 1;
}

int main()
{
	int times;
	int i,j;
	scanf("%d",&times);
	while(times--){
	scanf("%d",&length);
	for (i=0;i<length;i++)
			scanf("%s",&origin[i]);
	for (i=0;i<length;i++)
		scanf("%s",&cmp[i]);

	for (i=0;i<length;i++)
		for(j=0;j<length;j++)
			origincpy[i][j]=origin[i][j];
	
	/*TEST #1*/
		trans1(trans,origincpy);
		if(test(trans,cmp)) {printf("1\n"); continue;}
	/*TEST #2*/
		trans2(trans,origincpy);
		if(test(trans,cmp)) {printf("2\n"); continue;}
	/*TEST #3*/
		trans3(trans,origincpy);
		if(test(trans,cmp)) {printf("3\n"); continue;}
	/*TEST #4*/
		trans4(trans,origincpy);
		if(test(trans,cmp)) {printf("4\n"); continue;}
	/*TEST #5*/
		trans4(origincpy,origin);
			trans1(trans,origincpy);
			if(test(trans,cmp)) {printf("5\n"); continue;}
			trans2(trans,origincpy);
			if(test(trans,cmp)) {printf("5\n"); continue;}
			trans3(trans,origincpy);
			if(test(trans,cmp)) {printf("5\n"); continue;}
	/*TEST #6*/
		if(test(origin,cmp)) {printf("6\n"); continue;}
	/*TEST #7*/
		printf("7\n"); continue;

	}

	return 0;
}
