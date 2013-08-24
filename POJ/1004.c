#include <stdio.h>
int main(){
	float a=0.0,result=0.0;
	int i;
	for (i = 0; i < 12 ; i++){
		scanf("%f",&a);
		result+=a;
	}
	printf("$%.2f\n",result/12.0);

	return 0;
}
