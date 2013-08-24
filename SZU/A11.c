// SZU A11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int main()
{
	int times,time,a[50],temp,max1,max2,i,max;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&time);
		for (i=0;i<time;i++)
				scanf("%d",&a[i]);

			temp=max1=max2=1;

			//开始判断递增序列最大长度
			
			for (i=0;i<time-1;i++)
			{
				if(a[i+1]<=a[i])		temp=1; 
				else if(a[i+1]>a[i])	temp++;
				max1=(max1>temp?max1:temp);
			}
		
			//开始判断递减序列最大长度
			temp=1;
			for (i=0;i<time-1;i++)
			{
				if(a[i+1]>=a[i])		temp=1;
				else if(a[i+1]<a[i])	temp++;				
				max2=(max2>temp?max2:temp);
			}
		


		max=(max1>max2?max1:max2);
		printf("%d\n",max);
	}
	return 0;
}
