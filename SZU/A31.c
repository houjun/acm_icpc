#include "stdafx.h"

#include <stdio.h>
#include <string.h>
char atobi[26][6]= {"00001","00010","00011","00100","00101","00110",
					"00111","01000","01001","01010","01011","01100",
					"01101","01110","01111","10000","10001","10010",
					"10011","10100","10101","10110","10111","11000",
					"11001","11010"};

int main()
{
	int m,n,i,j,sum,over,t,count,num,ttt;
	int times,length,line,temp;
	char inputch[81];
	scanf("%d",&times);
	num=1;
	while(times--){
		ttt=0;
		char str[410]={'\0'};
		char matrix[25][25]={'\0'};
		scanf("%d %d",&m,&n);
		line=m;
		gets(inputch);
		if(strcmp(inputch," ")!=0)	ttt=1;
		length=strlen(inputch);
		for (i=ttt;i<length;i++){
			if(inputch[i]==' ')			strcat(str,"00000");
			else	strcat(str,atobi[inputch[i]-'A']);
		}
		for (i=(length-ttt)*5;i<m*n;i++){
			str[i]='0';
		}
		str[i]='\0';
		t=over=count=0;
		temp=(m>n?n:m);
		sum=m*n;
		if(temp%2!=0)	temp++;
		temp/=2;
		while(temp--){
			for (i=t,j=t;j<n;j++)	matrix[i][j]=str[count++];
			j--;
			for (i+=1	;i<m;i++)	matrix[i][j]=str[count++];
			i--;
			if(count>=sum)	break;
			for (j-=1	;j>=t;j--)	matrix[i][j]=str[count++];
			j++;
			if(count>=sum)	break;
			for (i-=1	;i>t;i--)	matrix[i][j]=str[count++];
			t++;
			n--;
			m--;
		}
		
		printf("%d ",num);
		for (i=0;i<line;i++)
			printf("%s",matrix[i]);
		if(times)	printf("\n");
		num++;
	}
	return 0;
}