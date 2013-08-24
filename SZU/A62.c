// A62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int main()
{
	int sum,max,times,i,j,size,a[10000];
	scanf("%d",&times);
	while(times--){
		scanf("%d",&size);
		for (i=0;i<size;i++)
			scanf("%d",&a[i]);
		max=a[0];
		
		for(i=0;i<size;i++){
			sum=0;
			  for(j=i;j<size;j++)
			  {
				   sum=sum+a[j];
				   if(sum>max)
					   max=sum;
			  }
		 }
		printf("%d\n",max);


	}
	return 0;
}
