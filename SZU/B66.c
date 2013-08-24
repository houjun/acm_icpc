#include "stdafx.h"

#include <stdio.h>
#include <string.h>

int main()
{
	int times,t1;
	scanf("%d",&times);
	for(t1=0;t1<times;t1++){
		int np,i,num,out,t,tt;
		char name[10][15]={'\0'},giver[15]={'\0'},receiver[15]={'\0'};
		int money[10]={0};
		scanf("%d",&np);
		tt=np;
		for(i=0;i<np;i++)
			scanf("%s",name[i]);
		while(tt--){
			scanf("%s",giver);
			scanf("%d %d",&out,&num);
			t=num;
			if(num==0)	continue;
			for (i=0;i<np;i++){
				if(strcmp(giver,name[i])==0){
					money[i]-=out;
					money[i]+=(out-(out/num)*num);
				}
			}
			
			while(t--){
				scanf("%s",receiver);
				for (i=0;i<np;i++){
					if(strcmp(receiver,name[i])==0)
						money[i]+=(out/num);
				}
			}
			
		}
		for (i=0;i<np;i++){
			printf("%s ",name[i]);
			printf("%d\n",money[i]);
		}
		if(t1!=times-1)	printf("\n");

	}

	return 0;
}
