#include "stdafx.h"

#include "stdio.h"
#include "stdlib.h"
void main ()
{   
	long a[30][30]={0}, b[30][30]={0},sum=0;
	int n,k,m,l;
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf("%ld",&a[i][j]); 
		}
	}
	
	for (i=0;i<n;i++){
		while (k<q){
			for (j=0;j<n;j++){
				sum = a[i][j]*a[j][k]+sum;     
			}   
			printf("%f\n",sum);
			k++;
			sum=0;
		}
	}

}