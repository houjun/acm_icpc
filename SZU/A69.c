// SZU A69.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times;
	scanf("%d",&times);
	while(times--){
		int c,n,vote,i,first,second,third,count;
		int snum,tnum;
		int votes[10001]={0};
		scanf("%d %d",&c,&n);
		for(i=1,first=0;i<=n;i++){
			scanf("%d",&vote);
			votes[vote]++;
			if (votes[vote]>first){	first=votes[vote];}
		}
		count=0;

		for (i=1;i<=c;i++)
			if (votes[i]==first)	count++;
		if (count==2){
			third=0;
			for (i=1;i<=c;i++){
				if (votes[i]<first&&votes[i]>third)
				{third=votes[i];tnum=i;}
			}
		}
		else{
			second=third=0;
			for (i=1;i<=c;i++){
				if (votes[i]<first&&votes[i]>second)
				{second=votes[i];snum=i;}
			}
			for (i=1;i<=c;i++){
				if (votes[i]<second&&votes[i]>third)
				{third=votes[i];tnum=i;}
			}

		}

		printf("%d\n",tnum);

	}
	return 0;
}
