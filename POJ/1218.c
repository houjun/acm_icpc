#include <stdio.h>
int main()
{
	int cell[101];
	int times,round,i,j,count;
	scanf("%d",&times);
	while(times--){
		scanf("%d",&round);
		count=0;
		for (i = 0; i <= round ; i++){
			cell[i]=1;
		}
		for (i = 2; i <= round ; i+=2){
			for (j = 1; i*j<=100&&j < 101 ; j++){
				if(cell[i*j]==1)
					cell[i*j]=0;
				else
					cell[i*j]=1;
			}
		}
		for (i = 3; i <= round ; i+=2){
			for (j = 1; i*j<=round&&j <= round ; j++){
				if(cell[i*j]==1)
					cell[i*j]=0;
				else
					cell[i*j]=1;			}
		}		
		for (i = 1; i <= round ; i++){
			if(cell[i]==1)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
