#include "stdafx.h"

#include <stdio.h>
#include <string.h>
int main()
{
	char t;
	int m,n,i,j,max,maxnum;
	scanf("%d %d",&n,&m);
	while(n!=0){
		char proname[10][21],color[10][21];
		char tmp[21];
		int pro_ans[10]={0};
		for (i=0;i<n;i++)
			scanf("%s %s",proname[i],color[i]);
		for (j=0;j<m;j++){
			scanf("%s",tmp);
			for(i=0;i<n;i++){
				if (strcmp(tmp,color[i])==0)
					pro_ans[i]++;			
			}
		}
		max=pro_ans[0];
		maxnum=0;
		for (i=1;i<n;i++){
			if (pro_ans[i]>max||(pro_ans[i]==max&&strcmp(proname[i],proname[maxnum])<0)){	
				max=pro_ans[i];
				maxnum=i;
			}
		}
		
		printf("%s %d\n",proname[maxnum],max);
		t=getchar();
		scanf("%d %d",&n,&m);
	}



	

	return 0;
}
