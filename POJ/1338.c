#include <stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
int main(){
	int unum[1501]={0 ,1};
	int t,i;
	int m1,m2,m3;
	m1=m2=m3=1;
	for (i = 2; i < 1501 ; i++){
		unum[i]=min(unum[m3]*5,min(unum[m1]*2,unum[m2]*3));
		if(unum[i]==unum[m1]*2)
			m1++;
		if(unum[i]==unum[m2]*3)
			m2++;
		if(unum[i]==unum[m3]*5)
			m3++;
	}
	while(scanf("%d",&t),t!=0){
		printf("%d\n",unum[t]);
	}

	return 0;
}