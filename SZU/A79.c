// SZU A79.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int n,c,k,i,j,num,smallest;
	n=1;
	while(n!=0){
	int	bet[101]={0};
		scanf("%d %d %d",&n,&c,&k);
		for(i=0;i<n;i++){
			for(j=0;j<c;j++){
				scanf("%d",&num);
				bet[num]++;	
			}
		}
		smallest=bet[1];

		for (i=1;i<=k;i++)	
			if(bet[i]<smallest)	smallest=bet[i];
		
		for (i=1;i<=k;i++)
			if (bet[i]==smallest){
				printf("%d ",i);
			}
		if(n!=0)	printf("\n");

	}

	return 0;
}
