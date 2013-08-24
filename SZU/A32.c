#include "stdafx.h"

#include <stdio.h>
#include <string.h>
char btoa(char *bstr){
	
	int i,sum=0,t=1;
	for(i=4;i>0;i--){
		sum+=(bstr[i]-'0')*t;
		t*=2;
	}
	if(sum==0)	return ' ';
	else		return 'A'+sum-1;	
}
int main()
{
	int m,n,i,j,sum,over,t,count,tt;
	int times,temp;

	scanf("%d",&times);
	char str[401]={'\0'},inputch[81]={'\0'},matrix[22][22]={'\0'};
	char bstr[6];
	tt=1;
		while(times--){
		scanf("%d %d ",&m,&n);
		sum=m*n;

		for (i=0;i<m;i++)
			for(j=0;j<n;j++)
				matrix[i][j]=getchar();
		t=over=count=0;
		temp=(m>n?n:m);
		if(temp%2!=0)	temp++;
		temp/=2;
		while(temp--){
			for (i=t,j=t;j<n;j++)	str[count++]=matrix[i][j];
			j--;
			for (i+=1	;i<m;i++)	str[count++]=matrix[i][j];
			i--;
			if(count>=sum)	break;
			for (j-=1	;j>=t;j--)	str[count++]=matrix[i][j];
			j++;
			if(count>=sum)	break;
			for (i-=1	;i>t;i--)	str[count++]=matrix[i][j];
			t++;
			n--;
			m--;
				}
		printf("%d ",tt);
		for(i=0;i<(sum-sum%5);i+=5){
			for(j=0;j<5;j++){
				bstr[j]=str[i+j];
				bstr[5]='\0';
			}
			printf("%c",btoa(bstr));
		}
		printf("\n");

	tt++;
	}
	return 0;
}
