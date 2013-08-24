#include "StdAfx.h"

#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,c,i,flag,tt=0;
	char sa[10],sb[10],t[10];
	while(scanf("%s",sa)!=EOF){
		scanf("%s",t);
		scanf("%s",sb);
		scanf("%s",t);
		scanf("%d",&c);
		flag=a=b=0;
		if(sa[0]=='x')	a=1;
		else
			for (i = 0;sa[i]!='x' ; i++)
				a=a*10+sa[i]-'0';
		if(sb[0]=='y')	b=1;
		else
			for (i = 0; sb[i]!='y' ; i++)
				b=b*10+sb[i]-'0';

		for (i = 0; i <(c/a+1)  ; i++){
			if((c-i*a)%b==0)
				flag=1;
		}
		for (i = 0; i <(c/b+1)  ; i++){
			if((c-i*b)%a==0)
				flag=1;
		}
		
		if(flag==1)
			printf("Yes.\n\n");
		else
			printf("No.\n\n");
		
		
	}
	return 0;
}