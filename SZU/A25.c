// SZU A25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
int prime(int n){
	int i,factors=0;
	if(n==1||n==2) return 1;
	
	if (n%2==0)				factors++;
	while(n%2==0)			n/=2;
	
	for(i=3;n>1;i+=2){
		if (n%i==0)			factors++;			
		while(n%i==0)	n/=i;			
	}
	return factors;
	
}

int main(){
	
	int times,time,i,t,max,result;
	scanf("%d",&times);
	while(times--){
		int a[1024];
		scanf("%d",&time);
		max=0;
		result=1;
	
		for (i=0;i<time;i++)
			scanf("%d",&a[i]);
		
		for (i=0;i<time;i++){
			t=prime(a[i]);
			if (max<t){
				max=t;
				result=a[i];
			}
			else if (max==t)
			{
				if (result>a[i])	result=a[i];
				
			}
		}
		printf("%d\n",result);	
	}
	
	
	
	
	return 0;
}