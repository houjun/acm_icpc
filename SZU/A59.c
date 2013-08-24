// SZU A59.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times;
	int mat[101][101]={0};
	scanf("%d",&times);
	while(times--){
		int x,y,l,i,j,count;
		char cmd[6];
		scanf("%s %d %d %d",cmd,&x,&y,&l);

		if (cmd[0]=='B')
		{
			for (i=x;i<x+l;i++)
				for (j=y;j<y+l;j++)
					mat[i][j]=1;				
		}
		else if (cmd[0]=='W')
		{
			for (i=x;i<x+l;i++)
				for (j=y;j<y+l;j++)
					mat[i][j]=0;
		}
		else
		{	count=0;
			for (i=x;i<x+l;i++)
				for (j=y;j<y+l;j++)
					if (mat[i][j]==1)	count++;

			printf("%d\n",count);

		}
	}
	return 0;
}
