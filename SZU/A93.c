#include "stdafx.h"

#include <stdio.h>
int main()
{
	int i,rnum,m,n,cases,casenum,t,totnum,j,count=0;
	while(1){
		count++;
		int num[50001];
		scanf("%d",&totnum);
		if(totnum==0)	break;
		printf("Genome %d\n",count);
		for(i=1;i<=totnum;i++)
			num[i]=i;
		scanf("%d",&rnum);
		for(i=0;i<rnum;i++){
			scanf("%d %d",&m,&n);
			for(;m<n;m++,n--){
				t=num[m];
				num[m]=num[n];
				num[n]=t;
			}
		}

		scanf("%d",&cases);
		for(i=0;i<cases;i++){
			scanf("%d",&casenum);
			for (j=1;j<=totnum;j++){
				if(num[j]==casenum){
					printf("%d\n",j);
					break;
				}
			}
		}


	}
	return 0;
}
