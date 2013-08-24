#include <stdio.h>
int main()
{
	char name[10];
	int n,t,i,points,tot;
	while(scanf("%d %d",&t,&n),t){
		tot=n*3;
		for (i = 0; i < t ; i++){
			scanf("%s %d",name,&points);
			tot-=points;
		}
		printf("%d\n",tot);
			
	}
	return 0;
}
