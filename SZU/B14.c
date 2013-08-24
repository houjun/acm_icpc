// SZU B14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
int main()
{
	char name[1000][100],t[1000];
	while(1){
		int times[1000];
		memset(times,0,sizeof(times));
		memset(name,'\0',sizeof(name));
		memset(t,'\0',sizeof(t));
		int i,j,amount,length,max,maxnum,n,flag;
		maxnum=amount=0;
		max=1;
		scanf("%d",&n);
		if(n==0)	break;
		while(n--){
			scanf("%s",t);
			scanf("%d",&length);
			for(i=0;i<length;i++){
				scanf("%s",t);
				for(j=0,flag=1;j<amount;j++){
					if(strcmp(t,name[j])==0){
						times[j]++;
						flag=0;
						if(max<times[j]){
							max=times[j];
							maxnum=j;
						}
						break;
					}
				}
				
				if(flag){
					strcpy(name[amount],t);
					times[i]=1;
					amount++;
				}
			}
		}

				printf("%s\n",name[maxnum]);
	
		
	}
	
	return 0;
}
