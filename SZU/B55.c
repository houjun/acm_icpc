#include "StdAfx.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 125010
	int num[MAX];
	int list[MAX];

int main()
{
	
	int n,m,p,i,j,flag,max;
	int times;
	scanf("%d",&times);
	while(times--){
		int none=1,t=0;
		for (i = 0; i < MAX ; i++){
			num[i]=list[i]=0;
		}
		scanf("%d%d",&n,&m);
		for (i = 0; i <= m ; i++){
			for (j = 0; j <= m ; j++){
				num[i*i+j*j]=1;
			}
		}
		max=m*m*2;
		for (i = 0; i <= max ; i++){
			if (num[i]==1){
				list[t++]=i;
			}
		}

		for (i = 1; i < max/(n-1)+1 ; i++){//difference between two num
			for (j = 0; j<t ; j++){//search from beginning
				flag=0;
				for (p = 0; p < n-1 ; p++){

					if (list[j]+(p+1)*i<=max&& num[list[j]+p*i]==1&&num[list[j]+(p+1)*i]==1)
						flag=1;
					
					else{
						flag=0;
						break;					
					}			
					
				}
				if (flag){
					printf("%d %d\n",list[j],i);
					none=0;
				}
			}

		}
		if (none){
			printf("NONE\n");
		}
	}


	return 0;
}


