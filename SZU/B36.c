// B49.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define MAX 110
int main()
{
	int n,m,i,j,t,t1,t2,result,min,tt,tmax,tmin;
	int book[MAX];
	int mark[MAX];
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0){
			printf("0\n");
			continue;
		}
		memset(book,0,MAX*sizeof(book[0]));
		memset(mark,0,MAX*sizeof(mark[0]));
		result=0;
		for (i = 0; i < n ; i++)
			scanf("%d",&book[i]);
		
		for (i = 0,t=1; i < m ; i++){
			scanf("%d %d",&t1,&t2);
			if(mark[t1]){
				if(mark[t2]==0)	mark[t2]=mark[t1];
				for (j = 0; j < n ; j++){
					if(j==t2)
						continue;
					else if(mark[j]==mark[t2]){
						mark[j]=mark[t1];					
					}
				}
				mark[t2]=mark[t1];
			}
			else if(mark[t2]){
				if(mark[t1]==0)	mark[t1]=mark[t2];
				for (j = 0; j < n ; j++){
					if(j==t1)
						continue;
					else if(mark[j]==mark[t1]){
						mark[j]=mark[t2];
					
					}
				}
			mark[t1]=mark[t2];
			}
			else{
				mark[t1]=mark[t2]=t;
				t++;
			}				
		}//类似的书有相同的mark值 共有t种 （有类似书） 的书
		tmax=tmin=mark[0];
		for (i = 1; i < n ; i++){
			if(mark[i]>tmax)	tmax=mark[i];
			if(mark[i]<tmin)	tmin=mark[i];
		}
		if(tmin==0)	tmin=1;
		for (i = tmin; i <= tmax ; i++){
			min=10000000;
			for (j = 0; j < n ; j++){
				if(mark[j]==i){
					if(book[j]<min){
						min=book[j];
						tt=j;
					}
				}
			} 
			if(min!=10000000) result+=min;
			for (j = 0; j < n ; j++)
				if(mark[j]==i&&j!=tt)
					result+=(int)(book[j]/2);			
		}
		for (i = 0; i < n ; i++){
			if(mark[i]==0)
				result+=book[i];
		}
		printf("%d\n",result);

	}
	return 0;
}
