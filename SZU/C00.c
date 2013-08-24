// C00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
double c(int elements, int selections )
{
	if(selections<=0)
		return 1.0;
	int i,ele;
	double answer;
	double p = 1;
	answer = elements;
	ele = elements;
	for(i = 1;i < selections; i ++){
		answer = answer *(--ele);
		p*=i;
	}
	p *= selections;
      answer/=p;
      return answer;		
}
int main()
{
	int n1,n2,n3,k,n,i,j,times;
	scanf("%d",&times);
	while(times--){
		scanf("%d %d %d %d",&n1,&n2,&n3,&k);
		n=n1+n2+n3;
		for (i = 0; i <= k ; i++){
			for (j = 0; j <= k ; j++){
				if(i+j<=k)
					printf("%f",c(n1,i)*c(n3,j)*c(n2,k-i-j)/c(n,k));
				
				else
					printf("0");	
				if(j!=k)	printf(" ");
			}
			printf("\n");
		}

	}
	return 0;
}
