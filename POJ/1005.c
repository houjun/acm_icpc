#include <stdio.h>
int main(){
	float x,y,r;
	int cases,t,result;
	scanf("%d",&cases);
	for (t = 1; t <= cases ; t++){
		scanf("%f %f",&x,&y);
		r=x*x+y*y;
		result=(int)(0.5*3.1416*r/50.0)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",t,result);

	}
	printf("END OF OUTPUT.\n");

	return 0;
}