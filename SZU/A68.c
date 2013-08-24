#include "stdafx.h"

#include <stdio.h>
#include <math.h>
int isprime(int n){
	int i,t;
	if(n<=3)			return  1;
	else if (n%2==0)	return -1;
	else{
		t=(int)(sqrt(n))+1;
		for (i=3;i<t;i++){
			if(n%i==0)
				return -1;
		}
	}
	return 1;
}
int ispa(int n){
	int num[8],i=0,j;
	while(n){
		num[i++]=n%10;
		n/=10;
	}
	i--;
	for (j=0;j<i;j++,i--)
		if(num[i]!=num[j])
			return -1;
	return 1;
}
int main()
{
	int times,num;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&num);
		while(1){
			if(ispa(num)==1&&isprime(num)==1){
				printf("%d\n",num);
				break;
			}
			num++;
		}
	}


	return 0;
}
