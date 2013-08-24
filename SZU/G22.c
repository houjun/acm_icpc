#include <stdio.h>

int main(){
	int cases,i,n,num[101],tot,flag;
	int tail,same;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		flag=0;
		for (i = 0; i < n ; i++){
			scanf("%d",&num[i]);	
			if(i>0&&num[i]!=num[i-1])	flag=1;
		}
		//all same
		if(n<3){printf("0\n");continue;}
		if(!flag){printf("%d\n",n);continue;}

		for (i=n-1; i > 0 ; i--)
			if(num[i]==num[i-1])
				break;
		tail=i;
		if(tail==0){printf("0\n");continue;}

		tot=tail+1;

		for (i = tail - 1; i >= 0 ; i--){
			if(num[i]!=num[tail])
				break;
		}
		tail=i;

		for (i = 0; i <= tail ; i++){
			same=0;
			if(num[i]==num[i+1]){
				while(num[i]==num[i+1]){
					i++;
					same++;
				}
				tot -= same;
			}
		}
		printf("%d\n",tot);


	
	}
	return 0;
}
