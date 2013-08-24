// A07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#define MAX 55
int main()
{
	char a[MAX],b[MAX];
	char fa[26];
	int map[26];
	int times,i,flag,n1,n2;
	scanf("%d",&times);
	while(times--){
		flag=1;
		for (i = 0; i < 26 ; i++){
			fa[i]='0';
			map[i]=0;
		}
		scanf("%s",a);
		scanf("%s",b);	
		n1=strlen(a);
		n2=strlen(b);
		if(n1!=n2){ 
			printf("No\n");
			continue;
		}
		for (i = 0; i < n1 ; i++){
			if(fa[a[i]-'a']==b[i]|| (fa[a[i]-'a']=='0'&&map[b[i]-'a']==0) ){
				fa[a[i]-'a']=b[i];
				map[b[i]-'a']=1;
			}
			else if(fa[a[i]-'a']!=b[i]||map[b[i]-'a']==1){
				flag=0;
				break;
			}
			
		}
		if(flag)	printf("Yes\n");
		else		printf("No\n");

	}
	return 0;
}
