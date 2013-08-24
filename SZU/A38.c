#include "StdAfx.h"

#define MAX 30
int sum,length,minoflen,tot,flag;
int stick[MAX];
#include <stdio.h>
void find(long n){
	long i;
	if(n==tot&&sum==length){
		if(!flag)	
			printf("%d\n",sum);
		flag=1;
		return;
	}
	else if(sum>length){
		if(sum<minoflen)
			minoflen=sum;
		return;
	}
	else if(n==tot)
		return;

	else{
		for (i = 0; i < 2 ; i++){
			if(i==1)
				sum+=stick[n];
			find(n+1);
		}
		sum-=stick[n];	
	}
}
long main()
{
	long times,i;
	scanf("%d",&times);
	while(times--){
		flag=sum=0;
		for (i = 0; i < MAX ; i++){
			stick[i]=0;
		}
		scanf("%d %d",&tot,&length);
		for (i = 0; i < tot ; i++){
			scanf("%d",&stick[i]);
		}
		minoflen=length+stick[0]+1000000;
		find(0);
		if(!flag){
			printf("%d\n",minoflen);
		}
	}
	return 0;
}
