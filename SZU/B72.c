#include "stdafx.h"

#include <stdio.h>
#define MAXN 10000
int list[MAXN];

int main()
{
	int t;
	int i,n;
	scanf("%d",&t);
	while (t--){
		int sum=0;
		scanf("%d",&n);
		for (i=0;i<n;i++){
			scanf("%d",&list[i]);
			sum+=list[i]*(1+i*2);
		}
		printf("%d\n",sum);
	}
	return 0;
}
