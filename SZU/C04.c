#include <stdio.h>
int main()
{
	int cases;
	int box[101][3],d,i,n,free[101],min,find,t;
	scanf("%d",&cases);
	while(cases--){
		min=2100000000;
		scanf("%d",&d);
		d*=2;
		scanf("%d",&n);
		for (i = 0; i < n ; i++){// n kinds of boxes
			scanf("%d%d%d",&box[i][0],&box[i][1],&box[i][2]);
			free[i]=-1;
		}
		for (i = 0; i < n ; i++){
			if(d>box[i][0]||d>box[i][1]||d>box[i][2])
				free[i]=-1;
			else{
				find=1;
				free[i]=box[i][0]*box[i][1]*box[i][2]-d*d*d;
				if(free[i]>=0)
					min=min>free[i]?free[i]:min;
			}

		}
		find=0;
		for (i = 0; i < n ; i++){
			if(free[i]>=0)
				find=1;
		}
		if(!find)
			printf("-1");
		else{
			t=0;
			for (i = 0; i < n ; i++){
				if(free[i]==min){
					if(t!=0)	printf(" ");
					printf("%d",i);
					t++;
				}
				
			}
		}
		printf("\n");

		
	}
	return 0;
}

