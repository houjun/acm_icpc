#include <stdio.h>
int divide(unsigned long num,int t){
	int tmp=num%t;
	if(tmp==0)
		return	num/t;
	else
		return	num/t+1;
}
int main(){
	long long num;
	while(scanf("%lu",&num)!=EOF){
		if (num<=9){
			printf("Nic wins.\n");
			continue;
		}
		while(1){
			num=divide(num,9);
			if (num==1){
				printf("Nic wins.\n");
				break;
			}

			num=divide(num,2);
			if(num==1){
				printf("Susan wins.\n");
				break;
			}
		}

	}
	return 0;
}
