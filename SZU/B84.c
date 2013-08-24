// B84.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int algorism(int n){
	if (n%2==0)		n=n/2;
	else			n=n*3+1;
	return n;
}
int main()
{
	int x,y;
	int i,t,times,max;
	while(scanf("%d %d",&x,&y)!=EOF){
		if (x>y){
			t=x;x=y;y=t;
		}
		max=0;
		for(i=x;i<=y;i++){
			times=0;
			t=i;
			while(t!=1){
				t=algorism(t);
				times++;
			}	
			if (t==1)	times++;
			max=max>times?max:times;
		}
		printf("%d %d %d\n",x,y,max);
	}


	return 0;
}
