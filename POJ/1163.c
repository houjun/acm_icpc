
#include <stdio.h>
#define  max(a,b) ((a)>(b)?a:b)
int main()
{
	int arr[100][100]={0},result[100][100]={0};
	int i,j,t;
	scanf("%d",&t);
	for (i = 0; i < t ; i++){
		for(j=0;j<=i;j++)
			scanf("%d",&arr[i][j]);
	}

	for (i = t-2; i >= 0 ; i--){
		for (j = 0; j <= i ; j++){
			arr[i][j]=max(arr[i+1][j],arr[i+1][j+1])+arr[i][j];
		}
	}

	printf("%d\n",arr[0][0]);
	return 0;
}
