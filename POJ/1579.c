
#include <stdio.h>
int main()
{
	int w[21][21][21];
	int i,j,k,a,b,c,ta,tb,tc;
	for (i = 0; i < 21 ; i++){
		for (j = 0; j < 21 ; j++){
			for (k = 0; k < 21 ; k++){
				if(i==0||j==0||k==0)
					w[i][j][k]=1;
				else if (i<j&&j<k){
					w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				}
				else
					w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
			}
		}
	}
	scanf("%d %d %d",&a,&b,&c);
	while(a!=-1||b!=-1||c!=-1){
		ta=a;tb=b;tc=c;
		if(a>20||b>20||c>20)
			ta=tb=tc=20;
		if(a<0)
			ta=0;
		if(b<0)
			tb=0;
		if(c<0)
			tc=0;
		

		printf("w(%d, %d, %d) = %d\n",a,b,c,w[ta][tb][tc]);
		scanf("%d %d %d",&a,&b,&c);
	}
	return 0;
}
