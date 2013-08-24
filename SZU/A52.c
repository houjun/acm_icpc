// SZU A52.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


int cmp ( const void *a , const void *b ) 
{ 
	return *(int *)b - *(int *)a; 
} 

int main()
{
	int times,length,i,t,a,b;
	scanf("%d",&times);
	while(times--){
		int books[1001]={0};
		scanf("%d",&length);
		for (i=0;i<length;i++)
			scanf("%d",&books[i]);
		scanf("%d",&t);

		for(i=0;i<t;i++){
			scanf("%d %d",&a,&b);
			qsort(&books[a],b-a+1,sizeof(books[a]),cmp);
		}

		for (i=0;i<length;i++){
			printf("%d",books[i]);
			if(i!=length-1)	printf(" ");
			else	printf("\n");
		}
		
	}

	return 0;
}
