// SZU A46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
int main()
{
	int times,length,i;
	long long result,t;
	scanf("%d",&times);
	while(times--){
		char num[11]={'\0'};
		result=0;
		t=1;
		scanf("%s",num);
		length=strlen(num);
		for (i=length-1;i>=0;i--){	
			result+=(num[i]-'A'+1)*t;
			t*=26;
		}
		result--;
		printf("%lld\n",result);
		
	}
	return 0;
}