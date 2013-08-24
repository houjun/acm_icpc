#include "stdafx.h"

#include <stdio.h>
#include <string.h>

int main()
{
	char str[1001],t;
	scanf("%s",str);
	while(strcmp(str,"#")!=0){
		int length,result=0;
		int front,end;
		length=strlen(str);
		front=0;
		end=length-1;
		while(front<=end){
			if (str[front]==str[end])
				result+=(front+1)*(front+1);
			front++;end--;
		}
		printf("%d\n",result);
	t=getchar();
	scanf("%s",str);
	}

	return 0;
}
