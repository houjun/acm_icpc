#include <stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
void swap(int *a,int *b){
	int t;
	if(*a<*b){
		t=*a;
		*a=*b;
		*b=t;
	}
}
int main()
{
	int l1,l2,w1,w2,result;
	while(scanf("%d %d %d %d",&l1,&w1,&l2,&w2),w1){
		swap(&l1,&w1);
		swap(&l2,&w2);		
		result=min((l2*100.0)/l1,(w2*100.0)/w1);
		if(result>100)
			result=100;
		printf("%d%%\n",result);
	}
	return 0;
}
