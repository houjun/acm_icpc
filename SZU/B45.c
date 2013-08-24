// SZU B45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define MAX 103
int main()
{	
	int m,n,i,j,k,l,t=0;
	char ch[MAX],c;
	char set[MAX][MAX];
	while(1){
		t++;
		scanf("%d %d",&m,&n);
		if(m==0)	break;
		if(t!=1)			printf("\n");
		memset(set,'0',sizeof(set));
		getchar();
		for(i=1;i<=m;i++)
		{
			scanf("%s",ch);
			for(j=0;j<n;j++)
			{	
				c=ch[j];
				if(c=='*')
				{
					set[i][j+1]=c;
					for(k=i-1;k<=i+1;k++)
						for(l=j;l<=j+2;l++)
							if(set[k][l]!='*')
								set[k][l]+=1;
				}

				
			}
		}
		printf("Field #%d:\n",t);		
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++)
				printf("%c",set[i][j]);
			printf("\n");
		}
		
	}
	return 0;
}
