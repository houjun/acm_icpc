// SZU B70.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int times,mi,mj,i,j;
	int matrix[100][100];
	scanf("%d",&times);
	while(times--){
		scanf("%d %d",&mi,&mj);
		for (i=0;i<mi;i++){
			for (j=0;j<mj;j++){
				scanf("%d",&matrix[i][j]);
			}
		}

		for (j=0;j<mj;j++){
			for (i=0;i<mi;i++){
				printf("%d",matrix[i][j]);
				if (i!=mi-1)	printf(" ");
			}
			printf("\n");
		}

	}
	return 0;
}
