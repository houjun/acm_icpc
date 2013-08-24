// A38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#define INF 2000000
#define MAX 30000
int main()
{
	int n,i,j,times;
	long b,size[MAX],seq[MAX];
	int min[2][MAX];
	
	scanf("%d",&times);
	while(times--){
		for (i = 0; i < MAX ; i++){
			min[0][i]=INF;
			min[1][i]=0;
		}//initialize
		
		scanf("%d %d",&n,&b);
		for (i = 0; i < n ; i++){
			scanf("%d",&size[i]);
		}
		
		min[0][0]=0;
		for (i = 1; i <= b ; i++){
			for (j = 0; j < n ; j++){
				if (size[j]<=i&&min[0][i-size[j]]!=INF&&min[0][i-size[j]]+1<min[0][i]){
					
					min[0][i]=min[0][i-size[j] ]+1;
					min[1][i]=i-size[j];
				}//if
			}
		}
		
		for (i=b,j = 0; j < min[0][b] ;j++){
			seq[j]=i-min[1][i];
			i=min[1][i];	
		} 
		printf("%d",min[0][b]);
		for (i = 0; i < min[0][b] ; i++){
			printf(" %d",seq[i]);
		}
		printf("\n");
	}//while
	
	
	return 0;
}
