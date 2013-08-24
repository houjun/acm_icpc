// A74.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
int cmp ( const void *a , const void *b ){ 
	return *(int *)b - *(int *)a; 
} 
int main()
{
	int times;
	scanf("%d",&times);
	while(times--){
		int m,q,i,j,t,k,tk,ttt;
		char id[MAX][7]={'\0'},query[201][7]={'\0'};
		int salary[MAX]={0},height[MAX]={0},sortsalary[MAX]={0},sortweight[MAX];
		scanf("%d %d",&m,&q);
		for (i = 0; i < m ; i++){
			scanf("%s", id[i]);
			scanf("%d %d",&salary[i],&height[i]);
			sortsalary[i]=salary[i];
			sortweight[i]=height[i];
		}
		for (i = 0; i < q ; i++){
			scanf("%s",&query[i]);
		}
		qsort(sortsalary,m,sizeof(sortsalary[0]),cmp);
		qsort(sortweight,m,sizeof(sortweight[0]),cmp);

		for (i = 0; i < q ; i++){
			for(j=0;j<m;j++){
				if(strcmp(query[i],id[j])==0)	
					break;
			}//j为当前query人的id编号

			for (k = 0; k < m ; k++){
				if(salary[j]==sortsalary[k])
					break;
			}//k is the current query's rank in salary
			tk=k;
			if(k!=0){
				for (t = 0; t < m ; t++){
					while(sortsalary[k-1]==salary[t]){
						if(height[j]<height[t])
							break;
						else{
							t=0;
							k--;
						}
					}
					if(sortsalary[k-1]==salary[t])
						break;
				}
			}//t is query's boss's id number
			if(k!=0)
				printf("%s ",id[t]);	
			else
				printf("0 ");
			ttt=0;

			if(tk==m-1||height[j]==sortweight[m-1])
				printf("0\n");
			else{
				printf("%d\n",m-k-1);
			}	



		}




	}
	return 0;
}
