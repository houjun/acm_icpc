// SZU A58.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int times,i,j,count,n,m,x,y;
	char mat[51][101];
	scanf("%d",&times);
	while(times--){
		count=0;
		scanf("%d %d",&n,&m);
		for (i=0;i<m;i++)
			scanf("%s",mat[i]);
		int length=strlen(mat[0]);

		for (i=0;i<m;i++){
			for (j=0;j<length;j++){
				if (mat[i][j]=='X')	{
					x=i;
					y=j;
				}
			}
		}

		for (i=0;i<m;i++){
			for (j=0;j<length;j++){
				if(mat[i][j]=='B'&&((fabs(x-i)+fabs(y-j))<=n))
						count++;
			}
		}
		printf("%d\n",count);

		
	}
	return 0;
}
