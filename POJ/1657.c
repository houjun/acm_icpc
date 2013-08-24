#include <stdio.h>
#include <math.h>

int main()
{
	int times,i;
	char a[3],b[3];
	int x,y;
	scanf("%d",&times);
	for(i=0;i<times;i++){
		getchar();
		scanf("%s %s",&a,&b);
		
		x=abs(a[0]-b[0]);
		y=abs(a[1]-b[1]);
		if(x==0&&y==0) printf("0 0 0 0\n");
		else{
			if(x<y)				 printf("%d",y);
			else				 printf("%d",x);
			if(x==y||x==0||y==0) printf(" 1");
			else				 printf(" 2");
			if(x==0||y==0)		 printf(" 1");
			else				 printf(" 2");
			if(abs(x-y)%2!=0)	 printf(" Inf");
			else if(x==y)		 printf(" 1");
			else				 printf(" 2");

			printf("\n");
		}

	}


	return 0;
}

