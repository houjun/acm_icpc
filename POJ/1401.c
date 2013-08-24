#include <stdio.h>

int main(){
	int f5;
	int cases,t;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&t);
		f5=0;	
		while(t>4){
			t/=5;
			f5+=t;
		}
		printf("%d\n",f5);
	}

	return 0;
}
