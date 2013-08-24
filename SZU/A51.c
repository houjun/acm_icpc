#include "stdafx.h"

#include <stdio.h>
int main()
{
	int times;
	int x1,y1,x2,y2,x3,y3,x4,y4;
	int x,y,a,b,c,d,share;
	scanf("%d",&times);
	while(times--){
		int flag=1;
		scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		a=b=c=d=0;
		if (x2<=x3||y2<=y3)
		{
			printf("0\n");
			continue;
		}

		for (x=x1;flag&&x<=x2;x++){
			for (y=y1;flag&&y<=y2;y++){
				if (x>=x3&&y>=y3){
					a=x;
					b=y;
					flag=0;
				}
			}
		}
		for (x=a;x<=x2;x++){
			if (x+1>x4||x+1>x2){
				c=x;
				break;
			}
		}
		for (y=b;y<=y2;y++){
			if (y+1>y4||y+1>y2){
				d=y;
				break;
			}
		}
		share=(c-a)*(d-b);
		printf("%d\n",share);
	}
	return 0;
}
