#include <stdio.h>
#define MAX 5000
int get(int n){
	if (n<2)
		return 0;	
	else
		return n/2;
}
int main(){
	int n,i,j,count,flag,ii,t;
	int fence[MAX+10];
	while(scanf("%d",&n),n){

		flag=0;
		count=0;
		for (i = 0; i < n ; i++){
			scanf("%d",&fence[i]);
			if(fence[i]==1)
				flag=1;
		}
		ii=0;
		j=n-1;
		if (fence[0]==0){//from the first 0 to left and rightmost 0
			while(ii<n&&fence[ii]==0)
				ii++;
			while(j>=ii&&fence[j]==0)
				j--;
			count+=get(ii+n-j-1);
		}
		
		for (i = ii; i <= j ; i++){ //from the first 1 to last 1
			t=0;
			while(i<n&&fence[i]==0){
				t++;
				i++;
			}
			count+=get(t);
		}
		if(!flag)// all 0
			if(n<=1)
				count=0;
			else
				count=(n+1)/2;

		printf("%d\n",count);

	}
	return 0;
}