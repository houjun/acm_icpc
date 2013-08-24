
#include <stdio.h>
int main(){
	int times,h,m;
	scanf("%d",&times);
	while(times--){
		scanf("%d:%d",&h,&m);
		if(m==0){
			if(h<13)
				printf("%d\n",h+12);
			else
				printf("%d\n",h-12);
		}
		else
			printf("0\n");
	}
	return 0;
}
