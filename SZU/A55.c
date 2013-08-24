
#include <stdio.h>
int main(){
	int times;
	long a,b,n,i,t;
	scanf("%d",&times);
	while(times--){
		scanf("%ld %ld %ld",&a,&b,&n);
		t=a/b;
		printf("%ld.",t);
		for (i = 0; i < n ; i++){
			a=a-t*b;
			a*=10;
			t=a/b;
			printf("%ld",t);
		}
		printf("\n");
		
	}
	return 0;
	
}