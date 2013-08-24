// SZU B48.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX 1010
int main()
{
	int times;
	char a[MAX],b[MAX];
	scanf("%d",&times);
	while(times--){
		int num1[MAX]={0},num2[MAX]={0},result[MAX*2]={0};
		int sign1=1,sign2=1,i,j,flag,neg;
		scanf("%s %s",a,b);
		if(a[0]=='-'){sign1=-1;strncpy(a,a+1,strlen(a));}
		if(b[0]=='-'){sign2=-1;strncpy(b,b+1,strlen(b));}
		if((sign1==-1&&sign2==-1)||(sign1==1&&sign2==1))
			neg=1;
		else
			neg=-1;
		int len1=strlen(a);
		int len2=strlen(b);
		for (i=len1-1,j=MAX-1;i>=0;i--,j--)	 /*�����ڴ����Ҷ���*/
			num1[j]=a[i]-'0';
		for (i=len2-1,j=MAX-1;i>=0;i--,j--)
			num2[j]=b[i]-'0';
		for (i=MAX-1;i>=(MAX-len1);i--)
			for (j=MAX-1;j>=(MAX-len2);j--)
				result[i+j+1]+=num1[i]*num2[j];

		for (i=MAX*2-1;i>=0;i--)
		{
			if(result[i]>=10){
				result[i-1]+=result[i]/10;
				result[i]%=10;
			}
		}
		
		for(i=0,flag=0;i<MAX*2;i++){
			if (flag)
				printf("%d",result[i]);				/*����ڶ�����Ľ��*/
			else if(result[i])
			{
				if(neg==-1)		printf("-");				/*�������λ*/
				printf("%d",result[i]);				/*����ǰ���0�������һ��������*/
				flag=1;
			}
		}
		if(flag==0)		printf("0");					/*��������0ʱ�����*/
	printf("\n");
	}
	return 0;
}
