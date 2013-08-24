// SZU B68.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
main () {
	int times;
	scanf("%d",&times);
	while(times--){
		int n,w=0,a=0,b=0,m=0,i;               
		char s[701]={0},nowc=0;       
		scanf("%d",&n);
		scanf("%s",s);
		memcpy(s+n,s,n);                    
		for (i=0;s[i]&&m<n;++i){
			if (s[i]=='w')++w,++b;
			else if (nowc!=s[i]){
				if (a+b>m)m=a+b;               
				a=b-w,b=w+1,w=0,nowc=s[i];     
			}
			else ++b,w=0;
		}
		if (a+b>m)m=a+b;
		printf("%d\n",m>n?n:m);   
	}
    return 0;
}