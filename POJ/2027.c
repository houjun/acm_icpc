#include <stdio.h>

int main(){

	int cases,x,y;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&x,&y);
		if(x<y)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}

	return 0;
}