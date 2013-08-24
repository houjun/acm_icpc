// SZU B67.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
main () {
		int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
		31,29,31,30,31,30,31,31,30,31,30,31};
	int day,year,i,j,leap,times;
	scanf("%d",&times);
		while(times--){
			int week[7]={0};
			scanf("%d",&year);
			day=0;
			for(i=1900;i<1900+year;i++){
				if(i%4==0&&i%100!=0||i%400==0)	leap=1;
				else				leap=0;
				for(j=0;j<12;j++){
					week[day%7]++;
					day+=month[leap][j];
				}
				
			}
			for (i=0;i<7;i++)		printf ("%d ",week[i]);
			printf ("\n");
		}
		return 0;
}