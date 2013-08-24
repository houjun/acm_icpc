#include "stdafx.h"

#include <stdio.h>

int main()
{
	int pupil[50];
	int round,n=1,add,out,i,flag;
	while(n){
		scanf("%d",&n);
		if(n==0)	break;
		for (i=0;i<n;i++)
			scanf("%d",&pupil[i]);
		round=0;
		while(1){
			round++;
			out=pupil[n-1]/2;
			for (i=0;i<n;i++)
			{
				add=out;
				out=pupil[i]/2;
				pupil[i]-=(out-add);
				if(pupil[i]%2!=0)	pupil[i]++;
							
			}
			
			for (i=1,flag=1;i<n&&flag;i++)
				if(pupil[i]!=pupil[0])
					flag=0;
			if (flag)
			{
				printf("%d %d\n",round,pupil[0]);
				break;
			}
		}

	}


	return 0;
}
