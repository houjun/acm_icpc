#include "stdafx.h"

#include <stdio.h>
long c(int n,int r){
	if(r>n/2)	r=n-r;
	int i,j;
	long sum=1;
	if(n==r||r==0)	return 1;
	else{
		for(i=n,j=1;i>=n-r+1;i--,j++){
			sum*=i;
			sum/=j;
		}
	}
	return sum;
}
int main()
{
	int times,win,num,wp,i,j;
	double winp,losep,winpercent,result;
	scanf("%d",&times);
	while(times--){
		scanf("%d %d %d",&num,&win,&wp);
		winpercent=(double)(wp);
		winpercent/=100.0;
		result=0.0;
		for(i=0;i<win;i++){
			winp=losep=1.0;
			for(j=1;j<=i;j++)
				winp*=winpercent;
			for(j=1;j<=num-i;j++)
				losep*=(1-winpercent);
			result+=(c(num,i)*winp*losep);
		}
		printf("%.4lf\n",result);


	}
	return 0;
}
